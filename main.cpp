#include <iostream>
#include "Food.h"
#include "ShoppingCart.h"
#include "Menu.h"
using namespace std;
void line()
{
    cout<<endl<<"----------------------------------------------------";
    cout<<endl<<"----------------------------------------------------"<<endl;
}

void display()
{
    cout<<"0 display menu : "<<endl;
    cout<<"1 display menu by price : "<<endl;
    cout<<"2 display menu by category : "<<endl;
    cout<<"3 display menu sorted by name : "<<endl;
    cout<<"4 display menu sorted by popularity : "<<endl;
    cout<<"5 display menu sorted by price : "<<endl;
    cout<<"6 display menu after delete : "<<endl;
    cout<<"7 to order : "<<endl;
    cout<<"enter your number : ";
}

void displayForShoppingCart()
{
    cout<<"0 Margherita Pizza "<<endl;
    cout<<"1 Grilled Chicken "<<endl;
    cout<<"2 Beef Burrito "<<endl;
    cout<<"3 display total cost "<<endl;
    cout<<"4 display my cart "<<endl;
    cout<<"5 checkout "<<endl;
    cout<<"6 close app "<<endl;
}

int main()
{
    Menu m;
    Food f=Food("Margherita Pizza","A healthy and delicious salad made with grilled chicken",15,30);
    m.loadMenu();
    //f.createMenu();

    display();
    int switcher; cin>>switcher;
    while(switcher !=7)
    {
       switch(switcher)
       {
           case 0:
                    m.displayMenu();
                    line();
                    break;
           case 1:
                    cout<<"enter lower price : ";
                    int lowerPrice; cin>>lowerPrice;
                    cout<<"enter max price : ";
                    int maxPrice; cin>>maxPrice;
                    m.displayMenuByPrice(lowerPrice,maxPrice);
                    line();
                    break;
           case 2:
                    {cout<<"enter category you want to :" ;
                    string category ; cin>>category;
                    m.displayMenuByCategory(category);
                    line();
                    break;
                    }
           case 3:
               {
                    m.sortByName();
                    m.displayMenu();
                    line();
                    break;
               }
           case 4:
                    m.sortByPopularity();
                    m.displayMenu();
                    line();
                    break;
           case 5:
                    m.sortByPrice();
                    m.displayMenu();
                    line();
                    break;

           case 6:
                    m.deleteFood(3);
                    m.displayMenu();
                    line();
                    break;

           case 7:
                    break;
       }
        display();
        cin>>switcher;
    }



    ShoppingCart sc;
    sc.load();
    displayForShoppingCart();
    int switcherForShoppingCart;
    cin>>switcherForShoppingCart;
    while(switcherForShoppingCart != 6){
        switch(switcherForShoppingCart)
            {
            case 0:
            {
                string s="Margherita Pizza";
                sc.addItem(s);
                break;
            }
            case 1:
             {

                string s;
                s="Grilled Chicken";
                sc.addItem(s);
                break;
            }
            case 2:
             {
                string s;
                s="Beef Burrito";
                sc.addItem(s);
                break;
            }
            case 3:
                cout<<"total cost = "<<sc.getTotal()<<endl;
                line();
                break;

            case 4:
                cout<<"your cart : "<<endl;
                sc.displayCart();
                break;

            case 5:
                cout<<"to checkout enter your charge : ";
                int charge; cin>>charge;
                sc.checkout(400);
                break;
            case 6:
                return 0;
                break;
            }
            displayForShoppingCart();
            cin>>switcherForShoppingCart;

        }}
