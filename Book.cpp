

#include "Book.h"
#include <string.h>
#include <stdexcept>
#include <limits>
char* Book::getTitle() {
    return bookTitle;
}
void Book::setTitle(char* title){
    strcpy(bookTitle,title);
}
char* Book::getAuthor() {
    return bookAuthor;
}
void Book::setAuthor(char* author){
    strcpy(bookAuthor,author);
}
char* Book::getPublisher() {
    return bookPublisher;
}
void Book::setPublisher(char* publisher){
    strcpy(bookPublisher,publisher);
}
char* Book::getCategory() {
    return bookCategory;
}
void Book::setCategory(char* category){
    strcpy(bookCategory,category);
}
double Book::getPrice() {
    return bookPrice;
}
void Book::setPrice(double price){
    bookPrice=price;
}

void Book::displayBookDetails(){
    cout<<"\nthe title is :"<<getTitle()<<endl;
    cout<<"the Author is :"<<getAuthor()<<endl;
    cout<<"the publisher is :"<<getPublisher()<<endl;
    cout<<"the category is :"<<getCategory()<<endl;
    cout<<"the price is :"<<getPrice()<<endl;
}

 void Book::ctreateBook(){

    cout<<"\nPlease enter title : ";
    cin.ignore();
    cin.getline(bookTitle,40);
    setTitle(bookTitle);

    cout<<"\nPlease enter author : ";
    cin.getline(bookAuthor,40);
    setAuthor(bookAuthor);

    cout<<"\nPlease enter publisher : ";
    cin.getline(bookPublisher,40);
    setPublisher(bookPublisher);

    cout<<"\nPlease enter category : ";
    cin.getline(bookCategory,40);
    setCategory(bookCategory);

    cout<<"\nPlease enter price : ";
    cin>>bookPrice;
    while(cin.fail())
    {
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry.Price Must be Number, PLEASE Enter a NUMBER : ";
        cin >> bookPrice;
    }
    setPrice(bookPrice);
}
//compare By price
bool Book::operator==( const Book check) const{
    if(bookPrice != check.bookPrice)
        return false;
    else
        return true;
}
bool Book::operator<( const Book check) const{
    if(bookPrice < check.bookPrice)
        return true;
    else
        return false;
}
