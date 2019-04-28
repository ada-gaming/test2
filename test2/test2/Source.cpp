#include<iostream>
#include<vector>


std::vector<int> MpVector(std::vector<int> & x);

int main()
{
	for (int i = 0; i < 10; i++) std::cout << "Ada Gaming\n";
	std::cout << "Hello GitHub\n";
	int a, b;
		std:: cout << "Hello GitHub\n";
		std::cin >> a;
		if (a == 1) {
			std::cout << "Pokemon\n";
		}
		else {
			std::cout << "NePokemon\n";
		}


		std::cout << "Who is Pokemon?\n";
		std::cin >> b;
		std::cout << b;
		int x=0;
		std::vector<int> old;
		std::cout<<"Enter numbers\n\"q\" for Exit\n";
		while (std::cin>>x)
		{
			old.push_back(x);
		}
		std::cout << "sqrt yours vector\n";
		std::vector<int> n=MpVector(old);
		for (int i = 0; i < n.size(); i++)
		{
			std::cout << n[i] << std::endl;
		}
	return 0;

}

std::vector<int> MpVector(std::vector<int> & x)
{
	std::vector<int>::iterator iter;
	std::vector<int> y;
	for (iter= x.begin(); iter != x.end(); iter++)
	{
		y.push_back(*iter  *  *iter);

	}
	return y;
}
