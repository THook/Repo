#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

void	ls_print_long_counters
			(t_list *entries, char *path, t_options *options, size_t *counts)
{
	struct passwd	*passwd;
	struct group	*group;
	char			*entry;
	struct stat		estat;

	while (entries)
	{
		entry = entries->content;
		if (!is_hidden(entry) || options->a)
		{
			lstat(get_full_name(path, entry, 0), &estat);
			passwd = getpwuid(estat.st_uid);
			group = getgrgid(estat.st_gid);
			ls_print_long_counters2(counts, &estat, passwd, group);
		}
		entries = entries->next;
	}
	if (counts[5] + counts[6] + 2 > counts[3])
		counts[3] = counts[5] + counts[6] + 2;
}

void	ls_print_long_counters2
			(size_t *counts, struct stat *s, struct passwd *p, struct group *g)
{
	size_t	l;

	l = (p) ? ft_strlen(p->pw_name) : ft_nbrlen(s->st_uid);
	counts[0] = (l > counts[0]) ? l : counts[0];
	l = (p) ? ft_strlen(g->gr_name) : ft_nbrlen(s->st_gid);
	counts[1] = (l > counts[1]) ? l : counts[1];
	if (ft_nbrlen(s->st_nlink) > counts[2])
		counts[2] = ft_nbrlen(s->st_nlink);
	if (ft_nbrlen(s->st_size) > counts[3])
		counts[3] = ft_nbrlen(s->st_size);
	counts[4] += s->st_blocks;
	if (ft_nbrlen(major(s->st_rdev)) > counts[5])
		counts[5] = ft_nbrlen(major(s->st_rdev));
	if (ft_nbrlen(minor(s->st_rdev)) > counts[6])
		counts[6] = ft_nbrlen(minor(s->st_rdev));
}

void	ls_print_name(char *entry, char *path, struct stat *estat)
{
	char	buffer[BUFF_SIZE + 1] = { '\0' };

	if (S_ISLNK(estat->st_mode))
	{
		ft_putstr(entry);
		ft_putstr(" -> ");
		ft_strclr(buffer);
		readlink(get_full_name(path, entry, 0), buffer, BUFF_SIZE);
		ft_putendl(clean_path(get_full_name(path, buffer, 0), 0));
	}
	else
		ft_putendl(entry);
}

void	ls_print_size(struct stat *estat, size_t *counts)
{
	if (S_ISCHR(estat->st_mode) || S_ISBLK(estat->st_mode))
	{
		ft_putnbr_right(major(estat->st_rdev), counts[5]);
		ft_putstr(", ");
		ft_putnbr_right(minor(estat->st_rdev), counts[6]);
	}
	else
		ft_putnbr_right(estat->st_size, counts[3]);
}

void	ls_print_long_line(char *entry, char *path, size_t *counts)
{
	struct stat	estat;
	time_t		time;

	if (!entry || !path || !counts)
		return ;
	lstat(get_full_name(path, entry, 0), &estat);
	ls_print_permissions(&estat);
	ft_putstr("  ");
	ft_putnbr_right(estat.st_nlink, counts[2]);
	ft_putchar(' ');
	ls_print_user(estat.st_uid, counts[0]);
	ft_putstr("  ");
	ls_print_group(estat.st_gid, counts[1]);
	ft_putstr("  ");
	ls_print_size(&estat, counts);
	ft_putchar(' ');
	ctime(&time);
	ls_print_time(ctime(&estat.st_mtime), &estat);
	ft_putstr(" ");
	ls_print_name(entry, path, &estat);
}
