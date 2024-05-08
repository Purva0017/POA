def conversion(a):
    q = a
    temp = count - len(a) + 1
    if (len(a) < (count+1)):
        q = "0"*temp + a
    return q

def twoc(a):
    a = list(a)
    for i in range(len(a)):
        if a[i] == "1":
            a[i] = "0"
        else:
            a[i] = "1"

    a = "".join(a)
    return bin(int(a,2) + 1).replace("0b", "")

def leftShift(ac, q):
    a = ""
    b = ""
    for i in range(1,len(ac)):
        a += ac[i]
    a += q[0]
    for i in range(1,len(q)):
        b += q[i]
    b += "_"
    return a,b

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

x = int(input("Enter Q(dividend): "))
y = int(input("Enter M(divisor): "))

Q = bin(x).replace("0b","")
M = bin(y).replace("0b","")

count = len(Q)
M = conversion(M)

M2 = twoc(M)
AC = conversion("0")

print("AC\tQ\tOperation Done")
print(f"{AC}\t{Q}\tInitial State")

while(count > 0):
    
    print(f"n = {count}:")
    AC, Q = leftShift(AC,Q)
    print(f"{AC}\t{Q}\tLeft Shift")
    
    AC = add(AC,M2)
    print(f"{AC}\t{Q}\tA=A-M")

    if(AC[0] == "1"):
        Q = Q.replace("_", "0")
        AC = add(AC,M)
        print(f"{AC}\t{Q}\tRestored and updated Q")
    else:
        Q = Q.replace("_", "1")
        print(f"{AC}\t{Q}\tQ updated")

    count -= 1

print(f"Quotient: {int(Q,2)}")
print(f"Remainder: {int(AC,2)}")