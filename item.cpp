#include "item.h"

Item::Item(){
    name = "";
    price = 0;
}

void Item::setName(string name){
    this->name = name;
}
void Item::setPrice(float price){
    this->price = price;
}

string Item::getName(){
    return name;
}
float Item::getPrice(){
    return price;
}

string Item::toString(){
    std::string s, f;
    
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << price;
    f = stream.str();

    s = name + ": $" + f;

    return s;
}