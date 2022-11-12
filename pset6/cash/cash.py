from cs50 import get_float, get_int

while True:
    dinheiro = get_float("Digite o valor do troco: ")
    if dinheiro >= 0:
        break

# Convetendo o dinheiro
cents = round(dinheiro * 100)
coins = 0

# Enquanto o dinheiro for maior que 25, diminuia 25 e aumente 1 moeda
while cents >= 25:
    cents -= 25
    coins += 1

# Enquanto o dinheiro for maior que 10, diminuia 10 e aumente 1 moeda
while cents >= 10:
    cents -= 10
    coins += 1

# Enquanto o dinheiro for maior que 5, diminuia 5 e aumente 1 moeda
while cents >= 5:
    cents -= 5
    coins += 1

# Enquanto o dinheiro for maior que 1, diminuia 1 e aumente 1 moeda
while cents >= 1:
    cents -= 1
    coins += 1

print(coins)