#include "DynamicVector.h"

template <typename T>
DynamicVector<T>::DynamicVector()
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
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

template <typename T>
bool				DynamicVector<T>::exists(const T& elem)
{
	Node<T>*	o;

	o = this->head;
	while (o != nullptr)
	{
		if (o->data == elem)
		{
			return true;
		}
		o = o->next;
	}
	return false;
}

template <typename T>
void				DynamicVector<T>::remove(const T& elem)
{
	if (!this->exists(elem))
		throw invalid_argument("Element does not exist.");

	Node<T>*	o;
	o = this->head;
	if (o->data == elem)
	{
		Node<T>*	tmp;

		tmp = this->head;
		this->head = o->next;
		tmp->next = nullptr;
		delete tmp;
	}
	else
		while (o->next != nullptr)
		{
			if (o->next->data == elem)
			{
				Node<T>*	tmp;

				tmp = o->next;
				o->next = o->next->next;
				tmp->next = nullptr;
				delete tmp;
			}
			else
				o = o->next;
		}
	--this->size;
}

template <typename T>
int					DynamicVector<T>::index_of(const T& elem)
{
	Node<T>*	o;
	int			i = 0;

	o = this->head;
	while (o != nullptr)
	{
		if (o->data == elem)
		{
			return i;
		}
		o = o->next;
		++i;
	}
	return -1;
}

template <typename T>
void				DynamicVector<T>::edit(const T& elem)
{
	Node<T>*	o;

	o = this->head;
	while (o != nullptr)
	{
		if (o->data == elem)
		{
			o->data = elem;
			return;
		}
		o = o->next;
	}
}

template class DynamicVector < Activity >;