#include "ShoppingCart.h"
#include "User.h"
#include <string>
#include <iostream>
#include "Book.h"
#include "Inventory.h"
#include <vector>
#include <string.h>

using namespace std;

void ShoppingCart::addBookToCart()
{
    Book book;
    Inventory inventory;

    char title[40];
    char author[40];

    cout<<"\nPlease choose Book you want to add to cart (enter its title and its author) : \n"<<endl;
    cout<<"\nEnter title of book : ";
    cin.ignore();
    cin.getline(title,40);

    cout<<"\nEnter author of book : \n";
    cin.getline(author,40);

    if(inventory.isExist(title,author) == true)
    {
        vector<Book> allBooks;
        allBooks=inventory.getInventoryBooks();
        for(int i=0; i<allBooks.size(); i++)
        {
            if((strcmp(allBooks[i].getTitle(),title)==0) && (strcmp(allBooks[i].getAuthor(),author)==0))
            {

                cart.push_back(allBooks[i]);
                break;
            }
        }
        cout<<"\nthis book has been added to your cart successfully \n"<<endl;
    }
    else
        cout<<"\nThis book not found in our inventory \n";
}


void ShoppingCart::displayUserCart()
{
    int flag=0;
    for(int i=0; i<cart.size(); i++)
    {
        flag=1;
        cout<<"\nBook : "<<i+1<<endl;
        cart[i].displayBookDetails();
        cout<<"=================================="<<endl;
    }
    if(flag == 0)
        cout<<"\nYOUR SHOPPING CART IS EMPTY,THERE IS NOT BOOKS TO DISPLAY !"<<endl;
}

void ShoppingCart::removeBookFromUserCart()
{
    if(cart.size() != 0)
    {
        Inventory inventory;
        char title[40];
        char author[40];
        cout<<"\nPlease choose Book you want to remove from cart (enter its title and its author) : "<<endl;
        cout<<"\nEnter title of book : ";
        cin.ignore();
        cin.getline(title,40);

        cout<<"\nEnter author of book : ";
        cin.getline(author,40);


        if(inventory.isExist(title,author))
        {
            vector<Book> booksAfterRemoving;
            for(int i=0; i<cart.size(); i++)
            {
                if((strcmp(cart[i].getTitle(),title)==0) && (strcmp(cart[i].getAuthor(),author)==0))
                {
                    continue;
                }
                booksAfterRemoving.push_back(cart[i]);
            }
            cout<<"\nthis book has been removed from your cart successfully "<<endl;
            cart.clear();
            cart=booksAfterRemoving;
        }
        else
            cout<<"\nThis book not found in your cart \n";
    }
    else
        cout<<"\nYOUR SHOPPING CART IS EMPTY,THERE IS NOT BOOKS TO REMOVE !"<<endl;

}

vector<Book> ShoppingCart::getCart()
{
    return cart;
}
