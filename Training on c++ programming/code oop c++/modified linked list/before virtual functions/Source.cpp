#include<iostream>
#include<cstdlib>
#include<string>
#include<string.h>
using namespace std;
//link hold the data and the address to the next link
struct link{
	int data;         //data in this entery
	link * next;      //point to the next link
	link * previous;  //point to the previous link
};
//linkedlist class
class linkedlist{
private:
	link * first;      //hold the start of the list to use the list as queue
	link * last;       //hold the last link in the list
	link * prelast;     // points to the previous link
	int   count ;       // number of full links in the stack
public:
	linkedlist() {
		link * link1 = new link;
		first = link1;
		last = link1;
		prelast = NULL;
		count = 0;
	}
	//insert item to list
	void additem(int d)
	{
		last->data = d;
		link * newlink = new link;           //create new link
		last->next = newlink;               //current full link now points to the empty newlink
		last->previous = prelast;          //current full link now points to the previous link
		prelast = last;                    //now the prelast is points to the lastest full link
		last=newlink;                      //last now points to the empty last link
		last->next = NULL;                // last empty link points to no link
		last->previous = prelast;         //last empty link points to the last full link
		count++;
	}
	//get item from the frontier of the list
	int  Get_Fristlink()
	{
		if (count==0)
		{
			cout << "list is empty\n";
			return -1;
		}

		int data = first->data;    //current item
		first = first->next;       //first now points to the next link
		count--;                   //decrease the counter by 1
		return data;               //return the data link
	}
	//get item from the back from the list
	int Get_Lastlink()
	{
		if (count == 0)
		{
			cout << "list is empty\n";
			return -1;
		}
		int data = prelast->data;
		last = prelast;
		prelast = prelast->previous;

	}
	//search for an item in the list
	bool search(int a)
	{
		link * f = first;   //used for searching the item
		while (f != NULL)
		{
			if (a == f->data)
				return true;
			else
				f = f->next;
		}
		return false;
	}
	// count of items in the list
	int Getcount()
	{
		return count;
	}
	
};
//main function
void main()
{
	linkedlist l;
	cout << l.Get_Lastlink() << endl;
	for (int i = 0; i < 2; i++)
		l.additem(i);
	// using the linked list as a Queue
	cout << "****************" << endl;
	//for (int i = 0; i < 10; i++)
	//	cout << l.Get_Fristlink() << endl;
	//using the linked list as a Stack
	cout << "****************" << endl;
	for (int i = 0; i < 10; i++)
		cout << l.Get_Lastlink() << endl;

	system("pause");
}

