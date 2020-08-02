n = "   Interviews     are   hard to              do"
def func(n):
    sp=0
    st=""
    l1=[]
    l2=[]
    for i in n:
        if(i==" " and sp==0):
            sp+=1
            l1.append(st)
            st=""
        elif(i==" " and sp!=0):
            sp+=1  
        else:
            st+=i
            if(sp>0):
                l2.append(sp)
                sp=0
    l1.append(st)
    main=""
    for i in range(len(l1)-1,-1,-1):
        if(len(l2)!=0):
            k = l2.pop()
            s = l1.pop()
            main+=(s+(" "*k))
        else:
            s = l1.pop()
            main+=s
    print(main)
func(n)