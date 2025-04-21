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



sh calc.sh 2 + 6
8

sh calc.sh 5 - 2
3

sh calc.sh 4 x 2
8

sh calc.sh 28 % 17
11

sh calc.sh 14 / 7
2






















