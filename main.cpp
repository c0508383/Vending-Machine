#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "item.h"
#include "vendingMachine.h"

void Menu(VendingMachine &vm);
int main(){
    Item objects[10];
    int quantities[10];

    std::string inFile;
    std::cin >> inFile;
    std::ifstream input(inFile);

    for(int a = 0; a < 10; a++){
        std::string s;

        std::getline(input,s);
        //std::cout << s << std::endl;
        objects[a].setName(s);

        std::getline(input,s);
        //std::cout << s << std::endl;
        objects[a].setPrice(stof(s));

        std::getline(input,s);
        //std::cout << s << std::endl;
        quantities[a] = stoi(s);
        
        //std::cout << "\nnext item\n" << std::endl;
    }

    VendingMachine vm(objects,quantities);

    Menu(vm);

    vm.printReportToFile();

    return 1;
}

void Menu(VendingMachine &vm){
   std::cout << "Make a selection: " << std::endl;
   std::cout << "1 - insert 1$ bill" << std::endl;
   std::cout << "2 - insert a quarter" << std::endl;
   std::cout << "3 - view menu" << std::endl;
   std::cout << "4 - select an item" << std::endl;
   std::cout << "5 - cancel" << std::endl;
   std::cout << std::endl;
   
   float inF = 0;
   int inI = 0;
   std::string inS = "";
   char inC;

   std::cin.clear();

   //std::cout << "Choose an option:" << std::endl;
   std::cin >> inC;
   
   while(inC != '1' && inC != '2' && inC != '3' && inC != '4' && inC != '5'){
      //std::cout << "Choose an option:" << std::endl;
      std::cin >> inC;
   }
    
   inI = inC - '0';
   //std::cout << std::endl;
   
   switch(inI){
      case 1:
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Total credit: $" << vm.insertDollar() << std::endl;
        std::cout << std::endl;
        break;
      case 2:
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Total credit: $" << vm.insertQuarter() << std::endl;
        std::cout << std::endl;
        break;
      case 3:
        vm.printMenu();
        break;
      case 4:
        vm.selectItem();
        break;
      case 5:
        if(vm.getCredit() != 0.0){
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Your change is $" << vm.cancel() << endl;
        }
        else{
          cout << "No change" << endl;
        }
        std::cout << std::endl;
        break;
      default:
        break;
   }

   if(inI != 5)
      Menu(vm);
}