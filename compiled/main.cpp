#include <iostream>

using namespace std;

struct phone{
	int code;
	string brand;
	string model;
	short ram;
	short storage;
	short stock;
	int phonePrice;
	int sellValue;
	phone* next;
} *head;

bool verifyCode(int cod){
	phone* i = head;
	
    while (i != nullptr) {
        if (i->code == cod) {
            return true; // duplicate found
        }
        i = i->next;
    }
    
	return false;
}

void addPhone(){
	phone* newPhone = new phone; 
	
	std::cout << "Enter code of the new phone: \n";
    std::cin >> newPhone->code;
    
    if (verifyCode(newPhone->code) == true){
    	std::cout << "Duplicate code, please try again.\n";
    	delete newPhone; // avoid memory leak
    	return;
	}
	
	std::cout << "Enter brand: ";
    std::cin >> newPhone->brand;
    
    std::cout << "Enter model: ";
    std::cin.ignore(); // Clean buffer
    std::getline(std::cin, newPhone->model);
    
    std::cout << "Enter RAM: ";
    std::cin >> newPhone->ram;
    
    std::cout << "Enter storage: ";
    std::cin >> newPhone->storage;
    
	// std::cout << "Enter the stock quantity: ";
	// std::cin >> newPhone->stock;
	
    // We start with 0 units by default.
    // This way, the inventory can begin empty (no phones in stock).
    newPhone->stock = 0; 
    
    std::cout << "Enter phone price: ";
    std::cin >> newPhone->phonePrice;
    
    std::cout << "Enter selling price: ";
	std::cin >> newPhone->sellValue;
    
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