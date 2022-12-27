import random
import sys

cases1 = list(range(10, 91, 10))
cases2 = cases1 + list(range(100, 901, 100))
cases3 = cases2 + list(range(1000, 9001, 1000))

originalStdOut = sys.stdout

for c in cases3:
    for t in range(1, 6):
        auxGraph = [[] for _ in range(c)]
        for i in auxGraph:
            for j in range(c):
                i.append(0x1FFFFF)
        print(len(auxGraph))
        with open('./test_cases/graph_{c}_{t}.txt'.format(c=c, t=t), 'w') as f:
            # Change the standard output to the file we created.
            sys.stdout = f
            print('{}'.format(c))
            for i in range(c):
                minConnection = random.choice(range(c))
                while (minConnection == i):
                    minConnection = random.choice(range(c))
                weight: int = random.choice(range(10, 100))
                auxGraph[i][minConnection] = weight
                auxGraph[minConnection][i] = weight
                for j in range(c):
                    if (j == minConnection):
                        continue
                    if (0.2 < random.random()):
                        weight: int = random.choice(range(10, 100))
                    else:
                        weight: int = 0x7FFFFFFF
                    print(auxGraph[i][j], sep=" ", end=" ")

            sys.stdout = originalStdOut
