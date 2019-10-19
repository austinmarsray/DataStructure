#include <iostream>
#include "MyDate.h"
#include "BindaryTree.h"
using namespace std;


int main()
{
//#define __Debug1__
#define __Debug2__
#ifdef  __Debug1__
	cout << "�������ͣ�char������" << endl;
	BinaryTree<char> tree("data.txt");

	cout << "ǰ����������(ǰΪ�ǵݹ飬��Ϊ�ݹ�)" << endl;
	tree.PreOrder(tree.GetRoot());
	cout << endl;
	tree.PreOrder_Recursive(tree.GetRoot());
	cout << endl << endl;

	cout << "������������(ǰΪ�ǵݹ飬��Ϊ�ݹ�)" << endl;
	tree.InOrder(tree.GetRoot());
	cout << endl;
	tree.InOrder_Recursive(tree.GetRoot());
	cout << endl << endl;

	cout << "������������(ǰΪ�ǵݹ飬��Ϊ�ݹ�)" << endl;
	tree.PostOrder(tree.GetRoot());
	cout << endl;
	tree.PostOrder_Recursive(tree.GetRoot());
	cout << endl << endl;

	cout << "������������" << endl;
	tree.LevelOrder(tree.GetRoot());
	cout << endl << endl;


	cout << "----------------------------------------------------" << endl;
	cout << "�������ͣ�MyDate�����ԣ�" << endl;


	//���캯�� OutputFormat()
	BinaryTree<MyDate> mytree("data2.txt");
	mytree.OutputFormat();

	cout << "ǰ����������(ǰΪ�ǵݹ飬��Ϊ�ݹ�)" << endl;
	mytree.PreOrder(mytree.GetRoot());
	cout << endl;
	mytree.PreOrder_Recursive(mytree.GetRoot());
	cout << endl << endl;

	cout << "������������(ǰΪ�ǵݹ飬��Ϊ�ݹ�)" << endl;
	mytree.InOrder(mytree.GetRoot());
	cout << endl;
	mytree.InOrder_Recursive(mytree.GetRoot());
	cout << endl << endl;

	cout << "������������(ǰΪ�ǵݹ飬��Ϊ�ݹ�)" << endl;
	mytree.PostOrder(mytree.GetRoot());
	cout << endl;
	mytree.PostOrder_Recursive(mytree.GetRoot());
	cout << endl << endl;

	cout << "������������" << endl;
	mytree.LevelOrder(mytree.GetRoot());
	cout << endl << endl;

	cout << "�����������Ϊ��";
	cout << mytree.GetHight() << endl << endl;

	cout << "�������Ľ����Ϊ��";
	cout << mytree.GetSize() << endl << endl;

	cout << "��������Ҷ�����Ϊ��";
	cout << mytree.GetLeaveSize() << endl << endl;

	MyDate oct_1(2019, 10, 1);
	MyDate oct_6(2019, 10, 6);
	MyDate oct_10(2019, 10, 10);
	MyDate oct_11(2019, 10, 11);

	//API��Search() Modify()
	cout << "����+�޸Ľ����" << endl;
	TreeNode<MyDate> *node = mytree.Search(oct_1);
	mytree.Modify(node, oct_10);
	mytree.OutputFormat();
	cout << endl;

	//API:Insert(��
	cout << "����+��������" << endl;
	TreeNode<MyDate> *newnode;
	newnode = new TreeNode<MyDate>(oct_11);
	node = mytree.Search(oct_6);
	mytree.Insert(node, newnode, LEFT);
	mytree.OutputFormat();
	cout << endl;

	//API:GetDegree() GetNodeHeight()
	cout << "ָ���ڵ�Ķ�Ϊ��" << mytree.GetDegree(node) << endl;
	cout << "ָ���ڵ�����Ϊ��" << mytree.GetNodeHeight(node) << endl <<endl;

	//API:DestroyNode()
	cout << "����+ɾ�������" << endl;
	node = mytree.Search(oct_6);
	mytree.DestroyNode(node);
	mytree.OutputFormat();
	cout << endl;

	//API:DestroyTree() IsEmpty()
	mytree.DestroyTree();
	if (mytree.IsEmpty()) cout << "������Ϊ�ա�" << endl << endl;
	else cout << "�������ǿա�" << endl << endl;
#endif //  __Debug1__

#ifdef  __Debug2__
	//���캯�� OutputFormat()
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