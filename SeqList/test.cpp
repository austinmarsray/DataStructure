#include "MyDate.h"
#include "SeqList.h"
#include <iostream>
using namespace std;


int main()
{
    SeqList<MyDate> date(15);

    //API:IsEmpty()
    if (date.IsEmpty() == true)
    {
        cout << "Function:IsEmpty() works well." << endl;
    }

    //API:getSize()
    cout << "Object has " << date.getSize() << " space(s)." << endl
         << "Function:getSize() works well." << endl;
    
    //API:readFromFile()
    date.readFromFile();
    date.output();
    cout << "Function:readFromFile() works well." << endl;
    cout << "Function:output() works well." << endl;

    //API:Add()
    MyDate sep_9_11(2019, 9, 11);
    MyDate sep_9_12(2019, 9, 12);
    MyDate sep_9_13(2019, 9, 13);
    MyDate sep_9_14(2019, 9, 14);
    MyDate sep_9_15(2019, 9, 15);
    date.Add(sep_9_11);

    //API:output()
    date.output();
    cout << "Function:Add() works well." << endl;

    //API:getLength()
    cout << "Object has " << date.getLength() << " element(s)." << endl
         << "Function:getLength() works well." << endl;

    //API:Insert()
    date.Insert(3, sep_9_12);
    date.InsertBefore(sep_9_12, sep_9_13);
    date.Insert(7, sep_9_14);
    date.InsertAfter(sep_9_14, sep_9_15);
    date.output();
    cout << "Function:Insert() works well." << endl;

    //API:IsFull()
    if(date.IsFull()==true)
    {
        cout << "Function:IsFull() works well." << endl;
    }

    //API:Sort()
    date.Sort();
    date.output();
    cout << "Function:Sort() works well." << endl;

    //API:Search()
    cout << "The element locates in the " << date.Search(sep_9_13) << "th of the SequentialList." << endl;
    cout << "Function:Search() works well." << endl;

    //API:getData()
    MyDate feedback;
    if(date.getData(5,feedback))
    cout << "The 5th element is " << feedback << "." << endl;
    cout << "Function:getData() works well." << endl;

    //API:setData()
    MyDate tem(2019, 12, 12);
    date.setData(5, tem);
    date.output();
    cout << "Function:setData() works well." << endl;

    //API:Remove()
    date.Remove(5);
    date.output();
    cout << "The 5th element has been removed."<<endl;
    date.Remove(sep_9_15);
    date.output();
    cout << "The element 2019/9/15 has been removed."<<endl;
    cout << "Function:Remove() works well." << endl;

    //API:writeToFile()
    date.writeToFile();
    cout << "Function:writeToFile() works well." << endl;

    return 0;
}
