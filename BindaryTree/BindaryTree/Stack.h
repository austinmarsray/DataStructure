#ifndef _STACK_H_
#define _STACK_H_

/*ջ�ṹ��ʵ��
*���ߣ��׺���
*ʱ��:2019��9��22��
*/


#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;

template<typename T>
class Stack
{
private:
	T *data;
	int top;
	int maxsize;
	void overflowProcess();
public:
	//���캯��
	Stack(int size = 10);
	//��������
	~Stack() { delete[] data; }
	//��������
	bool IsFull();
	//�пպ���
	bool IsEmpty()const;
	//��ջ
	T pop();
	//��ջ
	bool push(T &element);
	//��ȡջ��Ԫ��
	T getTop()const;
	//��ȡջ��Ԫ�ظ���
	int getSize();
	//���ջ
	void ToEmpty() { top = -1; }
	//���������
	friend ostream &operator<<(ostream &os, const Stack<T> &s)
	{
		int i = s.top;
		while (i != -1)
		{
			os << s.data[i] << endl;
			i--;
		}
		return os;
	}
	//�ļ����
	void writeToFile(string path);
	//�ļ�����
	void readFromFile(string path);


};

template<typename T>
inline void Stack<T>::overflowProcess()
{
	T *newData = new T[maxsize + 5];
	//assert(newData == nullptr);
	
	for (int i = 0; i <= top; i++)
	{
		newData[i] = data[i];
	}

	maxsize = maxsize + 5;
	delete[] data;
	data = newData;
}

template<typename T>
inline Stack<T>::Stack(int size)
{
	top = -1;
	maxsize = size;
	data = new T[maxsize];
}

template<typename T>
inline bool Stack<T>::IsFull()
{
	if (top + 1 == maxsize)
		return true;
	else
		return false;
}

template<typename T>
inline bool Stack<T>::IsEmpty() const
{
	if (top == -1)
		return true;
	else
		return false;
}

template<typename T>
inline T Stack<T>::pop()
{
	//���⣺��Ҫ�����쳣����Ҫ��ֵ��Ӧ����ô�죿
	assert(IsEmpty() != true);
	T tem;
	tem = data[top--];

	return tem;

}

template<typename T>
inline bool Stack<T>::push(T & element)
{
	if (IsFull() == true)
	{
		overflowProcess();
	}
	data[++top] = element;
	return true;

}

template<typename T>
inline T Stack<T>::getTop() const
{
	return data[top];
}

template<typename T>
inline int Stack<T>::getSize()
{
	return top+1;
}

template<typename T>
inline void Stack<T>::writeToFile(string path)
{
	ofstream cout(path.c_str());
	
	cout << top + 1;
	int i = top;
	while (i != -1)
	{
		cout << data[i] << endl;
		i--;
	}
}

template<typename T>
inline void Stack<T>::readFromFile(string path)
{
	ifstream cin(path.c_str());
	//��β�ʹ���������ƶ�ȡ�����ķ�ʽ��ȡ�ļ�?
	int tem;
	cin >> tem;
	for (int i = 0; i < tem; i++)
	{
		T Tem;
		cin >> Tem;
		push(Tem);
	}
	
}

#endif