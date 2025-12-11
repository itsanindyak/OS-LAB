reverse1(){
    rev=0
    n=$1
    while [ $n -ne 0 ]
    do
        digit=$((n%10))
        rev=$((rev*10+digit))
        n=$((n/10))
    done
    echo $rev    
}
read -p "enter:" x
y=$(reverse1 "$x")
if [ $x -eq $y ]
then
    echo "palindrome"
else
    echo "not palindrome"
fi        