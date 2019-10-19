#include <iostream>
#include "MyDate.h"
#include "BindaryTree.h"
using namespace std;


int main()
{
	cout << "�������ͣ�char������" << endl;
	BinaryTree<char> tree1("data.txt");

	cout << "ǰ����������(ǰΪ�ǵݹ飬��Ϊ�ݹ�)" << endl;
	tree1.PreOrder(tree1.GetRoot());
	cout << endl;
	tree1.PreOrder_Recursive(tree1.GetRoot());
	cout << endl << endl;

	cout << "������������(ǰΪ�ǵݹ飬��Ϊ�ݹ�)" << endl;
	tree1.InOrder(tree1.GetRoot());
	cout << endl;
	tree1.InOrder_Recursive(tree1.GetRoot());
	cout << endl << endl;

	cout << "������������(ǰΪ�ǵݹ飬��Ϊ�ݹ�)" << endl;
	tree1.PostOrder(tree1.GetRoot());
	cout << endl;
	tree1.PostOrder_Recursive(tree1.GetRoot());
	cout << endl << endl;

	cout << "������������" << endl;
	tree1.LevelOrder(tree1.GetRoot());
	cout << endl << endl;


	cout << "----------------------------------------------------" << endl;
	cout << "�������ͣ�MyDate�����ԣ�" << endl;


	//���캯�� OutputFormat()
	BinaryTree<MyDate> tree2("data2.txt");
	tree2.OutputFormat();

	cout << "ǰ����������(ǰΪ�ǵݹ飬��Ϊ�ݹ�)" << endl;
	tree2.PreOrder(tree2.GetRoot());
	cout << endl;
	tree2.PreOrder_Recursive(tree2.GetRoot());
	cout << endl << endl;

	cout << "������������(ǰΪ�ǵݹ飬��Ϊ�ݹ�)" << endl;
	tree2.InOrder(tree2.GetRoot());
	cout << endl;
	tree2.InOrder_Recursive(tree2.GetRoot());
	cout << endl << endl;

	cout << "������������(ǰΪ�ǵݹ飬��Ϊ�ݹ�)" << endl;
	tree2.PostOrder(tree2.GetRoot());
	cout << endl;
	tree2.PostOrder_Recursive(tree2.GetRoot());
	cout << endl << endl;

	cout << "������������" << endl;
	tree2.LevelOrder(tree2.GetRoot());
	cout << endl << endl;

	cout << "�����������Ϊ��";
	cout << tree2.GetHight() << endl << endl;

	cout << "�������Ľ����Ϊ��";
	cout << tree2.GetSize() << endl << endl;

	cout << "��������Ҷ�����Ϊ��";
	cout << tree2.GetLeaveSize() << endl << endl;

	MyDate oct_1(2019, 10, 1);
	MyDate oct_6(2019, 10, 6);
	MyDate oct_10(2019, 10, 10);
	MyDate oct_11(2019, 10, 11);

	//API��Search() Modify()
	cout << "����+�޸Ľ����" << endl;
	TreeNode<MyDate> *node = tree2.Search(oct_1);
	tree2.Modify(node, oct_10);
	tree2.OutputFormat();
	cout << endl;

	//API:Insert(��
	cout << "����+��������" << endl;
	TreeNode<MyDate> *newnode;
	newnode = new TreeNode<MyDate>(oct_11);
	node = tree2.Search(oct_6);
	tree2.Insert(node, newnode, LEFT);
	tree2.OutputFormat();
	cout << endl;

	//API:GetDegree() GetNodeHeight()
	cout << "ָ���ڵ�Ķ�Ϊ��" << tree2.GetDegree(node) << endl;
	cout << "ָ���ڵ�����Ϊ��" << tree2.GetNodeHeight(node) << endl <<endl;

	//API:DestroyNode()
	cout << "����+ɾ�������" << endl;
	node = tree2.Search(oct_6);
	tree2.DestroyNode(node);
	tree2.OutputFormat();
	cout << endl;

	//API:DestroyTree() IsEmpty()
	tree2.DestroyTree();
	if (tree2.IsEmpty()) cout << "������Ϊ�ա�" << endl << endl;
	else cout << "�������ǿա�" << endl << endl;

	cout << "----------------------------------------------------" << endl;
	cout << "�������캯����ǰ�й��졢�����ʽ���ԣ�" << endl;

	//�������캯�� OutputFormat()
	BinaryTree<char> tree3("data.txt");
	tree3.OutputFormat();
	BinaryTree<char> tree4(tree3);
	tree4.OutputFormat();
	cout << tree3.Isomorphic(tree4) << endl << endl;

	//���캯�� ͨ��ǰ��+����ȷ��������
	int pre[8] = { 1,2,4,7,3,5,6,8 };
	int in[8] = { 4,7,2,1,5,3,8,6 };
	BinaryTree<int> tree5(pre, in, 8);
	tree5.OutputFormat();

	cin.get();
	cin.get();
	return 0;
}