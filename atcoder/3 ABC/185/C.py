l=int(input())
l-=1
ans=1
for i in range(l-11+1,l+1):
    ans*=i
for  i in range(1,11+1):
    ans//=i
print(ans)