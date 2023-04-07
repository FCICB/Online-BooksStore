#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Inventory.h"
#include "Book.h"
#include "User.h"
#include "Purchase.h"
#include "ShoppingCart.h"
#include <exception>
#include <stdexcept>
#include <limits>

using namespace std;

User user;
Inventory inventory;
Purchase purchase;
ShoppingCart cart;

int login();
void displayAdminPage();
void displayCustomerPage();
void displayAdminActivities();
void displayCustomerActivities();
void handleCustomerActivity();
void handleAdminActivity();

int login()
{
    int role;
    cout<<"\n\n\n*********************   Online Bookstore *********************\n\n\n";
    cout<<"\n=========================Login To Our Bookstore=================== \n\n";
    cout<<"\nWhat is your role? \n"<<" 1-Admin? \t\t\t 2-Customer? \n";
    cout<<"\nEnter number 1 if you are admin OR number 2 if you are customer : ";
    cin>>role;
    while(cin.fail())
    {
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry. PLEASE Enter a NUMBER : ";
        cin >> role;
    }
    return role;
}
void displayAdminPage()
{

    cout<<"\n\n\t\t\t--------- Hello Our Admin! ---------\n\n"<<endl;
    displayAdminActivities();
    handleAdminActivity();
}

void displayCustomerPage()
{
    char name[40];
    char address[40];
    cout<<"\n\n\t\t\t--------- Hello To Our System! ---------\n\n"<<endl;
    cout<<"\nPlease enter Your name : \n";
    cin.ignore();
    cin.getline(name,40);
    user.setName(name);

    cout<<"\nPlease enter Your address : ";
    cin.getline(address,40);
    user.setAddress(address);
    handleCustomerActivity();
}

void displayAdminActivities()
{
    cout<<"\n***************************"<<endl;
    cout<<"\nThese are activities which can admin do : "<<endl;
    cout<<"1-Display all books in inventory"<<endl;
    cout<<"2-Add books in inventory"<<endl;
    cout<<"3-Delete books from inventory"<<endl;
    cout<<"4-sort books in inventory with price"<<endl;
    cout<<"5-Show purchase history of all users"<<endl;
    cout<<"6-Back To LOgin"<<endl;
    cout<<"7-Exit From System"<<endl;
}
void displayCustomerActivities()
{
    cout<<"\n***************************"<<endl;
    cout<<"\nThese are activities which you can do : "<<endl;
    cout<<"1-Browse books "<<endl;
    cout<<"2-Search books by title and author : "<<endl;
    cout<<"3-Add books in shopping cart"<<endl;
    cout<<"4-Delete books from shopping cart"<<endl;
    cout<<"5-Display books in shopping cart"<<endl;
    cout<<"6-sort books in inventory with price"<<endl;
    cout<<"7-checkout"<<endl;
    cout<<"8-Back To LOgin"<<endl;
    cout<<"9-Exit From System"<<endl;
}
void searchBook()
{
    char title[40];
    char author[40];

    cout<<"\nPlease choose Book you want to search(enter its title and its author) : "<<endl;
    cout<<"\nEnter title of book : ";
    cin.ignore();
    cin.getline(title,40);
    cout<<"\nEnter author of book : ";
    cin.getline(author,40);
    if(inventory.isExist(title,author) == false)
    {
        cout<<"This book not found in our inventory \n";
    }
}
void handleCustomerActivity()
{
    int choice;
    int flag=1;
    while(flag == 1)
    {
        displayCustomerActivities();
        cout<<"\nchoose number of activity you want to do it :";
        cin>>choice;
        while(cin.fail())
        {
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "Bad entry. PLEASE Enter a NUMBER : ";
            cin >> choice;
        }

        switch(choice)
        {
        case 1:
            cout<<"All Books We have : \n";
            inventory.displayEntireInventory();
            break;
        case 2:
            searchBook();
            break;
        case 3:
            cart.addBookToCart();
            break;
        case 4:
            cart.removeBookFromUserCart();
            break;
        case 5:
            cart.displayUserCart();
            break;
        case 6:
            inventory.sortBooksByPrice();
            break;
        case 7:
            purchase.checkout(user,cart);
            break;
        case 8:
            {flag=0;
            int role=login();
            if(role == 1)
                displayAdminPage();
            else if(role == 2)
                displayCustomerPage();
            else
                cout<<"Wrong Input!"<<endl;
            break;}
        case 9:
            flag=0;
            exit(0);
        default:
            cout<<"You enter a wrong choice "<<endl;
            break;
        }

    }

}
void handleAdminActivity()
{
    int choice;
    int flag=1;
    while(flag == 1)
    {
        cout<<"\nchoose number of activity you want to do it :";
        cin>>choice;
        while(cin.fail())
        {
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "Bad entry. PLEASE Enter a NUMBER : ";
            cin >> choice;
        }
        switch(choice)
        {
        case 1:
            inventory.displayEntireInventory();
            break;
        case 2:
            inventory.addBookToInventory();
            break;
        case 3:
            inventory.deleteBookFromInventory();
            break;
        case 4:
            inventory.sortBooksByPrice();
            break;
        case 5:
            purchase.displayEntirePurchaseHistory();
            break;
        case 6:
            {flag=0;
            int role=login();
            if(role == 1)
                displayAdminPage();
            else if(role == 2)
                displayCustomerPage();
            else
                cout<<"Wrong Input!"<<endl;
            break;}
        case 7:
            flag=0;
            exit(0);
        default:
            cout<<"You enter a wrong choice "<<endl;
            break;
        }
        displayAdminActivities();
    }
}

int main()
{

    int role;
    role=login();
    if(role == 1)
        displayAdminPage();
    else if(role == 2)
        displayCustomerPage();
    else
        cout<<"Wrong Input!"<<endl;

    return 0;
}
