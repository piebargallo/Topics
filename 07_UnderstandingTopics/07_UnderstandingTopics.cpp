// function attributes (C++11)
// concepts (C++20)

#include <concepts>
#include <utility>

void lambda()
{
	auto l = []<std::size_t ... Idx> (std::index_sequence<Idx...>) noexcept
		-> long {
		return (Idx + ...);
	};

	auto result = l(std::make_index_sequence<10>());
}

class Lambda {
public:
	template<std::size_t ... Idx>
	constexpr auto operator()(std::index_sequence<Idx...>) const noexcept -> long
	{
		return (Idx + ...);
	}
};

void equivalent()
{
	auto l = Lambda{};

	auto result = l(std::make_index_sequence<10>());
}