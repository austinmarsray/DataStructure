#include <iostream>
#include <string>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
	//构造函数  Inset()  OutputFormat()
	BinarySearchTree<int> tree("data.txt");
	tree.OutputFormat();

	//GetMax()  GetMin()
	cout << tree.GetMax() << endl;
	cout << tree.GetMin() << endl << endl;

	//GetNodeHeght() GetMinNode()  Search() GetSize() GetSize() GetDegree()
	cout << "树的结点个数为" << tree.GetSize() << endl;
	cout << "树的深度为" << tree.GetHeight() << endl;
	BSTNode<int> *tem = tree.Search(10);
	cout << "指定节点的深度为" << tree.GetNodeHeight(tree.GetMinNode(tem)) << endl;
	cout << "指定节点的度为" << tree.GetDegree(tem) << endl << endl;


	//Delete()  GetParent()  GetMaxNode()
	tree.Delete(tree.Search(20));
	tree.OutputFormat();


	cin.get();
	cin.get();
	return 0;
}