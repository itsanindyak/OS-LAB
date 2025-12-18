file="15_student.txt"

read -p "Enter roll" roll
# read -p "Enter new name" newName
# read

echo "roll|name|marks" > "temp.txt"

while IFS="|" read r n m
do
    if [ "$r" -eq "$roll" ]; then
        continue
    else
        echo "$r|$n|$m" >> "temp.txt"
    fi
done < <( tail -n +2 $file )

mv "temp.txt" "$file"
if [ -f "temp.txt" ]; then
    rm -f "temp.txt"
fi 
cat "$file"