places_input = input()
distances_input = input()

array_dist = distances_input.split()

array_dist_int = []

for each in array_dist:
	array_dist_int.append(int(each))


shorter_dist = min(array_dist_int)

def equal(array,x):
	t = 0
	for each in array:
		if(each == x):
			t+=1
			
	if(t>=2):
		return True
	else:
		return False

if equal(array_dist_int,shorter_dist) :
	print('Still Rozdil')
else:
	print(array_dist_int.index(shorter_dist)+1)