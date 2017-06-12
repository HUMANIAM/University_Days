#include <iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include <vector>
#include<list>
#include<stack>
#include<queue>
#include<string>
#include<iterator>
#include"Vector.h"
#include"Stackapp.h"
#include"circularqueue.h"
using namespace std;

//this template function used to delete items from container
template<class container>
void removeitems(container & con)
{
class container::iterator it=con.begin();
while(it != con.end())
{
it=con.erase(it);
if(it!=con.end())
it++;
}
}

//change the value of list
template<class container,class value>
void change(container & con, const value & v)
{
class container::iterator it=con.begin();
while(it != con.end())
*it++=v;
}

// printing any containers
template<class container>
void printcollection(const container & con,ostream & out = cout)
{

if(con.empty())
out<<"empty container"<<endl;

else{

class container::const_iterator it = con.begin();
out<<"[ "<<*it++;
while(it != con.end())
out<<", "<<*it++;
out<<" ]"<<endl;
}
}
//test Vector class
void vectorfunction()
{
Vector<int>vec;
for (int i=0;i<10;i++)
vec.push_back(i);
for (int i=0;i<10;i++)
cout<<vec[i]<<endl;
}
//function calls
template<class it>
void print(it s,it e )
{

if (s==e)
return;

cout<<*s++<<endl;
print(s,e);
}

int main()
{
Vector<int>v(20);
const int * it=v.begin();
for(int i=0;i<19;i++)
v.insert(it,i);
cout<<*it;


return 0;
}
