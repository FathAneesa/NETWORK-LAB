if [ $# -ne 2 ]
then
    echo "Syntax: $0 <file> <word to delete>"
    exit 1
fi

echo "Removing lines containing '$2' from $1"
grep -v "$2" $1 > temp
mv temp $1

if [ $? -eq 0 ]
then
    echo "'$2' deleted from $1 successfully"
else
    echo "Error deleting '$2' from $1"
fi

exit 0
