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
			std::cout << " - Brand: " << i->brand << "\n";
			std::cout << " - Model: " << i->model << "\n";
			std::cout << " - Available: " << i->stock << "\n";
			i = i->next;
		}
	}
}

void buyPhone() {
    short cod = 0, quant = 0;
    
    phone* i = head;
    
    if (i == nullptr) {
        std::cout << "- There are no available phones at this moment.\n";
    } else {
        std::cout << "Enter the code of the phone you want to buy: \n";
        std::cin >> cod;
        
        while (i != nullptr) {
            if (i->code == cod) {
                std::cout << "Enter purchase quantity: \n";
                std::cin >> quant;
                
                if (quant <= 0) {
                    std::cout << "Please enter a quantity of at least one (1).\n";
                } else {
                    i->stock += quant; 
                    std::cout << "- " << quant << " phones added to stock successfully!\n";
                    std::cout << "- Thank you for your purchase.\n";
                }
                break; // phone found, exit the loop
            }
            
            // Move to next node if code does not match
            i = i->next;
        }
        
        if (i == nullptr) {
            std::cout << "Phone code not found! Please try again.\n";
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
		std::cout << "2. View inventory.\n";
		std::cout << "3. Buy phone(s).\n";	
		std::cout << "4. Exit.\n";	
		
		std::cin >> opt;
		
		switch(opt){
			case 1:
				addPhone();
				break;
			case 2:
				printInventory();
				break;
			case 3:
				buyPhone();
				break;
			case 4:
				std::cout << "Closing app...\n";
				break;
			default:
				std::cout << "Invalid option!\n";
				break;
		}
	}while (opt != 4);
	
	return 0;
}