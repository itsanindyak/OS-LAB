
gcd(){
    a=$1
    b=$2

    while [ $b -ne 0 ]
    do 
        r=$((a%b))
        a=$b
        b=$r 
    done 

    echo $a
}

g=$1
l=$1

for num in "$@"
do  
    g=$(gcd $g $num)
    l=$((l*num/g))
done

echo "GCD=$g"
echo "LCM=$l"
