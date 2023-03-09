n = int(input())
data = []
for i in range(n):
    line = input()
    sp = line.split("\t")
    data.append(sp)

ok = []

school = {}
for i in range(n):
    school[data[i][3]] = 0

for x in school.keys():
    print(x)

for i in range(n):
    if len(ok) < 10:
        ok.append(i)
        school[data[i][3]] += 1
        print(len(ok),i+1,data[i][2],data[i][3],school[data[i][3]])

    elif len(ok) < 20 and school[data[i][3]] < 3:
        ok.append(i)
        school[data[i][3]] += 1
        print(len(ok),i+1,data[i][2],data[i][3],school[data[i][3]])
        
    elif len(ok) < 30 and school[data[i][3]] < 2:
        ok.append(i)
        school[data[i][3]] += 1
        print(len(ok),i+1,data[i][2],data[i][3],school[data[i][3]])
        
    elif len(ok) < 39 and school[data[i][3]] < 1:
        ok.append(i)
        school[data[i][3]] += 1
        print(len(ok),i+1,data[i][2],data[i][3],school[data[i][3]])