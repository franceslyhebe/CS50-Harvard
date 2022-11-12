from cs50 import get_int

# Condicao para garantir que o usuario digite entre 1 e 8
while True:
    n = get_int("Height: ")
    if n >= 1 and n <= 8:
        break

# Loop para adicionar a altura
for i in range(n):
    # Loop para adicionar a # e tbm o espaço
    for j in range(n):
        if i + j >= n - 1:
            print("#", end="")
        else:
            print(" ", end="")
    print()