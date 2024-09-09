// Lambdas (C++11)
// struct (C++98)
// constexpr (C++11)
// operator overloading (C++98)
// call operator (C++98)
// const member functions (C++98)
// braced initialization (C++11)
// 'auto' return type deduction (C++14)
// function parameters (C++98)
// pass-by-value (C++98)
// attributes on parameters (C++11)
// pass-by-reference (C++98)
// pass-by-value vs pass-by-reference (C++98)
// pre-increment vs post-increment

void lambda()
{
	auto l = []([[maybe_unused]] int value, int& value2) {
		return ++value + value2++;
	};

	int i = 13;
	l(42, i);
}

struct Lambda
{
	constexpr auto operator()([[maybe_unused]] int value, int& value2) const {
		return ++value + value2++;
	}
};

void equivalent()
{
	auto l = Lambda{};

	int i = 13;
	l(42, i);
}