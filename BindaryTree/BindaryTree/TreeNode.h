#ifndef _TREENODE_H_
#define _TREENODE_H_

template<class T>
class TreeNode
{
private:
	//������
	T data;
	//ָ����
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
	//	//����ʱ�ǵ���ָ֤��ָ��ĵ�ַ�Ƿ�һ�£������һ�£�������������
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