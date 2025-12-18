
file="11_directory.txt"
path=$1

cd $path

ls -p > "$file"

echo "file count = $(wc -w < "$file")"