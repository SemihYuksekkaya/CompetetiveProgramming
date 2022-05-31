x, y = input().split()
island=int(x)           #I
numberOfEdges=int(y)    #R

degreeLst=[0]*island


for i in range (numberOfEdges):
    x, y = input().split()
    x = int(x)
    y = int(y)
    degreeLst[x] += 1
    degreeLst[y] += 1

oddCount=0
for z in degreeLst:
    if z%2: #odd
        oddCount+=1

if oddCount<=2:
    print("VALID")
else:
    print("INVALID")
