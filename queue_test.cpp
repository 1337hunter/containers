#include "Queue.hpp"
#include <queue>
#include <iostream>
#include <fstream>
#include <stdexcept>

void	queue_test(std::ofstream &_ft, std::ofstream &_sd)
{
	_ft << "\n\n--------STACK TEST--------\n"; _sd << "\n\n--------STACK TEST--------\n";

	std::queue<int>	sd;
	ft::Queue<int>	my;

	if (sd.empty())
		_sd << "empty\n";
	if (my.empty())
		_ft << "empty\n";
	_sd << sd.size();
	_ft << my.size();

	my.push(1);
	sd.push(1);
	_sd << sd.front();
	_ft << my.front();

	my.push(2);
	sd.push(2);
	_sd << sd.front();
    _ft << my.front();
	sd.pop();
	my.pop();
	_sd << sd.front();
    _ft << my.front();
	_sd << sd.size();
    _ft << my.size();

	std::queue<int> sd1;
    ft::Queue<int>  my1;

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


	std::cout << "Queue\t\t[OK]\n";
}
