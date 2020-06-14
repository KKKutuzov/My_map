#include <iostream>
#include "mymap.h"
#include <string>

using namespace std;

int main()
{
    mymap<int> t;
    int tmp;
    t.insert("element1",5);
    t.insert("item",6);
    t.insert("sometype",10);
    t.insert("data",5);
    t.insert("key",5);
    t.insert("test1",5);
    t.insert("test2",5);

    t.find("element1") == 1 ? cout << "Great we have \" element 1\"\n" :  cout << "We don't have that key.\n";
    try{
        tmp = t.GetDataTree("item");
        cout << "Key: \"item\"  Data: " << tmp << "\n";
    }
    catch(myex &a)
    {
        cout << "Exp type " <<a.id << endl;
    }
    try{
        tmp = t.GetDataTree("item___");
        cout << "Key: \"item___\"  Data: " << tmp << "\n";
    }
    catch(myex &a)
    {
        cout << "Exp type " <<a.id << endl;
    }
   t.find("random_elm") == 1 ? cout << "Great we have \" element 1\"\n" :  cout << "We don't have that key.\n";
   cout << "mymap:\n";
   t.display();
   mymap<int>::bstit it(t);
   it.next();
   cout << it.GetKey() << " " << it.GetData() << endl;
   cout << endl;
   cout << "mymap size: " << t.mysize() << endl;
   cout << endl;
   t.remove("test2");
   cout << "mymap size: "  << t.mysize() << endl;
   cout << "mymap:\n";
   t.display();
}
