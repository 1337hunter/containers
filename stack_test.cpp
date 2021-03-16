#include "Stack.hpp"
#include <stack>
#include <iostream>
#include <fstream>
#include <stdexcept>

void	stack_test(std::ofstream &_ft, std::ofstream &_sd)
{
	_ft << "\n\n--------STACK TEST--------\n"; _sd << "\n\n--------STACK TEST--------\n";

	std::stack<int>	sd;
	ft::Stack<int>	my;

	if (sd.empty())
		_sd << "empty\n";
	if (my.empty())
		_ft << "empty\n";
	_sd << sd.size();
	_ft << my.size();

	my.push(1);
	sd.push(1);
	_sd << sd.top();
	_ft << my.top();

	my.push(2);
	sd.push(2);
	_sd << sd.top();
    _ft << my.top();
	sd.pop();
	my.pop();
	_sd << sd.top();
    _ft << my.top();
	_sd << sd.size();
    _ft << my.size();

	std::stack<int> sd1;
    ft::Stack<int>  my1;

	if (sd1 == sd)
		_sd << "==";
	if (my1 == my)
		_ft << "==";
	if (sd1 < sd)
		_sd << "<";
	if (my1 < my)
		_ft << "<";
	if (sd1 > sd)
		_sd << ">";
	if (my1 > my)
		_ft << ">";


	std::cout << "Stack\t\t[OK]\n";
}
