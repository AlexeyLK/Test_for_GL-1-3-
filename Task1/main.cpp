#include "Stack.h"

void main()
{
	StackL<int> SL;
	
	SL.Push(8);
	SL.Push(9);
	SL.Push(7);
	SL.Push(5);
	SL.Push(4);
	SL.Push(2);

	SL.Pop();

	std::cout << SL.Capacity() << std::endl;
	SL.Print("SL");

	std::cout << "------------------------"<<std::endl;

	SL.Push(4);
	std::cout << SL.Capacity() << std::endl;
	SL.Print("SL");
}