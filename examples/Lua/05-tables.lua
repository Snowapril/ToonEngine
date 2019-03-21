function dumpTable(collection)
    local index = 0
    local count = #collection
    return function()
        index = index + 1
        if index <= count then
            return collection[index]
        end
    end
end

mytable = {}
mytable[1] = "string"

for element in dumpTable(mytable) do
    print(element)
end

mytable = nil --[[ remove reference ]]--
--[[ table에 대한 reference가 없으면 lua 의 garbage collector가 이를 수집해준다 ]]--

mytable = {}
mytable['apple'] = 100

newtable = mytable

newtable['apple'] = -500

print(mytable['apple'])

newtable = nil

print(mytable['apple'])

mytable = nil

arr = {10, 2, 5, 4, -1, 10}

print("table.concat({1,2,3,4,5}) : ", table.concat(arr))
print(table.maxn(arr))

for element in dumpTable(arr) do
    io.write(element, ' ')
end
print()

table.sort(arr)

for element in dumpTable(arr) do
    io.write(element, ' ')
end
print()