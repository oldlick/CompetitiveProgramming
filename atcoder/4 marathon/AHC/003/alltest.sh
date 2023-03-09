filename="alltest_${1}"

g++ $1.cpp -Wall -Wextra -O2 -std=gnu++17 -D RESULT_ONLY -o ${filename}.out || exit 1

echo -n '' > ${filename}
sum=0
for i in {00..99};do
    result=`./${filename}.out ${2} <./input/input${i} 2>&1 > /dev/null`
    echo $result >> ${filename}
    sum=$(( sum + result ))
done
echo -e "\n$((sum/100))" >> ${filename}

