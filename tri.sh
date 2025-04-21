#script to check whether the given forms a triangle
if [ $# -ne 3 ]
then
echo " Syntax is <$0> <a> <b> <c>"
else
a=$1
b=$2
c=$3

if [ $a -gt $c ]
then
t=$a
a=$c
c=$t
fi

if [ $b -gt $c ]
then
t=$b
b=$c
c=$t
fi

if [ `expr $a + $b` -gt $c ]
then
echo 'triangle can be formed'
else
echo 'triangle cant be formed'
exit 1
fi

if [ $a -eq $b -a $a -eq $c ]
then
echo 'equilateral triangle'
exit 0
fi

if [ $a -eq $b -o $a -eq $c -o $b -eq $c ]
then
echo 'Isosceles triangle'
exit 0
fi

aa=`expr $a "*" $a`
bb=`expr $b "*" $b`
cc=`expr $c "*" $c`
if [ `expr $aa + $bb` -eq $cc ]
then
 echo 'right angled triangle'
exit 0
fi
echo "normal triangle"
fi


sh tri.sh 5 6 7
triangle can be formed
normal triangle


sh tri.sh 3 4 5
triangle can be formed
right angled triangle


sh tri.sh 2 2 1
triangle can be formed
Isosceles triangle


sh tri.sh 3 3 3
triangle can be formed
equilateral triangle



























