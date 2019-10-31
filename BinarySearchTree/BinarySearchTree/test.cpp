#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include <algorithm>
#include "BinarySearchTree.h"
using namespace std;

vector<int> RandomMotor(int Range,int Num)
{
	vector<int> tem;
	for (int i = 1; i <= Range; i++)
	{
		tem.push_back(i);
	}

	random_shuffle(tem.begin(), tem.end());
	
	tem.resize(Num);

	return tem;
}

void Sort(vector<int> &v)
{
	set<int> mySet(v.begin(),v.end());
	v.assign(mySet.begin(), mySet.end());
}

int Binary_search(vector<int> v, int number)
{
	int low = 0, high = v.size() - 1;
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (v[mid] < number)
			low = mid + 1;
		else if (v[mid] > number)
			high = mid - 1;
		else
			return mid;
	}
	return -1;

}


int main()
{
	//���캯��  Inset()  OutputFormat()
	string path = "data.txt";
	BinarySearchTree<int> tree(path);
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

	cout << "����������API������ɣ�" << endl << endl;

//--------------------------------------------------���������-------------------------------------------------------------
	vector<int> Num;
	int n, range;
	cout << "���������������ķ�Χ��1~";
	cin >> range;
	cout << "����������ĸ�����";
	cin >> n;
	Num = RandomMotor(range,n);
	cout << "��������������£�" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << Num[i] << "  ";
	}
	cout << endl << endl;

	cout << "�����������Ԫ��:";
	int toSearch;
	cin >> toSearch;
	cout << endl;

//------------------------------------------------------------------------------------------------------------------------
	clock_t start, end, time;

	BinarySearchTree<int> Tree(false);
	for (int i = 0; i < n; i++)
	{
		Tree.Insert(Num[i]);
	}
	cout << "����������������������" << endl;
	start = clock();

	BSTNode<int> *Tem = Tree.Search(toSearch);
	if (Tem == nullptr)
		cout << "�Ҳ�����Ԫ��" << endl;
	else
		cout << "���ҵ�" <<Tem->show() << "Ԫ��" << endl;

	end = clock();
	time = end - start;
	cout << "����" << time << "ms" << endl;

//------------------------------------------------------------------------------------------------------------------------
	Sort(Num);//����
	cout << "����һ�����ַ�����" << endl;
	start = clock();

	int index = Binary_search(Num, toSearch);
	if (index == -1)
		cout << "�Ҳ�����Ԫ��" << endl;
	else
		cout << "��Ԫ��λ�ڵ�" << index + 1 << "λ��" << endl;

	end = clock();
	time = end - start;
	cout << "����" << time << "ms" << endl;





	cin.get();
	cin.get();
	return 0;
}