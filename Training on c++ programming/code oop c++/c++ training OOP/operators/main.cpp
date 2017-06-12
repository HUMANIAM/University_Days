// countpp1.cpp
// increment counter variable with ++ operator
#include <iostream>
#include"mutex"
using namespace std;
////////////////////////////////////////////////////////////////
class Counter
{
private:
unsigned int count;
//count
public:
Counter() : count(0)
//constructor
{ }
unsigned int get_count()
//return count
{ return count; }
void operator ++ ()
//increment (prefix)
{
++count;
}
};

int main()
{
Counter c1, c2;
cout << "\nc1=" << c1.get_count();
cout << "\nc2="<< c2.get_count();
++c1;
++c2;
++c2;
//display
cout << "\nc1="<< c1.get_count(); //display again
cout << "\nc2="<< c2.get_count() << endl;
return 0;
}
