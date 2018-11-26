#pragma once

#include <map>
#include <vector>
#include "denomination.h"

class Branch;

class Base
{	
public:
	Base();
	void addStringsTo(std::vector<std::string>& vec);

	Denomination d_max;
	std::map<Denomination, unsigned int> d_count;

	std::vector<Branch*> sub_branches;
};

class Branch : Base {
public:
	Branch(Denomination collapse_by, Base* parent);
	using Base::addStringsTo;
};

class Trunk : Base {
public:
	Trunk(int amt);
	using Base::addStringsTo;
};