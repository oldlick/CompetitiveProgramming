p=998244353
for i in range(1,int(1000),int(10)):
    for j in range(1,int(1000),int(100)):
        for k in range(1,int(1000),int(100)):
            """
            if pow(j,k)>=100000000000000000:
                print("SKIP")
                continue
            """
            if pow(i,pow(j,k,p-1),p)!=pow(i,pow(j,k),p):
                print("NG")
                exit(0)
            else:
                print(i,j,k)