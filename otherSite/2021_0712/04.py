n,x=(int(x) for x in input().split())
saishou=0
saidai=0
for i in range(n):
    a,b,c,d=(int(x) for x in input().split())
    kyori=x
    kyori-=a
    nedan=b
    if kyori>=0:
        kaisu=kyori//c
        kaisu+=1
        nedan+=kaisu*d
    if i==0 or saishou>nedan:
        saishou=nedan
    if i==0 or saidai<nedan:
        saidai=nedan
print(saishou,saidai)
