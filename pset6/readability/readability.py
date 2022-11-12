from cs50 import get_string

# Capturar texto
text = get_string("Digite o seu texto: ")

letras = 0
palavras = 1
frases = 0

# Loop para verificar cada caractere do texto
for i in text:
    if i.isalpha():
        letras += 1
    elif i == " ":
        palavras += 1
    elif i == "." or i == "!" or i == "?":
        frases += 1

L = (letras / palavras) * 100
S = (frases / palavras) * 100

# Calculo de Colleman
index = round(0.0588 * L - 0.296 * S - 15.8)

# Resultado
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
