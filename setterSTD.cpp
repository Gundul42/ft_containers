
#include <set>
#include <vector>
#include <map>
#include <string>
#include <iostream>

int main(void)
{
		std::string					str;
		std::set<int>				S2;
		std::set<std::string>		S1;
		std::vector<char>			V1;
		std::vector<char>			V2;
		std::map<std::string, long>	M1;
		std::map<std::string, long>	M2;

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
