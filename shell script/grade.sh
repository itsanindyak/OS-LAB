
read -p "enter marks:" x
case $x in
    9[0-9]|100)
        echo " grade A "
        ;;
    8[0-9])
        echo " grade B "
        ;;
    7[0-9])
        echo " grade C "
        ;;
    6[0-9])
        echo " grade D "
        ;;
  
    *)
        echo "fail"
        ;;
esac
              