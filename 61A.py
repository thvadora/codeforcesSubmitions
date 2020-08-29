n1_input = input()
n2_input = input()
	
n1 = list(n1_input)
n2 = list(n2_input)

final_array = []
i = 0
while i < len(n1):
	if int(n1[i]) != int(n2[i]):
		final_array.append(1)
	else:
		final_array.append(0)
	i+=1
j = 0

for each in final_array:
	print(each, end="")