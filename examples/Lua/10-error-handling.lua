--[[ assert ]]--

local function add(a, b)
    assert(type(a) == "number", "a is not a number")
    assert(type(b) == "number", "b is not a number")
    return a + b
end

-- print(add(1)) 

--[[ error ]]--

-- error("dummy error message", 1)

--[[ pcall ]]--

local function foo(a) 
    return a / nil
end

if pcall(foo, a) then
    print("Success")
else
    print("Failure")
end

--[[ xpcall ]]--

local function myError(err)
    print("ERROR:", err)
end

status = xpcall(foo, myError)
print("status : ", status)