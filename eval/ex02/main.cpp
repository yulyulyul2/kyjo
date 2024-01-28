#include "Base.hpp"

int main()
{
	Base *base;

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	base = generate();
	identify(base);
	identify(*base);
	delete base;

	return (0);
}