print("Hello world")

io.write("Hello world, from ", _VERSION, "!\n")
--[[ this is comment in lua. wtf;; ]]--


apple = 3
oranges = 10

fruid = apple + oranges
print(fruid)

apple = nil

print(apple)

a = "Hello "
b = "World"
print(a..b)

print("Length of ", b, " is ", #b)

a = 10
while (a > 0)
do
    print("a is ", a)
    a = a - 1
end

for i=10,1,-1
do
    print(i)
end

local i = 10

repeat
    print(i)
    i = i + 1
    break
until(i > 15)

local var = 10
if (var < 15)
then
    print("Var is less than 15")
else
    print("Var is larger than or equal to 15")
end

function max(arg1, arg2)
    if (arg1 > arg2) then    
        return arg1
    else
        return arg2
    end
end

print("max(10, 100) = ", max(10, 100))

function add(...) 
    result = 0
    local arg = {...}
    for i,v in ipairs(arg) do
        print(i, v)
        result = result + v
    end
    print("length of args : ", #arg)
    return result
end

print(add(10,2030,4050,20,3401,401,40))