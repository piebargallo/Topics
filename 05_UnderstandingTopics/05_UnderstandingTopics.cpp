// templates (C++98)
// template argument type deduction (C++98)
// alias templates (C++11)
// template instantiations (C++98)
// noexcept (C++11)
// noexcept in the type system (C++17)

void lambda()
{
	auto l = [](auto value, int& value2)
		-> long { return ++value + value2++; };
	long (*fp)(int, int&) noexcept;
}

class Lambda
{
	template<typename T>
	using pointer_type = long (*)(T, int&);

	template<typename T>
	constexpr static auto FUNC(T value, int& value2) -> long
	{
		return ++value + value2++;
	}

	constexpr static auto FUNC_int(int value, int& value2) -> long
	{
		return ++value + value2++;
	}

public:

	template<typename T>
	constexpr auto operator()(T value, int& value2) const -> long
	{
		return ++value + value2++;
	}

	template<typename T>
	constexpr operator pointer_type<T>() const {
		return FUNC;
	}

	constexpr operator pointer_type<int>() const {
		return FUNC_int;
	}
};

void equivalent()
{
	auto l = Lambda{};
}