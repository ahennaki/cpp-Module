#include "easyfind.hpp"

int main()
{
    std::vector<int>	vec;

	for (size_t i = 0; i < 10; i++)
		vec.push_back(i);
	easyfind(vec, 4);
	easyfind(vec, 10);
    return 0;
}
