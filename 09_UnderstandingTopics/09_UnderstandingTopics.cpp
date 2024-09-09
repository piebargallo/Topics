// direct-initialization of members (C++11)

void lambda()
{
	int i = 42;
	int j = 24;
	auto l = [i, &j]() mutable {++j; return ++i; };
	l();
	auto l2 = l;
	l();
	l();
}

struct Lambda {
	constexpr auto operator()() {
		return ++i;
	}
	int i;
	int& j;
};

void equivalent()
{
	int i = 42;
	int j = 24;
	auto l = Lambda{i, j };
	l();
	auto l2 = l;
	l();
	l();
}