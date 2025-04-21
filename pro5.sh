#script to test whether the number is prime or not
if [ -z "$1" ];
then
 echo "usage: $0 <number>"
exit 1
fi
num=$1
if [ "$num" -lt 2 ] ;
then
echo " $num is not a prime number"
exit 0
fi
i=2
while [ $((i * i)) -le "$num" ];
do
if [ $((num % i )) -eq 0 ];
then
echo "$num is not a prime number"
exit 0
fi
i=$((i + 1))
done
echo "$num is prime number "


sh prime.sh 24
24 is not a prime number

sh prime.sh 11
11 is prime number 







