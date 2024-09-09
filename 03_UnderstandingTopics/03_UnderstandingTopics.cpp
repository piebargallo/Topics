// trailing return types (C++11)

void lambda()
{
	auto l = []([[maybe_unused]] int value, int &value2)
		-> long { return ++value + value2++; };

	long (*fp)(int, int&) noexcept;
}

struct Lambda
{
	constexpr auto operator()([[maybe_unused]] int value, int& value2)
		const -> long {
		return ++value + value2++;
	}
};

void equivalent()
{
	auto l = Lambda{};

	long (*fp)(int, int&) noexcept;
}