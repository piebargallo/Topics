// <functional>
#include <functional>

std::vector<int> get_data(){}

auto lambda()
{
	std::function f = [i = 42](int j, bool b) mutable {
		if (b) {
			return i++;
		}
		else {
			return j;
		}
	};

	auto f2 = f;
}