#to reverse a file
set -xv
cp $1 file 
l=`cat file | wc -l`
rm rfile
while [ $l -ge 1 ]
do 
tail -n | file >> rfile
l=`expr $l - 1`
head -n $l file > temp
mv temp file
done
