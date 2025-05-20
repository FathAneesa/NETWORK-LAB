#script to counting number of occurence of a word in set of files

if [ $# -lt 2 ]
then
echo "Syntax is <$0> <word> <filename1 [filename2.....]>"
exit 1
fi
word=$1
shift
count=0
while [ $# -ne 0 ]
do
for wd in `cat $1`
do
if [ $wd = $word ]
then
count=`expr $count + 1`
fi
done
shift
done
echo "Number of occurrance of word =$count"
exit 0
