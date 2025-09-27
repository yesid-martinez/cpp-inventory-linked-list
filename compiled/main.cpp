#include <iostream>

using namespace std;

struct phone{
	short code;
	string brand;
	string type;
	short ram;
	short dd;
	short units;
	int sellValue;
	int buyValue;
	phone* sig;
} *cab;

int main() {
	std::cout << "Hello world!";
	return 0;
}