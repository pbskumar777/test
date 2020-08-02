stri = "897-2*+"
l = []
for i in range(len(stri)):
    if(stri[i] not in ["+","-","/","*"]):
        l.append(stri[i])
    else:
        val1 = l[len(l)-1]
        l = l[:len(l)-1]
        val2 = l[len(l)-1]
        l = l[:len(l)-1]
        res = 0
        if(stri[i]=="+"):
            res = int(val1)+int(val2)
        elif(stri[i]=="-"):
            res = int(val1)-int(val2)
        elif(stri[i]=="*"):
            res = int(val2)*int(val1)
        else:
            res = int(val1)//int(val2)
        l.append(str(res))
print(l[0])