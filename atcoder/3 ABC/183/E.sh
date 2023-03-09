while :
do
    echo 5 5|./Esample > ./Etest.txt
    diff -s <(cat ./Etest.txt|./e) <(cat ./Etest.txt|./Eanswer) > /dev/null 2>&1
    if [ $? -eq 1 ]; then
        break
    fi
done