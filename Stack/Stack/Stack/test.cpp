#include <iostream>
#include "Stack.h"
#include "ParenthesesMatching .h"
#include "ExpressionCalculating.h"
using namespace std;



int main()
{
	cout << "测试注意事项：" << endl;
	cout << "1.暂不支持带空格、回车、制表符的字符串输入；" << endl;
	cout << "2.目前只支持一位数的加减乘除，多位数的运算由于时间不足将在后续才能实现；" << endl;
	cout << "3.在进行括号匹配和表达式计算时，输入中文的括号都可能得不到预期的结果。" << endl << endl;

	cout << "测试1：使用该栈完成一个字符串的逆序输出" << endl;
	Stack<char> reverse(20);
	string tok;

	cin >> tok;
	for (int i = 0; i < tok.length(); i++)
	{
		reverse.push(tok[i]);
	}

	cout << reverse;
	cout << "测试1完毕。" << endl;

	cout << "测试2:文件输入输出" << endl;
	Stack<int> testFile;
	testFile.readFromFile("data.txt");
	cout << testFile;
	cout << "测试2完毕。" << endl;


	cout << "测试3:括号匹配" << endl;
	string str;
	//getline(cin, expression);
	cin >> str;
	//cin.getline(expression);
	if (IsParenthesesMatched(str) == true)
	{
		cout << "括号匹配！" << endl;
	}
	else
	{
		cout << "括号不匹配！" << endl;
	}
	cout << "测试3完毕。" << endl;


	cout << "测试4:表达式计算" << endl;
	string expression;
	cin >> expression;

	double ans;
	ans = calculate(toRPN(expression));
	cout << "结果" << ans << endl;

	cout << "测试4完毕。" << endl;

	cin.get();
	cin.get();

	return 0;
}