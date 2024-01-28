#include "ScalarConverter.hpp"

char ScalarConverter::c = 0;
int ScalarConverter::i = 0;
double ScalarConverter::d = 0.0;
float ScalarConverter::f = 0.0f;

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	(void)obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	(void)obj;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

void ScalarConverter::printC(void)
{
	std::cout << "char: ";
	if (isnan(d) || isinf(d))
		std::cout << "impossible";
	else if (i >= 32 && i <= 126)
		std::cout << c;
	else if (i < 32 && i >= 0)
		std::cout << "Non displayable";
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void ScalarConverter::printI(void)
{
	std::cout << "int: ";
	if (isnan(d) || isinf(d))
		std::cout << "impossible";
	else
		std::cout << i;
	std::cout << std::endl;
}

void ScalarConverter::printF(void)
{
	std::cout << "float: ";
	if (isnan(d))
		std::cout << "nanf";
	else if (isinf(d))
	{
		if (d > 0)
			std::cout << "inff";
		else
			std::cout << "-inff";
	}
	else
	{
		float temp = static_cast<float>(i);
		if (static_cast<int>(temp) != i)
			std::cout << "impossible";
		else
		{
			std::stringstream ss;
			ss << i;
			if (static_cast<float>(i) == f && ss.str().length() <= 6)
			{
				std::cout << f << ".0f";
			}
			else
			{
				std::cout << f << "f";
			}
		}

	}
	std::cout << std::endl;
}

void ScalarConverter::printD(void)
{
	std::cout << "double: ";
	if (isnan(d))
		std::cout << "nan";
	else if (isinf(d))
	{
		if (d > 0)
			std::cout << "inf";
		else
			std::cout << "-inf";
	}
	else
	{
		double temp = static_cast<double>(i);
		if (static_cast<int>(temp) != i)
			std::cout << "impossible";
		else
		{
			std::stringstream ss;
			ss << i;
			if (static_cast<double>(i) == d && ss.str().length() <= 6)
			{
					std::cout << d << ".0";
			}
			else
			{
				std::cout << d;
			}
		}
	}
	std::cout << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	if (str == "nan" || str == "nanf")
	{
		d = sqrt(-1.0);
	}
	else if (str == "inf" || str == "+inf" || str == "inff" || str == "+inff")
	{
		d = std::numeric_limits<double>::infinity();
	}
	else if (str == "-inf" || str == "-inff")
	{
		d = -std::numeric_limits<double>::infinity();
	}
	else if (str.length() == 1 && !std::isdigit(static_cast<char>(str[0])))
	{
		c = static_cast<char>(str[0]);
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<float>(c);
	}
	else if (str.find('.') == std::string::npos)
	{
		if (str[0] == '+')
			str.erase(0, 1);
		i = atoi(str.c_str());

		std::stringstream ss;
		ss << i;
		if (ss.str() != str)
		{
			std::cout << "can not convert" << std::endl;
			exit(1);
		}
		else
		{
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
		}
	}
	else
	{
		if (str[0] == '+')
			str.erase(0, 1);
		char* endptr;

		d = strtod(str.c_str(), &endptr);
		if (*endptr && !(*endptr == 'f' && endptr == &str[str.length() - 1]))
		{
			std::cout << "can not convert" << std::endl;
			exit(1);
		}
		else
		{
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
		}
	}
	printC();
	printI();
	printF();
	printD();
}