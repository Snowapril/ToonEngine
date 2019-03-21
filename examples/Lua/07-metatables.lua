mytable = setmetatable({key1 = "value1"}, {
    __index = function(mytable, key)
        if key == "key2" then
            return "metavalue"
        else
            return mytable[key]
        end
    end
})

print("mytable.key1", mytable.key1)
print("mytable.key2", mytable.key2)

mytable.key3 = "new value"
print("mytable.key3", mytable.key3)

testtable = {}
testtable.key1 = "keyvalue"
print("testtable.key1", testtable.key1)

mytable2 = setmetatable({key1 = "value1"}, {
    __newindex = function(mytable, key, value)
        rawset(mytable, key, "\""..value.."\"")
    end
})

mytable2.key1 = "new value"
mytable2.key2 = 123
mytable2.key3 = "new new new value"
print(mytable2.key1, mytable2.key2, mytable2.key3)

util = require("util")

mytable3 = setmetatable({1, 3, 5, 10}, {
    __tostring = function(mytable)
        local concat = ""
        for key, value in ipairs(mytable) do
            concat = concat..value
        end
        return concat
    end        
})

print(mytable3)