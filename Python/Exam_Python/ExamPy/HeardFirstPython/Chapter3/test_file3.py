

man = []
other = []

try:
	fData = open("sketch.txt")

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
finally:
	fData.close()

print(man)
print(other)

try:
	man_file = open("man_file.txt", "w")
	other_file = open("other_file.txt", "w")

	print(man,file = man_file)
	print(other, file = other_file)
except IOError:
	print("file missing")

finally:
	man_file.close()
	other_file.close()

