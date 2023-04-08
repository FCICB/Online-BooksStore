
#include <bits/stdc++.h>
#include "Inventory.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include "Book.h"
#include <vector>
#include <exception>
#include <stdexcept>
#include <limits>
using namespace std;

void Inventory::addBookToInventory()
{
    fstream inventoryFile;
    Book book;
    inventoryFile.open("inventory.txt",ios::out|ios::app);
    if(!inventoryFile)   
    {
        cerr << "\nError: file could not be opened" << endl;

    }
    int numOfBooks;
    cout<<"\nplease enter number of books you want to add : ";
    cin >>numOfBooks;
    while(cin.fail())
    {
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "\nBad entry.Number Of Books Must be Number, PLEASE Enter a NUMBER : ";
        cin >> numOfBooks;
    }
    for(int i=0; i<numOfBooks; i++)
    {
        cout<<"******Enter Details of Book "<<i+1<<"*********"<<endl;
        book.ctreateBook();
        inventoryFile.write((char*)&book, sizeof(book));
        if(!inventoryFile)
        {
            cerr << "\nCould not write to file\n";
        }
        cout <<"\nThis book has been added to inventory successfully \n"<<endl;
    }
    inventoryFile.close();
}

void Inventory::deleteBookFromInventory()
{
    Book book;
    fstream inventoryFile;
    fstream tempFile;
    char title[40];
    char author[40];
    cout<<"Please enter title of book you want to delete :"<<endl;
    cin.ignore();
    cin.getline(title,40);
    cout<<"Please enter author of book you want to delete :";
    cin.getline(author,40);
    int flag=0;
    if(isExist(title,author))
    {
        tempFile.open("temp.txt",ios::out);
        if(!tempFile)   
        {
            cerr << "Error: file could not be opened" << endl;
        }
        loadBookfromInventory();
        for(int i=0; i<readingInventoryBooks.size(); i++)
        {
            book=readingInventoryBooks[i];
            if((strcmp(book.getTitle(),title)==0) && (strcmp(book.getAuthor(),author)==0))
            {
                continue;
            }
            tempFile.write((char*)&book, sizeof(book));

        }
        cout<<"this book has been deleted from  inventory successfully "<<endl;
        tempFile.close();
        remove("inventory.txt");
        rename("temp.txt","inventory.txt");
    }
    else
        cout<<"This book not found in our inventory ";

}

void Inventory::loadBookfromInventory()
{
    readingInventoryBooks.clear();
    fstream inventoryFile;
    Book book;
    inventoryFile.open("inventory.txt",ios::in);
    if(!inventoryFile)   
    {
        cerr << "Error: file could not be opened" << endl;
      
    }
    while(inventoryFile.read((char*)&book, sizeof(book)))
    {
        readingInventoryBooks.push_back(book);
    }
    inventoryFile.close();
}
void Inventory::displayEntireInventory()
{
    vector<Book> allBooks;
    allBooks=getInventoryBooks();
    int i;
    cout<<"All Books In Inventory :\n ";
    for( i=0; i<allBooks.size(); i++)
    {
        cout<<"========================\n";
        cout<<"\nBook "<<i+1<<endl;
        allBooks[i].displayBookDetails();
    }
    if(i== 0)
        cout<<"Inventory is empty"<<endl;
}
bool Inventory::isExist(char* title,char* author)
{
    loadBookfromInventory();
    int flag=0;
    for(int i=0; i<readingInventoryBooks.size(); i++)
    {
        if((strcmp(readingInventoryBooks[i].getTitle(),title)==0) && (strcmp(readingInventoryBooks[i].getAuthor(),author)==0))
        {
            readingInventoryBooks[i].displayBookDetails();
            flag=1;
            return true;
            break;
        }
    }
    if(flag==0)
        return false;
}
void Inventory::sortBooksByPrice()
{
    vector<Book> allBooks;
    allBooks=getInventoryBooks();
    int i;
    sort(allBooks.begin(), allBooks.end());
    cout<<"\nAll Inventory Books after sorting By price : "<<endl;
    cout<<"Sorted Books With Price : \n";
    for(i=0; i<allBooks.size(); i++)
    {
        cout<<"Book : "<<i+1<<endl;
        allBooks[i].displayBookDetails();
        cout<<"=================================="<<endl;
    }
    if(i==0)
        cout<<"There are not books in inventory to be sorted!!"<<endl;
}


vector<Book> Inventory::getInventoryBooks()
{
    loadBookfromInventory();
    return readingInventoryBooks;
}

