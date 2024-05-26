#pragma once
#include <iostream>
using namespace std;

class Product{
    private:
    string category,subCategory,price,ID;
    public:
    Product(string _category, string _subCategory, string _price, string _ID);
    string getCategory();
    string getSubCategory();
    string getPrice();
    string getID();
    void setCategory(string _Category);
    void setCategory(string _subCategory);
    void setCategory(string _price);
    void setCategory(string _ID);
};