#pragma once
#include "List.h"
#include <iostream>

template<class Type>
BiList<Type>::BiList()
{
	first = NULL;
	last = NULL;
	size = 0;
}

template<class Type>
void BiList<Type>::push_back(Type Value)
{
	Node* temp = new Node;
	temp->next = NULL;
	temp->data = Value;
	if (!this->IsEmpty())
	{
		temp->before = last;
		last->next = temp;
		last = temp;
	}
	else {
		temp->before = NULL;
		first = last = temp;
	}
	size++;
}

template<class Type>
void BiList<Type>::push_front(Type Value)
{
	Node* temp = new Node;
	temp->before = NULL;
	temp->data = Value;
	if (!this->IsEmpty())
	{
		temp->next = first;
		first->before = temp;
		first = temp;
	}
	else
	{
		temp->before = NULL;
		temp->next = NULL;
		first = last = temp;
	}
	size++;
}

template<class Type>
void BiList<Type>::pop_back()
{
	if (size == 0) {
		return;
	}
	if (size == 1)
	{
		delete last;
		last = first = NULL;
		size--;
		return;
	}
	delete last->next;
	last = last->before;
	last->next = NULL;
	size--;
}

template<class Type>
void BiList<Type>::pop_front()
{
	if (size == 0) {
		return;
	}
	if (size == 1)
	{
		delete first;
		first = last = NULL;
		size--;
		return;
	}
	delete first->before;
	first->before = NULL;
	first = first->next;
	size--;
}

template<class Type>
void BiList<Type>::insert(Type Value, size_t index)
{
	if ((size == 0 && index == 0) || index >= size)
		throw "Error";
	if (index == 0)
	{
		this->push_front(Value);
		return;
	}
	Node* currentf = first;
	for (size_t i = 0; i < index; i++) {
		currentf = currentf->next;
	}
	Node* temp = new Node;
	temp->data = Value;
	temp->next = currentf;
	temp->before = currentf->before;
	currentf->before = temp;
	temp->before->next = temp;
	size++;
}

template<class Type>
Type BiList<Type>::at(size_t index)
{
	if (index >= size || index < 0) {
		throw "Error";
	}
	Node* currentf = first;
	for (size_t i = 0; i < index; i++)
		currentf = currentf->next;
	return currentf->data;
}

template<class Type>
void BiList<Type>::remove(size_t index)
{
	if (index >= size || index <= 0) {
		throw "Error";
	}
	if (index == 0)
	{
		this->pop_front();
		return;
	}
	if (index == size - 1)
	{
		this->pop_back();
		return;
	}
	Node* currentf = first;
	for (size_t i = 0; i < index; i++) {
		currentf = currentf->next;
	}
	Node* temp = currentf;
	currentf->before->next = currentf->next;
	currentf->next->before = currentf->before;
	delete temp;
	size--;
}

template<class Type>
size_t BiList<Type>::get_size()
{
	return size;
}

template<class Type>
void BiList<Type>::print_to_console()
{
	Node* currentf = first;
	if (first)
	{
		while (currentf->next)
		{
			std::cout << currentf->data << "<-->";
			currentf = currentf->next;
		}
		std::cout << currentf->data;
	}
	else {
		throw "List is empty";
	}
}

template<class Type>
void BiList<Type>::clear()
{
	while (first != NULL) {
		this->pop_front();
	}
	first = last = NULL;
}

template<class Type>
void BiList<Type>::set(size_t index, Type Value)
{
	if (index >= size || index < 0) {
		throw "Error";
	}
	Node* currentf = first;
	for (size_t i = 0; i < index; i++) {
		currentf = currentf->next;
	}
	currentf->data = Value;
}

template<class Type>
bool BiList<Type>::IsEmpty()
{
	if (first == NULL) {
		return true;
	}
	return false;
}

template<class Type>
void BiList<Type>::reverse()
{
	if (!first || !first->next) {
		return;
	}
	last = first;
	Node* temp = NULL;
	Node* current = first;
	while (current != NULL)
	{
		temp = current->before;
		current->before = current->next;
		current->next = temp;
		current = current->before;
	}
	first = temp->before;
}

template<class Type>
void BiList<Type>::Swap(size_t first, size_t other)
{
	Node* temp_f = first, * temp_s = first;
	for (size_t i = 0; i < first; i++) {
		temp_f = temp_f->next;
	}
	for (size_t i = 0; i < other; i++) {
		temp_s = temp_s->next;
	}
	Type temp = temp_f->data;
	temp_f->data = temp_s->data;
	temp_s->data = temp;
}

template<class Type>
int BiList<Type>::find(Type info)
{
	Node* current = first;
	int i = 0;
	while (i < size)
	{
		if (current->data == info)
			return i;
		current = current->next;
		i++;
	}
	return -1;
}

template<class Type>
BiList<Type>::~BiList()
{
	while (first)
	{
		last = first->next;
		delete first;
		first = last;
	}
}

