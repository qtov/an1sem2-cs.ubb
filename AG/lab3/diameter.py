def ford(matrix_a, root):
	"""
	Input = adjacency matrix, root(from where to calculate the minimum distance, integer >= 0)
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

def graph_diameter(matrix_a):
	"""
	Input = adjacency matrix
	Output = integer -> diameter of graph represented by the matrix input
	~ Behaviour unknown if input different ~
	"""
	num_nodes = len(matrix_a)
	matrix_dist = [ford(matrix_a, x) for x in range(num_nodes)]
	# shortest road matrix from each node
	maximum_distance = 0

	for i in range(num_nodes):
		max_of_array = max(matrix_dist[i])
		# maximum of line i
		if (max_of_array > maximum_distance):
			maximum_distance = max_of_array

	return maximum_distance

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

	assert ford(matrix_a, 0) == [0, 5, 5, 7, 9, 8]
	assert ford(matrix_a, 1) == [float('inf'), 0, 0, 2, float('inf'), float('inf')]
	assert ford(matrix_a, 2) == [float('inf'), 1, 0, 3, float('inf'), float('inf')]
	assert ford(matrix_a, 3) == [float('inf'), -1, -2, 0, float('inf'), float('inf')]
	assert ford(matrix_a, 4) == [float('inf'), -4, -4, -2, 0, float('inf')]
	assert ford(matrix_a, 5) == [float('inf'), -3, -3, -1, 1, 0]

	assert graph_diameter(matrix_a) == float('inf')

	num_nodes = 6
	matrix_a = [[0 for y in range(num_nodes)] for x in range(num_nodes)]

	# http://www.allsyllabus.com/aj/note/Computer_Science/Computer%20Networks%20-%20II/Unit1/Bellman-Ford%20Algorithm%20or%20Ford-Fulkerson%20algorithm2.PNG
	# Graph used

	matrix_a[0][2] = 2
	matrix_a[3][2] = 2
	matrix_a[1][3] = 1
	matrix_a[2][5] = 1
	matrix_a[4][5] = 2

	assert ford(matrix_a, 0) == [0, float('inf'), 2, float('inf'), float('inf'), 3]
	assert ford(matrix_a, 1) == [float('inf'), 0, 3, 1, float('inf'), 4]
	assert ford(matrix_a, 2) == [float('inf'), float('inf'), 0, float('inf'), float('inf'), 1]
	assert ford(matrix_a, 3) == [float('inf'), float('inf'), 2, 0, float('inf'), 3]
	assert ford(matrix_a, 4) == [float('inf'), float('inf'), float('inf'), float('inf'), 0, 2]
	assert ford(matrix_a, 5) == [float('inf'), float('inf'), float('inf'), float('inf'), float('inf'), 0]

	assert graph_diameter(matrix_a) == float('inf')

	num_nodes = 6
	matrix_a = [[0 for y in range(num_nodes)] for x in range(num_nodes)]

	# http://d2vlcm61l7u1fs.cloudfront.net/media%2F7f4%2F7f416e85-7294-4a18-85fc-4de484c5b575%2FphpdB5r9L.png
	# Graph used

	matrix_a[2][0] = 1
	matrix_a[2][1] = 2
	matrix_a[4][1] = 4
	matrix_a[0][4] = -1
	matrix_a[3][4] = -8
	matrix_a[1][3] = 5
	matrix_a[1][5] = 6
	matrix_a[5][0] = -4
	matrix_a[3][0] = 3

	assert ford(matrix_a, 0) == [0, 3, float('inf'), 8, -1, 9]
	assert ford(matrix_a, 1) == [2, 0, float('inf'), 5, -3, 6]
	assert ford(matrix_a, 2) == [1, 2, 0, 7, -1, 8]
	assert ford(matrix_a, 3) == [-2, -4, float('inf'), 0, -8, 2]
	assert ford(matrix_a, 4) == [6, 4, float('inf'), 9, 0, 10]
	assert ford(matrix_a, 5) == [-4, -1, float('inf'), 4, -5, 0]

	assert graph_diameter(matrix_a) == float('inf')

	num_nodes = 7
	matrix_a = [[0 for y in range(num_nodes)] for x in range(num_nodes)]

	# https://people.hofstra.edu/geotrans/eng/methods/diameter1.html
	# Graph used

	matrix_a[0][1] = 1
	matrix_a[1][0] = 1
	matrix_a[1][3] = 1
	matrix_a[3][1] = 1
	matrix_a[3][5] = 1
	matrix_a[5][3] = 1
	matrix_a[4][5] = 1
	matrix_a[5][4] = 1
	matrix_a[4][2] = 1
	matrix_a[2][4] = 1
	matrix_a[2][0] = 1
	matrix_a[0][2] = 1
	matrix_a[0][5] = 1
	matrix_a[5][0] = 1
	matrix_a[4][6] = 1
	matrix_a[6][4] = 1

	assert ford(matrix_a, 0) == [0, 1, 1, 2, 2, 1, 3]
	assert ford(matrix_a, 1) == [1, 0, 2, 1, 3, 2, 4]
	assert ford(matrix_a, 2) == [1, 2, 0, 3, 1, 2, 2]
	assert ford(matrix_a, 3) == [2, 1, 3, 0, 2, 1, 3]
	assert ford(matrix_a, 4) == [2, 3, 1, 2, 0, 1, 1]
	assert ford(matrix_a, 5) == [1, 2, 2, 1, 1, 0, 2]
	assert ford(matrix_a, 6) == [3, 4, 2, 3, 1, 2, 0]

	assert graph_diameter(matrix_a) == 4

	num_nodes = 6
	matrix_a = [[0 for y in range(num_nodes)] for x in range(num_nodes)]

	# https://people.hofstra.edu/geotrans/eng/methods/diameter2.html
	# Graphs used

	matrix_a[0][1] = 1
	matrix_a[1][0] = 1
	matrix_a[1][3] = 1
	matrix_a[3][1] = 1
	matrix_a[3][2] = 1
	matrix_a[2][3] = 1
	matrix_a[2][0] = 1
	matrix_a[0][2] = 1
	matrix_a[2][4] = 1
	matrix_a[4][2] = 1
	matrix_a[4][5] = 1
	matrix_a[5][4] = 1

	assert ford(matrix_a, 0) == [0, 1, 1, 2, 2, 3]
	assert ford(matrix_a, 1) == [1, 0, 2, 1, 3, 4]
	assert ford(matrix_a, 2) == [1, 2, 0, 1, 1, 2]
	assert ford(matrix_a, 3) == [2, 1, 1, 0, 2, 3]
	assert ford(matrix_a, 4) == [2, 3, 1, 2, 0, 1]
	assert ford(matrix_a, 5) == [3, 4, 2, 3, 1, 0]

	assert graph_diameter(matrix_a) == 4

	matrix_a[3][5] = 1
	matrix_a[5][3] = 1

	assert graph_diameter(matrix_a) == 3

test()