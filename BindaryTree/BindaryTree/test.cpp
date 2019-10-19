#include <iostream>
#include "MyDate.h"
#include "BindaryTree.h"
using namespace std;


int main()
{
//#define __Debug1__
#define __Debug2__
#ifdef  __Debug1__
	cout << "基本类型（char）测试" << endl;
	BinaryTree<char> tree("data.txt");

	cout << "前序遍历结果：(前为非递归，后为递归)" << endl;
	tree.PreOrder(tree.GetRoot());
	cout << endl;
	tree.PreOrder_Recursive(tree.GetRoot());
	cout << endl << endl;

	cout << "中序遍历结果：(前为非递归，后为递归)" << endl;
	tree.InOrder(tree.GetRoot());
	cout << endl;
	tree.InOrder_Recursive(tree.GetRoot());
	cout << endl << endl;

	cout << "后序遍历结果：(前为非递归，后为递归)" << endl;
	tree.PostOrder(tree.GetRoot());
	cout << endl;
	tree.PostOrder_Recursive(tree.GetRoot());
	cout << endl << endl;

	cout << "层序遍历结果：" << endl;
	tree.LevelOrder(tree.GetRoot());
	cout << endl << endl;


	cout << "----------------------------------------------------" << endl;
	cout << "复合类型（MyDate）测试：" << endl;


	//构造函数 OutputFormat()
	BinaryTree<MyDate> mytree("data2.txt");
	mytree.OutputFormat();

	cout << "前序遍历结果：(前为非递归，后为递归)" << endl;
	mytree.PreOrder(mytree.GetRoot());
	cout << endl;
	mytree.PreOrder_Recursive(mytree.GetRoot());
	cout << endl << endl;

	cout << "中序遍历结果：(前为非递归，后为递归)" << endl;
	mytree.InOrder(mytree.GetRoot());
	cout << endl;
	mytree.InOrder_Recursive(mytree.GetRoot());
	cout << endl << endl;

	cout << "后序遍历结果：(前为非递归，后为递归)" << endl;
	mytree.PostOrder(mytree.GetRoot());
	cout << endl;
	mytree.PostOrder_Recursive(mytree.GetRoot());
	cout << endl << endl;

	cout << "层序遍历结果：" << endl;
	mytree.LevelOrder(mytree.GetRoot());
	cout << endl << endl;

	cout << "二叉树的深度为：";
	cout << mytree.GetHight() << endl << endl;

	cout << "二叉树的结点数为：";
	cout << mytree.GetSize() << endl << endl;

	cout << "二叉树的叶结点数为：";
	cout << mytree.GetLeaveSize() << endl << endl;

	MyDate oct_1(2019, 10, 1);
	MyDate oct_6(2019, 10, 6);
	MyDate oct_10(2019, 10, 10);
	MyDate oct_11(2019, 10, 11);

	//API：Search() Modify()
	cout << "搜索+修改结果：" << endl;
	TreeNode<MyDate> *node = mytree.Search(oct_1);
	mytree.Modify(node, oct_10);
	mytree.OutputFormat();
	cout << endl;

	//API:Insert(）
	cout << "搜索+插入结果：" << endl;
	TreeNode<MyDate> *newnode;
	newnode = new TreeNode<MyDate>(oct_11);
	node = mytree.Search(oct_6);
	mytree.Insert(node, newnode, LEFT);
	mytree.OutputFormat();
	cout << endl;

	//API:GetDegree() GetNodeHeight()
	cout << "指定节点的度为：" << mytree.GetDegree(node) << endl;
	cout << "指定节点的深度为：" << mytree.GetNodeHeight(node) << endl <<endl;

	//API:DestroyNode()
	cout << "搜索+删除结果：" << endl;
	node = mytree.Search(oct_6);
	mytree.DestroyNode(node);
	mytree.OutputFormat();
	cout << endl;

	//API:DestroyTree() IsEmpty()
	mytree.DestroyTree();
	if (mytree.IsEmpty()) cout << "二叉树为空。" << endl << endl;
	else cout << "二叉树非空。" << endl << endl;
#endif //  __Debug1__

#ifdef  __Debug2__
	//构造函数 OutputFormat()
	BinaryTree<char> mytree("data.txt");
	mytree.OutputFormat();
	BinaryTree<char> mytree2(mytree);
	mytree2.OutputFormat();

	cout << mytree.Isomorphic(mytree2);
#endif //  __Debug2__

	cin.get();
	cin.get();
	return 0;
}