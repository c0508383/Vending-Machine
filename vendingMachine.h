#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "item.h"
using namespace std;

class VendingMachine{
   public:
        VendingMachine(Item objects[10], int quantities[10]);
        float getCredit();
        float insertDollar();
        float insertQuarter();
        void printMenu();
        void selectItem();
        float cancel();
        void printReportToFile();
   private:
        Item objects[10];
        int quantities[10];
        float cash;
        float credit;
};

#endif