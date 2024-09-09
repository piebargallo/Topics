// object layout (C++98)
// member padding (C++98)
// order of construction / destruction (C++98)
// generalized lambda capture (C++14)
// inmediately invoked lambdas (C++11)
// return value optimization (C++98)
// guaranteed return value optimization (C++17)
// initialized-list (C++11)

#include <vector>

auto lambda()
{
	const auto data = [](int i) {
		return std::vector<int>{1, 2, 3, 4, i};
	}(42);
}
