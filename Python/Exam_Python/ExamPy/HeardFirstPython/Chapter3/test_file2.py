import os


dir_chd = os.getcwd()
print(dir_chd)

'''
if os.path.exists('sketch.txt'):
	fData = open("sketch.txt")
else:
	print("No File")
'''
'''
for read_line in fData:
	if not read_line.find(':') == -1 :
		(role, line_spoken) = read_line.split(":", 1)
	print(role, end='')
	print(' said: ', end='')
	print(line_spoken, end='')
'''

try :
	fData = open("sketch.txt")

	for read_line in fData:

		try:
			(role, line_spoken) = read_line.split(":", 1)
			print(role, end='')
			print(' said: ', end='')
			print(line_spoken, end='')
		except ValueError:
			pass

except IOError :
	print("File is missing!!!")
	
fData.close()