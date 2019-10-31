#ifndef _MINHEAP_H_
#define _MINHEAP_H_

#include <math.h>
#include <iostream>
using namespace std;
//��С�� = ��ȫ������ + ����ÿ�����Ĺؼ�ֵ���Ըýڵ�Ϊ�����������е���Сֵ��
//��С�ѹؼ����������롢ɾ��

//��Ϊ����ȫ��������������������ʵ��Ч�ʽϸ�
//�������1��λ��ʼ�洢����
//���ڽ��i��������Ϊ2i���Һ���Ϊ2i+1���׽��Ϊ[i/2]

template<class T>
class MinHeap
{
private:
	T *data;
	int size;
	int capacity;
private:
	void OverflowProcess(int space=10);

	bool IsFull();

	bool IsExist(const T &element);
public:
	MinHeap();

	MinHeap(const MinHeap<T> &minheap);

	//�ж��Ƿ�Ϊ��
	bool IsEmpty();

	//��ȡ��С���н��ĸ���
	int GetSize() const;

	//n��ͬʱ���룬ʱ�临�Ӷ� O(n)  [ʹ��Insert() ����n��Ԫ�أ�ʱ�临�Ӷ� O(nlogn)]
	bool Add(const T element[], int num);

	//����
	bool Insert(const T &element);

	//ɾ��
	T Delete();

	//����ʽ���
	void OutputFormat();
};
//---------------------------------------------------�ڲ���װ����----------------------------------------------------------
template<class T>
inline void MinHeap<T>::OverflowProcess(int space)
{
	T *tem = new T[capacity + space];
	capacity += space;

	for (int i = 1; i <= size; i++)
	{
		tem[i] = data[i];
	}

	delete[]data;
	data = tem;	
}

template<class T>
inline bool MinHeap<T>::IsFull()
{
	return (size==capacity)?true:false;
}

template<class T>
inline bool MinHeap<T>::IsExist(const T & element)
{
	for (int i = 1; i <= size; i++)
	{
		if (data[i] == element)
			return true;
	}
	return false;
}

//------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------�ⲿ API------------------------------------------------------------
template<class T>
inline MinHeap<T>::MinHeap()
{
	data = new T[10 + 1];
	size = 0;
	capacity = 10;
}

template<class T>
inline MinHeap<T>::MinHeap(const MinHeap<T>& minheap)
{
	capacity = minheap.capacity;
	data = new T[capacity + 1];
	size = minheap.size;
	for (int i = 1; i <= size; i++)
	{
		data[i] = minheap.data[i];
	}
}

template<class T>
inline bool MinHeap<T>::IsEmpty()
{
	return (size == 0) ? true : false;
}

template<class T>
inline int MinHeap<T>::GetSize() const
{
	return size;
}

template<class T>
inline bool MinHeap<T>::Add(const T element[], int num)
{
	//���Ѳ��裺
	//�����һ��ӵ�к��ӵĽ�㿪ʼ������������������λ�õ���
	//֮�󽫸����������λ��������ɾ���ĵ�����������

	//�����ظ������ܲ���
	for (int i = 0; i < num; i++)
	{
		if (IsExist(element[i]) == true)
			return false;
	}
	//���ռ䲻�㣬����
	if (size + num > capacity)
		OverflowProcess(size + num - capacity + 5);
	
	//1.��Ԫ�ز���
	for (int i = 0; i < num; i++)
	{
		data[++size] = element[i];
	}

	//2.����˳��
	int cur_index = floor(1.0*size / 2);
	int leftchild_index = 0, rightchild_index = 0;
	while (1)
	{
		leftchild_index = 2 * cur_index;
		rightchild_index = 2 * cur_index + 1;

		//2.2.֮�󽫸����������λ��������ɾ���ĵ�����������
		if (cur_index == 1)
		{
			//��ʱ�ѵ�Ҷ���
			if (leftchild_index > size || rightchild_index > size)
				break;
			//�����Һ��� �� ���ӹؼ�ֵС���Һ��ӹؼ�ֵ ʱ
			else if (leftchild_index == size || data[leftchild_index] < data[rightchild_index])
			{
				if (data[leftchild_index] > data[cur_index])
					break;
				else
				{
					T tem = data[cur_index];
					data[cur_index] = data[leftchild_index];
					data[leftchild_index] = tem;
					cur_index = leftchild_index;
				}
			}
			//���Һ��ӹؼ�ֵС�����ӹؼ�ֵʱ
			else
			{
				if (data[rightchild_index] > data[cur_index])
					break;
				else
				{
					T tem = data[cur_index];
					data[cur_index] = data[rightchild_index];
					data[rightchild_index] = tem;
					cur_index = rightchild_index;
				}
			}
		}

		//2.1.�����һ��ӵ�к��ӵĽ�㿪ʼ������������������λ�õ���
		else if (leftchild_index == size || data[leftchild_index] < data[rightchild_index])
		{
			if (data[leftchild_index] > data[cur_index])
				cur_index--;
			else
			{
				T tem = data[cur_index];
				data[cur_index] = data[leftchild_index];
				data[leftchild_index] = tem;
				cur_index--;
			}
		}
		else
		{
			if (data[rightchild_index] > data[cur_index])
				cur_index--;
			else
			{
				T tem = data[cur_index];
				data[cur_index] = data[rightchild_index];
				data[rightchild_index] = tem;
				cur_index--;
			}
		}
	}
	return true;
}

template<class T>
inline bool MinHeap<T>::Insert(const T &element)
{
	//����������������ȫ���������� �� ����
	//����ԭ������������뵽��ȫ�������Ľ��ڿ�λ�ã��ٲ������׽��Ƚϴ�С�������ؼ�ֵ��֪��������С�ѵĹ���

	//���������������ȫ��������ŵ����һλ+1��λ�ã���ʱ��������ȫ������������
	//���ýڵ�ؼ�ֵ�����׽��Ƚϣ���������ؼ�ֵ��С�����߽����ؼ�ֵ����֮��������
	//�������˹ؼ�ֵ�������򽻻����׽��Ĺؼ�ֵ����Ҫ�����һ����׽��Ĺؼ�ֵ�Ƚϣ�ȷ���Ƿ��轻�����߲���ɹ�
	//��������ؼ�ֵ����������㣬����ɹ�
	
	//Ԫ���ظ����޷�����
	if (IsExist(element) == true)
		return false;
	//�ռ䲻��������
	if (IsFull() == true)
		OverflowProcess();
	//1.��Ԫ�ز���
	data[++size] = element;
	int cur_index = size;
	//2.����˳��
	int parent_index = 0;
	while(1)
	{
		if (cur_index == 1)
			break;

		parent_index = floor(cur_index / 2);

		if (data[cur_index] > data[parent_index])
			break;

		T tem = data[cur_index];
		data[cur_index] = data[parent_index];
		data[parent_index] = tem;
		cur_index = parent_index;
	}
	return true;
}

template<class T>
inline T MinHeap<T>::Delete()
{
	//ɾ��������������ȫ���������� �� ����
	//ɾ��ԭ����ɾ������㡿��������ȫ��������������һ�����ɾ�������ؼ�ֵ��ֵ������㣬�ٲ������ӽڵ�Ƚϣ�����
	
	//��������ȫ��������������һ�����ɾ��������ؼ�ֵ��ֵ�������
	//�ҳ���Ů����йؼ�ָ��С�Ľ�㣬������Ĺؼ�ֵ�Ƚϡ�3�㼰���Ͻṹ�ؼ�ֵ�ر��ӽڵ�󣬱ȽϿ��Բ������Ǽ���ṹ�������ӽڵ�ؼ�ֵС�򽻻�
	//���ӽ���йؼ�ֵ��С�Ľ��ؼ�ֵ�����������ɹ�
	//�������˹ؼ�ֵ�������򽻻����ӽ��Ĺؼ�ֵ����Ҫ����һ����ӽ���С�Ĺؼ�ֵ�Ƚϣ�ȷ���Ƿ��轻������ɾ���ɹ�
	//��������Ҷ��㣬ɾ���ɹ�


	//1.ɾ��ĩ��㣬��ĩ����ֵ��ֵ�������
	T feedback = data[1];
	data[1] = data[size--];
	
	//2.����˳��
	int cur_index = 1;
	int leftchild_index = 0, rightchild_index = 0;
	while (1)
	{
		leftchild_index = 2 * cur_index;
		rightchild_index = 2 * cur_index + 1;

		//��ʱ�ѵ�Ҷ���
		if (leftchild_index > size && rightchild_index > size)
			break;
		//�����Һ��� �� ���ӹؼ�ֵС���Һ��ӹؼ�ֵ ʱ
		else if (leftchild_index == size || data[leftchild_index] < data[rightchild_index])
		{
			if (data[leftchild_index] > data[cur_index])
				break;
			else
			{
				T tem = data[cur_index];
				data[cur_index] = data[leftchild_index];
				data[leftchild_index] = tem;
				cur_index = leftchild_index;
			}
		}
		//���Һ��ӹؼ�ֵС�����ӹؼ�ֵʱ
		else
		{
			if (data[rightchild_index] > data[cur_index])
				break;
			else
			{
				T tem = data[cur_index];
				data[cur_index] = data[rightchild_index];
				data[rightchild_index] = tem;
				cur_index = rightchild_index;
			}
		}
	}
	return feedback;
}

template<class T>
inline void MinHeap<T>::OutputFormat()
{
	if (IsEmpty() == true)
		return;
	for (int i = 1; i <= size; i++)
	{
		cout << data[i] << "  ";
	}
}

#endif