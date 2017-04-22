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
	void			unshift(const T&);
	DynamicVector&	operator=(const DynamicVector&);
	void			push(const T&);
	int				get_size() const;
	Iterator<T>		begin();
	Iterator<T>		end();
	void			display();
	void			remove(const T&);
	T& 				operator[](int pos);
	T&				at_index(int pos);
	int				index_of(const T&);
	bool			exists(const T&);
	void			edit(const T&);
	~DynamicVector();
};

#endif