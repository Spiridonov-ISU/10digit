#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool prime(long long n) {
	for (long long i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	ifstream file ("C:/Users/Lenovo/Desktop/e2mil.txt");
	if (!file)
	{
		cout << "Error!\n";
		return 1;
	}
	else
	{
		char ch;
		string str;
		long long num;
		do {
			ch = file.get();
		} while (ch != '.');

		for (int i = 0; i < 10; i++) {
			str += file.get();
		}

		istringstream(str) >> num;
		while (!prime(num)) {
			str.erase(0, 1);
			str += file.get();
			istringstream(str) >> num;
		}
		cout << num;
	}
	return 0;
}