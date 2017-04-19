#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "Iterator.h"
#include <iterator>

template <typename T>
class DynamicVector
{
	Node<T>*	head;
	void		deleteAll();
	Node<T>*	copy(Node<T>* current);
public:
	DynamicVector() : head{ nullptr } {};
	DynamicVector(const DynamicVector& ot);
	void		operator=(const DynamicVector& ot);
	~DynamicVector();
	int			size;
	void		unshift(T v);
	void		push(T v);
	Iterator<T>	begin();
	Iterator<T>	end();
};

#endif