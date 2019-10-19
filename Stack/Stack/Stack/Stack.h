#ifndef _STACK_H_
#define _STACK_H_

/*栈结构的实现
*作者：雷海星
*时间:2019年9月22日
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
	//构造函数
	Stack(int size = 10);
	//解析函数
	~Stack() { delete[] data; }
	//判满函数
	bool IsFull();
	//判空函数
	bool IsEmpty()const;
	//出栈
	T pop();
	//入栈
	bool push(T &element);
	//获取栈顶元素
	T getTop()const;
	//获取栈中元素个数
	int getSize();
	//清空栈
	void ToEmpty() { top = -1; }
	//重载输出流
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
	//文件输出
	void writeToFile(string path);
	//文件输入
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
	//问题：需要返回异常和需要的值，应该怎么办？
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
	//如何不使用数字限制读取数量的方式读取文件?
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