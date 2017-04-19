#ifndef LIST_H
#define LIST_H

#include "node.h"

Node			*new_node(Car car);
void			unshift_node(Node **start, Car car);
void			push_node(Node **start, Car car);
void			show_node(Node *start);
void			edit_node(Node **start, Car car);
int				node_exists(Node *start, Car car);
void			clear_list(Node **start);
unsigned char	loan_car(Node **start, unsigned long reg_num);
Node			*sort_by_model(Node *start);
Node			*sort_by_category(Node *start);

#endif