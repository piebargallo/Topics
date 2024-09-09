// algorithms (C++11)
// ranges (C++20)

#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> get_data(){}

auto lambda()
{
	auto l = [i = 0](int value) mutable {
		std::cout << value << ": " << i++ << '\n';
	};

	std::ranges::for_each(get_data(), l);
	std::ranges::for_each(get_data(), std::ref(l));
	std::ranges::for_each(get_data(), l);
}