#include <sstream>
#include "branch.h"

Base::Base() = default;

void Base::addStringsTo(std::vector<std::string>& vec)
{
	std::ostringstream ss;
	for (auto d : denomination)
	{
		for (unsigned int i = 0; i < d_count[d]; i++)
		{
			ss << d << "+";
		}
	}

	auto str = ss.str();
	str = str.substr(0, str.length() - 1);

	vec.push_back(str);

	for (auto* branch : sub_branches)
	{
		branch->addStringsTo(vec);
	}
}

Branch::Branch(Denomination collapse_by, Base* parent)
{
	d_max = collapse_by;
	d_count = parent->d_count;
	d_count[1] -= collapse_by;
	d_count[collapse_by] += 1;

	for (auto d : denomination)
	{
		if (d > d_max || d > d_count[1] || d == 1U)
		{
			continue;
		}

		this->sub_branches.push_back(new Branch(d, this));
	}
}

Trunk::Trunk(int amt)
{
	d_max = denomination[0];
	d_count = {};
	d_count[1] = amt;

	for (auto d : denomination)
	{
		if (d > d_max || d > d_count[1])
		{
			continue;
		}

		this->sub_branches.push_back(new Branch(d, this));
	}
}
