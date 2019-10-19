/*������дջ������ƥ��ķ�������
*���ߣ��׺���
*ʱ��:2019��9��22��
*/
#include <string>
#include "Stack.h"
using namespace std;

//���������֮ǰû��inline����ʾ���Ӵ���link2005
//���ַ������ģ�
//1.��inline
//2.ͷ�ļ����壬cpp�ļ�ʵ��

//�ж������Ƿ�ƥ��
inline bool IsParenthesesMatched(string primary)
{
	string symbol;

	//ԭʼ�ַ���----->ֻ�����ŵ��ַ���
	for (int i = 0; i < primary.length(); i++)
	{
		if (primary[i] == '(' || primary[i] == '[' || primary[i] == '{' || primary[i] == ')' || primary[i] == ']' || primary[i] == '}')
		{
			symbol += primary[i];
		}
	}

	//����ƥ���ж�
	Stack<char> stack;
	for (int i = 0; i < symbol.length(); i++)
	{
		//��Ϊ������ֱ����ջ
		if (symbol[i] == '(' || symbol[i] == '[' || symbol[i] == '{')
		{
			stack.push(symbol[i]);
		}
		else
		{
			//��Ϊ��������ջ�գ���ʱ��ƥ��
			if (true==stack.IsEmpty())
			{
				return false;
			}
			else
			{
				//��Ϊ������ջ�ǿգ����������Ų�ƥ�䣬������ƥ��
				char topchar = stack.pop();
				if ((topchar == '('&&symbol[i] == ')') || (topchar == '['&&symbol[i] == ']') || (topchar == '{'&&symbol[i] == '}'))
					continue;
				else
					return false;
			}
		}
		
	}
	//����Ԫ���ѱ�������ջ����Ԫ�أ���ƥ�䣻��ջ�գ�������ƥ��
	return stack.IsEmpty();
}


//ʱ�临�Ӷ�O(n)���������ƥ�䣨Դ��ΪJava���Ը�ΪC++��
/*
public static int longestMatch(String str)
    {
	  if(str==null||str.length()==0)
		return 0;
	  char chs[]=str.toCharArray();
	  Stack<Integer> stack=new Stack<Integer>();
	  //ע�����ַ���ֻ���ж�һ�����͵��������ţ�����ͬʱ�ж����ּ����ϵ��������š�
	  int i=0,last=-1,max_len=0;
	  while(i<chs.length)
	  {
		if(chs[i]=='(')
		{
		    stack.push(i);
		}
		else {
		    if(stack.isEmpty())
		    {
			  last=i;
		    }
		    else {
			  stack.pop();
			  if(stack.isEmpty())
			  max_len=Math.max(max_len, i-last);
			  else {
				max_len=Math.max(max_len, i-stack.peek());
			  }
		    }
		}
		i++;
	  }
	  return max_len;
    }*/