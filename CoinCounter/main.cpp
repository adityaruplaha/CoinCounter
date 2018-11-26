#include <iostream>
#include "branch.h"

int main()
{
	int amt;
	std::cout << "Enter amount: ";
	std::cin >> amt;

	std::cout << "Please wait while tree is constructed...\n";
	auto* trunk = new Trunk(amt);

	std::vector<std::string> vec{};
	trunk->addStringsTo(vec);

	vec.pop_back();
	delete trunk;

	char p;
	std::cout << "Tree constructed. " << vec.size() << " results found.\n";
	std::cout << "Print results? (y/N): ";
	std::cin >> p;

	if (p == 'y' || p == 'Y')
	{
		for (auto s : vec)
		{
			std::cout << "|=>  " << s.c_str() << "\n";
		}
	}

	return 0;
}