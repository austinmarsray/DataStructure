#include <iostream>
#include <iomanip>
#include <string>
#include "Queue.h"
#include "MyDate.h"
using namespace std;

//���ڸ�ʽ���
Queue<int> buff(10000);

void print_yang_triangle(int line_num)
{
	int SIZE;
	int MAXNUM;

	Queue<int> q(100);

	int s = 0, t,u;
	int pri_1 = 1, pri_0 = 0;
	q.push(pri_1); q.push(pri_1);

	for (int i = 1; i <= line_num; i++)
	{
		//ÿһ������0��ӣ����зָ�
		q.push(pri_0);

		for (int j = 1; j <= i + 2; j++)
		{
			//t�Ƕ��еĵ�ǰֵ
			t = q.pop();
			buff.push(t);
			u = s + t;
			q.push(u);

			//�ж����ֵ��λ��
			if (i == line_num && j == ((i + 1) / 2) + 1)
			{
				MAXNUM = t;
				string tem = to_string(MAXNUM);
				SIZE = tem.length();
			}
			
			//s����һ��ֵ
			s = t;
		}

	}
	//��ʽ���
	int line = 1;
	while (buff.IsEmpty() != true)
	{
		for (int i = 0; i < line_num - line; i++)
		{
			cout << setw(SIZE) << "";
		}
		while (buff.front() != 0)
		{
			cout << setiosflags(ios::left) << setw(SIZE) << buff.pop() << setw(SIZE) << "";
		}		
		buff.pop();
		line++;
		cout << endl;
	}
}


int main()
{
	Queue<int> q1;

	cout << q1.IsEmpty() << endl;
	cout << "API:IsEmpty() works well." << endl << endl;


	Queue<MyDate> q2("data.txt");
	cout << "����" << q2.size() << "������Ԫ�ء�" << endl;
	cout << "API:push() works well." << endl;
	cout << "API:Queue(string) works well." << endl;
	cout << "API:size() works well." << endl << endl;

	cout << q2.front() << endl;
	cout << "API:front() works well." << endl << endl;

	for (int i = 1; i <= 5; i++)
	{
		cout << q2.pop() << endl;
	}
	cout << "API:pop() works well." << endl << endl;

	cout << q2.IsFull() << endl;
	cout << "API:IsFull() works well." << endl << endl;


	cout << "���ԣ���ӡ�������" << endl;
	cout << "���������ӡ��������" ;
	int n;
	cin >> n;
	print_yang_triangle(n);


	cin.get();
	cin.get();

	return 0;
}