tNum=int(input())
mx=[]
for i in range(tNum):
    fst=list(input().split())
    scd=list(input().split())
    maxCount=0
    for f in range(len(fst)):
        ff=f
        curCount=0
        for s in range(len(scd)):
            if(ff<len(fst)):
                if fst[ff]==scd[s]:
                    curCount+=1
                    ff+=1

                else:
                    if(maxCount<curCount):
                        maxCount=curCount
                    curCount=0
                    ff=f
            else:
                if(maxCount<curCount):
                    maxCount=curCount
                curCount=0
                ff=f
        if(maxCount<curCount):
            maxCount=curCount

    mx.append(maxCount)
for x in mx:
    print(x)