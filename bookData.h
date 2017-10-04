/*******************************************************************************
*Class:         bookData                                                       *
*Purpose:       The object stores and allowes restricted access to several     *
*               pieces of information about a book in the store's inventory.   *
*Author:        Nathan Hansen                                                  *
*******************************************************************************/

#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>

using namespace std;

class bookData
{
    private:
        string bookTitle;//Title of the Book
        string isbn;//ISBN Number of the Book
        string author;//Stores Book's Author
        string publisher;//Stores Publisher
        string dateAdded;//Stores the Date the book was added to inventory
        int qtyOnHand;//The number of the book left in inventory
        float wholesale, retail;//the wholesale and retail cost of the book
        bool empty;//Used to delineate open spot in the array/inventory
        
    public:
        bookData()//Default Constructor
        {
            qtyOnHand, wholesale, retail = 0;
            empty = true;
            bookTitle, isbn, author, publisher = "\0";
        }
        
        //Member Function Prototypes
        void setTitle(string title);      
        void setIsbn(string Isbn);       
        void setAuthor(string Author);       
        void setPub(string pub);      
        void setDateAdded(string date);      
        void setQty(int Qty);        
        void setWholesale(float Wholesale);        
        void setRetail(float Retail);       
        bool isEmpty();      
        void removeBook();        
        string getTitle();        
        string getIsbn();        
        string getAuthor();                 
        string getPub();        
        string getDateAdded();        
        int getQty();        
        float getWholesale();        
        float getRetail();
  };
  
#endif

