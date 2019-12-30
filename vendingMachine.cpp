#include "vendingMachine.h"

VendingMachine::VendingMachine(Item objects[10], int quantities[10]){
    for(int a = 0; a < 10; a++){
        this->objects[a] = objects[a];
    }
    for(int a = 0; a < 10; a++){
        this->quantities[a] = quantities[a];
    }

    cash = 0;
    credit = 0;
}
float VendingMachine::insertDollar(){
    credit += 1.00;
    cash += 1.00;
    return credit;
}
float VendingMachine::insertQuarter(){
    credit += 0.25;
    cash += 0.25;
    return credit;
}
void VendingMachine::printMenu(){
    std::cout << std::fixed << std::setprecision(2);
    for(int a = 0; a < 10; a++){
        //std::cout << objects[a].getName() << ": $" << objects[a].getPrice() << std::endl;
        std::cout << a+1 << ") " << objects[a].toString() << std::endl;
    }
    std::cout << std::endl;
}

void VendingMachine::selectItem(){
    int inI;
    
    std::cout << "Enter item number:" << std::endl;
    std::cin >> inI;
    inI--;

    for(int a = 0; a < 10; a++){
        if(a == inI){
            if(quantities[a] <= 0){
                std::cout << "Sorry! Item Not Available" << std::endl;
            }
            else if(credit < objects[a].getPrice()){
                std::cout << "Insufficient credit" << std::endl;
            }
            else{
                credit -= objects[a].getPrice();
                quantities[a] -= 1;

                std::cout << "Enjoy your " << objects[a].getName() << std::endl;
            }
        }
    }

    std::cout << std::endl;
}

float VendingMachine::getCredit(){
    return credit;
}

float VendingMachine::cancel(){
    float prevCredit = credit;
    credit = 0;
    cash -= prevCredit;

    return prevCredit;
}

void VendingMachine::printReportToFile(){
    std::ofstream output("log.txt");
    
    output << std::fixed << std::setprecision(2);
    output << "Current cash in machine: $" << cash << std::endl;
    output << "Items needed:" << std::endl;
    
    for(int a = 0; a < 10; a++){
        output << objects[a].getName() << ": " << 10-quantities[a] << std::endl;
    }
}