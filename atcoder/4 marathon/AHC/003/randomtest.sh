filename="randomtest_${1}"

g++ $1.cpp -Wall -Wextra -O2 -std=gnu++17 -D RESULT_ONLY -o ${filename}.out || exit 1

echo -n '' > ${filename}
sum=0
cnt=0
while [[ 1==1 ]];do
    result=`./randomInput/a.out | ./${filename}.out 2>&1 > /dev/null`
    sum=$(( sum + result ))
    cnt=$(( cnt + 1 ))
    echo "$result :$((sum/cnt))" >> ${filename}
done
