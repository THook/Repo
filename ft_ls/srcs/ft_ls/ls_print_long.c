#define PRINT_PERMISSION(cond, c)\
	if (cond)\
		ft_putchar(c);\
	else\
		ft_putchar('-');
#include "ft_ls.h"
#include <time.h>

void	ls_print_permissions(struct stat *estat)
{
	if (S_ISDIR(estat->st_mode))
		ft_putchar('d');
	else if (S_ISREG(estat->st_mode))
		ft_putchar('-');
	else if (S_ISLNK(estat->st_mode))
		ft_putchar('l');
	else if (S_ISBLK(estat->st_mode))
		ft_putchar('b');
	else if (S_ISCHR(estat->st_mode))
		ft_putchar('c');
	else if (S_ISFIFO(estat->st_mode))
		ft_putchar('p');
	else if (S_ISSOCK(estat->st_mode))
		ft_putchar('s');
	PRINT_PERMISSION((estat->st_mode & S_IRUSR), 'r')
	PRINT_PERMISSION((estat->st_mode & S_IWUSR), 'w')
	PRINT_PERMISSION((estat->st_mode & S_IXUSR), 'x')
	PRINT_PERMISSION((estat->st_mode & S_IRGRP), 'r')
	PRINT_PERMISSION((estat->st_mode & S_IWGRP), 'w')
	PRINT_PERMISSION((estat->st_mode & S_IXGRP), 'x')
	PRINT_PERMISSION((estat->st_mode & S_IROTH), 'r')
	PRINT_PERMISSION((estat->st_mode & S_IWOTH), 'w')
	PRINT_PERMISSION((estat->st_mode & S_IXOTH), 'x')
}

void	ls_print_user(uid_t uid, size_t length)
{
	struct passwd	*passwd;

	passwd = getpwuid(uid);
	if (!passwd)
		ft_putnbr_left(uid, length);
	else
		ft_putstr_left(passwd->pw_name, length);
}

void	ls_print_group(gid_t gid, size_t length)
{
	struct group	*group;

	group = getgrgid(gid);
	if (!group)
		ft_putnbr_left(gid, length);
	else
		ft_putstr_left(group->gr_name, length);
}

void	ls_print_time(char *str, struct stat *estat)
{
	char	**current_time;
	char	**date;
	char	**hours;
	time_t	t;

	date = ft_strsplit(str, ' ');
	hours = ft_strsplit(date[3], ':');
	time(&t);
	current_time = ft_strsplit(ctime(&t), ' ');
	ft_putstr(date[1]);
	ft_putchar(' ');
	ft_putstr_right(date[2], 2);
	ft_putchar(' ');
	if (t - 15768000 > estat->st_mtime)
	{
		ft_putchar(' ');
		ft_putstr(ft_strsub(current_time[4], 0, ft_strlen(current_time[4]) - 1));
		return ;
	}
	ft_putstr(hours[0]);
	ft_putchar(':');
	ft_putstr(hours[1]);
}

void	ls_print_long(t_list *entries, char *path, t_options *options)
{
	char	*entry;
	size_t	counts[7] = { 0 };

	ls_print_long_counters(entries, path, options, counts);
	if (ft_lstlen(entries) < 2 || (ft_lstlen(entries) == 2 && !options->a))
		return ;
	ft_putstr("total ");
	ft_putnbrln(counts[4]);
	while (entries)
	{
		entry = entries->content;
		if (!is_hidden(entry) || options->a)
			ls_print_long_line(entry, path, counts);
		entries = entries->next;
	}
}
