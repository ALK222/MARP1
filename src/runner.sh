#!/usr/bin/env bash

# (
#     cd ./decrease-key

#     (
#         cd ./williams-heap/test
#         echo "Generando monticulos nuevos"
#         mkdir test_cases
#         python3 ./HeapGenerator.py
#     )
#     echo "Probando casos"
#     ./runner.sh
# )

(
    cd ./prim-algorithm
    
    (
        cd ./graph/test
        echo "Generando grafos nuevos"
        mkdir test_cases
        python3 ./RandomGraphGenerator.py
    )
    echo "Probando casos"
    ./runner.sh
)
