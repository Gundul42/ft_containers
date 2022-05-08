
#include <list>
#include <deque>
#include <iostream>
#include <ctime>
#include <map>

#if 1
# include "stack.hpp"
  using namespace ft;

#else

# include <stack>
# include <vector>
  using namespace std;

#endif

void	stack_basiques()
{
	char	a = 'b';
	char	b = 'b';
	
	//member_functions
	vector<char>	v1;
	vector<char>	v2;
	stack<char> s1;
	std::cout << s1.size() << std::endl;
	stack<char> d;
	d.push('d');
	d.push('q');
	stack<char> s2 = d;
	s2.push('!');
	for (;!s2.empty(); s2.pop())
		std::cout << s2.top() << std::endl;
	//non_member functions oerloads
	s2.push(a);
	s1.push(b);
	std::cout << "size s1: " << s1.size() << "   size s2: " << s2.size() << std::endl;
	std::cout << "==   " << (s1 == s2) << std::endl;
	std::cout << "!=   " << (s1 != s2) << std::endl;
	std::cout << " <   " << (s1 < s2) << std::endl;
	std::cout << "<=   " << (s1 <= s2) << std::endl;
	std::cout << " >   " << (s1 > s2) << std::endl;
	std::cout << ">=   " << (s1 >= s2) << std::endl;
	std::cout << std::endl << std::endl;
	v2.push_back(a);
	v1.push_back(b);
	std::cout << "size v1: " << v1.size() << "   size v2: " << v2.size() << std::endl;
	std::cout << "==   " << (v1 == v2) << std::endl;
	std::cout << "!=   " << (v1 != v2) << std::endl;
	std::cout << " <   " << (v1 < v2) << std::endl;
	std::cout << "<=   " << (v1 <= v2) << std::endl;
	std::cout << " >   " << (v1 > v2) << std::endl;
	std::cout << ">=   " << (v1 >= v2) << std::endl;
}

int		main()
{
	stack_basiques();
	return 1;
}
