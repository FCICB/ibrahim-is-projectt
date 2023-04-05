#include <iostream>
#include "Food.h"
#include "ShoppingCart.h"
#include "Menu.h"
using namespace std;

int main()
{
    Menu m;
    Food f=Food("Margherita Pizza","A healthy and delicious salad made with grilled chicken",15,30);
    //f.createMenu();
    m.loadMenu();
    cout<<"display menu : "<<endl;
    m.displayMenu();
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<"display menu by price : "<<endl;
    m.displayMenuByPrice(10,14);
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<"display menu after delete : "<<endl;
    m.deleteFood(3);
    m.displayMenu();
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<"display menu by category : "<<endl;
    m.displayMenuByCategory("pizza");
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<"display menu sorted by name : "<<endl;
    m.sortByName();
    m.displayMenu();
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<"display menu sorted by popularity : "<<endl;
    m.sortByPopularity();
    m.displayMenu();
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<"display menu sorted by price : "<<endl;
    m.sortByPrice();
    m.displayMenu();
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<endl<<"----------------------------------------------------"<<endl;


    ShoppingCart sc;
    sc.load();
    string s="Margherita Pizza";
    //f=Food("Margherita Pizza","A healthy and delicious salad made with grilled chicken",15,30);
    sc.addItem(s);
    s="Grilled Chicken";
    //f=Food("Margherita Pizza","A healthy and delicious salad made with grilled chicken",15,30);
    sc.addItem(s);
    s="Beef Burrito";
    sc.addItem(s);
    cout<<"total cost = "<<sc.getTotal()<<endl;
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<"your cart : "<<endl;
    sc.displayCart();
    cout<<endl<<"----------------------------------------------------"<<endl;
    cout<<endl<<"----------------------------------------------------"<<endl;
    sc.checkout(400);
}
