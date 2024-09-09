// non-type template parameters (C++98)
// integer sequences (C++11)
// template parameter pattern matching (C++11)
// explicit lambda templates (C++17)
// unpacking of tuples (C++11)
// variadic 'sizeof...()' operator (C++11)

#include <concepts>
#include <utility>
#include <tuple>

void lambda()
{
	auto sum_tuple = []<typename ... T>(const std::tuple<T...> &input) {
		return[]<std::size_t ... Idx>(std::index_sequence<Idx...>, const auto & tuple) {
			return (std::get<Idx>(tuple) + ...);
		}(std::make_index_sequence<sizeof...(T)>(), input);
	};
		
	auto result = sum_tuple(std::make_tuple(1, 211, 31, 4.5));
}

class Lambda {
	struct Lambda_ {
		template<std::size_t ... Idx, typename Tuple>
		constexpr auto operator()(std::index_sequence<Idx...>, const auto& tuple) {
			return(std::get<Idx>(tuple) + ...);
		}
	};
public:
	template<typename ... T>
	constexpr auto operator()(const std::tuple<T...> &input) const noexcept
	{
		return Lambda_{}(std::make_index_sequence<sizeof...(T)>(), input);
	}
};

void equivalent()
{
	auto sum_tuple = Lambda{};
	auto result = sum_tuple(std::make_tuple(1, 211, 31, 4.5));
}