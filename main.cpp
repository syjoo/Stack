#include "Stack.hpp"
#include <iostream>

using namespace std;

int main()
{
	Stack<int> stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);

	while (!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}

	return 0;
}