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
	phone* prev;
} *head, *tail;

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
	
    newPhone->stock = 0; 
    
    std::cout << "Enter phone price: ";
    std::cin >> newPhone->phonePrice;
    
    std::cout << "Enter selling price: ";
	std::cin >> newPhone->sellValue;
    
    // LIFO Mode
    // newPhone->next = head;
    // head = newPhone;
    
    // FIFO Mode
    if(head == nullptr){
		head = tail = newPhone;
		newPhone->prev = nullptr;
		newPhone->next = nullptr; 
	}else{
	    tail->next = newPhone;
	    newPhone->prev = tail;
	    newPhone->next = nullptr;
	    tail = newPhone;
	}
    
    std::cout << "Phone added successfully!\n";
}

void printInventory(long &balance){
	phone* i = head;
	
	if(i == nullptr){
		std::cout << " - There is no available phones at this moment.\n";
		std::cout << " \n";
		std::cout << " - Balance: " << balance << "\n";			
	}else{
		std::cout << "| ----------- Inventory ----------- |\n";
		while(i != nullptr){
			std::cout << " \n";
			std::cout << " - Phone code: " << i->code << "\n";
			std::cout << " - Brand: " << i->brand << "\n";
			std::cout << " - Model: " << i->model << "\n";
			std::cout << " - Available: " << i->stock << "\n";
			std::cout << " \n";
			std::cout << "| -------------------------------- |";
			std::cout << " \n";		
			i = i->next;
		}
		std::cout << " - Balance: " << balance << "\n";
	}
}

void buyPhone(long &balance) {
    short cod = 0, quant = 0;
    
    phone* i = head;
    
    if (i == nullptr) {
        std::cout << "- There are no available phones at this moment.\n";
    } else {
        std::cout << "Enter the code of the phone you want to buy: \n";
        std::cin >> cod;
        
        bool found = false;
        
        while (i != nullptr) {
            if (i->code == cod) {
            	found = true;
            	
                std::cout << "Enter purchase quantity: \n";
                std::cin >> quant;
                
                if (quant <= 0) {
                    std::cout << "Please enter a quantity of at least one (1).\n";
                	return;
				}	
				
				if(balance < (quant * i->phonePrice)){
					std::cout << " \n";
                    std::cout << "Insufficient balance!\n";
                    std::cout << "Currently you have $" << balance << "\n";
                    std::cout << " \n";
                	return;
				}
				
                i->stock += quant; 
                balance -= (quant * i->phonePrice);
                std::cout << " \n";
                std::cout << "- " << quant << " phones added to stock successfully!\n";
                std::cout << "- Purchase cost: " << (quant * i->phonePrice) << "\n";
				std::cout << "- Thank you for your purchase.\n";
            	std::cout << " \n";
            	return;
			}
            i = i->next;
        }
        
	    if (!found) {
	        std::cout << "Phone code not found! Please try again.\n";
	    }
    }
}

void sellPhone(long &balance) {
	short cod = 0, quant = 0;

    phone* i = head;

    if (i == nullptr) {
        std::cout << "- There are no available phones at this moment.\n";
    } else {
        std::cout << "Enter the code of the phone you want to sell: \n";
        std::cin >> cod;

        bool found = false;

        while (i != nullptr) {
            if (i->code == cod) {
	
            	if(i->stock <= 0){
            		std::cout << "No stock available for model " << i->model << ".\n";
            		return;
				}

            	found = true;

                std::cout << "Enter quantity to sell: \n";
                std::cin >> quant;

                if (quant <= 0) {
                    std::cout << "Please enter a quantity of at least one (1).\n";
                	return;
				}

				if(i->stock < quant){
					std::cout << "Insufficient stock. Available units: " << i->stock << "\n";
                	return;
				}

                i->stock -= quant; 
                balance += (quant * i->sellValue);
                std::cout << " \n";
                std::cout << "- " << quant << " phone(s) sold successfully!\n";
                std::cout << "- Total sale value: $" << (quant * i->sellValue) << "\n";
				std::cout << " \n";
				std::cout << "- Transaction completed.\n";
            	std::cout << " \n";
            	return;
			}
            i = i->next;
        }

	    if (!found) {
	        std::cout << "Phone code not found! Please try again.\n";
	    }
    }
}

void deletePhone(){
	if(head == nullptr){
		std::cout << "Inventory is empty.\n";
        return;
	}
	
	int cod;
	std::cout <<"Enter the code of the phone you want to delete: \n";
	std::cin >> cod;
	
	phone* i = head;
	phone* j = head;
	
    while (i != nullptr && cod != i->code) {
        j = i; // Save previous node
        i = i->next; 
    }
    
    if (i == nullptr) {
        std::cout << "Product not found.\n";
        return;
    }
    
	if(i->stock != 0){
		std::cout << "This product still has stock!\n";
		return;
	}
	
	if(i == head){
		head = i->next;
		delete(i);
	}else{
		j->next = i->next;
		delete i;
	}
	
	std::cout << "The product was removed from inventory!\n";
}

int main() {
	
	head = nullptr;
	tail = nullptr;
	
	short opt = 0;
	long balance = 10000000;
	
	do{
		std::cout << "           --- Menu inventory ---\n";
		std::cout << "Select a option:\n";
		std::cout << "1. Add phone.\n";
		std::cout << "2. Delete phone.\n";
		std::cout << "3. View inventory.\n";
		std::cout << "4. Buy phone(s).\n";
		std::cout << "5. Sell phone(s).\n";
		std::cout << "6. Exit.\n";
		
		std::cin >> opt;
		
		switch(opt){
			case 1:
				addPhone();
				break;
			case 2:
				deletePhone();
				break;
			case 3:
				printInventory(balance);
				break;
			case 4:
				buyPhone(balance);
				break;
			case 5:
				sellPhone(balance);
				break;
			case 6:
				std::cout << "Closing app...\n";
				break;
			default:
				std::cout << "Invalid option!\n";
				break;
		}
	}while (opt != 6);
	
	return 0;
}