#include "Map.hpp"
#include <map>
#include <iostream>
#include <fstream>
#include <stdexcept>

void	map_test(std::ofstream &_ft, std::ofstream &_sd)
{
	_ft << "\n\n--------MAP TEST--------\n"; _sd << "\n\n--------MAP TEST--------\n";
	ft::Map<char, int>	my;
	std::map<char, int> sd;
	my.insert(std::pair<char, int>('f', 1));
	my.insert(std::pair<char, int>('a', 2));
	my.insert(std::pair<char, int>('g', 3));
	my.insert(std::pair<char, int>('h', 4));
	my.insert(std::pair<char, int>('c', 5));
	my.insert(std::pair<char, int>('x', 6));
	my.insert(std::pair<char, int>('y', 7));
	sd.insert(std::pair<char, int>('f', 1));
	sd.insert(std::pair<char, int>('a', 2));
	sd.insert(std::pair<char, int>('g', 3));
	sd.insert(std::pair<char, int>('h', 4));
	sd.insert(std::pair<char, int>('c', 5));
	sd.insert(std::pair<char, int>('x', 6));
	sd.insert(std::pair<char, int>('y', 7));
	std::map<char, int>::iterator	isd = sd.begin();
	ft::Map<char, int>::iterator   ift = my.begin();

	_ft << "\n------iterator(++--)---\n"; _sd << "\n------iterator(++--)---\n";
	for (; isd != sd.end(); ++isd)
		_sd << isd->second;
	for (; ift != my.end(); ift++)
		_ft  << ift->second;
	--isd;
	--ift;
	for (; isd != sd.begin(); isd--)
		_sd << isd->second;
	for (; ift != my.begin(); --ift)
		_ft  << ift->second;

	_ft << "\n-------riterator---------\n"; _sd<< "\n-------riterator---------\n";
	std::map<char, int>::reverse_iterator	risd = sd.rbegin();
	ft::Map<char, int>::reverse_iterator	rift = my.rbegin();

	for (; risd != sd.rend(); ++risd)
		_sd << risd->second;
	for (; rift != my.rend(); ++rift)
		_ft << rift->second;

	_ft << "\n-------constr---------\n"; _sd<< "\n-------constr---------\n";
	ft::Map<char, int>	mycp(my.begin(), my.end());
	std::map<char, int> sdcp(sd.begin(), sd.end());

	risd = sdcp.rbegin();
	rift = mycp.rbegin();
	for (; risd != sdcp.rend(); ++risd)
		_sd << risd->second;
	for (; rift != mycp.rend(); ++rift)
		_ft << rift->second;
	_ft << "\n-------constr---------\n"; _sd<< "\n-------constr---------\n";
	ft::Map<char, int>  mycp1(mycp);
	std::map<char, int> sdcp1(sdcp);
	risd = sdcp1.rbegin();
	rift = mycp1.rbegin();

	for (; risd != sdcp1.rend(); ++risd)
		_sd << risd->second;
	for (; rift != mycp1.rend(); ++rift)
		_ft << rift->second;
	_ft << "\n-------erase---------\n"; _sd<< "\n-------erase---------\n";
	sdcp1.erase(sdcp1.begin());
	mycp1.erase(mycp1.begin());
	isd = sdcp1.begin();
	ift = mycp1.begin();
	isd++;
	ift++;
	sdcp1.erase(isd);
	mycp1.erase(ift);
	risd = sdcp1.rbegin();
	rift = mycp1.rbegin();
	for (; risd != sdcp1.rend(); ++risd)
		_sd << risd->first;
	for (; rift != mycp1.rend(); ++rift)
		_ft << rift->first;
	sdcp1.erase('h');
	mycp1.erase('h');
	_sd << "\n";
	_ft << "\n";
	for (risd = sdcp1.rbegin(); risd != sdcp1.rend(); ++risd)
		_sd << risd->first;
	for (rift = mycp1.rbegin(); rift != mycp1.rend(); ++rift)
		_ft << rift->first;
	sdcp1.erase('g');
	mycp1.erase('g');
	for (risd = sdcp1.rbegin(); risd != sdcp1.rend(); ++risd)
		_sd << risd->first;
	for (rift = mycp1.rbegin(); rift != mycp1.rend(); ++rift)
		_ft << rift->first;
	sdcp1.erase(sdcp1.begin(), sdcp1.end());
	mycp1.erase(mycp1.begin(), mycp1.end());
	for (risd = sdcp1.rbegin(); risd != sdcp1.rend(); ++risd)
		_sd << risd->first;
	for (rift = mycp1.rbegin(); rift != mycp1.rend(); ++rift)
		_ft << rift->first;

	_ft << "\n-------oper=---------\n"; _sd<< "\n-------oper=---------\n";
	mycp1 = mycp;
	sdcp1 = sdcp;
	for (risd = sdcp1.rbegin(); risd != sdcp1.rend(); risd++)
		_sd << risd->first;
	for (rift = mycp1.rbegin(); rift != mycp1.rend(); rift++)
		_ft << rift->first;

	_ft << "\n-------size()---------\n"; _sd<< "\n-------size()---------\n";
	_ft << mycp1.size();
	_sd << sdcp1.size();

	_ft << "\n-------oper[]---------\n"; _sd<< "\n-------oper[]---------\n";
	mycp1['t'] = 10;
	sdcp1['t'] = 10;
	for (risd = sdcp1.rbegin(); risd != sdcp1.rend(); risd++)
		_sd << risd->first;
	for (rift = mycp1.rbegin(); rift != mycp1.rend(); rift++)
		_ft << rift->first;

	mycp1['t'] = 11;
	sdcp1['t'] = 11;
	for (risd = sdcp1.rbegin(); risd != sdcp1.rend(); risd++)
		_sd << risd->first;
	for (rift = mycp1.rbegin(); rift != mycp1.rend(); rift++)
		_ft << rift->first;
	for (risd = sdcp1.rbegin(); risd != sdcp1.rend(); risd++)
				_sd << risd->first;
		for (rift = mycp1.rbegin(); rift != mycp1.rend(); rift++)
					_ft << rift->first;

	_ft << "\n-------swap()---------\n"; _sd<< "\n-------swap()---------\n";
	mycp1.swap(my);
	sdcp1.swap(sd);
	for (risd = sdcp1.rbegin(); risd != sdcp1.rend(); risd++)
		_sd << risd->first;
	for (rift = mycp1.rbegin(); rift != mycp1.rend(); rift++)
		_ft << rift->first;

	_ft << "\n-------find()---------\n"; _sd<< "\n-------find()---------\n";
	ift = mycp1.find('h');
	isd = sdcp1.find('h');
	_ft << ift->first;
	_sd << isd->first;
	_ft << "\n-------count()---------\n"; _sd<< "\n-------count()---------\n";
	_ft << mycp1.count('h');
	_sd << sdcp1.count('h');

	_ft << "\n-------lower_b()---------\n"; _sd<< "\n-------lower_b()---------\n";
	ift = mycp1.lower_bound('a');
	isd = sdcp1.lower_bound('a');
	_ft << ift->first;
	_sd << isd->first;

	_ft << "\n-------upper_b()---------\n"; _sd<< "\n-------upper_b()---------\n";
	ift = mycp1.lower_bound('y');
	isd = sdcp1.lower_bound('y');
	_ft << ift->first;
	_sd << isd->first;
	std::pair<ft::Map<char, int>::iterator, ft::Map<char, int>::iterator>	mypair;
	std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator>	sdpair;

	_ft << "\n-------equal_r()---------\n"; _sd<< "\n-------equal_r()---------\n";
	mypair = mycp1.equal_range('h');
	sdpair = sdcp1.equal_range('h');
	_ft << mypair.first->first;
	_ft << mypair.second->first;
	_sd << sdpair.first->first;
	_sd << sdpair.second->first;

	std::cout << "Map\t\t[OK]" << std::endl;
}

