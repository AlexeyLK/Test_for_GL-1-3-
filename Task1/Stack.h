#pragma once
#include <iostream>
using namespace std;

// Structure describing the node
template <typename T>
struct NodeStack
{
	T item;
	NodeStack<T>* next;
};

// Template class Stack based on a linked list
template <typename T>
class StackL
{
private:
	NodeStack<T>* pTop; // pointer to the top of the stack

public:
	// default constructor
	StackL() { pTop = nullptr; }

	// copy constructor
	StackL(const StackL& SL)
	{
		NodeStack<T>* p; 
		NodeStack<T>* p2;
		NodeStack<T>* p3;

		// initialize pTop
		pTop = nullptr;
		p3 = nullptr;

		p = SL.pTop; // pointer p moves along the list SL.pTop -> ...
		while (p != nullptr)
		{
			
			try {
				p2 = new NodeStack<T>;
			}
			catch (bad_alloc e)
			{
				// if memory is not allocated then exit
				cout << e.what() << endl;
				return;
			}
			p2->item = p->item;
			p2->next = nullptr;

			// pTop = pTop + p2
			if (pTop == nullptr) 
			{
				pTop = p2;
				p3 = p2;
			}
			else
			{
				p3->next = p2;
				p3 = p3->next;
			}

			p = p->next;
		}
	}

	// push an item onto the stack
	// item is placed at the beginning of the list
	void Push(T item)
	{
		NodeStack<T>* p;

		try {
			p = new NodeStack<T>;
		}
		catch (bad_alloc e)
		{
			cout << e.what() << endl;
			return;
		}
		p->item = item;
		p->next = pTop; // p indicates the 1st element

		pTop = p;
	}

	/* The number of elements in the stack 
	//(there is no function for displaying the size, because when an element is removed, 
	//the size will automatically decrease by 1, similarly, during the push operation, the size will increase)*/
	int Capacity()
	{
		if (pTop == nullptr)
			return 0;
		else
		{
			NodeStack<T>* p = pTop;
			int count = 0;

			while (p != nullptr)
			{
				count++;
				p = p->next;
			}
			return count;
		}
	}

	//print stack
	void Print(const char* objName)
	{
		cout << "Object: " << objName << endl;
		if (pTop == nullptr)
			cout << "stack is empty." << endl;
		else
		{
			NodeStack<T>* p; 
			p = pTop;
			while (p != nullptr)
			{
				cout << p->item << "\t";
				p = p->next;
			}
			cout << endl;
		}
	}

	void Empty()
	{
		NodeStack<T>* p; 
		NodeStack<T>* p2;

		p = pTop;

		while (p != nullptr)
		{
			p2 = p; 
			p = p->next; 
			delete p2; 
		}
		pTop = nullptr; 
	}

	~StackL()
	{
		Empty();
	}

	// method that pops an element off the stack
	T Pop()
	{
	
		if (pTop == nullptr)
			return 0;

		NodeStack<T>* p2; 
		T item;
		item = pTop->item;

		p2 = pTop;
		pTop = pTop->next;

		delete p2;

		return item;
	}
};