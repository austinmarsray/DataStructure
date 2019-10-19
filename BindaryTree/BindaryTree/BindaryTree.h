#ifndef _BINDARYTREE_H_
#define _BINDARYTREE_H_
/*
*��������ʵ��
*���ߣ��׺���
*ʱ�䣺2019��10��10��
*����:
*1.2019��10��18�� �����˸��ƺ���
*2.2019��10��18�� ��Ӷ�����ͬ���ж�
*3.2019��10��19�� ���ǰ��+����ȷ���������Ĺ��캯��
*/

#include "TreeNode.h"
#include "Stack.h"
#include "Queue.h"
#include <cmath>
using namespace std;

enum FLAG{LEFT,RIGHT};


template<class T>
class BinaryTree
{
private:
	//�����
	TreeNode<T> *root;

private:
	//�ж�ͬ�����ڲ���װ
	bool Isomorphic_P(const TreeNode<T>* Root1 , const TreeNode<T>* Root2);
	
	//���ƺ������ڲ���װ
	TreeNode<T> *CopyTree(const TreeNode<T> *Root , TreeNode<T> *cur);

	//��װ����������
	void CreateBinaryTree1();

	//��װͨ���ļ�����������
	bool CreateBinaryTree2(string path);

	//��װͨ��ǰ��+����ȷ��������
	TreeNode<T>* CreateBinaryTree3(int pos1, int pos2, int num, T pre[], T in[], TreeNode<T> *cur);

public:
	BinaryTree();

	BinaryTree(string path);

	BinaryTree(const BinaryTree<T> &tree);

	BinaryTree(T pre[], T in[], int num);

	~BinaryTree();

	//�ж϶������Ƿ�Ϊ��
	bool IsEmpty();

	//ɾ��������
	void DestroyTree();

	//ɾ��ָ��Ԫ�ؽڵ㼰������
	bool DestroyNode(TreeNode<T> *Node);

	//��ȡ�����ڵ�ĸ��ڵ�
	TreeNode<T>* Parent(TreeNode<T>* current);

	//��ȡ�����ڵ������
	TreeNode<T>* LeftChild(TreeNode<T>* current);

	//��ȡ�����ڵ���Һ���
	TreeNode<T>* RightChild(TreeNode<T>* current);

	//��ȡ�ݹ�ķ�ʽ����ǰ�����
	void PreOrder_Recursive(TreeNode<T>* subtree);

	//��ȡ�ݹ�ķ�ʽ�����������
	void InOrder_Recursive(TreeNode<T>* subtree);

	//��ȡ�ݹ�ķ�ʽ���к������
	void PostOrder_Recursive(TreeNode<T>* subtree);

	//��ȡ�ǵݹ�ķ�ʽ����ǰ�����
	void PreOrder(TreeNode<T>* subtree);

	//��ȡ�ǵݹ�ķ�ʽ�����������
	void InOrder(TreeNode<T>* subtree);

	//��ȡ�ǵݹ�ķ�ʽ���к������
	void PostOrder(TreeNode<T>* subtree);

	//��ȡ���еķ�ʽ���в������
	void LevelOrder(TreeNode<T>* node);

	//�ݹ鷽ʽ���������
	int GetHight_Recursive(TreeNode<T> *subtree) const;

	//��ȡ�ڵ�Ķ�
	int GetDegree(TreeNode<T> *Node);

	//�ǵݹ鷽ʽ���������
	int GetHight();

	//��ȡ�ڵ����ڵ����
	int GetNodeHeight(TreeNode<T> *Node);

	//ͨ�������ķ�ʽ��ȡ�������еĽ�����
	int GetSize();

	//��ȡҶ�ڵ�ĸ���
	int GetLeaveSize();

	//��ȡ�����
	TreeNode<T> *GetRoot() const;

	//���Ҷ�����������Ԫ��
	TreeNode<T> *Search(T &item);

	//��ָ���ڵ�����
	bool Insert(TreeNode<T> *ParentNode,TreeNode<T> *ChildNode,FLAG child=LEFT);

	//�޸�ָ��Ԫ�ص�������
	bool Modify(TreeNode<T> *Node, T &Data);

	//�����ʽ
	void OutputFormat();

	//�ж϶�����ͬ����API,����Ϊ�����������
	bool Isomorphic(const BinaryTree<T> &tree);
};

//-------------------------------------------------------�ڲ���װ����------------------------------------------------------
template<class T>
inline bool BinaryTree<T>::Isomorphic_P(const TreeNode<T>* Root1, const TreeNode<T>* Root2)
{
	//����һ�����߽�Ϊ��
	if (Root1 == nullptr && Root2 == nullptr) return true;

	//���ζ���һ��Ϊ�գ�һ����Ϊ��
	if ((Root1 == nullptr && Root2 != nullptr) || (Root1 != nullptr && Root2 == nullptr)) return false;

	//������:���߸���㲻ͬ
	if (Root1->data != Root2->data) return false;

	//�����ģ���������Ϊ��,�Ƚ��������Ƿ�ͬ��
	if (Root1->leftchild == nullptr && Root2->leftchild == nullptr)
		return Isomorphic_P(Root1->rightchild, Root2->rightchild);

	//�����壺��������Ϊ�գ���������ͬ
	if (Root1->leftchild != nullptr && Root2->leftchild != nullptr && Root1->leftchild->data == Root2->leftchild->data)
		return (Isomorphic_P(Root1->leftchild, Root2->leftchild) && Isomorphic_P(Root1->rightchild, Root2->rightchild));

	//����������������Ϊ�գ������Ӳ�ͬ
	else
		return (Isomorphic_P(Root1->leftchild, Root2->rightchild) && Isomorphic_P(Root1->rightchild, Root2->leftchild));

}

template<class T>
inline TreeNode<T> *BinaryTree<T>::CopyTree(const TreeNode<T> *Root, TreeNode<T> *cur)
{
	TreeNode<T>* newnode;

	if (Root == nullptr)
	{
		return nullptr;
	}
	else
	{
		//�����½ڵ�
		newnode = new TreeNode<T>();
		//���ƽڵ�����
		newnode->data = Root->data;
		//����prarentָ��
		newnode->parent = cur;
		//����������
		newnode->leftchild = CopyTree(Root->leftchild, newnode);
		//����������
		newnode->rightchild = CopyTree(Root->rightchild, newnode);
	}
	return newnode;
}

template<class T>
inline void BinaryTree<T>::CreateBinaryTree1()
{
	cout << "����ִ�ж������Ĵ�������..." << endl;

	cout << "������ս���־:";
	T Symbol;
	cin >> Symbol;

	cout << "���������������ȣ�";
	int n;
	cin >> n;


	TreeNode<T> *cur;
	Queue<TreeNode<T> *> q(20);

	//��һ��
	cout << "�������1��Ľڵ�����(Ϊ���������Ӷ����־)��" << endl;
	T tem;
	cin >> tem;
	cur = new TreeNode<T>(tem);
	root = cur;
	q.push(cur);

	//���㼰����
	for (int i = 2; i <= n; i++)
	{
		cout << "�������" << i << "��Ľڵ�����(Ϊ���������Ӷ����־)��" << endl;

		for (int j = 1; j <= pow(2, i - 2); j++)
		{
			T L_tem, R_tem;
			cin >> L_tem >> R_tem;
			TreeNode<T> *rootNode = q.pop();

			if (L_tem == Symbol)
			{
				rootNode->leftchild == nullptr;
			}
			else
			{
				cur = new TreeNode<T>(L_tem);
				rootNode->leftchild = cur;
				rootNode->leftchild->parent = rootNode;
				q.push(cur);
			}
			if (R_tem == Symbol)
			{
				rootNode->rightchild == nullptr;
			}
			else
			{
				cur = new TreeNode<T>(R_tem);
				rootNode->rightchild = cur;
				rootNode->rightchild->parent = rootNode;
				q.push(cur);
			}
		}
	}
}

template<class T>
inline bool BinaryTree<T>::CreateBinaryTree2(string path)
{
	ifstream cin(path.c_str());

	T Symbol;
	cin >> Symbol;

	int n;
	cin >> n;


	TreeNode<T> *cur;
	Queue<TreeNode<T> *> q(20);

	//��һ��
	T tem;
	cin >> tem;
	cur = new TreeNode<T>(tem);
	root = cur;
	q.push(cur);

	//���㼰����
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= pow(2, i - 2); j++)
		{
			T L_tem, R_tem;
			cin >> L_tem >> R_tem;
			TreeNode<T> *rootNode = q.pop();

			if (L_tem == Symbol)
			{
				rootNode->leftchild == nullptr;
			}
			else
			{
				cur = new TreeNode<T>(L_tem);
				rootNode->leftchild = cur;
				rootNode->leftchild->parent = rootNode;
				q.push(cur);
			}
			if (R_tem == Symbol)
			{
				rootNode->rightchild == nullptr;
			}
			else
			{
				cur = new TreeNode<T>(R_tem);
				rootNode->rightchild = cur;
				rootNode->rightchild->parent = rootNode;
				q.push(cur);
			}
		}
	}
	return true;
}

template<class T>
inline TreeNode<T>* BinaryTree<T>::CreateBinaryTree3(int pos1, int pos2, int num, T pre[], T in[], TreeNode<T> *cur)
{
	//ǰ��ȷ������㡢���������
	//����ȷ����������
	//����ʹ�����������ݹ��ý��

	TreeNode<T> * p = nullptr;

	for (int i = 0; i < num; i++)
	{
		if (pre[pos1] == in[pos2 + i])
		{
			p = new TreeNode<T>(pre[pos1]);
			p->parent = cur;
			p->leftchild = CreateBinaryTree3(pos1 + 1, pos2, i, pre, in, p);
			p->rightchild = CreateBinaryTree3(pos1 + i + 1, pos2 + i + 1, num - i - 1, pre, in, p);
			return p;
		}
	}
	return p;

}
//------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------�ⲿ API--------------------------------------------------------
template<class T>
inline BinaryTree<T>::BinaryTree()
{
	root = nullptr;
	CreateBinaryTree1();
}

template<class T>
inline BinaryTree<T>::BinaryTree(string path)
{
	root = nullptr;
	CreateBinaryTree2(path);
}

template<class T>
inline BinaryTree<T>::BinaryTree(const BinaryTree<T>& tree)
{
	root = CopyTree(tree.root, this->root);
}

template<class T>
inline BinaryTree<T>::BinaryTree(T pre[], T in[],int num)
{
	root=CreateBinaryTree3(0, 0, num, pre, in, root);
}

template<class T>
inline BinaryTree<T>::~BinaryTree()
{
	delete root;
}

template<class T>
inline bool BinaryTree<T>::IsEmpty()
{
	return (root == nullptr) ? true : false;
}

template<class T>
inline void BinaryTree<T>::DestroyTree()
{
	root = nullptr;
}

template<class T>
inline bool BinaryTree<T>::DestroyNode(TreeNode<T>* Node)
{
	if (Node->parent == nullptr)
	{
		DestroyTree();
		return true;
	}
	else if (Node->parent->leftchild == Node)
	{
		Node->parent->leftchild = nullptr;
		return true;
	}
	else if (Node->parent->rightchild == Node)
	{
		Node->parent->rightchild = nullptr;
		return true;
	}
	else
		return false;
}

template<class T>
inline TreeNode<T>* BinaryTree<T>::Parent(TreeNode<T>* current)
{
	return current->parent;
}

template<class T>
inline TreeNode<T>* BinaryTree<T>::LeftChild(TreeNode<T>* current)
{
	return current->leftchild;
}

template<class T>
inline TreeNode<T>* BinaryTree<T>::RightChild(TreeNode<T>* current)
{
	return current->rightchild;
}

template<class T>
inline void BinaryTree<T>::PreOrder_Recursive(TreeNode<T>* subtree)
{
	if (subtree != nullptr)
	{
		cout << subtree->data << "  ";
		PreOrder_Recursive(subtree->leftchild);
		PreOrder_Recursive(subtree->rightchild);
	}
}

template<class T>
inline void BinaryTree<T>::InOrder_Recursive(TreeNode<T>* subtree)
{
	if (subtree != nullptr)
	{
		InOrder_Recursive(subtree->leftchild);
		cout << subtree->data << "  ";
		InOrder_Recursive(subtree->rightchild);

	}
}

template<class T>
inline void BinaryTree<T>::PostOrder_Recursive(TreeNode<T>* subtree)
{
	if (subtree != nullptr)
	{
		PostOrder_Recursive(subtree->leftchild);
		PostOrder_Recursive(subtree->rightchild);
		cout << subtree->data << "  ";
	}
}

template<class T>
inline void BinaryTree<T>::PreOrder(TreeNode<T>* subtree)
{
	Stack<TreeNode<T>*> stack(20);
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
	//˼�����㷨��һ·���󣬸����������Ҷ���ѹջ
}

template<class T>
inline void BinaryTree<T>::InOrder(TreeNode<T>* subtree)
{
	Stack<TreeNode<T>*> stack(20);
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
inline void BinaryTree<T>::PostOrder(TreeNode<T>* subtree)
{
	Stack<TreeNode<T>*> stack(20);
	TreeNode<T> *cur = subtree;
	TreeNode<T> *prev = nullptr;
	while (cur!=nullptr||stack.IsEmpty()!=true)
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
inline void BinaryTree<T>::LevelOrder(TreeNode<T>* node)
{
	Queue<TreeNode<T> *> q(30);
	q.push(node);
	while (q.IsEmpty()!=true)
	{
		TreeNode<T> *tem = q.pop();
		if (tem->leftchild != nullptr) q.push(tem->leftchild);
		if (tem->rightchild != nullptr) q.push(tem->rightchild);
		cout << tem->data << "  ";

	}
}

template<class T>
inline int BinaryTree<T>::GetHight_Recursive(TreeNode<T> *subtree) const
{
	if (subtree == nullptr) return 0;
	
	int leftHight = GetHight_Recursive(subtree->leftchild);
	int rightHight = GetHight_Recursive(subtree->rightchild);
	
	return (leftHight > rightHight) ? (leftHight + 1) : (rightHight + 1);
}

template<class T>
inline int BinaryTree<T>::GetDegree(TreeNode<T>* Node)
{
	int degree = 0;
	return degree = (Node->leftchild ? 1 : 0) + (Node->rightchild ? 1 : 0);
}

template<class T>
inline int BinaryTree<T>::GetHight()
{
	if (root == nullptr) return 0;

	int NodeNum = GetSize();
	int height=log2(NodeNum)+1;//��n>0ʱ  ���=[log_2(n)]+1  nΪ�ڵ����

	return height;
}

template<class T>
inline int BinaryTree<T>::GetNodeHeight(TreeNode<T>* Node)
{
	int nodeheight=0;
	while (Node->parent != nullptr)
	{
		nodeheight++;
		Node = Node->parent;
	}
	return nodeheight;
}

template<class T>
inline int BinaryTree<T>::GetSize()
{
	Queue<TreeNode<T> *> q(30);
	q.push(root);
	int size = 0;
	while (q.IsEmpty() != true)
	{
		TreeNode<T> *tem = q.pop();
		size++;
		if (tem->leftchild != nullptr) q.push(tem->leftchild);
		if (tem->rightchild != nullptr) q.push(tem->rightchild);
	}
	return size;
}

template<class T>
inline int BinaryTree<T>::GetLeaveSize()
{
	Queue<TreeNode<T> *> q(30);
	q.push(root);
	int leavesize = 0;
	while (q.IsEmpty() != true)
	{
		TreeNode<T> *tem = q.pop();
		if (tem->leftchild != nullptr) q.push(tem->leftchild);
		if (tem->rightchild != nullptr) q.push(tem->rightchild);
		if (tem->leftchild == nullptr && tem->rightchild == nullptr) leavesize++;
	}
	return leavesize;
}

template<class T>
inline TreeNode<T>* BinaryTree<T>::GetRoot() const
{
	return root;
}

template<class T>
inline TreeNode<T>* BinaryTree<T>::Search(T & item)
{
	Stack<TreeNode<T>*> stack(20);

	TreeNode<T> *subtree = root;
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

			if (subtree->data == item) 
				return subtree;

			subtree = subtree->rightchild;
		}
	}
	return nullptr;
}

template<class T>
inline bool BinaryTree<T>::Insert(TreeNode<T> *ParentNode, TreeNode<T> *ChildNode, FLAG child)
{
	if (child == LEFT)
	{
		if (ParentNode->leftchild == nullptr)
		{
			ParentNode->leftchild = ChildNode;
			ChildNode->parent = ParentNode;
			return true;
		}
		else
			return false;
	}
	if (child == RIGHT)
	{
		if (ParentNode->rightchild == nullptr)
		{
			ParentNode->rightchild = ChildNode;
			ChildNode->parent = ParentNode;
			return true;
		}
		else
			return false;
	}
	return false;
}

template<class T>
inline bool BinaryTree<T>::Modify(TreeNode<T>* Node, T & Data)
{
	if (Node != nullptr)
	{
		Node->data = Data;
		return true;
	}
	else
		return false;
}

template<class T>
inline void BinaryTree<T>::OutputFormat()
{
	TreeNode<T> *node = root;

	Stack<TreeNode<T>*> stack(20);
	while (node != nullptr || stack.IsEmpty() != true)
	{
		while (node != nullptr)
		{
			for (int i = 1; i <= GetNodeHeight(node); i++)
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

template<class T>
inline bool BinaryTree<T>::Isomorphic(const BinaryTree<T> &tree)
{
	return Isomorphic_P(tree.root,this->root);
}

#endif


