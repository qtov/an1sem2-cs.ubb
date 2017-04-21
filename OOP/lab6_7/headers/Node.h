#ifndef NODE_H
#define NODE_H

#include "Activity.h"

template <typename T>
struct Node {
	T		data;
	Node*	next;
	Node()
	{
		this->next = nullptr;
	};

	Node(T _data)
	{
		// cout << _data.get_title() << " " << _data.get_description() << " " << _data.get_type() << " " << _data.get_duration() << "\n";
		this->data.set_title(_data.get_title());
		this->data.set_description(_data.get_description());
		this->data.set_type(_data.get_type());
		this->data.set_duration(_data.get_duration());
		// cout << "this -> " << this->data.get_title() << " " << this->data.get_description() << " " << this->data.get_type() << " " << this->data.get_duration() << "\n";
		this->next = nullptr;
	};

	~Node()
	{
		delete this->next; //careful to set null for a thing that has to be deleted
	};
};

#endif