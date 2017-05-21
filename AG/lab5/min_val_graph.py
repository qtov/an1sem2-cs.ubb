def copy_edge_list(edge_list_param):
	"""
	input: lista de muchii
	output: copie lista de muchii
	"""
	edge_list = [[0 for x in range(3)] for y in range(len(edge_list_param))]
	for i in range(len(edge_list_param)):
		for j in range(3):
			edge_list[i][j] = edge_list_param[i][j]
	return edge_list

def remove_loops(edge_list):
	"""
	input: lista de muchii
	output: -
	sterge buclele din lista de muchii
	"""
	i = 0
	while (i < len(edge_list)):
		edge = edge_list[i]
		if edge[0] == edge[1]:
			edge_list.remove(edge)
			i -= 1
		i += 1

def equal_edges(edge1, edge2):
	"""
	input: 2 muchii
	output: daca muchiile au aceleasi varfuri
	"""
	if (edge1[0] == edge2[0] and edge1[1] == edge2[1]):
		return True
	return False

def heavier_edge(edge1, edge2):
	"""
	input: 2 muchii
	output: returneaza cea mai scumpa muchie
	"""
	if (edge1[2] > edge2[2]):
		return edge1
	return edge2

def remove_parallel_edges(edge_list):
	"""
	input: lista de muchii
	output: -
	sterge muchiile paralele
	"""
	i = 0
	to_remove = []
	while (i < len(edge_list) - 1):
		j = i + 1
		while (j < len(edge_list)):
			edge1 = edge_list[i]
			edge2 = edge_list[j]
			if (equal_edges(edge1, edge2)):
				to_remove.append(heavier_edge(edge1, edge2))
			j += 1
		i += 1
	for edge in to_remove:
		edge_list.remove(edge)

def find(vertex, parent):
	"""
	input: varf, lista de parinti
	output: parintele varfului
	cauta parintele varfului in lista de parinti "parent"
	"""
	if parent[vertex] != vertex:
		parent[vertex] = find(parent[vertex], parent)
	return parent[vertex]

def union(vertex1, vertex2, parent, rank):
	"""
	input: varf, varf, lista de parinti, lista de ranguri
	output: -
	modifica lista de ranguri si lista de parinti astfel incat sa se evite ciclurile
	"""
	root1 = find(vertex1, parent)
	root2 = find(vertex2, parent)
	if (root1 != root2):
		if (rank[root1] > rank[root2]):
			parent[root2] = root1
		else:
			parent[root1] = root2
		if rank[root1] == rank[root2]:
			rank[root2] += 1

def number_vertices(edge_list):
	"""
	input: lista de muchii
	output: numar de varfuri
	"""
	_max = 0
	for edge in edge_list:
		if edge[1] > _max:
			_max = edge[1]
		if edge[0] > _max:
			_max = edge[0]
	return _max + 1

def kruskal_min(edge_list_param):
	"""
	input: lista de muchii
	output: arborele partial de valoare minima
	"""
	tree_edge_list = []
	num_vert = number_vertices(edge_list_param)

	edge_list = copy_edge_list(edge_list_param)
	remove_loops(edge_list)
	remove_parallel_edges(edge_list)

	parent = []
	rank = []

	for vertex in range(num_vert):
		parent.append(vertex)
		rank.append(0)

	for edge in reversed(edge_list):
		if (find(edge[0], parent) != find(edge[1], parent)):
			union(edge[0], edge[1], parent, rank)
			tree_edge_list.append(edge)

	return tree_edge_list


def testing():
	edge_list = [
	[0,2,12],
	[0,0,8],
	[1,3,5],
	[3,3,4],
	[2,3,3],
	[0,2,2],
	[0,1,2],
	[1,2,1]]

	assert kruskal_min(edge_list) == [
	[1,2,1],
	[0,1,2],
	[2,3,3]]

	edge_list = [
	[6,5,9],
	[4,5,8],
	[5,3,7],
	[2,3,5],
	[1,2,4],
	[0,3,3],
	[0,2,3],
	[1,4,3],
	[0,1,2],
	[2,4,1]
	]
	
	assert kruskal_min(edge_list) == [
	[2,4,1],
	[0,1,2],
	[1,4,3],
	[0,3,3],
	[5,3,7],
	[6,5,9]
	]

	edge_list = [
	[3,4,7],
	[2,4,6],
	[1,2,5],
	[1,4,4],
	[0,1,3],
	[2,3,2],
	[0,4,1]
	]

	assert kruskal_min(edge_list) == [
	[0,4,1],
	[2,3,2],
	[0,1,3],
	[1,2,5]
	]

	edge_list = [
	[1,2,6],
	[1,5,5],
	[0,1,4],
	[4,5,4],
	[2,3,3],
	[0,5,2],
	[3,4,2],
	[2,5,1]
	]

	assert kruskal_min(edge_list) == [
	[2,5,1],
	[3,4,2],
	[0,5,2],
	[2,3,3],
	[0,1,4]
	]

testing()