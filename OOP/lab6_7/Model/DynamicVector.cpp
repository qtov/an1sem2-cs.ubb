#include "DynamicVector.h"

template <typename T>
DynamicVector<T>::DynamicVector()
{
	this->size = 0;
	this->head = nullptr;
}


template <typename T>
void				DynamicVector<T>::display()
{
	Node<T>*	o;

	o = this->head;
	while (o != nullptr)
	{
		cout << o->data.get_title() << " " << o->data.get_description() << " " << o->data.get_type() << " " << o->data.get_duration() << "\n";
		o = o->next;
	}
}

template <typename T>
void				DynamicVector<T>::push(const T& v)
{
	Node<T>	*p;

	p = new Node<T>(v);
	if (this->head == nullptr)
	{
		this->head = p;
		this->tail = p;
	}
	else
	{
		this->tail->next = p;
		this->tail = p;
	}
	++this->size;
}

template <typename T>
int					DynamicVector<T>::get_size() const
{
	return this->size;
}

template <typename T>
DynamicVector<T>&	DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	Node<T>*	o;

	return *this;
}

// template <typename T>
// Node<T>*			DynamicVector<T>::get_head()
// {
// 	return this->head; //delete
// }

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete this->head;
}

template <typename T>
T&					DynamicVector<T>::operator[](int pos)
{
	Node<T>*	o;
	Activity*	fucking_activity = new Activity("asd", "asd", "qwe", 3);
	int			i;

	o = this->head;
	i = 0;
	while (o != nullptr)
	{
		if (i == pos)
			;//return o->data;
		++i;
		o = o->next;
	}
	return *fucking_activity;
}

template <typename T>
T&					DynamicVector<T>::at_index(int pos)
{
	Node<T>*	o;
	int			i;

	o = this->head;
	i = 0;
	while (o != nullptr)
	{
		if (i == pos)
			return o->data;
		++i;
		o = o->next;
	}
	throw std::invalid_argument("Invalid index");
}

template class DynamicVector < Activity >;