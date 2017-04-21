#ifndef DYNAMICVECTOR_H
#define DYNAMICVECTOR_H

#include "debug.h"
#include "Node.h"
#include "Iterator.h"
#include <iterator>

template <typename T>
class DynamicVector
{
	Node<T>*		head;
	void			deleteAll();
	Node<T>*		copy(Node<T>* current);
	int				size;
	Node<T>*		tail;
public:
	DynamicVector();
	void			unshift(const T& v);
	DynamicVector&	operator=(const DynamicVector& v);
	void			push(const T& v);
	int				get_size() const;
	Iterator<T>		begin();
	Iterator<T>		end();
	void			display();
	T& 				operator[](int pos);
	T&				at_index(int pos);
	~DynamicVector();
};

#endif