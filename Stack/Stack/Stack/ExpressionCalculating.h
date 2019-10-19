#include "Stack.h"
#include <iostream>
using namespace std;

/*基于自写栈的表达式计算
*作者：雷海星
*时间:2019年9月22日
*改进方案:
*1.多位数的计算
*2.增强健壮性，针对错误输入报警
*/

inline string toRPN(string &expression)
{
	string RPN;

	Stack<char> Operator;
	for (int i = 0; i < expression.length(); i++)
	{
		//数字直接加RPN表达式
		if ('0' <= expression[i] && expression[i] <= '9')
		{
			RPN += expression[i];
		}
		//'(' 直接压栈
		else if (expression[i] == '(')
		{
			Operator.push(expression[i]);
		}
		//遇到')',循环弹出栈顶元素，知道遇到'('停止
		else if (expression[i] == ')')
		{
			while (1)
			{
				if (Operator.getTop() == '(')
				{
					Operator.pop();
					break;
				}

				RPN += Operator.pop();
			}
		}
		//乘除运算在四则运算中优先级较高，直接入栈
		else if (expression[i] == '*' || expression[i] == '/')
		{
			while (1)
			{
				if (Operator.getTop() == '*' || Operator.getTop() == '/')
				{
					RPN += Operator.pop();
				}
				else
				{
					Operator.push(expression[i]);
					break;
				}
			}
		}


		//加减运算优先级低，需要先和栈顶元素比较，若为乘除，则弹出栈顶元素，直到入栈
		else if (expression[i] == '-' || expression[i] == '+')
		{
			while (1)
			{
				//if (Operator.getTop() == '*' || Operator.getTop() == '/' || Operator.getTop() == '-' || Operator.getTop() == '+')
				if(Operator.IsEmpty()==true || Operator.getTop()=='(')
				{
					Operator.push(expression[i]);
					break;
				}
				else
				{
					RPN += Operator.pop();
				}
			}
		}

		
	}
	for (int i = 1; i <= Operator.getSize(); i++)
	{
		RPN += Operator.pop();
	}

	return RPN;

#ifdef __DEBUG__
	cout << RPN;
#endif

}

inline double calculate(string RPN)
{
	Stack<double> cal;
	for (int i = 0; i < RPN.length(); i++)
	{
		if ('0' <= RPN[i] && RPN[i] <= '9')
		{
			double tem = RPN[i] - '0';
			cal.push(tem);
		}
		else
		{
			double num1 = cal.pop();
			double num2 = cal.pop();
			double ans;
			if (RPN[i] == '-') ans = num2 - num1;
			else if (RPN[i] == '+') ans = num2 + num1;
			else if (RPN[i] == '*') ans = num2 * num1;
			else if (RPN[i] == '/') ans = num2 / num1;
			cal.push(ans);
		}
	}

	return cal.pop();
}
