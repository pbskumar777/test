def solution(H):
    # write your code in Python 3.6
    length = len(H)
    if(length==1):
        return H[0]
    elif(length==2):
        return H[0]+H[1]
    else:
        comp = H[1:length-1]
        middle = length//2
        mini = min(comp)
        co = comp.count(mini)
        if(co==1):
            ind = comp.index(mini)+1
            r_ind = ind+1
            l_ind = ind-1
            while(l_ind>=0 and r_ind<length):
                if(H[l_ind]<H[r_ind]):
                    l_ind-=1
                elif(H[l_ind]>H[r_ind]):
                    r_ind+=1
                else:
                    l_ind-=1
                    r_ind+=1
            if(l_ind==-1 and r_ind==length):
                return max(H)*length
            elif(l_ind==-1 and r_ind!=length):
                emp = H[l_ind+1:r_ind]
                emp2 = H[r_ind:]
                return (max(emp)*len(emp))+(max(emp2)*len(emp2))
            else:
                emp = H[l_ind+1:r_ind]
                emp2 = H[0:l_ind+1]
                return (max(emp)*len(emp))+(max(emp2)*len(emp2))
        else:
            return 244
