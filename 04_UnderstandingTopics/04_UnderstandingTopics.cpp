// class vs struct (C++98)
// private vs public (C++98)
// implicit conversions (C++ 98)
// function pointers (C++98)
// static member functions (C++98)
// using aliases (C++11)
// efficiency when chaining functions

class Lambda
{
	using pointer_type = long (*)(int, int&);
	constexpr static auto FUNC([[maybe_unused]] int value, int& value2) -> long
	{
		return ++value + value2++;
	}

public:
	constexpr auto operator()([[maybe_unused]] int value, int& value2) const -> long
	{
		return ++value + value2++;
	}

	constexpr operator pointer_type() const {
		return FUNC;
	}
};