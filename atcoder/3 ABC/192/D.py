x=input()
m=int(input())
if len(x)==1:
    if int(x)<=m:
        print(1)
    else:
        print(0)
    exit(0)

def isOk(key):
    num=int(0)
    base=int(1)
    #print("a",num)
    for i in range(len(x)-1,-1,-1):
        num+=int(x[i])*base
        base*=key
        #print("b",num)
    return num<=m

n=0
for y in x:
    if n<int(y):
        n=int(y)
ok=n
ng=int(1e18)+1
while abs(ok-ng)>1:
    mid=(ok+ng)//2
    #print(mid)
    if isOk(mid):ok=mid
    else:ng=mid
print(int(ok-n))