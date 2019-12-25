i = 5
print(i)
i = i +1
print(i)
s =''' This is a multi-line string.
this is second line. '''

print(s)


def total(init=5, *numbers, **keywords):
    """ This is DocString
        secod line
        third line.
    """
    count = init
    for number in numbers:
        count += number

    for key in keywords:
        count += keywords[key]

    return count

print(total(10, 1, 2, 3, bgetables=50, frutes=100))


print(total.__doc__)
