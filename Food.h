#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
#ifndef _Food_h_
#define _Food_h_

class Food
{
     friend bool operator <(const Food& a, const Food& b) {
            return a.name < b.name;
        }

    friend bool operator >(const Food& a, const Food& b) {
            return a.name > b.name;
        }

    friend bool operator ==(const Food& a, const Food& b) {
            return a.name == b.name;
        }


private:

    string name;
    string description;
    double price;
    int quantity;

public:
    Food(string n, string d, double p, int q) : name(n), description(d), price(p), quantity(q) {}
    string getName() const { return name; }
    string getDescription() const { return description; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    void setName(string n) { name = n; }
    void setDescription(string d) { description = d; }
    void setPrice(double p) { price = p; }
    void setQuantity(int q) { quantity = q; }
    void displayDetails() const {
            cout << "Name: " << name << endl;
            cout << "Description: " << description << endl;
            cout << "Price: " << price << endl;
            cout << "Quantity: " << quantity << endl;
        }
    void createMenu(){
        ofstream File;
        File.open("d:\\menu.txt",ios::out | ios::app);
        Food f=Food("Margherita Pizza ","A healthy and delicious salad made with grilled chicken ",15 ,30 );
        File << f.name<<", " << f.description<<", " << f.price<<" " << f.quantity <<endl;
        f=Food("Grilled Chicken Salad ","A classic pizza made with a thin crust ", 20 , 10 );
        File << f.name<<", " << f.description<< ", " << f.price<<" " << f.quantity <<endl;
        f=Food("Beef Burrito ","A hearty burrito filled with seasoned ground beef ", 10 , 15 );
        File << f.name<<", " << f.description<<", " << f.price<<" " << f.quantity <<endl;
        f=Food("Pad Thai ","A popular Thai dish made with rice noodles ",13,35);
        File << f.name<<", " << f.description<<", " << f.price<<" " << f.quantity <<endl;
        f=Food("Grilled Cheese Sandwich ","A comforting sandwich made with melted cheddar cheese and toasted bread ",11,50);
        File << f.name<<", " << f.description<<", " << f.price<<" " << f.quantity <<endl;
        File.close();
        }
};

#endif // _Food_
