#include "Food.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#ifndef _Menu_h_
#define _Menu_h_

class Menu
{

 public:
         vector<Food> foods;

        void loadMenu() {
            ifstream File("d:\\menu.txt");
            if (!File.is_open()) {
                throw runtime_error("Error opening file");
            }

            string line;
            while (getline(File, line)) {
                stringstream ss(line);
                string name, description;
                double price;
                int quantity;

                getline(ss, name, ',');
                getline(ss, description, ',');
                ss >> price;
                ss.ignore();
                ss >> quantity;

                foods.push_back(Food(name, description, price, quantity));
            }

            File.close();
        }

        void addFood(Food f) {
            foods.push_back(f);
        }

        void editFood(int index, Food f) {
            foods[index] = f;
        }

        void deleteFood(int index) {
            foods.erase(foods.begin() + index);
        }

        void displayMenu() const {
            for (const auto& f : foods) {
                f.displayDetails();
                cout << endl;
            }
        }

        void displayMenuByPrice(double minPrice, double maxPrice) const {
            for (const auto& f : foods) {
                if (f.getPrice() >= minPrice && f.getPrice() <= maxPrice) {
                    f.displayDetails();
                    cout << endl;
                }
            }
        }

        void displayMenuByCategory(string category) const {
            for (const auto& f : foods) {
                if (f.getDescription().find(category) != string::npos) {
                    f.displayDetails();
                    cout << endl;
                }
            }
        }

        void sortByName() {
            sort(foods.begin(), foods.end());
        }

        void sortByPrice() {
            sort(foods.begin(), foods.end(), [](const Food& a, const Food& b) {
                return a.getPrice() < b.getPrice();
            });
        }

        void sortByPopularity() {
            sort(foods.begin(), foods.end(), [](const Food& a, const Food& b) {
        return a.getQuantity() > b.getQuantity();
        });
        }
};
#endif
