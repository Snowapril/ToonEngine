function getNumber()
    local function getNumberHelper()
        co = coroutine.create(function()
        coroutine.yield(1)
        coroutine.yield(3)
        coroutine.yield(5)
        coroutine.yield(7)
        coroutine.yield(9)
        end)
        return co
    end

    if (numberHelper) then
        status, number = coroutine.resume(numberHelper)

        if coroutine.status(numberHelper) == "dead" then
            numberHelper = getNumberHelper()
            status, number = coroutine.resume(numberHelper)
        end
        return number
    else
        numberHelper = getNumberHelper()
        status, number = coroutine.resume(numberHelper)
        return number
    end
end

for i = 1, 10, 1 do
    print(i, getNumber())
end
