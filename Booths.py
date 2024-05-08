def conversion(a):
    q = ""
    current_n = len(a)
    temp = count - current_n
    if(current_n < count):
        q = "0"*temp + a
    return q

def add(a,b):
    max_len = max(len(a), len(b))
    result = ""
    carry = 0
    for i in range(max_len-1, -1, -1):
        r = carry
        if (a[i] == "1"):
            r += 1
        if (b[i] == "1"):
            r += 1
        if r % 2 == 1:
            result = "1" + result
        else:
            result = "0" + result
        if r < 2:
            carry = 0
        else:
            carry = 1

    return result

def twoc(a):
    a = list(a)
    for i in range(len(a)):
        if a[i] == "1":
            a[i] = "0"
        else:
            a[i] = "1"

    b = "0"*(len(a)-1) + "1"
    return (add("".join(a), b))

def rightShift(ac, q, q1):
    a = ac[0]
    for i in range(1,len(ac)):
        a += ac[i-1]
    b = ac[-1]
    for i in range(1, len(q)):
        b += q[i-1]
    c = q[-1]
    return (a,b,c)

x = int(input("Enter Multiplicand "))
y = int(input("Enter Multiplier "))

a = bin(x).replace("0b", "")
b = bin(y).replace("0b", "")

if (a[0] == "-"):
    a = a.replace("-", "")
    negative_a = 1
else:
    negative_a = 0
if (b[0] == "-"):
    b = b.replace("-", "")
    negative_b = 1
else:
    negative_b = 0

count = max(len(a), len(b)) + 1
count1 = count

firstP = conversion(a)
secondP = conversion(b)
firstN = twoc(firstP)
secondN = twoc(secondP)

if negative_a == 0:
    M = firstP
    M2 = firstN
else:
    M = firstN
    M2 = firstP

if negative_b == 0:
    Q = secondP
else:
    Q = secondN

AC = conversion("0")
Q1 = "0"

print("count\tAC\tQ\tQ1\tOperation")
print(f"{count}\t{AC}\t{Q}\t{Q1}\tInitial state")

while count>0:
    compare = Q[-1] + Q1
    if compare[0]==compare[-1]:
        AC, Q, Q1 = rightShift(AC, Q, Q1)
        Op = "Right Shift"
    
    elif compare == "01":
        AC = add(AC, M)
        AC, Q, Q1 = rightShift(AC, Q, Q1)
        Op = "AC=AC+M and right shift"

    else:
        AC = add(AC, M2)
        AC, Q, Q1 = rightShift(AC, Q, Q1)
        Op = "AC=AC-M and right shift"

    count -= 1
    print(f"{count}\t{AC}\t{Q}\t{Q1}\t{Op}")

answer = AC + Q

if (negative_a == negative_b):
    ans_d = str(int(answer,2))

else:
    ans_d = "-" + str(int(twoc(answer),2))

print(f"Answer in binary : {answer}")
print(f"Answer in decimal : {ans_d}")