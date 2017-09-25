
def print_lol(the_list):
    for each in the_list:
        if isinstance(each, list):
            print_lol(each)
        else:
            print(each)

movies = ["The Holy Grail", 1975, "Tarry Jones & Terry Gilliam", 91, \
["Graham Chapman", ["Michael Pain", "John Cleese", "Terry Gilliam", "Eric Idle", "Terry Johne"]]]

print_lol(movies)
