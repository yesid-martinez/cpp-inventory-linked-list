#include <iostream>

using namespace std;

struct phone{
	int code;
	string brand;
	string type;
	short ram;
	short dd;
	short units;
	int sellValue;
	int buyValue;
	phone* next;
} *head;

void addPhone(){
	phone* newPhone = new phone; 
	
	std::cout << "Enter phone code: \n";
    std::cin >> newPhone->code;
    
    newPhone->next = head;
    head = newPhone;
    
    std::cout << "Phone added successfully!\n";
}

void printInventory(){
	phone* i = head;
	
	if(i == nullptr){
		std::cout << " - There is no available phones at this moment.\n";
	}else{
		while(i != nullptr){
			std::cout << " - Phone code: " << i->code << "\n";
			i = i->next;
		}
	}

}

int main() {
	
	head = nullptr;
	
	short opt = 0;
	
	do{
		std::cout << "           --- Menu inventory ---\n";
		std::cout << "Select a option:\n";
		std::cout << "1. Add phone.\n";
		std::cout << "2. View available phones.\n";
		std::cout << "3. Exit.\n";	
		
		std::cin >> opt;
		
		switch(opt){
			case 1:
				addPhone();
				break;
			case 2:
				printInventory();
				break;
			case 3:
				std::cout << "Closing app...\n";
				break;
			default:
	            std::cout << "Invalid option!\n";
	            break;
		}
	}while (opt != 3);
	
	return 0;
}