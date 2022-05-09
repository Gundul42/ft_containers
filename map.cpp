
#include <algorithm>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <deque>
#include <time.h>

#if 0 //CREATE A REAL STL EXAMPLE
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

	ft::map<std::string, int> m1;
	ft::map<std::string, int>::reverse_iterator mrev2;
	ft::map<std::string, int>::const_iterator mci1;
	ft::map<std::string, int>::iterator mi1;

	std::cout << m1.empty() << std::endl;

	m1["CPU"] = 10;
	m1["GPU"] = 15;
	m1["RAM"] = 20;

	std::cout << m1.empty() << std::endl;

	print_map(m1, "Initial map: ");

	m1["CPU"] = 25;
	m1["SSD"] = 30;
	print_map(m1, "Updated map: ");

	std::cout << "m1[UPS] = " << m1["UPS"] << '\n';
	print_map(m1, "Updated map: ");
	mci1 = m1.begin();
	std::cout << "const iterator" << std::endl;
	while (mci1 != m1.end())
	{
			std::cout << (*mci1).first << std::endl;
			mci1++;
	}
	std::cout << "iterator" << std::endl;
	mi1 = m1.begin();
	while (mi1 != m1.end())
	{
			std::cout << (*mi1).first << std::endl;
			mi1++;
	}
	std::cout << "reverse_iterator" << std::endl;
	mrev2 = m1.rbegin();
	while (mrev2 != m1.rend())
	{
			std::cout << (*mrev2).first << std::endl;
			mrev2++;
	}
	
	std::cout << "const_reverse_iterator" << std::endl;
	ft::map<std::string, int>::const_reverse_iterator mrev1;
	ft::map<std::string, int>::const_reverse_iterator mrev3;
	mrev1 = m1.rbegin();
	mrev3 = m1.rend();
	while (mrev1 != mrev3)
	{
			std::cout << (*mrev1).first << std::endl;
			mrev1++;
	}
	
	return (0);
}
