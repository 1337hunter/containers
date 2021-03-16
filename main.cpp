#include <iostream>
#include <fstream>

void	list_test(std::ofstream&, std::ofstream&);
void	vector_test(std::ofstream &_ft, std::ofstream &_sd);
void    map_test(std::ofstream &_ft, std::ofstream &_sd);
void    stack_test(std::ofstream &_ft, std::ofstream &_sd);
void    queue_test(std::ofstream &_ft, std::ofstream &_sd);

int	main(void)
{
	std::ofstream   _ft;
    std::ofstream   _sd;

	_ft.open("./ft", std::ios::trunc | std::ios::out);
    _sd.open("./sd", std::ios::trunc | std::ios::out);
	list_test(_ft, _sd);
	vector_test(_ft, _sd);
	map_test(_ft, _sd);
	stack_test(_ft, _sd);
	queue_test(_ft, _sd);
}
