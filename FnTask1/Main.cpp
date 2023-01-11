#include <algorithm>
#include <iostream>
#include <string>

using std::string;

string convert(string str)
{
	std::transform(str.begin(), str.end(), str.begin(), toupper);

	string result(str.length(), '(');

	for (size_t i = 0; i < str.length(); ++i)
	{
		const auto& ch = str[i];
		if (str.find(ch) != str.rfind(ch))
		{
			result[i] = ')';
		}
	}

	return result;
}


bool test1()
{
	return convert("din") == "(((";
}

bool test2()
{
	return convert("recede") == "()()()";
}

bool test3()
{
	return convert("Success") == ")())())";
}

bool test4()
{
	return convert("(( @") == "))((";
}

int main()
{
	std::cout << test1() << std::endl;
	std::cout << test2() << std::endl;
	std::cout << test3() << std::endl;
	std::cout << test4() << std::endl;

	std::cin.get();
}