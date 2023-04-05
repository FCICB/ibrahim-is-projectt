#include "Food.h"
#include "Menu.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
class ShoppingCart {
 private:
    vector<Food> items;
    Menu m;
    vector<Food> MenuForUser = m.foods;

 public:
     void load()
     {
         m.loadMenu();
     }
    void addItem(string name) {
        //m.loadMenu();
        for (const auto& q : m.foods) {
                //q.displayDetails();
                if (q.getName().find(name) != string::npos) {
                        //cout<<" sa";
                        if (q.getQuantity() == 0) {
                        throw runtime_error("Out of stock");
                    }items.push_back(q);

                    }
                    //cout<<"sasa";
                    //q.displayDetails();

                }
        }

    void removeItem(int index) {
        items.erase(items.begin() + index);
    }


    double getTotal() const {
        double total = 0;
        for (const auto& f : items) {
            total += f.getPrice();
        }
        return total;
    }

    void checkout(double payment) {
        if (payment < getTotal()) {
            throw runtime_error("Insufficient funds");
        }
        cout<<endl<<"my charge after this pill = "<<payment-getTotal()<<endl;

        for (auto& f : m.foods) {
            f.setQuantity(f.getQuantity() - 1);
        }
        items.clear();
    }
    void displayCart() const {
        for (const auto& f : items) {
            f.displayDetails();
            cout << endl;
        }
    }


};
