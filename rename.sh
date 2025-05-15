#script to rename all ordinary files  with filename .pid

if [ $# -ne 1 ]; then
echo "syntax is $0 <directory location>"
exit 1
fi
cd $1
for file in *
do
if [ -f $file  ]; then
mv $file $$$file
fi
done
cd ..

