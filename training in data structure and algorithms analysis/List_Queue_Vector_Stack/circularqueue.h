#ifndef CIRCULARQUEUE_H_INCLUDED
#define CIRCULARQUEUE_H_INCLUDED

template<class T>
class Circqueue{

private :
T * circqueue;
int Size;
int Front;
int Back;

public:
Circqueue(int sz):Size(sz),Front(0),Back(0)
{ circqueue = new T [sz]; }
//enqueue an element into the queue
void Enqueue(const T & val)
{
//check if there is empty space
if((Size-Back+Front) >0 )
{
circqueue[Back%Size]=val;
Back++;
}

else
cout<<"Queue is full"<<endl;
}
//dequeue an element from the queue
T Dequeue()
{
if(Back-Front > 0)
{
T val=circqueue[Front%Size];
Front++;
return val;
}

else{
cout<<"Queue is empty"<<endl;
}
}

//count
int Count()
{return Back-Front;}
};


#endif // CIRCULARQUEUE_H_INCLUDED
