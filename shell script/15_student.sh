
file="15_student.txt"

max=0
name=""
roll=""


while IFS="|" read n r m  
do
    if [ "$m" -gt "$max" ]; then
        max=$m
        name=$n
        roll=$r
    fi 
# done < "$file"  
done < <(tail -n +2 $file)


echo "Highest Marks = $max"
echo "Student Name = $name"
echo "Roll Number = $roll"