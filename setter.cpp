#include "set.hpp"
#include "vector.hpp"
#include "map.hpp"
#include <string>

int main(void)
{
		std::string			str;
		ft::set<int>		i;
		ft::set<std::string>		tst;


		tst.insert("Kuemmel");
		tst.insert("Luemmel");
		tst.insert("Stange");
		tst.insert("Torte");

		std::cout << "Size is : "<< tst.size() << std::endl;

		tst.erase("Luemmel");

		std::cout << "Size is : "<< tst.size() << std::endl;
		return (0);
}
