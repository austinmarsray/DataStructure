#include "Stack.h"
#include <iostream>
using namespace std;

/*������дջ�ı��ʽ����
*���ߣ��׺���
*ʱ��:2019��9��22��
*�Ľ�����:
*1.��λ���ļ���
*2.��ǿ��׳�ԣ���Դ������뱨��
*/

inline string toRPN(string &expression)
{
	string RPN;

	Stack<char> Operator;
	for (int i = 0; i < expression.length(); i++)
	{
		//����ֱ�Ӽ�RPN���ʽ
		if ('0' <= expression[i] && expression[i] <= '9')
		{
			RPN += expression[i];
		}
		//'(' ֱ��ѹջ
		else if (expression[i] == '(')
		{
			Operator.push(expression[i]);
		}
		//����')',ѭ������ջ��Ԫ�أ�֪������'('ֹͣ
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
		//�˳��������������������ȼ��ϸߣ�ֱ����ջ
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


		//�Ӽ��������ȼ��ͣ���Ҫ�Ⱥ�ջ��Ԫ�رȽϣ���Ϊ�˳����򵯳�ջ��Ԫ�أ�ֱ����ջ
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
