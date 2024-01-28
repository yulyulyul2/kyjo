#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <sys/_types/_uintptr_t.h>

struct Data
{
	int i;
	Data(int i) : i(i) {};
};

class Serializer 
{
	private:
		Serializer(void);
		Serializer(const Serializer& obj);
	public:
		Serializer& operator=(const Serializer& obj);
		~Serializer(void);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif