de_sum = input()

array_input = de_sum.split('+')
array_input.sort()

def addplus(array):
	i = 0
	final_array = []
	while i < len(array)-1:
		final_array.append(array[i])
		final_array.append('+')
		i+=1
	final_array.append(array[i])
	return final_array

lol = addplus(array_input)

for each in lol:
	print(each, end='')