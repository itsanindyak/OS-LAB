
file="9_sort_input.txt"

read -a nums < "$file"

max=-9999
min=9999

for num in "${nums[@]}"
do
    if [ "$num" -gt "$max" ]; then
        max=$num
    fi

    if [ "$num" -lt "$min" ]; then
        min=$num
    fi
done

echo "max=$max   min=$min"
echo "${nums[@]}"