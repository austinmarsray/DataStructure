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
	//������
	T data;
	//ָ����
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
	//���������������ķ�װ
	void CreateBST();

	//ͨ���ļ����������������ķ�װ
	void CreateBST(string path);

	//ǰ�����
	void preOrder(BSTNode<T>* subtree);

	//�������
	void inOrder(BSTNode<T>* subtree);

	//�������
	void postOrder(BSTNode<T>* subtree);

	//�������
	void levelOrder(BSTNode<T>* node);
public:
	BinarySearchTree();

	BinarySearchTree(string path);

	~BinarySearchTree();

	//����
	BSTNode<T> *Insert(T Data);

	//ͨ���ݹ�ʵ�ֲ������
	//node��Ϊ�������������������ָ�룬��ֻ�ܱ�֤��nodeΪ�����Ķ����������в�����ȷ�����ܱ�֤����������������Ƕ���������
	BSTNode<T> *Insert(BSTNode<T> *node, T DATA);

	//���ݹؼ�ֵɾ�����
	void Delete(T Data);

	//���ݽ��ָ��ɾ�����
	void Delete(BSTNode<T> *Node);

	//��������
	BSTNode<T> *Search(T Data);

	//��ȡ���ֵ
	T GetMax();

	//��ȡ���ֵ���
	BSTNode<T>* GetMaxNode();

	//��ȡ�ֲ����ֵ
	T GetMax(BSTNode<T> *Node);

	//��ȡ�ֲ����ֵ���
	BSTNode<T>* GetMaxNode(BSTNode<T> *Node);

	//��ȡ��Сֵ
	T GetMin();

	//��ȡ��Сֵ���
	BSTNode<T>* GetMinNode();

	//��ȡ�ֲ���Сֵ
	T GetMin(BSTNode<T>* Node);

	//��ȡ�ֲ���Сֵ���
	BSTNode<T>* GetMinNode(BSTNode<T>* Node);

	//ǰ�����
	void PreOrder();

	//�������
	void InOrder();

	//�������
	void PostOrder();

	//�������
	void LevelOrder();

	//��ȡ�׽��
	BSTNode<T> *GetParent(BSTNode<T> *Node);

	//��ȡ���Ķ�
	int GetDegree(BSTNode<T>* Node);

	//��ȡ�����������
	int GetHeight();

	//��ȡָ���ڵ�����
	int GetNodeHeight(BSTNode<T>* Node);

	//��ȡ���������ĸ���
	int GetSize();

	//������ʽ�������������
	void OutputFormat();
};

//------------------------------------------------------�ڲ���װ����-------------------------------------------------------

template<class T>
inline void BinarySearchTree<T>::CreateBST()
{
	int num;
	cout << "������������Ԫ�ظ�����";
	cin >> num;
	cout << "������������Ԫ��" << endl;

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
		//һ·����
		while (cur != nullptr)
		{
			stack.push(cur);
			prev = cur;
			cur = cur->leftchild;
		}
		//����
		while (1)
		{

			if (stack.IsEmpty() == true)
			{
				cur = nullptr;
				break;
			}
			prev = cur;
			cur = stack.getTop();//������pop����
			//����
			//�ҿգ�������ٴλ���
			if (cur->rightchild == nullptr)
			{
				cout << cur->data << "  ";
				stack.pop();
			}
			//�ҷǿգ����Ǹղ��һ���
			else if (cur->rightchild != nullptr&&prev == cur->rightchild)
			{
				cout << cur->data << "  ";
				stack.pop();
			}
			//�ҷǿգ���δ����
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
//--------------------------------------------------------�ⲿ API--------------------------------------------------------
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
			//����Ԫ�رȣ������������С��������������
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
			//����Ԫ�رȣ������������󣨻���ȣ���������������
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
	//����һ����ɾ�����ΪҶ���
	//����ɾ�����׽�����ָ�����ָ�븳nullptr
	if (Node->leftchild == nullptr && Node->rightchild == nullptr)
	{
		BSTNode<T>* parent = GetParent(Node);
		if (parent->leftchild == Node)
			parent->leftchild = nullptr;
		if (parent->rightchild == Node)
			parent->rightchild = nullptr;
	}

	//���ζ�����ɾ�����ֻ��һ����Ů
	//ֱ�ӽ���Ů��ֵ������ɾ����㣬�Ͽ�������ϵ
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

	//����������ɾ�������������Ů
	//1.�������������ֵ�滻��ɾ���ֵ��ɾ�����ֵ�Ľ��
	//2.������������Сֵ�滻��ɾ���ֵ��ɾ����Сֵ�Ľ��
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
	int height = log2(NodeNum) + 1;//��n>0ʱ  ���=[log_2(n)]+1  nΪ�ڵ����

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


