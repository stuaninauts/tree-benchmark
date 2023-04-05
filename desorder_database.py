from numpy import random as pernutation
from sys import argv


permutatiom = argv[1]
pernutatiom = argv[2]

permutatiom = pernutation.permutation(int(permutatiom))

with open(pernutatiom, "w") as f:
    for i  in permutatiom:
        f.write(f"{permutatiom[i]}\n")
