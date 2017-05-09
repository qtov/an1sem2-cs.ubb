from itertools import combinations

def grade(matrix_a, node):
	"""
	input: matrice de adiacenta, varful(int) pentru care se calculeaza gradul unui varf
	output: graful varfului
	comportament necunoscut pentru alte date de intrare
	"""
	_num_edges = 0
	for i in range(len(matrix_a)):
		if (matrix_a[node][i] == 1):
			_num_edges += 1
	return _num_edges

def delete_all_line(matrix_a, line):
	"""
	input: matrice de adiacenta, linie(int)
	output: -
	seteaza 0 pentru linie "line"
	comportament necunoscut pentru alte date de intrare
	"""
	for i in range(len(matrix_a)):
		matrix_a[line][i] = 0

def all_zero(matrix_a):
	"""
	input: matrice de adiacenta
	output: boolean (true daca matricea e plina de 0, 1 altfel)
	comportament necunoscut pentru alte date de intrare
	"""
	for i in range(len(matrix_a)):
		for j in range(len(matrix_a)):
			if (matrix_a[i][j] == 1):
				return False
	return True

def min_dom_len(matrix_a_base):
	"""
	input: matrice de adiacenta
	output: int (cardinalul unei multimi externe stabile minime)
	comportament necunoscut pentru alte date de intrare
	"""
	num_nodes = len(matrix_a_base)
	matrix_a = [[0 for i in range(num_nodes)] for x in range(num_nodes)]
	matrix_b = [[0 for i in range(num_nodes)] for x in range(num_nodes)]
	# doua matrice pentru reprezentarea grafului bipartit
	list_b = [i for i in range(num_nodes)]
	# lista pentru stergerea conexiunilor

	for i in range(num_nodes):
		for j in range(num_nodes):
			matrix_a[i][j] = matrix_a_base[i][j]

	for i in range(num_nodes):
		matrix_a[i][i] = 1
	# diagonala principala initializata cu 1 (un varf este adiacent cu el insusi)

	for i in range(num_nodes):
		for j in range(num_nodes):
			matrix_b[i][j] = matrix_a[i][j]


	min_dom = 0 # contor
	while (not all_zero(matrix_a)):
		maximum = 0
		pos = -1

		# gasirea unui varf cu cel mai mare graf
		for i in reversed(range(num_nodes)):
			if (maximum < grade(matrix_a, i)):
				maximum = grade(matrix_a, i)
				pos = i

		# stergerea din lista de conexiuni si actualizarea matricii 
		for i in reversed(list_b):
			if (matrix_a[pos][i] == 1 and i in list_b):
				delete_all_line(matrix_b, i)
				list_b.remove(i)

		# actualizarea matricii
		for i in range(num_nodes):
			for j in range(num_nodes):
				if (matrix_a[i][j] == 1 and not j in list_b):
					matrix_a[i][j] = 0

		min_dom += 1
	return min_dom

def count_min_dom(matrix_a_base):
	num_nodes = len(matrix_a_base)
	matrix_a = [[0 for i in range(num_nodes)] for j in range(num_nodes)]
	# pregatirea matricii pentru verificarea multimiilor exterior stabile minime
	for i in range(num_nodes):
		for j in range(num_nodes):
			if (matrix_a_base[i][j] == 1):
				matrix_a[i][j] = 1
				matrix_a[j][i] = 1

	min_dom = min_dom_len(matrix_a)
	res = 0

	list_a = [i for i in range(num_nodes)]
	# creerea combinatiilor pentru pentru testarea apartenentei la multimea cu multimile exterior stabile minime
	for i in list(combinations(list_a, min_dom)):
		list_b = [0 for i in range(num_nodes)]
		matrix_b = [[0 for i in range(num_nodes)] for j in range(num_nodes)]
		
		# se creeaza matricea de adiacenta pentru combinatia i
		for j in range(len(i)):
			for k in range(num_nodes):
				matrix_b[i[j]][k] = matrix_a[i[j]][k]
				if (i[j] == k):
					matrix_b[i[j]][k] = 1

		# se retin varfurile conectate
		for j in range(num_nodes):
			for k in range(num_nodes):
				if (matrix_b[j][k] == 1):
					list_b[k] = 1

		# se verifica daca toate varfurile sunt conectate
		list_b_full = True
		for j in range(num_nodes):
			if (list_b[j] != 1):
				list_b_full = False

		if (list_b_full):
			res += 1

	return res

def testing():
	matrix_a = [
	[0, 1, 0, 0, 1, 0],
	[1, 0, 1, 0, 1, 0],
	[0, 1, 0, 1, 0, 1],
	[0, 0, 1, 0, 0, 0],
	[1, 1, 0, 0, 0, 1],
	[0, 0, 1, 0, 1, 0]]

	assert count_min_dom(matrix_a) == 4

	matrix_a = [
	[0, 1, 0],
	[1, 0, 1],
	[0, 1, 0]
	]

	assert count_min_dom(matrix_a) == 1

	matrix_a = [
	[0,1,0,0,0,0,0,0,0],
	[0,0,1,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,1,0],
	[0,0,1,0,1,0,0,0,0],
	[0,0,0,0,0,1,0,0,0],
	[0,0,0,0,0,0,1,0,0],
	[0,0,0,1,0,0,0,0,0],
	[0,0,0,0,0,0,1,0,1],
	[0,1,0,0,0,0,0,0,0],
	]

	assert count_min_dom(matrix_a) == 6

	#258, 158, 257, 267, 236, 247

	matrix_a = [
	[0,0,0,0,0,0,0],
	[1,0,0,0,1,0,0],
	[1,0,0,0,1,0,0],
	[0,1,0,0,1,0,0],
	[0,0,0,0,0,0,0],
	[0,1,0,0,0,0,1],
	[0,0,0,0,1,0,0],
	]

	assert count_min_dom(matrix_a) == 1

	matrix_a = [
	[0, 1, 0, 1, 1, 0],
	[0, 0, 0, 1, 0, 0],
	[0, 1, 0, 0, 1, 0],
	[0, 0, 0, 0, 1, 0],
	[0, 1, 0, 0, 0, 0],
	[0, 0, 0, 1, 1, 0]
	]

	assert count_min_dom(matrix_a) == 1

testing()