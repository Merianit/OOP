#pragma once
#include "iostream"
#include "student.h"

class tNode {
public:
	Student data;
	tNode* next;
	tNode();
};


class List {
private:
	tNode* begin;
	int size;
public:
	List();
	Student& operator[] (const int);
	void insert(Student value);
	void print();
	void swap(const int one, const int two);
	~List();
};



//template <typename DataType>
//void List<DataType>::swap(const int one, const int two)
//{
//	tNode<DataType>* node1 = begin;
//	tNode<DataType>* node2 = begin;
//	tNode<DataType>* prev1 = nullptr;
//	tNode<DataType>* prev2 = nullptr;
//	tNode<DataType>* temp = nullptr;
//	int i = one;
//	while (i-- && node1) {
//		prev1 = node1;
//		node1 = node1->next;
//	}
//	i = two;
//	while (i-- && node1) {
//		prev2 = node2;
//		node2 = node2->next;
//	}
//	if (prev1)
//		prev1->next = node2;
//	if (prev2)
//		prev2->next = node1;
//	temp = node1->next;
//	node1->next = node2->next;
//	node2->next = temp;
//}
