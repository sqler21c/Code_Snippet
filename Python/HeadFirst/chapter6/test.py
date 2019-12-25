import traceback

class Athlete:
	def __init__(self, aName, aDob = None, aTimes = []):
		self.name = aName
		self.dob = aDob
		self.times = aTimes

	def top3(self):
		return (sorted(set([santize(t) for t in self.times]))[0:3])

	def add_Time(self, a_time):
		self.times.append(a_time)

	def add_times(self, a_times):
		self.times.extend(a_times)

def get_coach_data(filename):
	try:
		with open(filename) as f :
			data = f.readline()
		
		templ = data.strip().split(',')
		return(Athlete(templ.pop(0), templ.pop(0), templ))
	except IOError as ioerror :
		print('File error : ' + str(ioerror))
		traceback.print_stack()
		return(None)


class AthleteList(list):
	def __init__(self, a_name, a_dob=None, a_times=[]):
		list.__init__([])
		self.name = a_name
		self.dob = a_dob
		self.extend = a_times
	def top3(self):
		return(sotred(set([santize(t) for t in self]))[0:3])

def santize(time_string):
	if '-' in time_string:
		splitter = '-'
	elif ':' in time_string:
		splitter = ':'
	else:
		return(time_string)

	(min, secs) = time_string.split(splitter)

	return (min + '.' + secs)


james = get_coach_data('./james2.txt')
mikey = get_coach_data('./mikey2.txt')
julie = get_coach_data('./julie2.txt')
sarah = get_coach_data('./sarah2.txt')

print(james.name + "'s fastest times are : " + str(james.top3()))
print(mikey.name + "'s fastest times are : " + str(james.top3()))
print(julie.name + "'s fastest times are : " + str(james.top3()))
print(sarah.name + "'s fastest times are : " + str(james.top3()))


vera = AthleteList('vera vi')
vera.append('2.32')
vera.extend(['2.34', '3.4'])
print("vera vi " + 'is a' + vera.top3())