#include <iostream>
#include <atlbase.h>
using namespace std;
/*class MyDate isn't function well.
 *
 *MyDate is still in lack of some API to fix it.  
 * 
 * this class was coded to finish the test of sequentiallist.
 * 
 * it can set value and make comparesion.
 */

class MyDate
{
    private:
        int year;
        int month;
        int day;
    public:
        MyDate(int year_ = 1970, int month_ = 1, int day_ = 1)
        {
            year = year_;
            month = month_;
            day = day_;
        }
        MyDate(MyDate &x)
        {
            year = x.year;
            month = x.month;
            day = x.day;
        }
        ~MyDate(){}

        void setDate(int year_, int month_,int day_)
        {
            year = year_;
            month = month_;
            day = day_;
        }

        bool operator==(MyDate &x)
        {
            if (year == x.year && month == x.month && day == x.day)
                return true;
            else
                return false;
        }
        
        bool operator>(MyDate &x)
        {
            if (year > x.year)
                return true;
            else if (year == x.year && month > x.month)
                return true;
            else if (year == x.year && month == x.month && day > x.day)
                return true;
            else
                return false;
        }
        
        bool operator<(MyDate &x)
        {
            if (year < x.year)
                return true;
            else if (year == x.year && month < x.month)
                return true;
            else if (year == x.year && month == x.month && day < x.day)
                return true;
            else
                return false;
        }

        bool operator<=(MyDate &x)
        {
            MyDate tem(year, month, day);
            if (tem == x)
                return true;
            else if (tem < x)
                return true;
            else
                return false;
        }

        bool operator>=(MyDate &x)
        {
            MyDate tem(year, month, day);
            if (tem == x)
                return true;
            else if (tem > x)
                return true;
            else
                return false;
        }

        friend ostream &operator<<(ostream &os,const MyDate &x)
        {
            os << x.year << "/" << x.month << "/" << x.day;
            return os;
        }
        friend istream &operator>>(istream &is,MyDate &x)
        {
            //char sideline;
            //is >> x.year >> sideline >> x.month >> sideline >> x.day;
            //return is;

		  char date[11];
		  is >> date;

		  int num=0;
		  while (date[num] != '\0')
		  {
			  num++;
		  }


		  x.year = 0; x.month = 0; x.day = 0;
		  int mark=0,flag=0;
		  for (int i = 0; i < num; i++)
		  {
			  if (date[i] == '/')
			  {
				  if (flag == 1)
				  {
					  flag++;
					  for (int j = mark + 1; j < i; j++)
					  {
						  x.month = 10 * x.month + (date[j] - '0');
					  }
					  mark = i;
				  }
				  if (flag == 0)
				  {
					  mark = i;
					  flag++;
					  for (int j = 0; j < i; j++)
					  {
						  x.year = 10 * x.year + (date[j] - '0');
					  }
				  }
			  }
			  if (flag == 2)
			  {
				  flag++;
				  for (int j = mark + 1; j < num; j++)
				  {
					  x.day = 10 * x.day + (date[j] - '0');
				  }
			  }
		  }
		  return is;
        }
};