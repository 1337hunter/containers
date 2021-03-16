#include "Vector.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>

void	vector_test(std::ofstream &_ft, std::ofstream &_sd)
{
	_ft << "\n\n--------VECTOR TEST--------\n"; _sd << "\n\n--------VECTOR TEST--------\n";
	{
		ft::Vector<int>	__ft;
		std::vector<int> __sd;
	}
	{
		_ft << "\n-------- operators --------\n"; _sd << "\n-------- operators --------\n";
		ft::Vector<int> __ft(10, 5);
		std::vector<int> __sd(10, 5);
		ft::Vector<int>::iterator	b = __ft.begin();
		std::vector<int>::iterator	tb = __sd.begin();
		std::vector<int>::iterator   ttest = __sd.begin();
		ft::Vector<int>::iterator	test = __ft.begin();
		for (; b != __ft.end(); b++)
		   _ft	<< *b;
		for (; tb != __sd.end(); tb++)
			_sd << *tb;
		b = __ft.begin();
		tb = __sd.begin();
		if (test == b)
			_ft  << "==";
		if (tb == ttest)
			_sd << "==";
		test++;
		ttest++;
		if (ttest > tb)
			_sd << ">";
		if (test > b)
			_ft << ">";
		if (b < test)
			_ft << "<";
		if (tb < ttest)
			_sd << "<";
		b++;
		tb++;
		if (test >= b)
			_ft << ">=";
		if (ttest >= tb)
			_sd << ">=";
		__ft[0] = 1; __ft[1] = 2; __ft[2] = 3; __ft[3] = 4; __ft[4] = 5;
		__sd[0] = 1; __sd[1] = 2; __sd[2] = 3; __sd[3] = 4; __sd[4] = 5;
		_sd << __sd[2];
		_ft << __ft[2];
		_sd << ttest[0] << std::endl;
		_ft << test[0] << std::endl;
		test += 2;
		ttest += 2;
		_sd << ttest[0];
		_ft << test[0];
		test -= 1;
		ttest -= 1;
		*test++;
		*ttest++;
		_sd << ttest[0];
		_ft << test[0];
		test = test + 1;
		ttest = ttest + 1;
		_sd << ttest[0];
		_ft << test[0];
		test = test - 1;
		ttest = ttest - 1;
		_sd << ttest[0];
		_ft << test[0];
		test = 1 + test + 1;
		ttest = 1 + ttest + 1;
		_sd << ttest - tb;
		_ft << test - b;
		_sd << tb - ttest;
        _ft << b - test;
		_sd << *tb++;
		_ft << *b++;
		_sd << *tb++;
		_ft << *b++;
		++b;
		++tb;
		_sd << *tb;
		_ft << *b;
		*tb = 10;
		*b = 10;
		_sd << *tb;
		_ft << *b;
		if (test == b)
			_ft << "\n" << true;
		if (ttest == tb)
			_sd << "\n" << true;
		_sd << "\n" << ttest - tb << "\n";
		_ft << "\n" << test - b << "\n";

		b--;
		tb--;
		b--;
		tb--;
		_ft << "\n--------copy constr--------\n"; _sd << "\n--------copy constr--------\n";
		ft::Vector<int>		v1(b, test);
		std::vector<int>	vv1(tb, ttest);

		for (ft::Vector<int>::iterator v1b = v1.begin(); v1b < v1.end(); v1b++)
			_ft << *v1b;
		for (std::vector<int>::iterator vv1b = vv1.begin(); vv1b < vv1.end(); vv1b++)
			_sd << *vv1b;
		_ft << "\n";
        _sd << "\n";

		ft::Vector<int>		v2(v1);
		std::vector<int>	vv2(vv1);
		for (ft::Vector<int>::iterator v2b = v2.begin(); v2b < v2.end(); v2b++)
			_ft << *v2b;
		for (std::vector<int>::iterator vv2b = vv2.begin(); vv2b < vv2.end(); vv2b++)
			_sd << *vv2b;

		_ft << "\n--------oper=--------\n"; _sd << "\n--------oper=--------\n";
		ft::Vector<int>		v3 = v1;
		std::vector<int>	vv3 = vv1;
		for (ft::Vector<int>::iterator v3b = v3.begin(); v3b < v3.end(); v3b++)
			_ft << *v3b;
		for (std::vector<int>::iterator vv3b = vv3.begin(); vv3b < vv3.end(); vv3b++)
			_sd << *vv3b;

		_sd << __sd.size();
		_ft << __ft.size();
		_ft << "\n--------reverse--------\n"; _sd << "\n--------reverse--------\n";
		ft::Vector<int>::const_iterator		cb;
		std::vector<int>::const_iterator	ctb;
		ft::Vector<int>::reverse_iterator	rb = __ft.rbegin();
		std::vector<int>::reverse_iterator	rtb = __sd.rbegin();
		for (; rtb < __sd.rend(); rtb++)
			_sd << *rtb;
		for (; rb < __ft.rend(); rb++)
			_ft << *rb;
		_ft << "\n--------max_size ?--------\n"; _sd << "\n--------max_size ?--------\n";
		_ft << __ft.max_size() << std::endl;
		_sd << __sd.max_size() << std::endl;

		_ft << "\n--------resize ?--------\n"; _sd << "\n--------resize ?--------\n";
		__ft.resize(20, 5);
		__sd.resize(20, 5);
		for (rtb = __sd.rbegin(); rtb < __sd.rend(); rtb++)
            _sd << *rtb;
        for (rb = __ft.rbegin(); rb < __ft.rend(); rb++)
            _ft << *rb;
		if (!__sd.empty())
			_sd << "not_empty\n";
		if (!__ft.empty())
			_ft << "not_empty\n";

		__ft.reserve(100);
		__sd.reserve(100);

		_ft << "\n" << __ft.capacity();
		_sd << "\n" << __sd.capacity();

		_ft << __ft.at(1);
		_sd << __sd.at(1);
		try
		{
			_ft << __ft.at(100);
		}
		catch (std::out_of_range &e)
		{
			_ft << "\nindexout\n";
		}
		try
		{
			_sd << __sd.at(100);
		}
		catch (std::out_of_range &e)
		{
			_sd << "\nindexout\n";
		}

		ft::Vector<int> const v4(10, 10);
		std::vector<int> const vv4(10, 10);
		_sd << vv4.front();
		_ft << v4.front();
		_sd << __sd.back();
		_ft << __ft.back();
		__ft.assign(v1.begin(), v1.end());
		__sd.assign(vv1.begin(), vv1.end());
		for (rtb = __sd.rbegin(); rtb < __sd.rend(); rtb++)
			_sd << *rtb;
		for (rb = __ft.rbegin(); rb < __ft.rend(); rb++)
            _ft << *rb;
		__ft.assign(5, 5);
		__sd.assign(5, 5);
		for (rtb = __sd.rbegin(); rtb < __sd.rend(); rtb++)
            _sd << *rtb;
        for (rb = __ft.rbegin(); rb < __ft.rend(); rb++)
            _ft << *rb;
		ft::Vector<std::string>	v5;
		std::vector<std::string> vv5;

		v5.assign(5, "FLUPPY");
		vv5.assign(5, "FLUPPY");
		for (std::vector<std::string>::iterator it5 = vv5.begin(); it5 != vv5.end(); it5++)
			_sd << *it5;
		for (ft::Vector<std::string>::iterator gg = v5.begin(); gg != v5.end(); gg++)
			_ft << *gg;
		_ft << "\n--------pushb--------\n"; _sd << "\n--------pushb--------\n";
		v5.push_back("DUPPY"); v5.push_back("DUPPY"); v5.push_back("DUPPY");
		v5.push_back("DUPPY"); v5.push_back("DUPPY"); v5.push_back("DUPPY");
		vv5.push_back("DUPPY"); vv5.push_back("DUPPY"); vv5.push_back("DUPPY");
		vv5.push_back("DUPPY"); vv5.push_back("DUPPY"); vv5.push_back("DUPPY");
		for (std::vector<std::string>::iterator it5 = vv5.begin(); it5 != vv5.end(); it5++)
            _sd << *it5;
        for (ft::Vector<std::string>::iterator gg = v5.begin(); gg != v5.end(); gg++)
            _ft << *gg;
		v5.pop_back(); v5.pop_back();
		vv5.pop_back(); vv5.pop_back();
		for (std::vector<std::string>::iterator it5 = vv5.begin(); it5 != vv5.end(); it5++)
            _sd << *it5;
        for (ft::Vector<std::string>::iterator gg = v5.begin(); gg != v5.end(); gg++)
            _ft << *gg;
		v5.pop_back(); vv5.pop_back();
		for (std::vector<std::string>::iterator it5 = vv5.begin(); it5 != vv5.end(); it5++)
            _sd << *it5;
        for (ft::Vector<std::string>::iterator gg = v5.begin(); gg != v5.end(); gg++)
            _ft << *gg;
		_ft << "\n--------popb--------\n"; _sd << "\n--------popb--------\n";
		v5.pop_back(); vv5.pop_back(); v5.pop_back(); vv5.pop_back();
		v5.pop_back(); vv5.pop_back(); v5.pop_back(); vv5.pop_back();
		v5.pop_back(); vv5.pop_back(); v5.pop_back(); vv5.pop_back();
		for (std::vector<std::string>::iterator it5 = vv5.begin(); it5 != vv5.end(); it5++)
            _sd << *it5;
        for (ft::Vector<std::string>::iterator gg = v5.begin(); gg != v5.end(); gg++)
            _ft << *gg;
		_ft << "\n--------popb--------\n"; _sd << "\n--------popb--------\n";
		v5.pop_back(); vv5.pop_back(); v5.pop_back(); vv5.pop_back();
		for (std::vector<std::string>::iterator it5 = vv5.begin(); it5 != vv5.end(); it5++)
            _sd << *it5;
        for (ft::Vector<std::string>::iterator gg = v5.begin(); gg != v5.end(); gg++)
            _ft << *gg;
		v5.pop_back(); v5.pop_back(); //vv5.pop_back(); v5.pop_back(); vv5.pop_back();
		for (std::vector<std::string>::iterator it5 = vv5.begin(); it5 != vv5.end(); it5++)
            _sd << *it5;
        for (ft::Vector<std::string>::iterator gg = v5.begin(); gg != v5.end(); gg++)
            _ft << *gg;
		_ft << "\n--------pushb--------\n"; _sd << "\n--------pushb--------\n";
		v5.push_back("DUPPY"); v5.push_back("DUPPY"); v5.push_back("DUPPY");
		vv5.push_back("DUPPY"); vv5.push_back("DUPPY"); vv5.push_back("DUPPY");
		for (std::vector<std::string>::iterator it5 = vv5.begin(); it5 != vv5.end(); it5++)
            _sd << *it5;
        for (ft::Vector<std::string>::iterator gg = v5.begin(); gg != v5.end(); gg++)
            _ft << *gg;
		_sd << vv5.size();
		_ft << v5.size();
		_ft << "\n--------insert--------\n"; _sd << "\n--------insert--------\n";
		v5.insert(v5.begin(), "HOHO");
		vv5.insert(vv5.begin(), "HOHO");
		for (std::vector<std::string>::iterator it5 = vv5.begin(); it5 != vv5.end(); it5++)
            _sd << *it5;
        for (ft::Vector<std::string>::iterator gg = v5.begin(); gg != v5.end(); gg++)
            _ft << *gg;
		_sd << "\n\n";
        _ft << "\n\n";
		v5.insert(v5.begin() + 2, "TOTO");
		vv5.insert(vv5.begin() + 2, "TOTO");
		for (std::vector<std::string>::iterator it5 = vv5.begin(); it5 != vv5.end(); it5++)
            _sd << *it5;
        for (ft::Vector<std::string>::iterator gg = v5.begin(); gg != v5.end(); gg++)
            _ft << *gg;
		v5.reserve(20);
		v5.insert(v5.begin() + 1, 5, "1");
		vv5.insert(vv5.begin() + 1, 5, "1");
		for (std::vector<std::string>::iterator it5 = vv5.begin(); it5 != vv5.end(); it5++)
            _sd << *it5;
		for (ft::Vector<std::string>::iterator gg = v5.begin(); gg != v5.end(); gg++)
            _ft << *gg;
		v5.insert(v5.begin() + 1, 15, "1");
        vv5.insert(vv5.begin() + 1, 15, "1");
		for (std::vector<std::string>::iterator it5 = vv5.begin(); it5 != vv5.end(); it5++)
            _sd << *it5;
        for (ft::Vector<std::string>::iterator gg = v5.begin(); gg != v5.end(); gg++)
            _ft << *gg;
		ft::Vector<std::string>	v6;
		std::vector<std::string> vv6;

		_sd << "\n\n";
        _ft << "\n\n";
		v6.insert(v6.begin(), v5.begin() + 20, v5.end() - 1);
		vv6.insert(vv6.begin(), vv5.begin() + 20, vv5.end() - 1);
		for (std::vector<std::string>::iterator it = vv6.begin(); it != vv6.end(); it++)
            _sd << *it;
        for (ft::Vector<std::string>::iterator gg = v6.begin(); gg != v6.end(); gg++)
            _ft << *gg;
		v6.insert(v6.begin(), v5.begin() + 20, v5.end() - 1);
        vv6.insert(vv6.begin(), vv5.begin() + 20, vv5.end() - 1);
		for (std::vector<std::string>::iterator it = vv6.begin(); it != vv6.end(); it++)
            _sd << *it;
        for (ft::Vector<std::string>::iterator gg = v6.begin(); gg != v6.end(); gg++)
            _ft << *gg;

		_ft << "\n--------insert<int>it--------\n"; _sd << "\n--------insert<int>it--------\n";
		ft::Vector<int> i1;
		std::vector<int> ii1;
		i1.insert(i1.end(), v4.begin() + 2, v4.end() - 1);
		ii1.insert(ii1.end(), vv4.begin() + 2, vv4.end() - 1);
		for (std::vector<int>::iterator it = ii1.begin(); it != ii1.end(); it++)
            _sd << *it;
        for (ft::Vector<int>::iterator gg = i1.begin(); gg != i1.end(); gg++)
            _ft << *gg;
		i1.erase(i1.begin());
		ii1.erase(ii1.begin());
		for (std::vector<int>::iterator it = ii1.begin(); it != ii1.end(); it++)
            _sd << *it;
        for (ft::Vector<int>::iterator gg = i1.begin(); gg != i1.end(); gg++)
            _ft << *gg;
		_ft << "\n--------erase<int>--------\n"; _sd << "\n--------erase<int>--------\n";
		i1.erase(i1.begin());i1.erase(i1.begin());i1.erase(i1.begin());
		i1.erase(i1.begin());
		ii1.erase(ii1.begin());ii1.erase(ii1.begin());ii1.erase(ii1.begin());
		ii1.erase(ii1.begin());
		for (std::vector<int>::iterator it = ii1.begin(); it != ii1.end(); it++)
            _sd << *it;
        for (ft::Vector<int>::iterator gg = i1.begin(); gg != i1.end(); gg++)
            _ft << *gg;
		_sd << "\n";
        _ft << "\n";
		__ft.erase(__ft.begin() + 2, __ft.end() - 1);
		__sd.erase(__sd.begin() + 2, __sd.end() - 1);
		for (std::vector<int>::iterator it = __sd.begin(); it != __sd.end(); it++)
            _sd << *it;
        for (ft::Vector<int>::iterator gg = __ft.begin(); gg != __ft.end(); gg++)
            _ft << *gg;
		__ft.erase(__ft.begin(), __ft.begin() + 1);
        __sd.erase(__sd.begin(), __sd.begin() + 1);
		_sd << "\n";
        _ft << "\n";
		for (std::vector<int>::iterator it = __sd.begin(); it != __sd.end(); it++)
            _sd << *it;
        for (ft::Vector<int>::iterator gg = __ft.begin(); gg != __ft.end(); gg++)
            _ft << *gg;
		__ft.erase(__ft.begin(), __ft.begin() + 2);
        __sd.erase(__sd.begin(), __sd.begin() + 2);
		_sd << "\n";
        _ft << "\n";
		for (std::vector<int>::iterator it = __sd.begin(); it != __sd.end(); it++)
            _sd << *it;
        for (ft::Vector<int>::iterator gg = __ft.begin(); gg != __ft.end(); gg++)
            _ft << *gg;
		v6.clear();
		vv6.clear();
		for (std::vector<std::string>::iterator it = vv6.begin(); it != vv6.end(); it++)
            _sd << *it;
        for (ft::Vector<std::string>::iterator gg = v6.begin(); gg != v6.end(); gg++)
            _ft << *gg;

		_ft << "\n--------swap--------\n"; _sd << "\n--------swap--------\n";
		v6.swap(v5);
		vv6.swap(vv5);
		for (std::vector<std::string>::iterator it = vv6.begin(); it != vv6.end(); it++)
            _sd << *it;
        for (ft::Vector<std::string>::iterator gg = v6.begin(); gg != v6.end(); gg++)
            _ft << *gg;
		_ft << "\n--------opers--------\n"; _sd << "\n--------opers--------\n";
		if (v6 != v5)
			_ft << "f";
		if (vv6 != vv5)
			_sd << "f";
		v6 = v5;
		vv6 = vv5;
		if (v6 == v5)
            _ft << "t";
        if (vv6 == vv5)
            _sd << "t";
		if (v6 <= v5)
            _ft << "t";
        if (vv6 <= vv5)
            _sd << "t";
		if (v6 >= v5)
            _ft << "t";
        if (vv6 >= vv5)
            _sd << "t";
	}
	ft::Vector<int>		my;
	std::vector<int>	test;

	_ft << "\n";
	_sd << "\n";
	std::cout << "Vector\t\t[OK]" << std::endl;
}
