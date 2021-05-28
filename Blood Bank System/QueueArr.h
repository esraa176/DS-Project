#pragma once
#include "QueueArr.cpp"
#include<string>
using namespace std;

template <class T>
class QueueArr
{
	T* arr;
	int count, size;
	int front, back;
public:
	QueueArr();
	int length();
	void enqueue(T);
	void dequeue();
	T Front();
	bool empty();
	bool full();
	~QueueArr();
};
