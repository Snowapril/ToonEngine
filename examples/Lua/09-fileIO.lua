file = io.open("util.lua", "r")
io.input(file)
print(io.read("*all"))
print(io.type(file))
io.close(file)
print(io.type(file))
file = nil

for line in io.lines("02-string.lua") do
    print(line)
end