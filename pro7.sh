#to count number of words and lines in a file
if [ $# -gt 1 ]
then
echo "Syntax is <$0> [<filename>]"
exit 1
fi

flag=0
if [ $# -eq 1 ]
then
term=`tty`
exec < $1
flag=1
fi

while read line
do
nol=`expr $nol + 1`
set $line > /dev/null
nowds=`expr $nowds + $#`
done
echo "Number of line= $nol"
echo "Number of words = $nowds"
if [ $flag -eq 1 ]
then
exec < $term
fi

exit 0





sh count.sh tri.sh
Number of line= 55
Number of words = 153

