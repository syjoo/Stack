#ifndef _STACK_
#define _STACK_

#include <iostream>
#include <exception>
#include <typeinfo>
#include <string>

using namespace std;

template <typename T>
class Stack
{
private:
	T* data;
	int size;
	int tp;
public:
	Stack(int = 10);
	~Stack();

	T top() const;
	void push(T);
	void pop();

	bool empty() const;
	bool full() const;
	void increase();
	string type() const;
};

template <typename T>
Stack<T>::Stack(int size)
	:data(new T[size]), size(size), tp(-1)
{}

template <typename T>
Stack<T>::~Stack()
{
	delete[] data;
}

template <typename T>
T Stack<T>::top() const
{
	return data[tp];
}

template <typename T>
void Stack<T>::push(T v)
{
	if (full())
		increase();
	data[++tp] = v;
}

template <typename T>
void Stack<T>::pop()
{
	if (empty())
		throw std::exception("Stack is empty.");
	--tp;
}

template <typename T>
bool Stack<T>::empty() const
{
	return tp == -1;
}

template <typename T>
bool Stack<T>::full() const
{
	return tp == size;
}

template <typename T>
void Stack<T>::increase()
{
	T* tmp = new T[size * 2];

	memmove(data, tmp, size * sizeof(T));
	size *= 2;

	delete[] data;
	data = tmp;
}

template <typename T>
string Stack<T>::type() const
{
	return string(typeid(*this).name());
}

#endif
