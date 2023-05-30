#!/usr/bin/env python3
import random
import sys

l1 = list(range(10, 91, 10))
l2 = l1 + list(range(100, 901, 100))
l3 = list(range(1000, 45001, 1000))  # List of test cases

originalStdOut = sys.stdout  # original output saved

for c in l3:
    for t in range(1, 6):
        auxGraph = [[] for _ in range(c)]  # list of edges

        print("Caso {c}_{t}".format(c=c, t=t))
        with open('./test_cases/graph_{c}_{t}.txt'.format(c=c, t=t), 'w') as f:

            sys.stdout = f
            print('{c}'.format(c=c))
            for i in range(c):
                # print("Nodo {i}".format(i=i))
                # Change the standard output to the file we created.

                # print("{c}".format(c=c))
                # Random node to connect node i
                minConnection = random.choice(range(c))
                while (minConnection == i):
                    minConnection = random.choice(range(c))

                # Random weight
                weight: int = random.choice(range(10, 100))

                # Mark them as connected
                auxGraph[i].append((minConnection, weight))

                # minConnection = i + 1

                # if (i == c):
                #     minConnection = 0

                # # Random weight
                # weight: int = random.choice(range(10, 100))

                # # Mark them as connected
                # auxGraph[i].append((minConnection, weight))
                # print(random.choices(list(range(c)), k=int(c*0.1)))

                for j in random.choices(list(range(c)), k=int(c*0.1)):
                    # Chance to create extra connections
                    if (j == i):
                        continue
                    if (0.2 < random.random()):
                        weight: int = random.choice(range(10, 100))
                        auxGraph[i].append((j, weight))

            # Write node to file
            for node in auxGraph:
                print(len(node), sep="", end="\n")
                for connection in node:
                    print(connection[0], connection[1], sep=" ", end=" ")
                print("\n", sep="", end="")

            sys.stdout = originalStdOut
