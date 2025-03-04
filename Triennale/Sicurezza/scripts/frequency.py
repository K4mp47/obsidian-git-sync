input_string = "This is a test in which we count the frequency of letters. Guess what? Blank space is the most frequent!"

input_string = sorted(input_string)

freq = []
checked = []

for char in input_string:
    if char not in checked:
        count = input_string.count(char)
        # append tuple to freq
        freq.append((char, count))
        checked.append(char)

#sort freq using the keys
freq.sort(key=lambda x: x[1], reverse=True)
print(freq)
