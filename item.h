#ifndef ITEM_H
#define ITEM_H
#include <iomanip>
#include <sstream>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

class Item{
   public:
        Item();
        void setName(string name);
        void setPrice(float price);
        string getName();
        float getPrice();
        string toString();
   private:
        string name;
        float price;
};

#endif