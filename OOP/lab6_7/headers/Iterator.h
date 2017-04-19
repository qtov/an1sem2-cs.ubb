#ifndef ITERATOR_H
#define ITERATOR_H

template<typename T>
class Iterator
{
	Node<T>*	current;
public:
	Iterator(Node<T>* c) : current{ c }
	{}
	bool		operator!=(const Iterator& ot);
	void		operator++();
	T&			operator*();
};

#endif