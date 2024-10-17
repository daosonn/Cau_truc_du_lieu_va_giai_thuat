n = int(input("Nhập số lượng: "))
a = []

for i in range(n):
    a.append(input().strip().lower()) 

red, white, blue = 0, 0, 0

for color in a:
    if color == "red":
        red += 1
    elif color == "white":
        white += 1
    elif color == "blue":
        blue += 1

sorted_list = ["red"] * red + ["white"] * white + ["blue"] * blue
print("{", ", ".join(sorted_list), "}")
