local util = {}

function iterator(collection)
    local index = 0
    local count = #collection

    return function()
        index = index + 1
        if index <= count then
            return collection[index]
        end
    end
end

function util.dumpTable(collection)
    for element in iterator(collection) do
        io.write(element, ' ')
    end
    print()
end

return util