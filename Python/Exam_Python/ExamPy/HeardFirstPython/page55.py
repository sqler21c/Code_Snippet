import sys

movies = ["The Holy Grail", 1975, "Tarry Jones & Terry Gilliam", 91,
		["Graham Chapman", ["Michael Pain", "John Cleese", "Terry Gilliam", "Eric Idle", "Terry Johne"]]]

'''
print(movies)

for each_item in movies:
	if isinstance(each_item, list):
		for each_items in each_item:
			print(each_items)
	else:
		print(each_item)
'''
'''
def lol(each_item):
	for each_items in each_item:
		if(isinstance(each_items, list)):
			lol(each_items)
		else:
			print(each_items)
'''

def print_lol(each_item, indent=False, level=0, fh = sys.stdout):
	for each_items in each_item:
		if(isinstance(each_items, list)):
			print_lol(each_items, indent, level+1, fh)
		else:
			#print(each_items)
			if indent: 
				for each_tab in range(level):
					print("\t", end='', file=fh)
			
			print(each_items, file = fh)


#print_lol(movies)
