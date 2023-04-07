//
// Created by maza on 02/04/2023.
//

#ifndef ONLINE_BOOKSTORE_BOOK_H
#define ONLINE_BOOKSTORE_BOOK_H
#include <string>
#include <iostream>
using namespace  std;
class Book
{
public:
    //setter and getter functions
    char* getTitle() ;
    void setTitle(char* title);
    char* getAuthor() ;
    void setAuthor(char* author);
    char* getPublisher() ;
    void setPublisher(char* publisher);
    char* getCategory() ;
    void setCategory(char* category);
    double getPrice() ;
    void setPrice(double price);

    //function display book details;

    void displayBookDetails();
    void ctreateBook();

    bool operator==( const Book check) const;
    bool operator<( const Book check) const;

private:
    char bookTitle[40];
    char bookAuthor[40];
    char bookPublisher[40];
    double bookPrice;
    char bookCategory[40];
};


#endif //ONLINE_BOOKSTORE_BOOK_H
