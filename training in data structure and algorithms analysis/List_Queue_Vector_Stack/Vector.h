#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include<iostream>
using namespace std;
/*vector like the array in c but you can resize it and it also it extends dynamically and you
you can see that it can push_back only
*/
/*in this file we try to implement the vector class and its methods*/

template<class object>
class Vector {

private:
int idxf;
int thesize;
int itemsinsize;
int thecapacity;
object * objects;
typedef object * iterator;
typedef object * const_iterator;
enum{SPARE_CAPACITY=16};

public:
//this is default constructro and also the constructor to intialize the size of vector
explicit Vector (int initsize =0)
:thesize(initsize),thecapacity(initsize+SPARE_CAPACITY),itemsinsize(0)
{
objects = new object [thecapacity];}
//copy constructor
Vector(const Vector & rhs):objects(NULL)
{
operator=(rhs);}
//deconstructor
~Vector()
{
delete [] objects;}
//assignment operator
const Vector & operator = (const Vector& rhs)
{
if(this != &rhs)
{
delete[] objects;
thesize=rhs.thesize;
thecapacity=rhs.thecapacity;
objects=new object[thecapacity];

for(int k=0; k<thesize;k++)
objects[k]=rhs.objects[k];
}
return *this;
}
//resize the vector
void resize(int newsize)
{
if(newsize>thecapacity)
reserveback(newsize*2+1);
thesize=newsize;
}
//subscript operator
object & operator [](int idx)
{
if(idx>-1 && idx < thesize)
{   return objects[idx];
}
}
//this operator for constant vector prevent v[i] appear on the left
const object & operator [](int idx) const
{
if(idx>-1 && idx < thesize)
return objects[idx];
}
//reserve new capacity
void reserveback(int newcapacity)
{

if(newcapacity<thesize)
    return;
object* oldarray=objects;
objects =new object[newcapacity];

for(int k=0; k<thesize;k++)
    objects[k]=oldarray[k];

thecapacity=newcapacity;
delete [] oldarray;

}
//empty() funciton
bool empty()const
{
return size()==0;
}

int size()const
{
return thesize;
}

int capacity()const
{
return thecapacity;
}
//push back of the vector
void push_back(const object & ob)
{
if(thesize==thecapacity)
    reserveback(2*thecapacity+1);
objects[thesize++]=ob;
}
//pop back of the vector
void pop_back()
{

if(thesize>0)
thesize--;
}
//back funciton
const object & back()const
{
return objects[thesize-1];}


iterator begin()const
{
return &objects[0];}

iterator end()
{
return &objects[size()];
}
//insert element into the vector by pointer
void insert(const object * & pos, const object& val)
{
//if position >= end use pushback function
if(pos >= end())
    push_back(val);
//check position .>= begin()
else if(pos >= begin())
{
    object* oldarray = objects;
    if(thesize >= thecapacity)
    {
        objects = new object[thesize+capacity()];
        thecapacity = thesize + thecapacity;
        cout<<endl<<thecapacity<<endl;
        cout<<thesize<<endl;
    }

    for(int i=0,j=0 ; i<thesize ; i++,j++)
    {
        if(pos != &oldarray[i])
            objects[j]=oldarray[i];
        else
        {
            objects[j++]=val;
            objects[j] = oldarray[i];
            thesize++;
        }
    }
return;
    delete [] oldarray ;
}

else
    return;
}

};



#endif // VECTOR_H_INCLUDED
