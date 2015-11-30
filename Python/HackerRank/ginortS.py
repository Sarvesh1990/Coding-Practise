myString = "Sorting1234"
myString =  sorted(myString)

arrayOdd = []
arrayEven = []
lowerCase = []
upperCase = []

for i in myString:
	if(i.isdigit()):
		if(int(i)%2 == 0):
			arrayEven.append(i)
		else :
			arrayOdd.append(i)
	else:
		if(i.istitle()):
			upperCase.append(i)
		else:
			lowerCase.append(i)
myString = lowerCase
myString.extend(upperCase)
mySting.exted(arrayOdd)
myString.extend(arrayEven)

print myString