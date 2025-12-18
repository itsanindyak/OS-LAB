
file="7_palindrome_word.txt"

while read -r line
do
    for word in $line
    do
        clean=$(echo $word | tr -d ".?!," )
        rev=$(echo $clean | rev)

        if [ $clean = $rev ]
        then
            echo "$clean is palindrome" >> "output.txt"
        fi
    done
done < "$file"