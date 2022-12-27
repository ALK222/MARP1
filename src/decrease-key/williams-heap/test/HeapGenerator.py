import random
import sys

cases1 = list(range(10, 91, 10))
cases2 = cases1 + list(range(100, 901, 100))
cases3 = cases2 + list(range(1000, 9001, 1000))

originalStdOut = sys.stdout

for c in cases3:
    for t in range(1, 6):
        with open('./test_cases/heap_{c}_{t}.txt'.format(c=c, t=t), 'w') as f:
            # Change the standard output to the file we created.
            sys.stdout = f
            print('{}'.format(c))
            for _ in range(c):
                # Adding values to the heap
                print(random.choice(range(1, 501)), sep=" ", end=" ")
            print("", end="\n")

            # Adding key to decrease
            print(random.choice(range(0, c)))

            # Adding value to decrease
            print(random.choice(range(1, 501)))

            sys.stdout = originalStdOut
