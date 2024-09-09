// variadic templates (C++11)
// variadic lambdas (C++14)
// fold expressions (C++17)

void lambda()
{
	auto l = [](auto ... value) noexcept
		-> long { return (value + ...); };

	auto result = l(1, 2, 3, 4, 5, 6);
}

class Lambda {
public:
	template<typename ... T>
	[[nodiscard]] constexpr auto operator()(T ... value) const noexcept -> long
	{
		return (value + ...);
	}
};

void equivalent()
{
	auto l = Lambda{};

	auto result = l(1, 2, 3, 4, 5, 6);
}