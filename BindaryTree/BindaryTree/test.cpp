#include <iostream>
#include "MyDate.h"
#include "BindaryTree.h"
using namespace std;


int main()
{
	cout << "基本类型（char）测试" << endl;
	BinaryTree<char> tree1("data.txt");

	cout << "前序遍历结果：(前为非递归，后为递归)" << endl;
	tree1.PreOrder(tree1.GetRoot());
	cout << endl;
	tree1.PreOrder_Recursive(tree1.GetRoot());
	cout << endl << endl;

	cout << "中序遍历结果：(前为非递归，后为递归)" << endl;
	tree1.InOrder(tree1.GetRoot());
	cout << endl;
	tree1.InOrder_Recursive(tree1.GetRoot());
	cout << endl << endl;

	cout << "后序遍历结果：(前为非递归，后为递归)" << endl;
	tree1.PostOrder(tree1.GetRoot());
	cout << endl;
	tree1.PostOrder_Recursive(tree1.GetRoot());
	cout << endl << endl;

	cout << "层序遍历结果：" << endl;
	tree1.LevelOrder(tree1.GetRoot());
	cout << endl << endl;


	cout << "----------------------------------------------------" << endl;
	cout << "复合类型（MyDate）测试：" << endl;


	//构造函数 OutputFormat()
	BinaryTree<MyDate> tree2("data2.txt");
	tree2.OutputFormat();

	cout << "前序遍历结果：(前为非递归，后为递归)" << endl;
	tree2.PreOrder(tree2.GetRoot());
	cout << endl;
	tree2.PreOrder_Recursive(tree2.GetRoot());
	cout << endl << endl;

	cout << "中序遍历结果：(前为非递归，后为递归)" << endl;
	tree2.InOrder(tree2.GetRoot());
	cout << endl;
	tree2.InOrder_Recursive(tree2.GetRoot());
	cout << endl << endl;

	cout << "后序遍历结果：(前为非递归，后为递归)" << endl;
	tree2.PostOrder(tree2.GetRoot());
	cout << endl;
	tree2.PostOrder_Recursive(tree2.GetRoot());
	cout << endl << endl;

	cout << "层序遍历结果：" << endl;
	tree2.LevelOrder(tree2.GetRoot());
	cout << endl << endl;

	cout << "二叉树的深度为：";
	cout << tree2.GetHight() << endl << endl;

	cout << "二叉树的结点数为：";
	cout << tree2.GetSize() << endl << endl;

	cout << "二叉树的叶结点数为：";
	cout << tree2.GetLeaveSize() << endl << endl;

	MyDate oct_1(2019, 10, 1);
	MyDate oct_6(2019, 10, 6);
	MyDate oct_10(2019, 10, 10);
	MyDate oct_11(2019, 10, 11);

	//API：Search() Modify()
	cout << "搜索+修改结果：" << endl;
	TreeNode<MyDate> *node = tree2.Search(oct_1);
	tree2.Modify(node, oct_10);
	tree2.OutputFormat();
	cout << endl;

	//API:Insert(）
	cout << "搜索+插入结果：" << endl;
	TreeNode<MyDate> *newnode;
	newnode = new TreeNode<MyDate>(oct_11);
	node = tree2.Search(oct_6);
	tree2.Insert(node, newnode, LEFT);
	tree2.OutputFormat();
	cout << endl;

	//API:GetDegree() GetNodeHeight()
	cout << "指定节点的度为：" << tree2.GetDegree(node) << endl;
	cout << "指定节点的深度为：" << tree2.GetNodeHeight(node) << endl <<endl;

	//API:DestroyNode()
	cout << "搜索+删除结果：" << endl;
	node = tree2.Search(oct_6);
	tree2.DestroyNode(node);
	tree2.OutputFormat();
	cout << endl;

	//API:DestroyTree() IsEmpty()
	tree2.DestroyTree();
	if (tree2.IsEmpty()) cout << "二叉树为空。" << endl << endl;
	else cout << "二叉树非空。" << endl << endl;

	cout << "----------------------------------------------------" << endl;
	cout << "拷贝构造函数、前中构造、输出格式测试：" << endl;

	//拷贝构造函数 OutputFormat()
	BinaryTree<char> tree3("data.txt");
	tree3.OutputFormat();
	BinaryTree<char> tree4(tree3);
	tree4.OutputFormat();
	cout << tree3.Isomorphic(tree4) << endl << endl;

	//构造函数 通过前序+中序确定二叉树
	int pre[8] = { 1,2,4,7,3,5,6,8 };
	int in[8] = { 4,7,2,1,5,3,8,6 };
	BinaryTree<int> tree5(pre, in, 8);
	tree5.OutputFormat();

	cin.get();
	cin.get();
	return 0;
}