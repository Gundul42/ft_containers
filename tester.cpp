#include "map.hpp"
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
		ft::map<std::string, int>::reverse_iterator	mit2;

		m1["LOLO"] = 192;
		m1["luemmel"] = 193;
		m1["Klais"] = 194;
		m1["Hermmi"] = 195;
		m1["ussel"] = 196;
		m1["luel"] = 197;
		m1["Gargamel"] = 198;
		m1["Aamel"] = 198;

		mit1 = m1.begin();
		while (mit1 != m1.end())
		{
				std::cout << (*mit1).first << ", ";
				mit1++;
		}
		std::cout << std::endl;

		mit2 = m1.rbegin();
		while (mit2 != m1.rend())
		{
				std::cout << (*mit2).first << ", ";
				mit2++;
		}
		std::cout << std::endl;
		
		mit1 = m1.end();
		
		mit1--;
		if (mit1 == m1.end())
				std::cout << "NULL" << std::endl;
		else
				std::cout << (*mit1).first << std::endl;
		print_map(m1);
		return (0);
}



