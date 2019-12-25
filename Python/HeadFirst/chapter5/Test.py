# -*- coding: utf-8 -*-
# 
import traceback

'''
try:

	with open('jasmes.txt') as jaf :
		data = jaf.readline()
		james = data.strip().split(',')

	with open('julie.txt') as juf :
		data = juf.readline()
		julie = data.strip().split(',')

	with open('mikey.txt') as mif :
		data = mif.readline()
		mikey = data.strip().split(',')

	with open('sarah.txt') as sha:
		data = sha.readline()
		shara = data.strip().split(',')
except IOError as ioerror:
	print("IO Error : " + str(ioerror))
	traceback.print_stack()
	traceback.print_exc()
	exit(1)
except:
	traceback.print_stack()
	traceback.print_exc()
	exit(1)

'''
filename = ['james.txt', 'julie.txt', 'mikey.txt', 'sarah.txt']

def get_coach_data(filename):
	try:
		with open(filename) as fd:
			data = fd.readline()
		#return data.strip().split(',')
	except IOError as ie:
		print('file error' + str(ie))
		traceback.print_stack()
		traceback.print_exc()
		return None

	return data.strip().split(',')

james = get_coach_data('james.txt') 
julie = get_coach_data('julie.txt')
mikey = get_coach_data('mikey.txt')
shara = get_coach_data('sarah.txt')
#print(james)
#print(julie)
#print(mikey)
#print(shara)

def santize(time_string):

	if '-' in time_string:
		splitter = '-'
	elif ':' in time_string:
		splitter = ':'
	else:
		return(time_string)

	(min, secs) = time_string.split(splitter)

	return (min + '.' + secs)

clean_james = []
clean_julie = []
clean_mikey = []
clean_shara = []

print(sorted(set([santize(t) for t in james]))[0:3])
print(sorted(set([santize(t) for t in mikey]))[0:3])
print(sorted(set([santize(t) for t in julie]))[0:3])
print(sorted(set([santize(t) for t in shara]))[0:3])
'''
for each_items in james:
	#imsi = santize(each_items)
	#print(imsi, end='\n')
	clean_james.append(santize(each_items))
 
for each_items in julie:
 	clean_julie.append(santize(each_items))
for each_items in mikey:
 	clean_mikey.append(santize(each_items))
'''
'''
for each_items in shara:
	clean_shara.append(santize(each_items))
'''
#clean_mikey = [santize(each_items) for each_items in mikey]
#clean_shara = [santize(each_items) for each_items in shara]
clean_james = [santize(each_items) for each_items in james]
#clean_julie = [santize(each_items) for each_items in julie]

unique_mikey = []
unique_shara = []
unique_james = []
unique_julie = []
'''
for each_t in shara:
	if each_t not in unique_shara:
		unique_shara.append(each_t)

for each_t in mikey:
	if each_t not in unique_mikey:
		unique_mikey.append(each_t)

for each_t in james:
	if each_t not in unique_james:
		unique_james.append(each_t)

for each_t in julie:
	if each_t not in unique_julie:
		unique_julie.append(each_t)



print(unique_shara[0:3])
print(unique_julie[0:3])
print(unique_james[0:3])
print(unique_mikey[0:3])
'''
'''
print(sorted(clean_james))
print(sorted(clean_julie))
print(sorted(clean_mikey))
print(sorted(clean_shara, reverse=True))
'''