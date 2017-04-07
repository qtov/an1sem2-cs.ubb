def test():
	num_nodes = 6
	matrix_a = [[0 for y in range(num_nodes)] for x in range(num_nodes)]
	nodes = [float('inf') for i in range(num_nodes)]
	nodes[0] = 0
	matrix_a[0][1] = 10
	matrix_a[0][5] = 8
	matrix_a[1][3] = 2
	matrix_a[2][1] = 1
	matrix_a[3][2] = -2
	matrix_a[4][1] = -4
	matrix_a[4][3] = -1
	matrix_a[5][4] = 1
	
	print(nodes)

	for i in range(num_nodes):
		for j in range(num_nodes):
			if (num_nodes != float('inf')):
				su = nodes[i] + matrix_a[i][j]
				print(str(nodes[i]) + " and " + str(su))
				if (nodes[i] + matrix_a[i][j] < nodes[j] and matrix_a[i][j] != 0):
					nodes[j] = nodes[i] + matrix_a[i][j]
					print(nodes)
		
	print(nodes)

test()

