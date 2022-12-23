import random
import sys

cases = range(10, 101, 10)

originalStdOut = sys.stdout

for c in cases:
    auxGraph = [[] for _ in range(c)]
    for i in auxGraph:
        for j in range(c):
            i.append(0x1FFFFF)
    print(len(auxGraph))
    with open('./graph_{}.txt'.format(c), 'w') as f:
        sys.stdout = f  # Change the standard output to the file we created.
        print('{}'.format(c))
        sys.stdout = originalStdOut
        for i in range(c):
            print(i)
            minConnection = random.choice(range(c))
            while (minConnection == i):
                minConnection = random.choice(range(c))
            print(minConnection)
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
