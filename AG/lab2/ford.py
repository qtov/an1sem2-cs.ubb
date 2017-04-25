def solve(matrix_a, root):
	"""
	Input = adiacence matrix, root(from where to calculate the minimum distance, integer >= 0)
	Output = array of minimum roads or ValueError exception if there is a negative cycle
	~ Behaviour unknown if input is different ~

	"""
	num_nodes = len(matrix_a)
	nodes = [float('inf') for i in range(num_nodes)]
	nodes[root] = 0

	for repeat_times in range(num_nodes):
	# repeat n-1 times and the nth time to detect negative cycles
		changed = False
		for prev in range(num_nodes):
			if (nodes[prev] != float('inf')):
			# if the node from which we have to calculate is infinite, there is no road to it yet so it can be skipped
				for node in range(num_nodes):
					if (matrix_a[prev][node] != 0):
					# if there is a road between prev and the current node
						if (nodes[prev] + matrix_a[prev][node] < nodes[node]):
							# shortest road is the min between existing distance and the distance of the previous node + the road between the previous node(prev) and the current node(node)
							nodes[node] = nodes[prev] + matrix_a[prev][node]
							changed = True
		if (not changed):
			return (nodes)

	if (changed):
		raise ValueError("Input matrix contains negative cycles.")

	return (nodes)

def test():
	num_nodes = 6
	matrix_a = [[0 for y in range(num_nodes)] for x in range(num_nodes)]
	
	matrix_a[0][1] = 10
	matrix_a[0][5] = 8
	matrix_a[1][3] = 2
	matrix_a[2][1] = 1
	matrix_a[3][2] = -2
	matrix_a[4][1] = -4
	matrix_a[4][3] = -1
	matrix_a[5][4] = 1

	assert solve(matrix_a, 0) == [0, 5, 5, 7, 9, 8]
	assert solve(matrix_a, 1) == [float('inf'), 0, 0, 2, float('inf'), float('inf')]
	assert solve(matrix_a, 2) == [float('inf'), 1, 0, 3, float('inf'), float('inf')]
	assert solve(matrix_a, 3) == [float('inf'), -1, -2, 0, float('inf'), float('inf')]
	assert solve(matrix_a, 4) == [float('inf'), -4, -4, -2, 0, float('inf')]
	assert solve(matrix_a, 5) == [float('inf'), -3, -3, -1, 1, 0]

	num_nodes = 6
	matrix_a = [[0 for y in range(num_nodes)] for x in range(num_nodes)]

	# http://www.allsyllabus.com/aj/note/Computer_Science/Computer%20Networks%20-%20II/Unit1/Bellman-Ford%20Algorithm%20or%20Ford-Fulkerson%20algorithm2.PNG
	# Matrix used

	matrix_a[0][2] = 2
	matrix_a[3][2] = 2
	matrix_a[1][3] = 1
	matrix_a[2][5] = 1
	matrix_a[4][5] = 2

	assert solve(matrix_a, 0) == [0, float('inf'), 2, float('inf'), float('inf'), 3]
	assert solve(matrix_a, 1) == [float('inf'), 0, 3, 1, float('inf'), 4]
	assert solve(matrix_a, 2) == [float('inf'), float('inf'), 0, float('inf'), float('inf'), 1]
	assert solve(matrix_a, 3) == [float('inf'), float('inf'), 2, 0, float('inf'), 3]
	assert solve(matrix_a, 4) == [float('inf'), float('inf'), float('inf'), float('inf'), 0, 2]
	assert solve(matrix_a, 5) == [float('inf'), float('inf'), float('inf'), float('inf'), float('inf'), 0]

	num_nodes = 6
	matrix_a = [[0 for y in range(num_nodes)] for x in range(num_nodes)]

	# http://d2vlcm61l7u1fs.cloudfront.net/media%2F7f4%2F7f416e85-7294-4a18-85fc-4de484c5b575%2FphpdB5r9L.png
	# Matrix used

	matrix_a[2][0] = 1
	matrix_a[2][1] = 2
	matrix_a[4][1] = 4
	matrix_a[0][4] = -1
	matrix_a[3][4] = -8
	matrix_a[1][3] = 5
	matrix_a[1][5] = 6
	matrix_a[5][0] = -4
	matrix_a[3][0] = 3

	assert solve(matrix_a, 0) == [0, 3, float('inf'), 8, -1, 9]
	assert solve(matrix_a, 1) == [2, 0, float('inf'), 5, -3, 6]
	assert solve(matrix_a, 2) == [1, 2, 0, 7, -1, 8]
	assert solve(matrix_a, 3) == [-2, -4, float('inf'), 0, -8, 2]
	assert solve(matrix_a, 4) == [6, 4, float('inf'), 9, 0, 10]
	assert solve(matrix_a, 5) == [-4, -1, float('inf'), 4, -5, 0]


test()