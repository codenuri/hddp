#include <iostream>
#include <string>
#include <conio.h>


class Edit
{
	std::string data;
public:
	std::string getData()
	{
		data.clear();
		while (1)
		{
			char c = _getch();

			if (c == 13) break; // enter

			if (isdigit(c))
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};
int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


