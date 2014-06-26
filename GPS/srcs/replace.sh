for file in *.c
do
/bin/mv $file $file.old
sed 's/\.\.\/\.\.\/includes\///g' <$file.old >$file
done