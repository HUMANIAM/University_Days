#include<iostream>
#include<cstdlib>
#include<string>
#include<string.h>
#include"Iterators.h"
using namespace std;
//link hold the data and the address to the next link

//doubly linkedlist as generic class
template<class obj>
class linkedlist{

private:
    struct link
    {
        int data;         //data in this entery
        link * next;      //point to the next link
        link * previous;  //point to the previous link
        link(const obj& d = obj(),  link * n =NULL,  link * p =NULL)
        //3 argument constructor
        :data(d), next(n) , previous(p){}
    };
	link * head;      //hold the start of the list to use the list as queue
	link * tail;       //hold the last link in the list
	int   count ;       // number of full links in the stack

public:
    class Const_Iterator{
         protected:
            link* current;
            friend class linkedlist<obj>;
            Const_Iterator(link* l):current(l)
            {}
            obj& retrieve()const{
                return current->data;
            }
        public:
            //defautl constructor
            Const_Iterator():current(NULL){}
            //* overload operator
            const obj & operator * ()const
            {return retrieve();}
            //++ prefix overload operaotr
            Const_Iterator & operator ++()
            {current = current->next; return *this;}
            //++ posfix overload operator
            Const_Iterator & operator ++(int)
            {
                Const_Iterator old = *this;
                current=current->next;
                return old;
            }
            // comparsion operator
            bool operator == (const Const_Iterator & rhs)const
            { return current == rhs.current; }
            //!= overload operator
            bool operator != (const Const_Iterator & rhs)const
            {return !( *this == rhs); }
            //assign operator
            Const_Iterator & operator = (const Const_Iterator & rhs)
            { current=rhs.current; return *this;}


    };
    //class iterator inherit from the constiterator
    class Iterator:public Const_Iterator
        {
            protected:
                friend class linkedlist<obj>;
                Iterator(link* l):Const_Iterator(l){}

            public:

            Iterator (){}

            obj & operator *()const
            {return Const_Iterator::retrieve();}

            Iterator operator ++()
            {Const_Iterator::current = Const_Iterator::current->next; return *this;}

            Iterator operator ++(int)
            {
                Iterator old= *this;
                Const_Iterator::current = Const_Iterator::current->next;
                return old;
            }
        };
        //initailize the linkedlist
         void init()
         {
            head = new link;
            tail = new link;
            head->next = tail;
            tail->previous = head;
            count = 0;
         }
        //default constructor
        linkedlist()
        {init();}
	//copy constructor
	linkedlist(const linkedlist & rhs)
	{
        init();
        *this=rhs;
	}
	//assignment overload operator
	const linkedlist & operator = (const linkedlist & rhs)
	{
        //rhs is alias for the *this list
        if(*this=rhs)
        return *this;

        Clear();
        for(Const_Iterator it=rhs.begin();it!=rhs.end();it++)
        *this.addback(*it);

        return *this;
	}
	//return iterator to the first element in the list
	Iterator begin()
	{
        return Iterator(head->next);
	}
	//return iterator to the end of the list
	Iterator end()
	{
        return Iterator(tail);
	}
	//return iterator to the right hand side to avoid overwritting
	Const_Iterator end()const
	{
        return Const_Iterator(tail);
	}
	//return iterator to the right hand side to avoid overwritting
	Const_Iterator begin()const
	{
        return Const_Iterator(head->next);
	}
	//insert item to the front of the list
	void addfront(obj d)
	{
		head->next=head->next->previous=new link(d,head->next,head);
		count++;
	}
	//insert item ot the end of the list
	void addback(obj d)
	{
        tail->previous=tail->previous->next=new link(d , tail, tail->previous);
        count++;
	}
	//read from the back
	bool  readback(obj & val)
	{
        if(count==0)
        return -1;

        else{
                 obj x=tail->previous->data;
                val=x;
                return true;
        }
	}
	//read from the front
	bool readfront(obj & val)
	{
        if (count == 0)
            return -1;

        else
            {
                val=head->next->data;
                return true;
            }
	}
	//pop from front
	void popfront()
	{
        if(count !=0)
        {
            delete head->next;
            head->next = head->next->next;
            head->next->previous = head;
            count--;
        }
	}
	//pop from the back
	void popback()
	{
        if(count != 0)
        {
            delete tail->previous;
            tail->previous = tail->previous->previous;
            tail->previous->next = tail;
            count--;
        }
	}
	//search for an item in the list
	bool search(const obj & a)
	{
		link * l = head->next;
		while(l != tail)
		{
            if(a == l->data)
                return true;
            else
                l=l->next;
		}
		return false;
	}
	// count of items in the list
	int Getcount()
	{
		return count;
	}

    void Clear()
    {
        while(head->next !=tail)
        popfront();

    }
    bool isempty()
    {
        return count==0?true:false;
    }
    ~linkedlist()
    {
        Clear();
        delete head;
        delete tail;
    }
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
};
int x=0;
int & fn()
{
x=50;
return x;
}
//main function
int main()
{

//linkedlist<int>l;
//for(int i=1;i<5;i++)
//l.addback(i);
//
//bool s=l.search(5);
//cout<<s;
//linkedlist<int>::Const_Iterator it;
//
//l.popback();
//for(it=l.begin();it!=l.end();it++)
//cout<<*it<<endl;

return 0;
}
