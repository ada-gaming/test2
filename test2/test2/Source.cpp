#include<iostream>
#include<vector>
#include<string>

using std::string;

void myFunc(int x);
	


int main()
{


	for (int i = 0; i < 10; i++) std::cout << "Ada Gaming\n";
	std::cout << "Hello GitHub\n";
	int a=0;
	string b;
		std:: cout << "Hello GitHub\n";
		std::cin >> a;
		if (a == 1) {
			std::cout << "Pokemon\n";
		}
		else {
			std::cout << "NePokemon\n";
		}
		myFunc(20);

		std::cout << "Who is Pokemon?\n";
		std::cin >> b;
		std::cout << b;
	return 0;

}

void myFunc(int x)
{
	if (x != 0)
	{
		std::cout << "Hello\t" << x << std::endl;
		myFunc(x - 5);
	}
}
