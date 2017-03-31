a, b=input().split()
flag=0
for i in a:
    if i==".":
        flag=1
import sys
if flag==0 :
    print(pow(int(a), int(b)))
    sys.exit()
a1, a2=a.split(".")
length=len(a2)
a1=a1+a2
a1=int(a1)
b=int(b)
length=length*b
a1=pow(a1, b)
a3=str(a1)
if len(a3) <= length : 
    for i in range(0, length-len(a3)+1):
        a3="0"+a3
for i in range(0, len(a3)):
    if i<len(a3)-length :
        sys.stdout.write("%c"%(a3[i]))
    elif i==len(a3)-length :
        sys.stdout.write(".")
        sys.stdout.write("%c"%(a3[i]))
    else :
        sys.stdout.write("%c"%(a3[i]))
print()

