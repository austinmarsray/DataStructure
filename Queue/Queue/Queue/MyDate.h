#include <iostream>
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
            os << x.year << " / " << x.month << " / " << x.day;
            return os;
        }
        friend istream &operator>>(istream &is,MyDate &x)
        {
            char sideline;
            is >> x.year >> sideline >> x.month >> sideline >> x.day;
            return is;
        }
};