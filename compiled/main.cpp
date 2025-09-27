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
	short opt = 0;
	
	
	do{
		std::cout << "           --- Menu inventory ---\n";
		std::cout << "Select a option:\n";
		std::cout << "1. Option 1.\n";
		std::cout << "2. Exit.\n";	
		
		std::cin >> opt;
		
		switch(opt){
			case 1:
				std::cout << "Option 1 selected!\n";
				break;
			case 2:
				std::cout << "Closing app...\n";
				break;
			default:
	            std::cout << "Invalid option!\n";
	            break;
		}
	}while (opt != 2);
	
	return 0;
}