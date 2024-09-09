// inheritance (C++98)
// multiple inheritance (C++98)
// function hiding (C++98)
// variadic 'using' declarations (C++17)
// scoping / lookupg rules (C++98)
// class template argument deduction (C++17)
// deduction guides (C++17)

template<typename ... Ts>
struct overloaded : Ts... { using Ts::operator()...; };

template<typename ... Ts> overloaded(Ts...) -> overloaded<Ts...>;

auto lambda()
{
	auto overloaded_set = overloaded{
		[](int x) { return x + 42; },
		[](int x, int y) { return x + y; }
	};

	return overloaded_set(12);
}