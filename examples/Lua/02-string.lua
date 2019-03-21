local str = "agsdva apple asdaczxapplevcxzc apple"
str = string.gsub(str, "apple", "oranges")
print(str)

print(string.rep("apple", 10))

print("apple".."oranges")

date = 2; month = 1; year = 2014
print(string.format("Date formatting %02d/%02d/%03d", date, month, year))
print(string.format("%.4f", 1/3))