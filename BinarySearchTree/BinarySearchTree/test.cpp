#include <iostream>
#include <string>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
	//���캯��  Inset()  OutputFormat()
	BinarySearchTree<int> tree("data.txt");
	tree.OutputFormat();

	//GetMax()  GetMin()
	cout << tree.GetMax() << endl;
	cout << tree.GetMin() << endl << endl;

	//GetNodeHeght() GetMinNode()  Search() GetSize() GetSize() GetDegree()
	cout << "���Ľ�����Ϊ" << tree.GetSize() << endl;
	cout << "�������Ϊ" << tree.GetHeight() << endl;
	BSTNode<int> *tem = tree.Search(10);
	cout << "ָ���ڵ�����Ϊ" << tree.GetNodeHeight(tree.GetMinNode(tem)) << endl;
	cout << "ָ���ڵ�Ķ�Ϊ" << tree.GetDegree(tem) << endl << endl;


	//Delete()  GetParent()  GetMaxNode()
	tree.Delete(tree.Search(20));
	tree.OutputFormat();


	cin.get();
	cin.get();
	return 0;
}