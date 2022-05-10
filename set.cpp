
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

	ft::set<std::string> m1;
	ft::set<std::string>::reverse_iterator mrev2;
	ft::set<std::string>::const_iterator mci1;
	ft::set<std::string>::iterator mi1;

	std::cout << m1.empty() << std::endl;

	m1.insert("CPU");
	m1.insert("GPU");
	m1.insert("RAM");

	std::cout << m1.empty() << std::endl;

	print_set(m1, "Initial map: ");


	mci1 = m1.begin();
	std::cout << "const iterator" << std::endl;
	while (mci1 != m1.end())
	{
			std::cout << (*mci1) << std::endl;
			mci1++;
	}
	std::cout << "iterator" << std::endl;
	mi1 = m1.begin();
	while (mi1 != m1.end())
	{
			std::cout << (*mi1) << std::endl;
			mi1++;
	}
	std::cout << "reverse_iterator" << std::endl;
	mrev2 = m1.rbegin();
	while (mrev2 != m1.rend())
	{
			std::cout << (*mrev2) << std::endl;
			mrev2++;
	}
	std::cout << "const_reverse_iterator" << std::endl;
	ft::set<std::string>::const_reverse_iterator mrev1;
	ft::set<std::string>::const_reverse_iterator mrev3;
	mrev1 = m1.rbegin();
	mrev3 = m1.rend();
	while (mrev1 != m1.rend()) //rev3)
	{
			std::cout << (*mrev1) << std::endl;
			mrev1++;
	}
	return (0);
}
