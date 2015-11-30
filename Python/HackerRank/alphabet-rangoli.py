import sys
alphabetArray = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
number = int(raw_input())
centre = 2*(number-1)+1
for i in range(1,2*number): #More than 2 lines will result in 0 score. Do not leave a blank line also
	for j in range (1, 2*(2*number - 1)):
		tempI = i
		if(tempI > number):
			tempI = tempI - 2*(tempI-number)
		if(j >= (centre - 2*(tempI-1)) and (j <= centre + 2*(tempI-1)) and j%2 !=0):
			if(j >= centre):
				sys.stdout.write(alphabetArray[(j-1)/2 - tempI + 1])
			else:
				tempJ = (j + 2*(centre - j))
				sys.stdout.write(alphabetArray[(tempJ-1)/2 - tempI + 1])
		else :
			sys.stdout.write('-')
	print ''

