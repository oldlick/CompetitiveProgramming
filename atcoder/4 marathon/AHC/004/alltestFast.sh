filename="alltestFast_${1}"

g++ $1.cpp -Wall -Wextra -O2 -std=gnu++17 -o ${filename}.out || exit 1

function calc(){
    ./$1.out <$2 2>&1 > /dev/null
}

export -f calc
result=`seq -f "./in/00%02g.txt" 00 99 | xargs -I{} -P100 bash -c "calc ${filename} {}"`


sum=0
echo -n "" > ${filename}.txt
for i in $result;do
    echo $i >> ${filename}.txt
    sum=$(( sum + i ))
done
echo $sum >> ${filename}.txt