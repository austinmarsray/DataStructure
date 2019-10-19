#ifndef _TREENODE_H_
#define _TREENODE_H_

template<class T>
class TreeNode
{
private:
	//数据域
	T data;
	//指针域
	TreeNode<T> *parent, *leftchild, *rightchild;
public:
	TreeNode()
	{
		parent = nullptr;
		leftchild = nullptr;
		rightchild = nullptr;
	}
	TreeNode(const T &Data)
	{
		data = Data;
		parent = nullptr;
		leftchild = nullptr;
		rightchild = nullptr;
	}
	//TreeNode(const TreeNode &node)
	//{
	//	//调试时记得验证指针指向的地址是否一致，如果不一致，后续操作有误
	//	data = node.data;

	//	parent = node.parent;
	//	leftchild = node.leftchild;
	//	rightchild = node.rightchild;
	//}
	~TreeNode()
	{
		delete parent, leftchild, rightchild;
	}

	template<class T> friend class BinaryTree;
};
#endif // !_TREENODE_H_