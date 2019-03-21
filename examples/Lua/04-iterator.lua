local arr = {1, 2, 3, 4, 5, 6}


for key, value in ipairs(arr) do
    print("arr[", key, "] : ", value)
end


--[[ this is stateless iterator ]]--
function tri(iteratorMaxCount, currentNumber) 
    if currentNumber < iteratorMaxCount then
        currentNumber = currentNumber + 1
        return currentNumber, currentNumber ^ 3
    end
end

function tries(iteratorMaxCount)
    return tri, iteratorMaxCount, 0
end

for key, value in tries(5) do
    print(key, value)
end

--[[ this is stateful iterator ]]--
function elementIterator(collection) 
    local index = 0
    local count = #collection

    --[[ closure function is retruned ]]--
    return function() 
        index = index + 1
        if index <= count then
            return collection[index]
        end
    end
end

for element in elementIterator(arr) do
    print(element)
end

--[[ collection test function ]]--
function test1(var) 
    return #var --[[ # <- this return length of string or array ]]--
end
