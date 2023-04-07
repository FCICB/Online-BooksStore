//
// Created by maza on 02/04/2023.
//

#ifndef ONLINE_BOOKSTORE_INVENTORY_H
#define ONLINE_BOOKSTORE_INVENTORY_H
#include <string>
#include <iostream>
#include "Book.h"
#include <vector>
using namespace  std;

class Inventory {

public:
    void addBookToInventory();
    void deleteBookFromInventory();
    void loadBookfromInventory();
    void displayEntireInventory();
    bool isExist(char* title,char* author);
    int getIndexOfExistingBook(char* title,char* author);
    void sortBooksByPrice();
    vector<Book> getInventoryBooks();
private:
   //vector<Book>addingInventoryBooks;
   vector<Book>readingInventoryBooks;
};


#endif //ONLINE_BOOKSTORE_INVENTORY_H
