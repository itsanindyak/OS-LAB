
file="9_sort_input.txt"

read -a nums < "$file"

# read from file
echo "${nums[@]}" | tr ' ' '\n' | sort -n > "9_sort_output.txt"

# read from command line
# echo "$@" | tr ' ' '\n' | sort -n > "9_sort_output.txt"