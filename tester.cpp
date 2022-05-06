#include "map.hpp"
#include <set>
#include <iostream>

template<typename T, typename U>
void	print_map(const ft::map<T, U>& m, std::string comment = "")
{
	std::cout << comment;
	for (typename ft::map<T, U>::const_iterator it = m.begin(); it != m.end(); it++)
		std::cout << it->first << " = " << it->second << "; ";
	std::cout << '\n';
}

int	main(void)
{
		ft::map<std::string, int>	m1;
		ft::map<std::string, int>	m2;
		ft::map<std::string, int>::iterator	mit1;
		ft::map<std::string, int>::iterator	mit2;

		m1.insert(ft::make_pair("LOLO", 192));
		m1.insert(ft::make_pair("Luemmel", 193));
		m1["Klais"] = 194;
		m1["Hermmi"] = 195;
		//m1["ussel"] = 196;
		m1["luel"] = 197;
		m1["Gargamel"] = 198;
		m1["Aamel"] = 198;
		mit1 = m1.begin();
		mit2 = m1.end();
		
		m1.erase(mit1, mit2);
		print_map(m1);
		
		mit1 = m1.find("Hermi");
		if (mit1 != m1.end())
			std::cout << (*mit1).second << std::endl;
		else
			std::cout << "Key not found" << std::endl;
		print_map(m1);
		/*
		std::set<int>				lolo;
		std::set<int>::iterator		l;

		lolo.insert(123);
		lolo.insert(125);
		lolo.insert(127);
		l = lolo.end();

		std::cout << *l << std::endl;
*/
		return (0);
}



