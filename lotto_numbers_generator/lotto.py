from random import randrange

row = []

for i in range(3):
    for j in range (6):
        x = randrange(50)
        if x not in row or x == 0:
            row.append(x)
        else:
            j=j-1
    print(row)
    row =[]
