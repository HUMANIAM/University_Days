#include <iostream>
#include<list>
#include<queue>
#include<vector>
#include<iterator>
#include<string>
using namespace std;
//############### exe1 ###########

template<class obj>
void printlist(const list<obj> & l , const list<obj>& p)
{
typename list<obj>::const_iterator itl=l.begin();
typename list<obj>::const_iterator itp=p.begin();
typename list<obj>::const_iterator temp=itl;

for (itp = p.begin();itp!=p.end();itp++)
{
    obj x=*itp;
    while(x-- !=0 )
        itl++;
    cout<<*(itl)<<endl;

    itl=temp;
}
}
//test exe1
void testexe1()
{
    list<int>l,p;

    for (int i=1;i<11;i++)
        l.push_back(i);

    for (int i=0;i<10;i+=1)
        p.push_back(i);

    printlist(l,p);
}
//##########################exe2#######################
//##########################single list ###############
template<class obj>
class singlelist
{
private:
struct link{
obj data;
link * next;
link(const obj & d , link * n=NULL):data(d),next(n)
{}
};
link* pre;
int Size;

public:

singlelist():pre(NULL),Size(0)
{}

void additem(const obj& d)
{
pre=new link(d,pre);
Size++;
}

obj & readlastitem() const
{ return pre->data;}

int getsize()const
{return Size;}

obj& pop()
{
obj& d=pre->data;
link* p=pre->next;
pre=p;
Size--;
return d;
}
};
//##################ex3 add find function to doubly linked list#######
template<class Iterator , class obj>
Iterator find_It( Iterator  start ,  Iterator  End , const obj & val)
{
Iterator it=start;
while(it != End)
{
if(*it == val)
    return it;
else
    it++;
}
return End;
}
//################# ex4  #########
//l1 U l2
template<class container>
void append(container & l1 ,container & l2)
{

typename container::iterator it=l2.begin();
while(it != l2.end())
l1.push_back(*it++);

}
//#################  ex5 #########
//l1 intersect l2
template<class container>
container intersection(container  l1 ,container  l2)
{
container result;
typename container::iterator it1=l1.begin();
typename container::iterator it2=l2.begin();

//check that l1 is larger than l2
if(l1.size()<l2.size())
{
result = l1;
l1=l2;
l2=result;
result.clear();
}

while(it2 != l2.end() && it1 != l1.end())
{
if(*it1==*it2)
{
result.push_back(*it1++);
it2++;
}
else
it1++;
}

return result;
}
//################### exe6 ##############
//increment iterator to list circularly by any value
list<int>::iterator  inciterator( list<int>& l ,list<int>::iterator & it , int val)
{
    while(val-- > 0)
    {
         it++;
         if(it==l.end())
         it=l.begin();
    }

    return it;
}
//josephusproblem state that who will win the patato after specific moves
int Josephusproblem (queue<int> & qu , const int N, const int M)
{
//create the circle with index from 1 to N
list<int>l;
for(int i=1;i<=N;i++)
l.push_back(i);

list<int>::iterator it = l.begin();

while(l.size()!=1)
{
it=inciterator(l,it , M);

qu.push(*it);
list<int>::iterator temp=it;
it++;
l.remove(*temp);
}

return l.back();
}
// Test josephusproblem
void Testjospro()
{
queue<int>qu;
int winner = Josephusproblem(qu,5,1);
cout<<"Winner : "<<winner<<endl;
cout<<"sequence of removal persons"<<endl;
while(!qu.empty())
{
cout<<qu.front()<<"   ";
qu.pop();
}
}
//################exe7 & exe8 in vecor.h #########
int main()
{
//
list<int>l;
//
for(int i=1;i<=10;i++)
{l.push_back(i); }
//
list<int>::iterator itt,it =l.begin();

vector<int>v(5);
v.push_back(10);
cout<<v.size()<<endl;
cout<<v[5];



    return 0;
}
