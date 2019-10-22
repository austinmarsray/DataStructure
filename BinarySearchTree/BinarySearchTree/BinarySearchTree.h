#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_

#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
using namespace std;

template<class T>
class BSTNode
{
private:
	//数据域
	T data;
	//指针域
	BSTNode *leftchild, *rightchild;
public:
	BSTNode()
	{
		leftchild = nullptr;
		rightchild = nullptr;
	}
	BSTNode(T Data)
	{
		data = Data;
		leftchild = nullptr;
		rightchild = nullptr;
	}
	~BSTNode()
	{
		delete leftchild, rightchild;
	}

	template<class T> friend class BinarySearchTree;
};


template<class T>
class BinarySearchTree
{
private:
	BSTNode<T> *root;
private:
	//创建二叉搜索树的封装
	void CreateBST();

	//通过文件创建二叉搜索树的封装
	void CreateBST(string path);

	//前序遍历
	void preOrder(BSTNode<T>* subtree);

	//中序遍历
	void inOrder(BSTNode<T>* subtree);

	//后序遍历
	void postOrder(BSTNode<T>* subtree);

	//层序遍历
	void levelOrder(BSTNode<T>* node);
public:
	BinarySearchTree();

	BinarySearchTree(string path);

	~BinarySearchTree();

	//插入
	BSTNode<T> *Insert(T Data);

	//通过递归实现插入操作
	//node可为二叉搜索树中任意结点的指针，但只能保证在node为根结点的二叉搜索树中插入正确，不能保证整个插入后整体仍是二叉搜索树
	BSTNode<T> *Insert(BSTNode<T> *node, T DATA);

	//根据关键值删除结点
	void Delete(T Data);

	//根据结点指针删除结点
	void Delete(BSTNode<T> *Node);

	//搜索函数
	BSTNode<T> *Search(T Data);

	//获取最大值
	T GetMax();

	//获取最大值结点
	BSTNode<T>* GetMaxNode();

	//获取局部最大值
	T GetMax(BSTNode<T> *Node);

	//获取局部最大值结点
	BSTNode<T>* GetMaxNode(BSTNode<T> *Node);

	//获取最小值
	T GetMin();

	//获取最小值结点
	BSTNode<T>* GetMinNode();

	//获取局部最小值
	T GetMin(BSTNode<T>* Node);

	//获取局部最小值结点
	BSTNode<T>* GetMinNode(BSTNode<T>* Node);

	//前序遍历
	void PreOrder();

	//中序遍历
	void InOrder();

	//后序遍历
	void PostOrder();

	//层序遍历
	void LevelOrder();

	//获取亲结点
	BSTNode<T> *GetParent(BSTNode<T> *Node);

	//获取结点的度
	int GetDegree(BSTNode<T>* Node);

	//获取二叉树的深度
	int GetHeight();

	//获取指定节点的深度
	int GetNodeHeight(BSTNode<T>* Node);

	//获取二叉树结点的个数
	int GetSize();

	//缩进形式输出二叉搜索树
	void OutputFormat();
};

//------------------------------------------------------内部封装方法-------------------------------------------------------

template<class T>
inline void BinarySearchTree<T>::CreateBST()
{
	int num;
	cout << "请输入待插入的元素个数：";
	cin >> num;
	cout << "请输入待插入的元素" << endl;

	T Data;
	for (int i = 1; i <= num; i++)
	{
		cin >> Data;
		Insert(Data);
	}
}

template<class T>
inline void BinarySearchTree<T>::CreateBST(string path)
{
	ifstream cin(path.c_str());
	int num;

	cin >> num;

	T Data;
	for (int i = 1; i <= num; i++)
	{
		cin >> Data;
		Insert(Data);
	}
}

template<class T>
inline void BinarySearchTree<T>::preOrder(BSTNode<T>* subtree)
{
	Stack<BSTNode<T>*> stack(20);
	while (subtree != nullptr || stack.IsEmpty() != true)
	{
		while (subtree != nullptr)
		{
			cout << subtree->data << "  ";
			stack.push(subtree);
			subtree = subtree->leftchild;
		}
		if (stack.IsEmpty() != true)
		{
			subtree = stack.pop();
			subtree = subtree->rightchild;
		}

	}
}

template<class T>
inline void BinarySearchTree<T>::inOrder(BSTNode<T>* subtree)
{
	Stack<BSTNode<T>*> stack(20);
	while (subtree != nullptr || stack.IsEmpty() != true)
	{
		while (subtree != nullptr)
		{
			stack.push(subtree);
			subtree = subtree->leftchild;
		}
		if (stack.IsEmpty() != true)
		{
			subtree = stack.pop();
			cout << subtree->data << "  ";
			subtree = subtree->rightchild;
		}
	}
}

template<class T>
inline void BinarySearchTree<T>::postOrder(BSTNode<T>* subtree)
{
	Stack<BSTNode<T>*> stack(20);
	BSTNode<T> *cur = subtree;
	BSTNode<T> *prev = nullptr;
	while (cur != nullptr || stack.IsEmpty() != true)
	{
		//一路左移
		while (cur != nullptr)
		{
			stack.push(cur);
			prev = cur;
			cur = cur->leftchild;
		}
		//回退
		while (1)
		{

			if (stack.IsEmpty() == true)
			{
				cur = nullptr;
				break;
			}
			prev = cur;
			cur = stack.getTop();//不能用pop回退
			//判右
			//右空，输出，再次回退
			if (cur->rightchild == nullptr)
			{
				cout << cur->data << "  ";
				stack.pop();
			}
			//右非空，但是刚才右回退
			else if (cur->rightchild != nullptr&&prev == cur->rightchild)
			{
				cout << cur->data << "  ";
				stack.pop();
			}
			//右非空，且未经过
			else
			{
				cur = cur->rightchild;
				break;
			}
		}
	}

}

template<class T>
inline void BinarySearchTree<T>::levelOrder(BSTNode<T>* node)
{
	Queue<BSTNode<T> *> q(30);
	q.push(node);
	while (q.IsEmpty() != true)
	{
		BSTNode<T> *tem = q.pop();
		if (tem->leftchild != nullptr) q.push(tem->leftchild);
		if (tem->rightchild != nullptr) q.push(tem->rightchild);
		cout << tem->data << "  ";

	}
}


//------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------外部 API--------------------------------------------------------
template<class T>
inline BinarySearchTree<T>::BinarySearchTree()
{
	root = nullptr;
	CreateBST();
}

template<class T>
inline BinarySearchTree<T>::BinarySearchTree(string path)
{
	root = nullptr;
	CreateBST(path);
}

template<class T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
	delete root;
}

template<class T>
inline BSTNode<T>* BinarySearchTree<T>::Insert(T Data)
{
	if (root == nullptr)
	{
		root = new BSTNode<T>(Data);
	}
	else
	{
		BSTNode<T> *cur = root;
		BSTNode<T> *newnode = new BSTNode<T>(Data);

		while (1)
		{
			//插入元素比（子树）根结点小，在左子树插入
			if (Data < cur->data)
			{
				if (cur->leftchild == nullptr)
				{
					cur->leftchild = newnode;
					break;
				}
				else
					cur = cur->leftchild;
			}
			//插入元素比（子树）根结点大（或相等），在右子树插入
			else
			{
				if (cur->rightchild == nullptr)
				{
					cur->rightchild = newnode;
					break;
				}
				else
					cur = cur->rightchild;
			}

		}
	}
	return nullptr;
}

template<class T>
inline BSTNode<T> *BinarySearchTree<T>::Insert(BSTNode<T> *node, T DATA)
{
	if (node == nullptr)
		node = new BSTNode<T>(DATA);
	else if (DATA < node->data)
		node->leftchild = Insert(DATA, node->leftchild);
	else
		node->rightchild = Insert(DATA, node->rightchild);

	return node;
}

template<class T>
inline void BinarySearchTree<T>::Delete(T Data)
{
	Delete(Search(Data));
}

template<class T>
inline void BinarySearchTree<T>::Delete(BSTNode<T>* Node)
{
	//情形一：待删除结点为叶结点
	//给待删结点的亲结点的左指针或右指针赋nullptr
	if (Node->leftchild == nullptr && Node->rightchild == nullptr)
	{
		BSTNode<T>* parent = GetParent(Node);
		if (parent->leftchild == Node)
			parent->leftchild = nullptr;
		if (parent->rightchild == Node)
			parent->rightchild = nullptr;
	}

	//情形二：待删除结点只有一个子女
	//直接将子女的值赋给待删除结点，断开两者联系
	else if (Node->leftchild != nullptr && Node->rightchild == nullptr)
	{
		Node->data = Node->leftchild->data;
		Node->leftchild = nullptr;
	}
	else if (Node->leftchild == nullptr && Node->rightchild != nullptr)
	{
		Node->data = Node->rightchild->data;
		Node->rightchild = nullptr;
	}

	//情形三：待删除结点有两个子女
	//1.用左子树的最大值替换待删结点值，删除最大值的结点
	//2.用右子树的最小值替换待删结点值，删除最小值的结点
	else if (Node->leftchild != nullptr && Node->rightchild != nullptr)
	{
		//1.
		BSTNode<T>* tem = GetMaxNode(Node->leftchild);
		T Data = tem->data;
		Delete(tem);
		Node->data = Data;
		//2.
		//BSTNode<T>* tem = GetMinNode(Node->rightchild);
		//Delete(tem);
		//Node->data = tem->data;

	}
}

template<class T>
inline BSTNode<T>* BinarySearchTree<T>::Search(T Data)
{
	if (root == nullptr)
		return nullptr;

	BSTNode<T> *cur = root;
	while (cur != nullptr)
	{
		if (Data < cur->data)
			cur = cur->leftchild;
		else if (Data > cur->data)
			cur = cur->rightchild;
		else
			return cur;
	}
	return nullptr;
}

template<class T>
inline T BinarySearchTree<T>::GetMax()
{
	BSTNode<T> *cur = root;
	T Max;

	while (cur != nullptr)
	{
		Max = cur->data;
		cur = cur->rightchild;
	}
	return Max;
}

template<class T>
inline BSTNode<T>* BinarySearchTree<T>::GetMaxNode()
{
	BSTNode<T> *cur = root;

	while (cur->rightchild != nullptr)
	{
		cur = cur->rightchild;
	}
	return cur;
}

template<class T>
inline T BinarySearchTree<T>::GetMax(BSTNode<T>* Node)
{
	BSTNode<T> *cur = Node;
	T Max;

	while (cur != nullptr)
	{
		Max = cur->data;
		cur = cur->rightchild;
	}
	return Max;
}

template<class T>
inline BSTNode<T>* BinarySearchTree<T>::GetMaxNode(BSTNode<T>* Node)
{
	BSTNode<T> *cur = Node;

	while (cur->rightchild != nullptr)
	{
		cur = cur->rightchild;
	}
	return cur;
}

template<class T>
inline T BinarySearchTree<T>::GetMin()
{
	BSTNode<T> *cur = root;
	T Min;

	while (cur != nullptr)
	{
		Min = cur->data;
		cur = cur->leftchild;
	}
	return Min;
}

template<class T>
inline BSTNode<T>* BinarySearchTree<T>::GetMinNode()
{
	BSTNode<T> *cur = root;

	while (cur->leftchild != nullptr)
	{
		cur = cur->leftchild;
	}
	return cur;
}

template<class T>
inline T BinarySearchTree<T>::GetMin(BSTNode<T>* Node)
{
	BSTNode<T> *cur = Node;
	T Min;

	while (cur != nullptr)
	{
		Min = cur->data;
		cur = cur->leftchild;
	}
	return Min;
}

template<class T>
inline BSTNode<T>* BinarySearchTree<T>::GetMinNode(BSTNode<T>* Node)
{
	BSTNode<T> *cur = Node;

	while (cur->leftchild != nullptr)
	{
		cur = cur->leftchild;
	}
	return cur;
}

template<class T>
inline void BinarySearchTree<T>::PreOrder()
{
	preOrder(root);
}

template<class T>
inline void BinarySearchTree<T>::InOrder()
{
	inOrder(root);
}

template<class T>
inline void BinarySearchTree<T>::PostOrder()
{
	postOrder(root);
}

template<class T>
inline void BinarySearchTree<T>::LevelOrder()
{
	levelOrder(root);
}



template<class T>
inline BSTNode<T>* BinarySearchTree<T>::GetParent(BSTNode<T>* Node)
{
	if (Node == root)
		return nullptr;

	if (root == nullptr)
		return nullptr;

	BSTNode<T> *cur = root;
	BSTNode<T> *prev = nullptr;

	while (cur != nullptr)
	{
		if (Node->data < cur->data)
		{
			prev = cur;
			cur = cur->leftchild;
		}
		else if (Node->data > cur->data)
		{
			prev = cur;
			cur = cur->rightchild;
		}
		else
			return prev;
	}
	return nullptr;
}


template<class T>
inline int BinarySearchTree<T>::GetDegree(BSTNode<T>* Node)
{
	int degree = 0;
	return degree = (Node->leftchild ? 1 : 0) + (Node->rightchild ? 1 : 0);
}

template<class T>
inline int BinarySearchTree<T>::GetHeight()
{
	if (root == nullptr) return 0;

	int NodeNum = GetSize();
	int height = log2(NodeNum) + 1;//当n>0时  深度=[log_2(n)]+1  n为节点个数

	return height;
}

template<class T>
inline int BinarySearchTree<T>::GetSize()
{
	Queue<BSTNode<T> *> q(30);
	q.push(root);
	int size = 0;
	while (q.IsEmpty() != true)
	{
		BSTNode<T> *tem = q.pop();
		size++;
		if (tem->leftchild != nullptr) q.push(tem->leftchild);
		if (tem->rightchild != nullptr) q.push(tem->rightchild);
	}
	return size;
}

template<class T>
inline int BinarySearchTree<T>::GetNodeHeight(BSTNode<T>* Node)
{
	int nodeheight = 0;

	BSTNode<T> *cur = root;
	while (cur != nullptr)
	{
		nodeheight++;
		if (Node->data < cur->data)
			cur = cur->leftchild;
		else if (Node->data > cur->data)
			cur = cur->rightchild;
		else
			break;
	}
	return nodeheight;
}

template<class T>
inline void BinarySearchTree<T>::OutputFormat()
{
	BSTNode<T> *node = root;

	Stack<BSTNode<T>*> stack(20);
	while (node != nullptr || stack.IsEmpty() != true)
	{
		while (node != nullptr)
		{
			for (int i = 1; i <= GetNodeHeight(node)-1; i++)
			{
				cout << "    ";
			}
			cout << node->data << endl;
			stack.push(node);
			node = node->leftchild;
		}
		if (stack.IsEmpty() != true)
		{
			node = stack.pop();
			node = node->rightchild;
		}

	}
}

#endif


