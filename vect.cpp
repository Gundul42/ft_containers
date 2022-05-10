
#include <algorithm>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <deque>
#include <time.h>

#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;

#else

	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	#include "set.hpp"

#endif

template<typename T>
void	print_vector(ft::vector<T>& v, size_t id = 0, const std::string& delimiter = " ")
{
	std::cout << "vector" << id << ": " << "[ ";
	for (typename ft::vector<T>::iterator it1 = v.begin(); it1 != v.end(); it1++)
		std::cout << *it1 << delimiter;
	std::cout << "]" << std::endl;
}

template<typename T, typename U>
void	print_map(const ft::map<T, U>& m, std::string comment = "")
{
	std::cout << comment;
	for (typename ft::map<T, U>::const_iterator it = m.begin(); it != m.end(); it++)
		std::cout << it->first << " = " << it->second << "; ";
	std::cout << '\n';
}

template<typename T>
void	print_stack(ft::stack<T> s, size_t id = 0, const std::string& delimiter = "\n")
{
	size_t n_elems = s.size();
	std::cout << "stack" << id << ":\n";
	for (; !s.empty(); --n_elems)
	{
		std::cout << "[ " << s.top() << " ]" << delimiter;
		s.pop();
	}
}

template<typename T>
void print_set(const ft::set<T>& s, std::string comment = "")
{
	std::cout << comment;
	for (typename ft::set<T>::const_iterator it = s.begin(); it != s.end(); it++)
		std::cout << *it << " -> ";
	std::cout << "(end)" << std::endl;
}

#include <stdlib.h>
int	main(void)
{
	ft::set<std::string>					s1;
	ft::set<std::string>::reverse_iterator	srev2;
	ft::set<std::string>::const_iterator	sci1;
	ft::set<std::string>::iterator			si1;

	std::cout << s1.empty() << std::endl;

	s1.insert("CPU");
	s1.insert("GPU");
	s1.insert("RAM");

	std::cout << s1.empty() << std::endl;

	print_set(s1, "Initial map: ");


	sci1 = s1.begin();

	std::cout << "const iterator" << std::endl;
	while (sci1 != s1.end())
	{
			std::cout << (*sci1) << std::endl;
			sci1++;
	}
	std::cout << "iterator" << std::endl;
	si1 = s1.begin();
	si1 += 2;
	while (si1 != s1.end())
	{
			std::cout << (*si1) << std::endl;
			si1++;
	}
	std::cout << "reverse_iterator" << std::endl;
	srev2 = s1.rbegin();
	while (srev2 != s1.rend())
	{
			std::cout << (*srev2) << std::endl;
			srev2++;
	}
	std::cout << "const_reverse_iterator" << std::endl;
	ft::set<std::string>::const_reverse_iterator srev1;
	ft::set<std::string>::const_reverse_iterator srev3;
	srev1 = s1.rbegin();
	srev3 = s1.rend();
	while (srev1 != s1.rend()) //rev3)
	{
			std::cout << (*srev1) << std::endl;
			srev1++;
	}
	return (0);
}
