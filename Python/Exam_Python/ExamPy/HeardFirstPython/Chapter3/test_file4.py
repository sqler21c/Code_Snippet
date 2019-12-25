import sys
import pickle


def print_lol(each_item, indent=False, level=0, fh = sys.stdout):
	for each_items in each_item:
		if(isinstance(each_items, list)):
			print_lol(each_items, indent, level+1, fh)
		else:
			#print(each_items)
			if indent: 
				for each_tab in range(level):
					#print("\t", end='', file=fh)
					pickle.dump(each_tab, fh)
			
			#print(each_items, file = fh)
			pickle.dump(each_items, fh)



man = []
other = []

try:
	with open("sketch.txt") as fData:

		for each_line in fData:
			try:
				(role, line_spoken) = each_line.split(':', maxsplit=1)
				line_spoken = line_spoken.strip()

				if role == 'Man':
					man.append(line_spoken)
				elif role == 'Other Man':
					other.append(line_spoken)
			except ValueError :
				pass
except IOError :
	print("miss file")


print(man)
print(other)

try:
	with open("man_file.txt", "wb") as man_file, open("other_file.txt", "wb") as other_file:
		print_lol(man, fh = man_file)
		print_lol(other, fh = other_file)

		#print(man,file = man_file)
		#print(other, file = other_file)
except IOError as err :
	print("file missing ::: " + str(err) )


try:
	with open("man_file.txt", "rb") as read_man, open("other_file.txt", "rb") as read_other:
		
		a_man = pickle.load(read_man)
		a_other = pickle.load(read_other)
		print(a_man)
		print("==================")
		print(a_other)
except IOError as err:
	print("err is ::" + str(err))

except pickle.PickleError as perr:
	print("pickle err is :: " + str(perr))
'''
with open('mydata', 'wb') as mysavedata:
	pickle.dump([1,2,3], mysavedata)

with open('mydata', 'rb') as myreaddata:
	a_list = pickle.load(myreaddata)

print(a_list)
'''