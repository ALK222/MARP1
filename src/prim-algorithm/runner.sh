#!/usr/bin/sh

make clean prueba

echo "Unzipping test cases"
cd graph/test/test_cases

unzip -qq graphs.zip
rm graphs.zip
cd ../../..

rm -rf ./results/result_files/*.txt

echo "Running cases"

for test in {10..90..10};
do
    for c in {1..5}
    do
        echo "Case ${test}-${c}"
        for times in {0..1000};
        do 
            { time ./bin/Prim-algo-prueba.out ./graph/test/test_cases/graph_${test}_${c}.txt ; } &>> ./results/result_files/${test}_${c}.txt
        done 
    done
done

for test in {100..1000..100};
do
    for c in {1..5}
    do
        echo "Case ${test}-${c}"
        for times in {0..1000};
        do 
            { time ./bin/Prim-algo-prueba.out ./graph/test/test_cases/graph_${test}_${c}.txt ; } &>> ./results/result_files/${test}_${c}.txt
        done 
    done
done

for test in {1000..9000..1000};
do
    for c in {1..5}
    do
        echo "Case ${test}-${c}"
        for times in {0..50};
        do 
            { time ./bin/Prim-algo-prueba.out ./graph/test/test_cases/graph_${test}_${c}.txt ; } &>> ./results/result_files/${test}_${c}.txt
        done 
    done
done

echo "Zipping test cases"

zip -m -qq ./graph/test/test_cases/graphs.zip ./graph/test/test_cases/*.txt

echo "Analyzing results/result_files"

cd results

python ./resultsParser.py

zip -m -qq result_files/results.zip *.txt

cd ..
