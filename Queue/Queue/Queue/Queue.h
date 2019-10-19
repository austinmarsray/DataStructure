#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
using namespace std;

//����
//���ȼ�����
//˫�˶���

/*ѭ�����нṹ��ʵ��
*���ߣ��׺���
*ʱ��:2019��10��1��
*/


template<typename T>
class Queue
{
private:
	int capacity;
	int begin;
	int end;
	T *data;
public:
	Queue(int size = 10);
	Queue(string filepath);
	~Queue() { delete[] data; }
	T pop();
	bool push(T &element);
	T front();
	bool IsFull();
	bool IsEmpty();
	int size();
};

template<typename T>
inline Queue<T>::Queue(int size)
{
	//ѭ������������һ���ռ�
	capacity = size + 1;
	data = new T[capacity];
	begin = end = 0;
}

template<typename T>
inline Queue<T>::Queue(string filepath)
{
	ifstream cin(filepath.c_str());
	int size;
	cin >> size;

	capacity = size + 1;
	data = new T[capacity];
	begin = end = 0;

	T tem;
	for (int i = 0; i < size; i++)
	{
		cin >> tem;
		push(tem);
	}
}

template<typename T>
inline T Queue<T>::pop()
{
	assert(IsEmpty() != true);

	T tem = data[begin];
	begin = (begin + 1) % capacity;

	return tem;

}

template<typename T>
inline bool Queue<T>::push(T & element)
{
	if (IsFull() == true) return false;

	data[end] = element;
	end = (end + 1) % capacity;

	return true;
}

template<typename T>
inline T Queue<T>::front()
{
	assert(IsEmpty() != true);

	T tem = data[begin];

	return tem;
}

template<typename T>
inline bool Queue<T>::IsFull()
{
	if (((end+1)%capacity) == begin)
		return true;
	else
		return false;
}

template<typename T>
inline bool Queue<T>::IsEmpty()
{
	if (begin == end) 
		return true;
	else
		return false;
}

template<typename T>
inline int Queue<T>::size()
{
	return (end-begin+capacity)%capacity;
}

#endif