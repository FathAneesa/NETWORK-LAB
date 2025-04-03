#create a small calculator program

if [ $# -ne 3 ]
then
echo "Syntax is <$0> <no1> [operator]  <no3>"
else
case $2 in
+) sum=`expr $1 + $3`;;
-) sum=`expr $1 - $3`;;
x|X) sum=`expr $1 \* $3`;;
%) sum=`expr $1 % $3`;;
/) sum=`expr $1 / $3`;;
*) echo 'invalid operator';;
esac
echo $sum
fi

