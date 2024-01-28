#include "Serializer.hpp"

int main(void)
{
    Data before(42);

	std::cout << "before : " << before.i << std::endl;
    uintptr_t serializedPtr = Serializer::serialize(&before);
    std::cout << "after  : " << Serializer::deserialize(serializedPtr)->i << std::endl;

    return (0);
}