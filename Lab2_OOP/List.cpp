#include "List.h"

tNode::tNode() {
	next = nullptr;
}

tNode* insert_node(tNode* p_begin, Student data) {
	tNode* p = new tNode;
	p->data = data;
	p->next = p_begin;
	return p;
}


List::List() {
	begin = nullptr;
	size = 0;
}


void List::insert(Student value) {
	size++;
	begin = insert_node(begin, value);
}


List::~List() {
	tNode* p = begin;
	tNode* prev;
	while (p) {
		prev = p;
		p = p->next;
		delete prev;
	}
	size = 0;
	begin = nullptr;
}

void List::print() {
	tNode* p = begin;
	while (p) {
		p->data.show_data();
		p = p->next;
	}
}


Student& List::operator[](const int index)
{
	tNode* p = begin;
	int i = index;
	while (i-- && p) {
		p = p->next;
	}
	if (p) {
		return p->data;
	}
}