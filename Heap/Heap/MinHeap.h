#ifndef _MINHEAP_H_
#define _MINHEAP_H_

#include <math.h>
#include <iostream>
using namespace std;
//最小堆 = 完全二叉树 + 规则（每个结点的关键值是以该节点为根结点的子树中的最小值）
//最小堆关键操作：插入、删除

//因为是完全二叉树，所以用数组来实现效率较高
//从数组的1号位开始存储，则
//对于结点i，其左孩子为2i，右孩子为2i+1，亲结点为[i/2]

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

	//判断是否为空
	bool IsEmpty();

	//获取最小堆中结点的个数
	int GetSize() const;

	//n个同时插入，时间复杂度 O(n)  [使用Insert() 插入n个元素，时间复杂度 O(nlogn)]
	bool Add(const T element[], int num);

	//插入
	bool Insert(const T &element);

	//删除
	T Delete();

	//缩进式输出
	void OutputFormat();
};
//---------------------------------------------------内部封装方法----------------------------------------------------------
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

//----------------------------------------------------外部 API------------------------------------------------------------
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
	//建堆步骤：
	//从最后一个拥有孩子的结点开始，调整堆序，逐步向根结点位置调整
	//之后将根结点调整后得位置再类似删除的调整方法调序

	//若有重复，不能插入
	for (int i = 0; i < num; i++)
	{
		if (IsExist(element[i]) == true)
			return false;
	}
	//若空间不足，补齐
	if (size + num > capacity)
		OverflowProcess(size + num - capacity + 5);
	
	//1.将元素插入
	for (int i = 0; i < num; i++)
	{
		data[++size] = element[i];
	}

	//2.调整顺序
	int cur_index = floor(1.0*size / 2);
	int leftchild_index = 0, rightchild_index = 0;
	while (1)
	{
		leftchild_index = 2 * cur_index;
		rightchild_index = 2 * cur_index + 1;

		//2.2.之后将根结点调整后得位置再类似删除的调整方法调序
		if (cur_index == 1)
		{
			//此时已到叶结点
			if (leftchild_index > size || rightchild_index > size)
				break;
			//当无右孩子 或 左孩子关键值小于右孩子关键值 时
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
			//当右孩子关键值小于左孩子关键值时
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

		//2.1.从最后一个拥有孩子的结点开始，调整堆序，逐步向根结点位置调整
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
	//插入条件：满足完全二叉树条件 和 规则
	//插入原理：将插入结点插入到完全二叉树的紧邻空位置，再不断与亲结点比较大小，交换关键值，知道满足最小堆的规则

	//将待插入结点放在完全二叉树编号的最后一位+1的位置，此时满足了完全二叉树的条件
	//将该节点关键值与其亲结点比较，若插入结点关键值更小，两者交换关键值，反之则插入完成
	//若进行了关键值交换，则交换到亲结点的关键值还需要与更上一层的亲结点的关键值比较，确定是否还需交换或者插入成功
	//当插入结点关键值交换到根结点，插入成功
	
	//元素重复，无法插入
	if (IsExist(element) == true)
		return false;
	//空间不够，扩容
	if (IsFull() == true)
		OverflowProcess();
	//1.将元素插入
	data[++size] = element;
	int cur_index = size;
	//2.调整顺序
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
	//删除条件：满足完全二叉树条件 和 规则
	//删除原理：【删除根结点】将满足完全二叉树编码的最后一个结点删除，将关键值赋值给根结点，再不断与子节点比较，交换
	
	//将满足完全二叉树编码的最后一个结点删除，将其关键值赋值给根结点
	//找出子女结点中关键指较小的结点，与根结点的关键值比较【3层及以上结构关键值必比子节点大，比较可以不关心是几层结构】，若子节点关键值小则交换
	//若子结点中关键值较小的结点关键值都更大，则插入成功
	//若进行了关键值交换，则交换到子结点的关键值还需要与下一层的子结点较小的关键值比较，确定是否还需交换或者删除成功
	//当交换到叶结点，删除成功


	//1.删除末结点，将末结点的值赋值给根结点
	T feedback = data[1];
	data[1] = data[size--];
	
	//2.调整顺序
	int cur_index = 1;
	int leftchild_index = 0, rightchild_index = 0;
	while (1)
	{
		leftchild_index = 2 * cur_index;
		rightchild_index = 2 * cur_index + 1;

		//此时已到叶结点
		if (leftchild_index > size && rightchild_index > size)
			break;
		//当无右孩子 或 左孩子关键值小于右孩子关键值 时
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
		//当右孩子关键值小于左孩子关键值时
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