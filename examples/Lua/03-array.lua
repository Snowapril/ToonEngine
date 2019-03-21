local arr1 = {}
for i = -2, 2, 1 do
    arr1[i] = i * 10
end

for i = -2, 2, 1 do
    print(arr1[i])
end

local arr2 = { {1, 2, 3}, {2, 3, 4}, {3, 4, 5}}

for i = 1,3,1 do
    for j = 1,3,1 do
        io.write(arr2[i][j], ' ')
    end
    io.write('\n')
end