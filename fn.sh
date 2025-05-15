#to find ncr

if [ $# -ne 2 ]
then
echo "syntax is <$0> <n> <r>"
exit 1
fi

fact()
{
 n=$1
i=1
f=1
while [ $1 -le $n ]
do
f=`expr $f \* $i`
i=`expr $ + 1`
done
return $f
}

fact $1
factn= $?
fact $2
factr=$?
fact=`expr $1 - $2`
factnr= $?
rnr=`expr $factr \* $factnr`
echo "$1C$2 =`expr $factn / $rnr`"


