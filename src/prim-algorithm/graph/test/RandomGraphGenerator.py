#!/usr/bin/env python3
import random
import sys

l1 = list(range(10, 91, 10))
l2 = l1 + list(range(100, 901, 100))
l3 = l2 + list(range(1000, 100001, 1000))  # List of test cases

originalStdOut = sys.stdout  # original output saved

for c in l3:
    for t in range(1, 6):
        auxDict = {}
        auxGraph = [[] for _ in range(c)]  # list of edges

        print("Caso {c}_{t}".format(c=c, t=t))
        with open('./test_cases/graph_{c}_{t}.txt'.format(c=c, t=t), 'w') as f:

            print('{}'.format(c))
            for i in range(c):
                # print("Nodo {i}".format(i=i))
                # Change the standard output to the file we created.
                sys.stdout = f
                print("{c}".format(c=c))
                auxDict[i] = []
                # Random node to connect node i
                minConnection = random.choice(range(c))
                while (minConnection == i & (minConnection in auxDict[i]) & i in auxDict[minConnection]):
                    minConnection = random.choice(range(c))

                # Random weight
                weight: int = random.choice(range(10, 100))

                # Mark them as connected
                auxList = auxDict[i]
                auxList.append(minConnection)
                auxDict[i] = auxList

                # Make non directed edge
                auxGraph[i].append((minConnection, weight))
                auxGraph[minConnection].append((i, weight))

                for j in range(c):
                    # Chance to create extra connections
                    if ((minConnection in auxDict[i])):
                        continue
                    if (0.2 < random.random()):
                        weight: int = random.choice(range(10, 100))
                        auxList = auxDict.get(i)
                        auxList.append(minConnection)
                        auxDict.update(i, auxList)
                        auxGraph[i].append((j, weight))
                        auxGraph[j].append((i, weight))

            # Write node to file
            for node in auxGraph:
                print(len(node), sep="", end="\n")
                for connection in node:
                    print(connection[0], connection[1], sep=" ", end=" ")
                print("\n", sep="", end="")

            sys.stdout = originalStdOut
