from sys import argv

size = argv[1]
filename = argv[2]

with open(filename, "w") as f:
    for i  in range(1, (int(size) + 1)):
        f.write(f"{i}\n")