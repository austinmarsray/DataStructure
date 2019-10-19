#include <iostream>
#include "Stack.h"
#include "ParenthesesMatching .h"
#include "ExpressionCalculating.h"
using namespace std;



int main()
{
	cout << "����ע�����" << endl;
	cout << "1.�ݲ�֧�ִ��ո񡢻س����Ʊ�����ַ������룻" << endl;
	cout << "2.Ŀǰֻ֧��һλ���ļӼ��˳�����λ������������ʱ�䲻�㽫�ں�������ʵ�֣�" << endl;
	cout << "3.�ڽ�������ƥ��ͱ��ʽ����ʱ���������ĵ����Ŷ����ܵò���Ԥ�ڵĽ����" << endl << endl;

	cout << "����1��ʹ�ø�ջ���һ���ַ������������" << endl;
	Stack<char> reverse(20);
	string tok;

	cin >> tok;
	for (int i = 0; i < tok.length(); i++)
	{
		reverse.push(tok[i]);
	}

	cout << reverse;
	cout << "����1��ϡ�" << endl;

	cout << "����2:�ļ��������" << endl;
	Stack<int> testFile;
	testFile.readFromFile("data.txt");
	cout << testFile;
	cout << "����2��ϡ�" << endl;


	cout << "����3:����ƥ��" << endl;
	string str;
	//getline(cin, expression);
	cin >> str;
	//cin.getline(expression);
	if (IsParenthesesMatched(str) == true)
	{
		cout << "����ƥ�䣡" << endl;
	}
	else
	{
		cout << "���Ų�ƥ�䣡" << endl;
	}
	cout << "����3��ϡ�" << endl;


	cout << "����4:���ʽ����" << endl;
	string expression;
	cin >> expression;

	double ans;
	ans = calculate(toRPN(expression));
	cout << "���" << ans << endl;

	cout << "����4��ϡ�" << endl;

	cin.get();
	cin.get();

	return 0;
}