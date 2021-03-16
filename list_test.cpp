
#include "List.hpp"
#include <list>
#include <iostream>
#include <limits>
#include <fstream>
#include <vector>

struct is_even {
  bool operator() (const int& value) { return (value % 2) == 0; }
};

bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
	if (tolower(first[i])<tolower(second[i])) return true;
	else if (tolower(first[i])>tolower(second[i])) return false;
	++i;
  }
  return ( first.length() < second.length() );
}

void	test_constructors(std::ofstream &_ft, std::ofstream &_sd)
{
	{
		ft::List<int> my(10, 10);
		std::list<int> test(10, 10);
		std::list<int>::iterator tb = test.begin();
		std::list<int>::iterator te = test.end();
		ft::List<int>::iterator b = my.begin();
		ft::List<int>::iterator e = my.end();
		_ft << "\n-----assign constr-----\n"; _sd << "\n-----assign constr-----\n";
		for(; b != e; b++)
			_ft << *b;
		for (; tb != te; tb++)
			_sd << *tb;
	}
	{
		std::vector<std::string>	strs(5, "Dead byte");
		ft::List<std::string>	   my(strs.begin(), strs.end());
		std::list<std::string>		sd(strs.begin(), strs.end());
		std::list<std::string>::iterator tb = sd.begin();
		std::list<std::string>::iterator te = sd.end();
		ft::List<std::string>::iterator b = my.begin();
		ft::List<std::string>::iterator e = my.end();
		_ft << "\n----range constructor-----\n"; _sd << "\n----range constructor-----\n";
		for(; b != e; b++)
			_ft << *b << "\n";
		for (; tb != te; tb++)
			_sd << *tb << "\n";
	}
	{
		_ft << "----- copy constructor -----\n"; _sd << "----- copy constructor -----\n";

		ft::List<int>	my(10, 10);
		std::list<int>	test(10, 10);

		ft::List<int>	my_copy(my);
		std::list<int>	test_copy(test);

		std::list<int>::iterator tb = test_copy.begin();
		std::list<int>::iterator te = test_copy.end();
		ft::List<int>::iterator b = my_copy.begin();
		ft::List<int>::iterator e = my_copy.end();
		for(; b != e; b++)
			_ft << *b;
		for (; tb != te; tb++)
			_sd << *tb;

		_ft << "\n----- operator= -----\n"; _sd << "\n----- operator= -----\n";
		ft::List<int>	temp_my(5, 5);
		std::list<int>	temp_test(5, 5);
		my = temp_my;
		test = temp_test;
		tb = test.begin();
		te = test.end();
		b = my.begin();
		e = my.end();
		for(; b != e; b++)
			_ft << *b;
		for (; tb != te; tb++)
			_sd << *tb;
	}
}

void	list_test(std::ofstream &_ft, std::ofstream &_sd)
{
	ft::List<int> my;
	std::list<int> test;

	std::list<int>::iterator tb = test.begin();
	std::list<int>::iterator te = test.end();
	ft::List<int>::iterator b = my.begin();
	ft::List<int>::iterator e = my.end();

	_ft << "----- LIST TEST -----\n"; _sd << "----- LIST TEST -----\n";
	test_constructors(_ft, _sd);
	_ft << "\n----- test begin == end -----\n"; _sd << "\n----- test begin == end -----\n";
	if (b == e)
		_ft << "begin == end";
	if (tb == te)
		_sd << "begin == end";
	_ft << "\n----- test empty -----\n"; _sd << "\n----- test empty -----\n";
	if (my.empty())
		_ft << "empty";
	if (test.empty())
		_sd << "empty";
	b = my.insert(b, 100);
	b = my.insert(b, 200);
	tb = test.insert(tb, 100);
	tb = test.insert(tb, 200);
	_sd << "size = " << test.size();
	_ft << "size = " << my.size();
	_ft << "\n---- test insert() -----\n"; _sd << "\n---- test insert() -----\n";
	for (; b != my.end(); ++b)
		_ft << *b;
	for (; tb != test.end(); ++tb)
		_sd << *tb;
	_sd << "size = " << test.size();
	_ft << "size = " << my.size();

	_ft << "\n---- test insert(1) -----\n"; _sd << "\n---- test insert(1) -----\n";
	test.insert(test.begin(), 5, 69);
	my.insert(my.begin(), 5, 69);
	for (b = my.begin(); b != my.end(); ++b)
		_ft << *b;
	for (tb = test.begin(); tb != test.end(); ++tb)
		_sd << *tb;
	_sd << "size = " << test.size();
	_ft << "size = " << my.size();

	_ft << "\n---- test insert(2) -----\n"; _sd << "\n---- test insert(2) -----\n";
	test.insert(test.begin(), test.begin(), test.end());
	my.insert(my.begin(), my.begin(), my.end());
	for (b = my.begin(); b != my.end(); ++b)
		_ft << *b;
	for (tb = test.begin(); tb != test.end(); ++tb)
		_sd << *tb;

	_ft << "\n-----test push_front-------\n"; _sd << "\n-----test push_front-------\n";
	my.push_front(300);
	test.push_front(300);
	for (b = my.begin(), tb = test.begin(); b != my.end(); ++b)
		_ft << *b;
	for (; tb != test.end(); ++tb)
		_sd << *tb;
	_sd << "size = " << test.size();
	_ft << "size = " << my.size();
	my.pop_front();
	test.pop_front();
	_sd << "size = " << test.size();
	_ft << "size = " << my.size();

	_sd << "\n-----test pop_front -------\n"; _ft << "\n-----test pop_front -------\n";
	for (b = my.begin(), tb = test.begin(); b != my.end(); ++b)
		_ft << *b << "\n";
	for (; tb != test.end(); ++tb)
		_sd << *tb << "\n";
	_sd << "size = " << test.size();
	_ft << "size = " << my.size();

	_sd << "\n-----test push_back -------\n"; _ft << "\n-----test push_back -------\n";
	my.push_back(7);
	test.push_back(7);
	for (b = my.begin(), tb = test.begin(); b != my.end(); ++b)
		_ft << *b;
	for (; tb != test.end(); ++tb)
		_sd << *tb;
	_sd << "size = " << test.size();
	_ft << "size = " << my.size();

	_sd << "\n-----test assign -------\n"; _ft << "\n-----test assign -------\n";
	test.assign(1, 7);
	my.assign(1, 7);
	for (tb = test.begin(); tb != test.end(); ++tb)
		_sd << *tb;
	for (b = my.begin() ; b != my.end(); ++b)
		_ft << *b;
	test.assign(5, 5);
	my.assign(5, 5);
	for (tb = test.begin(); tb != test.end(); ++tb)
		_sd << *tb;
	for (b = my.begin() ; b != my.end(); ++b)
		_ft << *b;
	std::vector<int>	vec(10, 20);
	test.assign(vec.begin(), vec.end());
	my.assign(vec.begin(), vec.end());
	for (tb = test.begin(); tb != test.end(); ++tb)
		_sd << *tb;
	for (b = my.begin() ; b != my.end(); ++b)
		_ft << *b;
	_sd << "size = " << test.size();
	_ft << "size = " << my.size();

	_sd << "-----test pop_back -------\n"; _ft << "-----test pop_back -------\n";
	test.pop_back();
	test.pop_back();
	my.pop_back();
	my.pop_back();
	_sd << "size = " << test.size();
	_ft << "size = " << my.size();
	for (tb = test.begin(); tb != test.end(); ++tb)
		_sd << *tb;
	for (b = my.begin() ; b != my.end(); ++b)
		_ft << *b;

	_sd << "\n----- erase(it, it) -------\n"; _ft << "\n----- erase(it, it) -------\n";
	test.erase(test.begin(), ++(++test.begin()));
	my.erase(my.begin(), ++(++my.begin()));
	for (tb = test.begin(); tb != test.end(); ++tb)
		_sd << *tb;
	for (b = my.begin() ; b != my.end(); ++b)
		_ft << *b;

	_sd << "\n----- clear() -------\n"; _ft << "\n----- clear() -------\n";
	if (test.empty())
		_sd << "empty";
	if (my.empty())
		_ft << "empty";
	test.clear();
	my.clear();
	if (test.empty())
		_sd << "empty";
	if (my.empty())
		_ft << "empty";
	
	_sd << "\n----- resize() -------\n"; _ft << "\n----- resize() -------\n";
	my.resize(10);
	test.resize(10);
	for (tb = test.begin(); tb != test.end(); ++tb)
		_sd << *tb;
	for (b = my.begin() ; b != my.end(); ++b)
		_ft << *b;
	
	_sd << "\n----- swap() -------\n"; _ft << "\n----- swap() -------\n";
	ft::List<int>	ftswap(10, 10);
	std::list<int>	sdswap(10, 10);
	my.swap(ftswap);
	test.swap(sdswap);
	for (tb = test.begin(); tb != test.end(); ++tb)
		_sd << *tb;
	for (b = my.begin() ; b != my.end(); ++b)
		_ft << *b;

	_sd << "\n----- splice() -------\n"; _ft << "\n----- splice() -------\n";
	my.splice(++my.begin(), ftswap);
	test.splice(++test.begin(), sdswap);
	for (tb = test.begin(); tb != test.end(); ++tb)
		_sd << *tb;
	for (b = my.begin() ; b != my.end(); ++b)
		_ft << *b;

	_sd << "\n----- splice(1) -------\n"; _ft << "\n----- splice(1) -------\n";
	ft::List<int>	fttemp;
	std::list<int>	sdtemp;

	fttemp.push_back(777);
	fttemp.push_back(888);
	sdtemp.push_back(777);
	sdtemp.push_back(888);
	sdtemp.sort();
	fttemp.sort();
	my.splice(++my.begin(), fttemp, ++fttemp.begin());
	test.splice(++test.begin(), sdtemp, ++sdtemp.begin());
	for (tb = test.begin(); tb != test.end(); ++tb)
		_sd << *tb << " ";
	for (b = my.begin() ; b != my.end(); ++b)
		_ft << *b << " ";
	for (tb = sdtemp.begin(); tb != sdtemp.end(); ++tb)
		_sd << *tb << " ";
	for (b = fttemp.begin() ; b != fttemp.end(); ++b)
		_ft << *b << " ";

	_sd << "\n----- splice(2) -------\n"; _ft << "\n----- splice(2) -------\n";
	fttemp.splice(++fttemp.begin(), my, (++(++my.begin())), my.end());
	sdtemp.splice(++sdtemp.begin(), test, (++(++test.begin())), test.end());

	for (tb = sdtemp.begin(); tb != sdtemp.end(); ++tb)
		_sd << *tb << " ";
	for (b = fttemp.begin() ; b != fttemp.end(); ++b)
		_ft << *b << " ";

	_sd << "\n----- remove() -------\n"; _ft << "\n----- remove() -------\n";
	fttemp.remove(10);
	sdtemp.remove(10);

	for (tb = sdtemp.begin(); tb != sdtemp.end(); ++tb)
		_sd << *tb << " ";
	for (b = fttemp.begin() ; b != fttemp.end(); ++b)
		_ft << *b << " ";

	_sd << "\n----- remove_if() -------\n"; _ft << "\n----- remove_if() -------\n";
	fttemp.remove_if(is_even());
	sdtemp.remove_if(is_even());

	for (tb = sdtemp.begin(); tb != sdtemp.end(); ++tb)
		_sd << *tb << " ";
	for (b = fttemp.begin() ; b != fttemp.end(); ++b)
		_ft << *b << " ";

	_sd << "\n----- unique() -------\n"; _ft << "\n----- unique() -------\n";
	fttemp.push_back(1); fttemp.push_back(1); fttemp.push_back(1); fttemp.push_back(3);
	sdtemp.push_back(1); sdtemp.push_back(1); sdtemp.push_back(1); sdtemp.push_back(3);

	fttemp.unique();
	sdtemp.unique();
	for (tb = sdtemp.begin(); tb != sdtemp.end(); ++tb)
		_sd << *tb << " ";
	for (b = fttemp.begin() ; b != fttemp.end(); ++b)
		_ft << *b << " ";

	_sd << "\n----- unique(1) -------\n"; _ft << "\n----- unique(1) -------\n";
	double mydoubles[]={12.15, 2.72, 73.0, 12.77, 3.14, 12.77, 73.35, 72.25, 15.3, 72.25 };
	std::list<double> sdtemp1(mydoubles, mydoubles + 10);
	ft::List<double> fttemp1(mydoubles, mydoubles + 10);
	fttemp1.unique(same_integral_part);
	sdtemp1.unique(same_integral_part);
	std::list<double>::iterator	sdi;
	ft::List<double>::iterator	fti;
	for (sdi = sdtemp1.begin(); sdi != sdtemp1.end(); ++sdi)
		_sd << *sdi << " ";
	for (fti = fttemp1.begin() ; fti != fttemp1.end(); ++fti)
		_ft << *fti << " ";

	_sd << "\n----- sort() -------\n"; _ft << "\n----- sort() -------\n";
	sdtemp1.sort();
	fttemp1.sort();
	for (sdi = sdtemp1.begin(); sdi != sdtemp1.end(); ++sdi)
		_sd << *sdi << " ";
	for (fti = fttemp1.begin() ; fti != fttemp1.end(); ++fti)
		_ft << *fti << " ";

	_sd << "\n----- unique(1) -------\n"; _ft << "\n----- unique(1) -------\n";
	fttemp1.unique(same_integral_part);
	sdtemp1.unique(same_integral_part);
	for (sdi = sdtemp1.begin(); sdi != sdtemp1.end(); ++sdi)
		_sd << *sdi << " ";
	for (fti = fttemp1.begin() ; fti != fttemp1.end(); ++fti)
		_ft << *fti << " ";

	_sd << "\n----- sort(Compare) -------\n"; _ft << "\n----- sort(Compare) -------\n";
	ft::List<std::string>	ft2;
	std::list<std::string>	sd2;
	ft2.push_back("One"); ft2.push_back("one"); ft2.push_back("One"); ft2.push_back("AA");
	ft2.push_back("aa");
	sd2.push_back("One"); sd2.push_back("one"); sd2.push_back("One"); sd2.push_back("AA");
	sd2.push_back("aa");
	ft2.sort(compare_nocase);
	sd2.sort(compare_nocase);
	std::list<std::string>::iterator sd2i = sd2.begin();
	ft::List<std::string>::iterator ft2i = ft2.begin();

	for (sd2i = sd2.begin(); sd2i != sd2.end(); ++sd2i)
		_sd << *sd2i << " ";
	for ( ft2i = ft2.begin() ; ft2i != ft2.end(); ++ft2i)
		_ft << *ft2i << " ";
	_sd << "size = " << ft2.size();
	_ft << "size = " << sd2.size();

	_sd << "\n----- merge() -------\n"; _ft << "\n----- merge() -------\n";
	std::list<double> sd3, sd4;
	ft::List<double> ft3, ft4;
	sd3.push_back(3.1);
 	sd3.push_back(2.2);
  	sd3.push_back(2.9);
  	sd4.push_back(3.7);
  	sd4.push_back(7.1);
  	sd4.push_back(1.4);
	sd3.sort();
	sd4.sort();
	sd3.merge(sd4);

	ft3.push_back(3.1);
 	ft3.push_back(2.2);
  	ft3.push_back(2.9);
  	ft4.push_back(3.7);
  	ft4.push_back(7.1);
  	ft4.push_back(1.4);
	ft3.sort();
	ft4.sort();
	ft3.merge(ft4);
	for (sdi = sd3.begin(); sdi != sd3.end(); ++sdi)
		_sd << *sdi << " ";
	for (fti = ft3.begin(); fti != ft3.end(); ++fti)
		_ft << *fti << " ";
	_sd << "size = " << sd3.size();
	_ft << "size = " << ft3.size();
	_sd << "\n----- merge(comp) -------\n"; _ft << "\n----- merge(comp) -------\n";
	std::list<double> sd5, sd6;
	ft::List<double> ft5, ft6;
	sd5.push_back(3.1);
	sd5.push_back(2.2);
	sd5.push_back(2.9);
	sd6.push_back(3.7);
	sd6.push_back(7.1);
	sd6.push_back(1.4);

	sd5.sort();
	sd6.sort();
	sd5.merge(sd6, same_integral_part);

	ft5.push_back(3.1);
	ft5.push_back(2.2);
	ft5.push_back(2.9);
	ft6.push_back(3.7);
	ft6.push_back(7.1);
	ft6.push_back(1.4);
	ft5.sort();
	ft6.sort();
	ft5.merge(ft6, same_integral_part);
	for (sdi = sd5.begin(); sdi != sd5.end(); ++sdi)
		_sd << *sdi << " ";
	for (fti = ft5.begin(); fti != ft5.end(); ++fti)
		_ft << *fti << " ";
	_sd << "size = " << sd5.size();
	_ft << "size = " << ft5.size();
	_sd << "\n----- reverse() -------\n"; _ft << "\n----- reverse() -------\n";

	ft5.reverse();
	sd5.reverse();
	for (sdi = sd5.begin(); sdi != sd5.end(); ++sdi)
		_sd << *sdi << " ";
	for (fti = ft5.begin(); fti != ft5.end(); ++fti)
		_ft << *fti << " ";

	ft::List<double>::reverse_iterator	ftri;
	std::list<double>::reverse_iterator	sdri;
	for (sdri = sd5.rbegin(); sdri != sd5.rend(); ++sdri)
		_sd << *sdri << " ";
	for (ftri = ft5.rbegin(); ftri != ft5.rend(); ++ftri)
		_ft << *ftri << " ";
	_sd << "\n----- operator==() -------\n"; _ft << "\n----- operator==() -------\n";
	if (ft5 == ft5)
		_ft << "list == list";
	if (sd5 == sd5)
		_sd << "list == list";

	_sd << "\n----- operator!=() -------\n"; _ft << "\n----- operator!=() -------\n";
	if (!(ft5 != ft5))
		_ft << "!(list != list)";
	if (!(sd5 != sd5))
		_sd << "!(list != list)";

	_sd << "\n----- operator<() -------\n"; _ft << "\n----- operator<() -------\n";
	if (!(ft5 < ft5))
		_ft << "!(list < list)";
	if (!(sd5 < sd5))
		_sd << "!(list < list)";
	_sd << "\n----- ::swap() -------\n"; _ft << "\n----- ::swap() -------\n";
	ft::swap(ft3, ft5);
	std::swap(sd3, sd5);
	for (sdi = sd5.begin(); sdi != sd5.end(); ++sdi)
		_sd << *sdi << " ";
	for (fti = ft5.begin(); fti != ft5.end(); ++fti)
		_ft << *fti << " ";
	for (sdi = sd3.begin(); sdi != sd3.end(); ++sdi)
		_sd << *sdi << " ";
	for (fti = ft3.begin(); fti != ft3.end(); ++fti)
		_ft << *fti << " ";
	_ft << ft3.max_size() << std::endl;
	_sd << sd3.max_size() << std::endl;
	std::cout << "List\t\t[OK]\n";
}
