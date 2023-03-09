n,m=(int(x) for x in input().split())
for i in range(n):
    a,b=(int(x) for x in input().split())
    a-=b*5
    if a<0:
        a=0
    if a>=m:
        print(i+1)
