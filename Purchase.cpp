#include "Purchase.h"
#include "User.h"
#include "Book.h"
#include <string.h>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

void Purchase::checkout(User user,ShoppingCart shopCart)
{
    vector<Book> cart;
    cart=shopCart.getCart();
    strcpy(userName,user.getName());
    strcpy(userAddrees,user.getAddress());
    totalPrice=getTotalPrice(shopCart);
    if(totalPrice == 0)
    {
        cout<<"\nYOUR SHOPPING CART IS EMPTY !"<<endl;
        //exit(0);
        return;
    }
    time_t now = time(0);
    char* datte = ctime(&now);
    string sDate=datte;
    strcpy(date, sDate.c_str());
    cout<<"\nYour Purchases\n"<<endl;
    for(int i=0; i<cart.size(); i++)
    {
        cout<<"\nBook Name : "<<cart[i].getTitle()<<"\t\t"<<"Price : "<<cart[i].getPrice()<<endl;
    }
    cout<<"\n\nTotalPrice Is : "<<totalPrice<<endl;
    cout<<"\nDate Is :"<<date<<endl;
    addPurchaseToPurchaseHistory();//to record any purchase in our system.
    cart.clear();//to make cart empty after purchase.
}
double Purchase::getTotalPrice(ShoppingCart shopCart)
{
    totalPrice=0;
    vector<Book> cart;
    cart=shopCart.getCart();
    for(int i=0; i<cart.size(); i++)
    {
        totalPrice+=cart[i].getPrice();
    }
    return totalPrice;
}

void Purchase::addPurchaseToPurchaseHistory()
{
    Purchase purchase;
    purchase=*this;
    fstream purchaseFile;
    purchaseFile.open("purchase.txt",ios::out|ios::app);
    if(!purchaseFile)   // file couldn't be opened
    {
        cerr << "Error: file purchase could not be opened" << endl;
    }
    purchaseFile.write((char*)&purchase, sizeof(purchase));
    if(!purchaseFile)
    {
        cerr << "Could not write to file\n";
    }

    purchaseFile.close();
}


void Purchase::displayEntirePurchaseHistory()
{
    Purchase purchase;
    fstream purchaseFile;
    purchaseFile.open("purchase.txt",ios::in);
    if(!purchaseFile)   // file couldn't be opened
    {
        cerr << "Error: file could not be opened" << endl;
    }
    int flag=0;//to check if there is books in cart.
    while(purchaseFile.read((char*)&purchase, sizeof(purchase)))
    {
        flag=1;
        purchase.displayPurchaseDetails();
    }
    if(flag == 0)
        cout<<"\nYOUR SHOPPING CART IS EMPTY!"<<endl;
    purchaseFile.close();
}

void Purchase::displayPurchaseDetails()
{
    cout<<"=======================\n";
    cout<<"At Date : "<<date<<endl;
    cout<<"User Name : "<<userName<<endl;
    cout<<" His Address : "<<userAddrees<<endl;
    cout<<"Total Price Of his Cart : "<<totalPrice<<endl;
    cout<<"=======================\n";
}
