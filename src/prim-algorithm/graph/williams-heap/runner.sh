#!/usr/bin/sh

make clean prueba

EXE=Williams-decrease-prueba.out
LIB=williams-heap

(
    echo "Unzipping test cases"
    cd ./${LIB}/test/test_cases
    
    unzip -qq ${LIB}s.zip
    rm ${LIB}s.zip
)


rm -rf ./results/result_files/*.txt

echo "Running cases"

for test in $(seq 10 10 90; seq 100 100 900; seq 1000 1000 100000);
do
    for c in $(seq 1 5);
    do
        echo "Case ${test}-${c}"
        for _ in $(seq 1 1000);
        do
            { time ../bin/Williams-decrease-prueba.out ./williams-heap/test/test_cases/heap_${test}_${c}.txt ; } &>> ./results/result_files/${test}_${c}.txt
        done
    done
done

(
    echo "Zipping test cases"
    
    cd ./${LIB}/test/test_cases
    
    zip -m -qq ${LIB}s.zip ./*.txt
)

(
    
    echo "Analyzing results/result_files"
    
    cd ./results/result_files
    
    python ResultParser.py
    
    zip -m -qq results.zip ./*.txt
)
