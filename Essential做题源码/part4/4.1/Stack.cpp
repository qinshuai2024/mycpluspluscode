#include "Stack.h"

bool Stack::push(string& elem)
{
	if (full())
	{
		return false;
	}
	_stack.push_back(elem);
	return true;
}
bool Stack::pop(string& elem)
{
	if (full())
		return false;

	return ;
}
bool Stack::peek(string& elem)
{

}
bool Stack::empty()
{

}
bool Stack::full()
{

}
