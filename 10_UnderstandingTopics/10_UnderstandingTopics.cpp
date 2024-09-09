// member copies

auto lambda()
{
	auto l = [a = 1, b = true, c = 2, d = false]() {};
}

struct Lambda {
	constexpr auto operator()() { }
	int a;
	bool b;
	int c;
	bool d;
};

auto equivalent()
{
	auto l = Lambda{ 1, true, 2, false };
}