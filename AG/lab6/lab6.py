import collections

def copy_matrix(matrix_a):
	i = 0
	num_nodes = len(matrix_a)
	new_matrix = [[0 for x in range(num_nodes)] for y in range(num_nodes)]
	while (i < num_nodes):
		j = 0
		while (j < num_nodes):
			new_matrix[i][j] = matrix_a[i][j]
			j += 1
		i += 1
	return new_matrix

def breadth_first(matrix_a, source, sink, parent):
	visited = [False for x in range(len(matrix_a))]
	queue = collections.deque()

	queue.append(source)
	visited[source] = True

	while queue:
		u = queue.popleft()

		for index, value in enumerate(matrix_a[u]):
			if visited[index] == False and value > 0:
				queue.append(index)
				visited[index] = True
				parent[index] = u

	return visited[sink]

def ford_fulkerson(matrix_a_param, source, sink):
	num_nodes = len(matrix_a_param)
	parent = [-1 for x in range(num_nodes)]
	matrix_a = copy_matrix(matrix_a_param)
	max_flow = 0

	while (breadth_first(matrix_a, source, sink, parent)):
		path_flow = float('inf')
		s = sink
		while (s != source):
			path_flow = min(path_flow, matrix_a[parent[s]][s])
			s = parent[s]

		max_flow += path_flow

		v = sink
		while (v != source):
			par = parent[v]
			matrix_a[par][v] -= path_flow
			matrix_a[v][par] += path_flow
			v = parent[v]

	return max_flow

def testing():
	matrix_a = [
	[0,10,0,10,0,0],
	[0,0,4,2,8,0],
	[0,0,0,0,0,9],
	[0,0,0,0,9,0],
	[0,0,6,0,0,10],
	[0,0,0,0,0,0]
	]
	assert ford_fulkerson(matrix_a, 0, 5) == 19


	# https://kunuk.files.wordpress.com/2010/11/fordfulkerson1.gif?w=700
	matrix_a = [
	[0,10,10,0,0,0],
	[0,0,2,4,8,0],
	[0,0,0,0,9,0],
	[0,0,0,0,0,10],
	[0,0,0,6,0,10],
	[0,0,0,0,0,0]
	]

	assert ford_fulkerson(matrix_a, 0, 5) == 19


	# https://i.stack.imgur.com/Scduo.jpg
	matrix_a = [
	[0,13,10,10,0,0,0,0],
	[0,0,0,0,24,0,0,0],
	[0,0,0,0,0,0,7,0],
	[0,0,0,0,0,0,15,0],
	[0,0,0,0,0,1,0,9],
	[0,0,0,0,0,0,6,13],
	[0,0,0,0,0,0,0,16],
	[0,0,0,0,0,0,0,0]
	]

	assert ford_fulkerson(matrix_a, 0, 7) == 26


	# https://i.stack.imgur.com/WH4JC.jpg
	matrix_a = [
	[0,3,6,8,0,0,0,0],
	[0,0,4,0,2,7,0,0],
	[0,0,0,0,6,1,2,0],
	[0,0,4,0,0,0,4,0],
	[0,0,0,0,0,1,0,3],
	[0,0,0,0,0,0,0,9],
	[0,0,0,0,0,5,0,5],
	[0,0,0,0,0,0,0,0]
	]

	assert ford_fulkerson(matrix_a, 0 ,7) == 14

testing()