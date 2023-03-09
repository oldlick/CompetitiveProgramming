g++ $1.cpp -O
if [[ $? -ne 0 ]];then
    exit
fi
for i in {0000..0099};do
    echo $i
    ./a.out < ./8c847d8177acc2dd417be4327252e39e/in/${i}.txt
done