#ifndef _BINDARYTREE_H_
#define _BINDARYTREE_H_
/*
*二叉树的实现
*作者：雷海星
*时间：2019年10月10日
*更新:
*1.2019年10月18日 修正了复制函数
*2.2019年10月18日 添加二叉树同构判断
*3.2019年10月19日 添加前序+中序确定二叉树的构造函数
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
	//根结点
	TreeNode<T> *root;

private:
	//判断同构的内部封装
	bool Isomorphic_P(const TreeNode<T>* Root1 , const TreeNode<T>* Root2);
	
	//复制函数的内部封装
	TreeNode<T> *CopyTree(const TreeNode<T> *Root , TreeNode<T> *cur);

	//封装创建二叉树
	void CreateBinaryTree1();

	//封装通过文件创建二叉树
	bool CreateBinaryTree2(string path);

	//封装通过前序+中序确定二叉树
	TreeNode<T>* CreateBinaryTree3(int pos1, int pos2, int num, T pre[], T in[], TreeNode<T> *cur);

public:
	BinaryTree();

	BinaryTree(string path);

	BinaryTree(const BinaryTree<T> &tree);

	BinaryTree(T pre[], T in[], int num);

	~BinaryTree();

	//判断二叉树是否为空
	bool IsEmpty();

	//删除二叉树
	void DestroyTree();

	//删除指定元素节点及其子树
	bool DestroyNode(TreeNode<T> *Node);

	//获取给定节点的父节点
	TreeNode<T>* Parent(TreeNode<T>* current);

	//获取给定节点的左孩子
	TreeNode<T>* LeftChild(TreeNode<T>* current);

	//获取给定节点的右孩子
	TreeNode<T>* RightChild(TreeNode<T>* current);

	//采取递归的方式进行前序遍历
	void PreOrder_Recursive(TreeNode<T>* subtree);

	//采取递归的方式进行中序遍历
	void InOrder_Recursive(TreeNode<T>* subtree);

	//采取递归的方式进行后序遍历
	void PostOrder_Recursive(TreeNode<T>* subtree);

	//采取非递归的方式进行前序遍历
	void PreOrder(TreeNode<T>* subtree);

	//采取非递归的方式进行中序遍历
	void InOrder(TreeNode<T>* subtree);

	//采取非递归的方式进行后序遍历
	void PostOrder(TreeNode<T>* subtree);

	//采取队列的方式进行层序遍历
	void LevelOrder(TreeNode<T>* node);

	//递归方式求树的深度
	int GetHight_Recursive(TreeNode<T> *subtree) const;

	//获取节点的度
	int GetDegree(TreeNode<T> *Node);

	//非递归方式求树的深度
	int GetHight();

	//获取节点所在的深度
	int GetNodeHeight(TreeNode<T> *Node);

	//通过遍历的方式获取二叉树中的结点个数
	int GetSize();

	//获取叶节点的个数
	int GetLeaveSize();

	//获取根结点
	TreeNode<T> *GetRoot() const;

	//查找二叉树中数据元素
	TreeNode<T> *Search(T &item);

	//在指定节点后插入
	bool Insert(TreeNode<T> *ParentNode,TreeNode<T> *ChildNode,FLAG child=LEFT);

	//修改指定元素的数据域
	bool Modify(TreeNode<T> *Node, T &Data);

	//输出形式
	void OutputFormat();

	//判断二叉树同构的API,参数为二叉树根结点
	bool Isomorphic(const BinaryTree<T> &tree);
};

//-------------------------------------------------------内部封装方法------------------------------------------------------
template<class T>
inline bool BinaryTree<T>::Isomorphic_P(const TreeNode<T>* Root1, const TreeNode<T>* Root2)
{
	//情形一：两者皆为空
	if (Root1 == nullptr && Root2 == nullptr) return true;

	//情形二：一个为空，一个不为空
	if ((Root1 == nullptr && Root2 != nullptr) || (Root1 != nullptr && Root2 == nullptr)) return false;

	//情形三:两者根结点不同
	if (Root1->data != Root2->data) return false;

	//情形四：左子树均为空,比较右子树是否同构
	if (Root1->leftchild == nullptr && Root2->leftchild == nullptr)
		return Isomorphic_P(Root1->rightchild, Root2->rightchild);

	//情形五：左子树不为空，且左孩子相同
	if (Root1->leftchild != nullptr && Root2->leftchild != nullptr && Root1->leftchild->data == Root2->leftchild->data)
		return (Isomorphic_P(Root1->leftchild, Root2->leftchild) && Isomorphic_P(Root1->rightchild, Root2->rightchild));

	//情形六：左子树不为空，且左孩子不同
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
		//创建新节点
		newnode = new TreeNode<T>();
		//复制节点内容
		newnode->data = Root->data;
		//复制prarent指针
		newnode->parent = cur;
		//复制左子树
		newnode->leftchild = CopyTree(Root->leftchild, newnode);
		//复制右子树
		newnode->rightchild = CopyTree(Root->rightchild, newnode);
	}
	return newnode;
}

template<class T>
inline void BinaryTree<T>::CreateBinaryTree1()
{
	cout << "正在执行二叉树的创建过程..." << endl;

	cout << "请输入空结点标志:";
	T Symbol;
	cin >> Symbol;

	cout << "请输入二叉树的深度：";
	int n;
	cin >> n;


	TreeNode<T> *cur;
	Queue<TreeNode<T> *> q(20);

	//第一层
	cout << "请输入第1层的节点数据(为空则输入子定义标志)：" << endl;
	T tem;
	cin >> tem;
	cur = new TreeNode<T>(tem);
	root = cur;
	q.push(cur);

	//二层及以上
	for (int i = 2; i <= n; i++)
	{
		cout << "请输入第" << i << "层的节点数据(为空则输入子定义标志)：" << endl;

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

	//第一层
	T tem;
	cin >> tem;
	cur = new TreeNode<T>(tem);
	root = cur;
	q.push(cur);

	//二层及以上
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
	//前序确定根结点、子树根结点
	//中序确定左右子树
	//不断使用左右子树递归获得结果

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
//--------------------------------------------------------外部 API--------------------------------------------------------
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
	//思考，算法：一路向左，根结点输出，右儿子压栈
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
	int height=log2(NodeNum)+1;//当n>0时  深度=[log_2(n)]+1  n为节点个数

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


