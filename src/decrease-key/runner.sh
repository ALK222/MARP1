#!/usr/bin/sh

make clean prueba

echo "Unzipping test cases"
cd williams-heap/test/test_cases

unzip -qq heaps.zip
rm heaps.zip
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
            { time ./bin/Williams-decrease-prueba.out ./williams-heap/test/test_cases/heap_${test}_${c}.txt ; } &>> ./results/result_files/${test}_${c}.txt
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
            { time ./bin/Williams-decrease-prueba.out ./williams-heap/test/test_cases/heap_${test}_${c}.txt ; } &>> ./results/result_files/${test}_${c}.txt
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
            { time ./bin/Williams-decrease-prueba.out ./williams-heap/test/test_cases/heap_${test}_${c}.txt ; } &>> ./results/result_files/${test}_${c}.txt
        done 
    done
done

echo "Zipping test cases"

zip -m -qq ./williams-heap/test/test_cases/heaps.zip ./williams-heap/test/test_cases/*.txt

echo "Analyzing results"

cd results

python ./resultsParser.py

zip -m -qq ./result-files/results.zip result_files/*.txt

cd ..
