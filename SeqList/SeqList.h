#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
/*Author: Austin Ray
 *
 *Time: 2019/9/7 19:50 
 * 
 */

/*
（1）插入：操作方式为在指定位置完成插入（done）、在指定元素前插入(done)、在指定元素之后插入(done)

（2）删除：操作方式可分为删除指定元素(done)、删除指定位置的元素等（done），尝试实现逻辑删除操作。

（3）显示数据（done）

（4）查找：查询指定的元素（可根据某个数据成员完成查询操作）（done）

（5）定位操作：定位指定元素的序号(done)

（6）更新：修改指定元素的数据（done）

（7）数据文件的读写操作等。
*/
template <class T>
class SeqList{
    protected:
        T *data;
        int MaxSize;
        int Length;
        void reSize(int newSize);
    public:
		SeqList(int sz = 100);
		SeqList(SeqList<T> &x);
        ~SeqList() { delete[] data; }

        int getSize() const { return MaxSize; }
        int getLength() const { return Length; }
        int Search(T &x) const;
		bool Add(T &x);
		bool getData(int i, T &x) const;
        bool setData(int i, T &x);
        bool Insert(int i, T &x);
		bool InsertBefore(T &x, T &y);
		bool InsertAfter(T &x, T &y);
		bool Remove(int i);
		bool Remove(T &x);
		void Sort();
		bool IsEmpty() const;
        bool IsFull() const;
        void output();
		bool writeToFile();
		bool readFromFile();
		void operator=(SeqList<T> &x);
};

//类模板的定义和实现都需要在同一头文件中完成

template <class T>
//类模板在实现时不能设置默认参数值
SeqList<T>::SeqList(int sz)
{
	if (sz > 0)
	{
		MaxSize = sz;
		Length = 0;
		data = new T[MaxSize];
		if (nullptr == data)
		{
			cerr << "Memory Allocation Error!" << endl;
		}
	}
}

template<class T>
SeqList<T>::SeqList(SeqList<T> &x)
{
	MaxSize = x.getSize();
	Length = x.getLength();
	data = new T[MaxSize];
	if (nullptr == data)
	{
		cerr << "Memory Allocation Error!" << endl;
	}
	T value;
	for (int i = 0; i < Length; i++)
	{
		//data[i] = x.data[i];  //My Plan
		x.getDate(i, value);
		setDate(i, value);
	}
}

template<class T>
int SeqList<T>::Search(T &x) const
{
	for (int i = 0; i < Length; i++)
	{
		if (x == data[i])
			return i + 1;
	}
	return -1;
}

template<class T>
bool SeqList<T>::Add(T &x)
{
	if(Length==MaxSize)
		return false;

	data[Length] = x;
	Length++;
	return true;
}

template<class T>
bool SeqList<T>::getData(int i, T &x) const
{
	if (0 == Length)
		return false;
	if (i < 1 || i > Length)
		return false;

	x = data[i - 1];
	return true;
}

template<class T>
bool SeqList<T>::setData(int i, T &x)
{
	if (i < 1 || i > Length)
		return false;

	data[i - 1] = x;
	return true;
}

template<class T>
bool SeqList<T>::Insert(int i, T &x)
{
	if (Length == MaxSize)
		return false;
	if (i < 1 || i > Length + 1)
		return false;

	for (int j = Length - 1; j >= i-1; j--)
	{
		data[j + 1] = data[j];
	}
	data[i-1] = x;
	Length++;
	return true;
}

template<class T>
bool SeqList<T>::InsertBefore(T &x, T &y)
{
	if (Search(x) == -1)
		return false;
	else if (Insert(Search(x), y) == true)
		return true;
	else
		return false;
}

template<class T>
bool SeqList<T>::InsertAfter(T &x, T &y)
{
	if (Search(x) == -1)
		return false;
	else if (Insert(Search(x) + 1, y) == true)
		return true;
	else
		return false;
}

template<class T>
bool SeqList<T>::Remove(int i)
{
	if (Length == 0)
		return false;
	if (i < 1 || i > Length)
		return false;

	for (int j = i - 1; j < Length - 1; j++)
	{
		data[j] = data[j + 1];
	}
	Length--;
	return true;
}

template <class T>
bool SeqList<T>::Remove(T &x)
{
	if(Remove(Search(x))==true)
		return true;
	else
		return false;
}

template<class T>
void SeqList<T>::Sort()
{
	for (int i = 0; i < Length - 1; i++)
	{
		for (int j = 0; j < Length - 1 - i; j++)
		{
			if (data[j] > data[j + 1])
			{
				T tem = data[j + 1];
				data[j + 1] = data[j];
				data[j] = tem;
			}
		}
	}
}

template <class T>
bool SeqList<T>::IsEmpty() const
{
	if (Length == 0)
		return true;
	else
		return false;
}

template<class T>
bool SeqList<T>::IsFull() const
{
	if (MaxSize == Length)
		return true;
	else
		return false;
}


template<class T>
void SeqList<T>::output()
{
	cout << "Totally " << Length << " Element(s)!" << endl;
	for (int i = 0; i < Length; i++)
	{
		cout << data[i] << endl;
	}
}

template<class T>
void SeqList<T>::operator=(SeqList<T> &x)
{
	MaxSize = x.getSize();
	Length = x.getLength();
	data = new T[MaxSize];
	if (nullptr == data)
	{
		cerr << "Memory Allocation Error!" << endl;
	}
	T value;
	for (int i = 0; i < Length; i++)
	{
		//data[i] = x.data[i];  //My Plan
		x.getDate(i, value);
		setDate(i, value);
	}
}

template<class T>
bool SeqList<T>::writeToFile()
{
	ofstream cout("data.txt");
	cout << Length << endl;
	for (int i = 0; i < Length; i++)
	{
		cout << data[i] << endl;
	}
	return true;
}

template<class T>
bool SeqList<T>::readFromFile()
{
	Length = 0;
	ifstream cin("data.txt");
	int length;
	cin >> length;
	if (length > MaxSize)
		return false;
	else
	{
		T file_tem;
		for (int i = 0; i < length; i++)
		{
			cin >> file_tem;

			data[Length] = file_tem;
			Length++;
		}
		return true;
	}	
}