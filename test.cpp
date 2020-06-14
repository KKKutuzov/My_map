#include <iostream>
#include "mymap.h"

using namespace std;

int main()
{
    mymap<int> t;
    t.insert("20",5);
    t.insert("sss",6);
    t.insert("kek",10);
    t.insert("212",5);
    t.insert("203",5);
    t.insert("201111",5);
    t.insert("20asdddd",5);
    t.insert("21230",5);
    t.insert("2a0",5);
    t.insert("20aaaa",5);
    cout << " ishem 2a0      " << t.find("2a0") << endl;
    try{
     cout << " get elem      " << t.GetDataTree("2aasdasd0") << endl;
   }
   catch(...)
   {
      cout << "kek" << endl;
   }
   cout << " ishem 2a0      " << t.find("2a0asd") << endl;
   t.display();
   mymap<int>::bstit it(t);
   it.next();
   cout << it.GetKey() << " " << it.GetData() << endl;
   cout << endl;
   cout << t.mysize() << endl;
   cout << endl;
   t.remove("kek");
   cout << t.mysize() << endl;
   t.display();
}
