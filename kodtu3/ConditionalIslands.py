x, y = input().split()
limit=int(x)
island=limit*2
KlistNumber=int(y)

visited=[False]*island

kList = [[0 for i in range(2)] for j in range(KlistNumber)]

for i in range(KlistNumber):
    x, y = input().split()
    kList[i][0]=int(x)
    kList[i][1]=int(y)


def recursive(IndexListK):
    
    prevVisited=False
    if visited[kList[IndexListK][0]-1]:   #visited K 0 # use this one
        prevVisited=True
        if IndexListK==KlistNumber-1:
            return True
        return recursive(IndexListK+1)
        
    elif visited[kList[IndexListK][1]-1]:# visited k 1 # use this one
        prevVisited=True
        if IndexListK==KlistNumber-1:
            return True
        return recursive(IndexListK+1)
    else:# use in order 0 to 1
        for x in range(2):
            if kList[IndexListK][x] - limit>=0:#second half
                if visited[kList[IndexListK][x]-1 - limit]==False:#not visited can be applied
                    visited[kList[IndexListK][x]-1]=True

                    if IndexListK==KlistNumber-1:
                        return True

                    reached=recursive(IndexListK+1)
                    if(reached==True):
                        return True
                    else:
                        visited[kList[IndexListK][x]-1]=False
                        continue

            else:       #first half
                if visited[kList[IndexListK][x] + limit-1]==False:
                    visited[kList[IndexListK][x]-1]=True
                    
                    if IndexListK==KlistNumber-1:
                        return True

                    reached=recursive(IndexListK+1)
                    if(reached==True):
                        return True
                    else:
                        visited[kList[IndexListK][x]-1]=False
                        continue
        return False#both island cant be used

                        



if recursive(0):
    print('T')
else:
    print('F')
