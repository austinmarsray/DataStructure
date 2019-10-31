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
	//构造函数  Inset()  OutputFormat()
	string path = "data.txt";
	BinarySearchTree<int> tree(path);
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

	cout << "二叉搜索树API测试完成！" << endl << endl;

//--------------------------------------------------产生随机数-------------------------------------------------------------
	vector<int> Num;
	int n, range;
	cout << "请输入产生随机数的范围：1~";
	cin >> range;
	cout << "产生随机数的个数：";
	cin >> n;
	Num = RandomMotor(range,n);
	cout << "产生的随机数如下：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << Num[i] << "  ";
	}
	cout << endl << endl;

	cout << "请输入待查找元素:";
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
	cout << "方案二：二叉搜索树搜索" << endl;
	start = clock();

	BSTNode<int> *Tem = Tree.Search(toSearch);
	if (Tem == nullptr)
		cout << "找不到该元素" << endl;
	else
		cout << "已找到" <<Tem->show() << "元素" << endl;

	end = clock();
	time = end - start;
	cout << "花费" << time << "ms" << endl;

//------------------------------------------------------------------------------------------------------------------------
	Sort(Num);//排序
	cout << "方案一：二分法搜索" << endl;
	start = clock();

	int index = Binary_search(Num, toSearch);
	if (index == -1)
		cout << "找不到该元素" << endl;
	else
		cout << "该元素位于第" << index + 1 << "位置" << endl;

	end = clock();
	time = end - start;
	cout << "花费" << time << "ms" << endl;





	cin.get();
	cin.get();
	return 0;
}