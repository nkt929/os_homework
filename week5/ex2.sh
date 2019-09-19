while true; do
    if (( ! ln ex2.txt ex2.txt.lock ))
    then
       sleep 1
    else
        if [ ! -f ex2.txt ]; then echo 0 > ex2.txt; fi
        count=0
        while [[ $count != 1000 ]]; do
            count=`expr $count + 1`
            n=`tail -1 ex2.txt`
            expr $n + 1 >> ex2.txt
        done
        rm ex2.txt.lock
        break
    fi
done