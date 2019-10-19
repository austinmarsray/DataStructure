/*基于自写栈的括号匹配的方法集合
*作者：雷海星
*时间:2019年9月22日
*/
#include <string>
#include "Stack.h"
using namespace std;

//错误更正：之前没加inline，显示链接错误：link2005
//两种方案更改：
//1.加inline
//2.头文件定义，cpp文件实现

//判断括号是否匹配
inline bool IsParenthesesMatched(string primary)
{
	string symbol;

	//原始字符串----->只含括号的字符串
	for (int i = 0; i < primary.length(); i++)
	{
		if (primary[i] == '(' || primary[i] == '[' || primary[i] == '{' || primary[i] == ')' || primary[i] == ']' || primary[i] == '}')
		{
			symbol += primary[i];
		}
	}

	//括号匹配判断
	Stack<char> stack;
	for (int i = 0; i < symbol.length(); i++)
	{
		//若为左括号直接入栈
		if (symbol[i] == '(' || symbol[i] == '[' || symbol[i] == '{')
		{
			stack.push(symbol[i]);
		}
		else
		{
			//若为右括号且栈空，此时不匹配
			if (true==stack.IsEmpty())
			{
				return false;
			}
			else
			{
				//若为右括号栈非空，但左右括号不匹配，则结果不匹配
				char topchar = stack.pop();
				if ((topchar == '('&&symbol[i] == ')') || (topchar == '['&&symbol[i] == ']') || (topchar == '{'&&symbol[i] == '}'))
					continue;
				else
					return false;
			}
		}
		
	}
	//所有元素已遍历，若栈中有元素，则不匹配；若栈空，则括号匹配
	return stack.IsEmpty();
}


//时间复杂度O(n)的最大括号匹配（源码为Java，自改为C++）
/*
public static int longestMatch(String str)
    {
	  if(str==null||str.length()==0)
		return 0;
	  char chs[]=str.toCharArray();
	  Stack<Integer> stack=new Stack<Integer>();
	  //注意这种方法只能判断一种类型的左右括号，不能同时判断两种及以上的左右括号。
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