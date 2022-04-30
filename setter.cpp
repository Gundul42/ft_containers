#include "set.hpp"
#include "vector.hpp"
#include "map.hpp"
#include <string>

int main(void)
{
		std::string					str;
		ft::set<int>				S2;
		ft::set<std::string>		S1;
		ft::vector<char>			V1;
		ft::vector<char>			V2;
		ft::map<std::string, long>	M1;
		ft::map<std::string, long>	M2;

		S1.insert("Kuemmel");
		S1.insert("Luemmel");
		S1.insert("Stange");
		S1.insert("Torte");

		std::cout << "Size is : "<< S1.size() << std::endl;

		S1.erase("Luemmel");

		std::cout << "Size is : "<< S1.size() << std::endl;
		
		if (S1 > S2)
				std::cout << "small" << std::endl;
		return (0);
}
