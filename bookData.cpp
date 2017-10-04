#include <string>
#include "bookData.h"



/*******************************************************************************
*       Mutator Functions:                                                     *
*******************************************************************************/        
void bookData::setTitle(string title)
{bookTitle = title;}
        
void bookData::setIsbn(string Isbn)
{isbn = Isbn;}
        
void bookData::setAuthor(string Author)
{author = Author;}
        
void bookData::setPub(string pub)
{publisher = pub;}
        
void bookData::setDateAdded(string date)
{dateAdded = date;}
        
void bookData::setQty(int Qty)
{qtyOnHand = Qty;}
        
void bookData::setWholesale(float Wholesale)
{wholesale = Wholesale;}
        
void bookData::setRetail(float Retail)
{retail = Retail;}
   
        
/*******************************************************************************
*       Accessor Functions                                                     *
*******************************************************************************/                  
string bookData::getTitle()
{return bookTitle;}
        
string bookData::getIsbn()
{return isbn;}
        
string bookData::getAuthor()
{return author;}         
        
string bookData::getPub()
{return publisher;}
        
string bookData::getDateAdded()
{return dateAdded;}
        
int bookData::getQty()
{return qtyOnHand;}
        
float bookData::getWholesale()
{return wholesale;}
        
float bookData::getRetail()
{return retail;}


/*******************************************************************************
*       Special Function                                                       *                   
*******************************************************************************/
bool bookData::isEmpty()
{return empty;}
        
void bookData::removeBook()
{empty = true;}
        

