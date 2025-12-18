

while true
do
    echo "------ MENU ------"
    echo "1. List files with permissions"
    echo "2. List user processes"
    echo "3. Today's date"
    echo "4. List users in the system"
    echo "5. Exit"
    echo "------------------"
    read -p "Enter your choice: " ch

    case $ch in
        1)
            ls -l
            ;;
        2)
            ps -u $USER
            ;;
        3)
            echo "today is $(date "+%d-%B %Y") "
            ;;
        4)
            cut -d: -f1 /etc/passwd
            ;;
        5)
            exit 0
            ;;
        *)
            echo "invalid option"
            ;;
    esac
done