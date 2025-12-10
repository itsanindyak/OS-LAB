# **Introduction to Shell Script — Notes**

## **➡️ ARRAY**

### **Declare an Array**

```bash
arr=( 1 2 3 4 )
```

### **1) Get a particular index**

```bash
echo ${arr[2]}
```

### **2) Get all values**

```bash
echo ${arr[*]}
```

### **3) Get length of array**

```bash
echo ${#arr[*]}
```

### **4) Update the array**

```bash
arr+=( 5 6 7 )
```

### **5) Key-Value (Associative) Arrays**

```bash
declare -A myArray
myArray=( [name]=Paul [age]=20 )
echo "${myArray[name]}"
```

---

## **➡️ STRINGS**

```bash
myVar="Hello World!"
```

### **Length of string**

```bash
length=${#myVar}
```

### **Convert to Uppercase**

```bash
upper=${myVar^^}
```

### **Convert to Lowercase**

```bash
lower=${myVar,,}
```

### **Replace substring**

*(variable, target, replacement)*

```bash
replace=${myVar/World/Buddy}
```

### **Slice string**

*(variable, start_index, number_of_characters)*

```bash
slice=${myVar:6:11}
```

---

## **➡️ USER INPUT**

### **Basic input**

```bash
read var_name
```

### **Input with prompt**

```bash
read -p "Your name: " NAME
```

---

## **➡️ ARITHMETIC OPERATIONS**

### **1) Using `let` command**

```bash
let a++
let a=5*10
```

**Example:**

```bash
a=10
b=5
let sum=a+b
let diff=a-b

echo "Sum: $sum"
echo "Difference: $diff"
```

---

### **2) Using Double Brackets**

Inline:

```bash
echo "Sum: $((a+b))"
```

Or assigning:

```bash
a=10
b=5

(( sum = a + b ))
(( diff = a - b ))

echo "Sum: $sum"
echo "Difference: $diff"
```

---

## **➡️ CONDITIONAL STATEMENTS**

### **1) Basic If-Else**

*(Remember: spaces around `[` and `]` and around operators)*

```bash
if [ $marks -gt 40 ]
then
    echo "You are PASS"
else
    echo "You are FAIL"
fi
```

---

### **2) Comparison Operator Chart**

| Operator     | Meaning                  |
| ------------ | ------------------------ |
| `-eq` / `==` | Equal                    |
| `-ge`        | Greater than or equal to |
| `-le`        | Less than or equal to    |
| `-ne` / `!=` | Not equal                |
| `-gt`        | Greater than             |
| `-lt`        | Less than                |

---

### **3) Multiple Conditions (if-elif-else)**

```bash
if [ $marks -ge 80 ]
then
    echo "First Division"
elif [ $marks -ge 60 ]
then
    echo "Second Division"
else
    echo "Fail"
fi
```

---


