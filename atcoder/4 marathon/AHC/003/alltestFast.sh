filename="alltestFast_${1}"

g++ $1.cpp -Wall -Wextra -O2 -std=gnu++17 -D RESULT_ONLY -o ${filename}.out || exit 1

function calc(){
    ./$1.out $3 <$2 2>&1 > /dev/null
}

export -f calc
result=`seq -f "./input/input%02g" 00 99 | xargs -I{} -P100 bash -c "calc ${filename} {} $2"`

sum=0
for i in $result;do
    sum=$(( sum + i ))
done
echo $sum

