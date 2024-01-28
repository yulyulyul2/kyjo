#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cmath>
# include <sstream>

class ScalarConverter
{
	private:
		ScalarConverter (void);
		ScalarConverter (const ScalarConverter & obj);
		static char c;
		static int	i;
		static double d;
		static float f;
		static void printC(void);
		static void printI(void);
		static void printD(void);
		static void printF(void);
	public:
		ScalarConverter & operator=(const ScalarConverter & obj);
		~ScalarConverter (void);
		static void convert(std::string str);
};

std::ostream& operator<<(std::ostream &out, const ScalarConverter  &b);

#endif
