#!/usr/bin/python3

def	create_arc_array(matrix_a):
	"""
	Creeaza un vector de arcuri si il returneaza
	Date de intrare: matrice de adiacenta
	"""
	num_nodes = len(matrix_a)
	arcs = []
	for i in range(num_nodes):
		for j in range(num_nodes):
			if (matrix_a[i][j] == 1):
				arcs.append([i,j])
	return (arcs)

def	create_incidence_matrix(arcs, num_nodes):
	"""
	Pe baza vectorului de arce, creeaza matricea de incidenta si o returneaza
	Date de intrare: vectorul de arce(arcs) si numarul de noduri(num_nodes)
	"""
	matrix_i = [[0 for x in range(len(arcs))] for y in range(num_nodes)]
	for i in range(len(arcs)):
		matrix_i[arcs[i][0]][i] = 1
		matrix_i[arcs[i][1]][i] = -1
	return (matrix_i)

def adiacente_to_incidence(matrix_a):
	"""
	Pe baza matricei de adiacenta returneaza matricea de incidenta
	Date de intrare: matricea de adiacenta
	"""
	arcs = create_arc_array(matrix_a)
	return create_incidence_matrix(arcs, len(matrix_a))


def	validator():
	test_matrix = [[0, 0, 1], [1,0,0], [1,0,1]]
	assert(create_arc_array(test_matrix) == [[0, 2], [1,0], [2,0], [2,2]])
	test_matrix[0][0] = 1
	assert(create_arc_array(test_matrix) == [[0,0], [0, 2], [1,0], [2,0], [2,2]])
	test_matrix[0][0] = 0
	test_matrix[2][0] = 0
	assert(create_arc_array(test_matrix) == [[0, 2], [1,0], [2,2]])
	test_matrix[0][0] = 1
	test_matrix[2][0] = 1
	test_arcs = create_arc_array(test_matrix)
	assert(create_incidence_matrix(test_arcs, len(test_matrix)) == [[-1,1,-1,-1,0], [0,0,1,0,0], [0,-1,0,1,-1]]);
	test_arcs = [[0,1],[2,3],[3,0],[3,2]];
	assert(create_incidence_matrix(test_arcs, 4) == [[1,0,-1,0],[-1,0,0,0],[0,1,0,-1],[0,-1,1,1]])
	test_arcs = [[0,1], [1,2], [2,3], [3,0], [3,2]];
	assert(create_incidence_matrix(test_arcs, 4) == [[1,0,0,-1,0],[-1,1,0,0,0],[0,-1,1,0,-1],[0,0,-1,1,1]])

def	test():
	num_nodes = 4

	matrix_a = [[0 for x in range(num_nodes)] for y in range(num_nodes)]
	matrix_a[0][1] = 1
	matrix_a[0][3] = 1
	matrix_a[1][2] = 1
	matrix_a[2][0] = 1
	matrix_a[2][3] = 1
	matrix_a[3][1] = 1

	matrix_i = adiacente_to_incidence(matrix_a)

	print(matrix_a)
	print(matrix_i)

validator()
test()
