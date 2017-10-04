/*******************************************************************************
*Program:       Serendipity Booksellers                                        *
*Purpose:       To give the bookstore POS functionality & inventory management *
*Date Created:  October 1st, 2004                                              *
*Author:        Nathan Hansen                                                  *
*Revision:      0.1(Alpha)                                                     *
*******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include "bookData.h"

using namespace std;

const int SIZE_OF_ARRAY = 20;//Global Declaration of Array Size

//Function Prototypes
void cashier();
void bookInfo(bookData invArray);
void reports();
        //Functions Used by reports
        void repListing();
        void repWholesale();
        void repRetail();
        void repQty();
        void repCost();
        void repAge();
void invMenu(bookData invArray[]);
        //Functions Used by invMenu
        void lookUpBook(bookData invArray[]);
        void addBook(bookData invArray[]);
        void editBook(bookData invArray[]);
        void deleteBook(bookData invArray[]);
        int findBook(string searchString, bookData invArray[]);

int main()
{
    int choice;
    bookData bookArray[SIZE_OF_ARRAY];
    
    cout << "Serendipity Booksellers" << endl;
    cout << "Main Menu \n";
    
    do //Diplays the Main Menu and Accesses the other menus
    {
        cout << "\n\t1. Cashier Menu \n\t";
        cout << "2. Inventory Database Module \n\t";
        cout << "3. Report Module \n\t";
        cout << "4. Exit \n\n\t";
        
        cout << "Enter your Choice: ";
        cin >> choice;
        
        while(choice < 1 || choice > 4)
        {
            cout << "\nPlease enter a number in the range 1-4:";
            cin >> choice;
        }    
        
        switch (choice)//Runs the Module programs of the Main Program
          {
              case 1:
                cashier();
                break;

            case 2:
                invMenu(bookArray);
                break;

            case 3:
                reports();
                break;
       }
  } while(choice !=4);         
  
  system("PAUSE");	
  return 0;
}



/*******************************************************************************
*Function:      Reports                                                        *
*Purpose:       Unknown                                                        *
*Author:        Nathan Hansen                                                  *
*******************************************************************************/
void reports()
{
    int choice;
    
    do
    {
    
    cout << "\nSerendipity Booksellers \n";
    cout << "Reports\n\n";
    
    cout << "1. Inventory Listing\n";
    cout << "2. Inventory wholesale value\n";
    cout << "3. Inventory Retail Value\n";
    cout << "4. Listing by Quantity\n";
    cout << "5. Listing by Cost\n";
    cout << "6. Listing by Age\n";
    cout << "7. Return to Main Menu\n\n";
    
    cout << "Enter your choice: ";
    cin >> choice;
    
    while(choice < 1 || choice > 7)
        {
            cout << "\nPlease enter a number in the range 1-7";
        }    
        
        switch (choice)
          {
              case 1:
                repListing();
                break;
            
            case 2:
                repWholesale();
                break;
                
            case 3:
                repRetail();
                break;
                
            case 4:
                repQty();
                break;
            
            case 5:
                repCost();
                break;
                
            case 6:
                repAge();
                break;
       }
    } while(choice != 7);	
}



/*******************************************************************************
*Function:       reports Stub-Functions                                        *
*Purpose:        Unknown                                                       *
*Author:         Nathan Hansen                                                 *
*******************************************************************************/
void repListing()
    {
        cout << "\nYou selected Inventory Listing\n\n";
    }
     
    void repWholesale()
    {
        cout << "\nYou selected Inventory Wholesale Value\n\n";
    }
    
    void repRetail()
    {
        cout << "\nYou selected Inventory Retail Value\n\n";
    }
    
    void repQty()
    {
        cout << "\nYou selected Listing by Qauntity\n\n";
    }
    
    void repCost()
    {
        cout << "\nYou selected Listing by Cost\n\n";
    }
    
    void repAge()
    {
        cout << "\nYou selected Listing by Age\n\n";
    }

/*******************************************************************************
*Function:      cashier                                                        *
*Purpose:       Displays a cashiers receipt for a book purchase                *
*Author:        Nathan Hansen                                                  *
*******************************************************************************/
void cashier()
{
    string date, ISBN;
    char title[100], choice;
    int quantity;
    float price, subtotal, total, tax;
    
    
    
    cout << "\nSerendipity Booksellers\n";
    cout << "Cashier Module ";
    
    do
    {
        cout << "\n\n\tDate: ";
        cin >> date;
        
        cout << "\tQuantity of Book: ";
        cin >> quantity;
        
        cout << "\tISBN: ";
        cin >> ISBN;
        
        cout << "\tTitle: ";
        cin.ignore();
        cin.getline(title, 100);
        
        cout << "\tPrice: ";
        cin >> price;
        
        subtotal = price * quantity;
        tax = subtotal * .065;
        total = subtotal + tax;
    
    cout << setprecision(2) << setiosflags(ios::fixed | ios::showpoint);
    cout << "\nSerendipity Booksellers \n\n" << endl;
    cout << "Date: " << date << "\n\n";
    
    cout << setw(4) << "Qty" << setw(13) << "ISBN" << setw(25) << "Title" << setw(10) << "Price" << setw(10) << "Total\n";
    cout << "----------------------------------------------------------------------------\n";
    cout << setw(4) << quantity << setw(13) << ISBN << setw(25) << title << setw(10) << price << setw(10) << subtotal << endl << endl;
    cout << setw(4) << " " << setw(13) << " " << setw(25) << "Subtotal" << setw(10) << setw(10) << subtotal << endl;
    cout << setw(4) << " " << setw(13) << " " << setw(25) << "Tax" << setw(10) << setw(10) << tax << endl;
    cout << setw(4) << " " << setw(13) << " " << setw(25) << "Total" << setw(10) << setw(10)<< total << endl << endl;
                                  
    cout << "Thank You for Shopping at Serendipidity\n\n";
    
    cout << "Would you like to run again? Y or N: ";
    cin >> choice;

    }while(choice == 'Y' || choice == 'y');	
}


/*******************************************************************************
*Function:      bookInfo                                                       *
*Purpose:       Displays the info of a book object passed to it.               *
*Author:        Nathan Hansen                                                  *
*******************************************************************************/
void bookInfo(bookData invArray)
{
    cout << "\nSerendipity Booksellers \n" << endl;
    cout << "Book Information\n\n";
    
    cout << "\nTitle:  " << invArray.getTitle();
    cout << "\nISBN:  " << invArray.getIsbn();
    cout << "\nAuthor:  " << invArray.getAuthor();
    cout << "\nPublsiher:  " << invArray.getPub();
    cout << "\nDate Added:  " << invArray.getDateAdded();
    cout << "\nQuantity-On-Hand:  " << invArray.getQty();
    cout << "\nWholesale Cost:  " << invArray.getWholesale();
    cout << "\nRetail Price:  " << invArray.getRetail();
}



/*******************************************************************************
*Function:      Inventory Menu                                                 *
*Purpose:       Allows you to look up a book, add a book, edit a book, or      *
*               remove a book from the inventory.                              *
*Author:        Nathan Hansen                                                  * 
*******************************************************************************/
void invMenu(bookData invArray[])
{
    int choice;
    
    //Displays invMenu Header
    cout << "\n";
    cout << "Serendipity Booksellers";
    cout << "\n";
    cout << "Inventory Database";
    
    do//Displays the invMenu menu and accesses functions
    {    
    cout << "\n\n\t";
    cout << "1. Look up a book";
    cout << "\n\t";
    cout << "2. Add a book";
    cout << "\n\t";
    cout << "3. Edit a Book's Records";
    cout << "\n\t";
    cout << "4. Delete a Book";
    cout << "\n\t";
    cout << "5. Return to the Main Menu";
    cout << "\n\n\t";
    
    cout << "Enter your choice: ";
    cin >> choice;
    
    while(choice < 1 || choice > 5)
        {
            cout << "\nPlease enter a number in the range 1-5";
        }    
        
        switch (choice)
          {
              case 1:
                lookUpBook(invArray);
                break;
            
            case 2:
                addBook(invArray);
                break;
                
            case 3:
                editBook(invArray);
                break;
                
            case 4:
                deleteBook(invArray);
                break;
       }
    } while(choice !=5);
}


   
/*******************************************************************************
*Function:      findBook                                                       *
*Purpose:       Locates a book in the array using the book's title or ISBN     *
*               number                                                         *
*Author:         Nathan Hansen                                                 *
*******************************************************************************/
int findbook(string searchString, bookData invArray[])
{
    int index = 0;
    int position = -1;
    bool found = false;
    
    while(index < SIZE_OF_ARRAY && !found)
    {
        if((invArray[index].getIsbn() == searchString) || (invArray[index].getTitle() == searchString))
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}            



/*******************************************************************************
*Function:      addBook                                                        *
*Purpose:       Accepts an array of bookData objects, looks through the array  *
*               for an empty object, and creates a new bookData object is one  *
*               is found.  If not, the function reports this to the user       *
*******************************************************************************/      
void addBook(bookData invArray[])
{
  int index = 0;
  int position = -1;
  bool found = false;
    
    while(index < SIZE_OF_ARRAY && !found)
    {
        if(invArray[index].isEmpty() == true)
        {
            found = true;
            position = index;
        }
        index++;
    }
  if(found == false)
  {
      cout << "\nThe inventory is full and no more books may be added.";
      return;
  }
  else
  {
      string newTitle, newISBN, newAuthor, newPublisher, newDate;
      int newQTY;
      float newWholesale, newRetail;
      
      cout << "\nThere is room in inventory for a new book.  Please enter in"
      << "the following fields.";


      cout << "\n\nPlease enter the book's Title: ";
      cin >> newTitle;
      invArray[position].setTitle(newTitle);

      cout << "\nPlease enter the book's ISBN number: ";
      cin >> newISBN;
      invArray[position].setIsbn(newISBN);
      
      cout << "\nPlease enter the book's Author: ";
      cin >> newAuthor;
      invArray[position].setAuthor(newAuthor);
      
      cout << "\nPlease enter the book's Publisher: ";
      cin >> newPublisher;
      invArray[position].setPub(newPublisher);
      
      cout << "\nPlease enter today's date: ";
      cin >> newDate;
      invArray[position].setDateAdded(newDate);
      
      cout << "\nPlease enter the quantity of the book: ";
      cin >> newQTY;
      invArray[position].setQty(newQTY);
      
      cout << "\nPlease enter the wholesale cost of the book: ";
      cin >> newWholesale;
      invArray[position].setWholesale(newWholesale);
      
      cout << "\nPlease enter the retail cost of the book: ";
      cin >> newRetail;
      invArray[position].setRetail(newRetail);
  }    
}     


          
/*******************************************************************************
*Function:      lookUpBook                                                     *
*Purpose:       Looks for a book object, using the findBook function, then     *
*               displays the info of the book object.                          *
*Author:        Nathan Hansen                                                  *
*******************************************************************************/
void lookUpBook(bookData invArray[])
{
    string search_string;
    int position;
    
    cout << "Please enter either the title or the ISBN number of the book you "
        << "are searching for: ";
    cin >> search_string;
    
    position = findbook(search_string, invArray);
    
    if(position == -1)
    {
        cout << "\nSorry, but the book you are looking for is not in our "
        << "inventory.  Make sure you use the correct spelling and try again.";
        
        return;
    }
    else
        bookInfo(invArray[position]);   
}    

void editBook(bookData invArray[])
{
    string search_string;
    int position;
    
    position = findbook(search_string, invArray);
    
    if(position == -1)
    {
        cout << "\nSorry, but the book you are looking for is not in our "
        << "inventory.  Make sure you use the correct spelling and try again.";
        
        return;
    }
    else
    {
        bookInfo(invArray[position]);
        
        string newTitle, newISBN, newAuthor, newPublisher, newDate;
        int newQTY, choice;
        float newWholesale, newRetail;
        
        do
        {
            cout << "Which field would you like to change?";
            cout << "\n\t1. Book Title";
            cout << "\n\t2. ISBN Nubmer";
            cout << "\n\t3. Author's Name";
            cout << "\n\t4. Publisher's Name";
            cout << "\n\t5. Date Added";
            cout << "\n\t6. Quantity";
            cout << "\n\t7. Wholesale Cost";
            cout << "\n\t8. Retail Price";
            cout << "\n\t9. Return to Menu";
            
            cout << "\n\n Please enter you choice(1-9): ";
            cin >> choice;
            
            while(choice < 1 || choice > 9)
            {
                cout << "\nPlease enter a number in the range of 1-9; ";
                cin >> choice;
            }
            
                switch(choice)
                {
                 case 1:
                     cout << "\n\nPlease enter the book's Title: ";
                     cin >> newTitle;
                     invArray[position].setTitle(newTitle);
                     break;
                 
                 case 2:
                     cout << "\nPlease enter the book's ISBN number: ";
                     cin >> newISBN;
                     invArray[position].setIsbn(newISBN);
                     break;
                 
                 case 3:
                     cout << "\nPlease enter the book's Author: ";
                     cin >> newAuthor;
                     invArray[position].setAuthor(newAuthor);
                     break;
                 
                 case 4:
                     cout << "\nPlease enter the book's Publisher: ";
                     cin >> newPublisher;
                     invArray[position].setPub(newPublisher);
                     break;
                 
                 case 5:
                     cout << "\nPlease enter today's date: ";
                     cin >> newDate;
                     invArray[position].setDateAdded(newDate);
                     break;
                 
                 case 6:
                     cout << "\nPlease enter the quantity of the book: ";
                     cin >> newQTY;
                     invArray[position].setQty(newQTY);
                     break;
                 
                 case 7:
                     cout << "\nPlease enter the wholesale cost of the book: ";
                     cin >> newWholesale;
                     invArray[position].setWholesale(newWholesale);
                     break;
                     
                 case 8:
                     cout << "\nPlease enter the retail cost of the book: ";
                     cin >> newRetail;
                     invArray[position].setRetail(newRetail);
                     break;
                 }
             }while(choice!=9);
         }
                                
}

void deleteBook(bookData invArray[])
{
    string search_string;
    int position;
    char choice;
    
    position = findbook(search_string, invArray);
    
    if(position == -1)
    {
        cout << "\nSorry, but the book you are looking for is not in our "
        << "inventory.  Make sure you use the correct spelling and try again.";
        
        return;
    }
    else
    {
        bookInfo(invArray[position]);
        
        cout << "Are you sure you want to delete the records of this book? (Y " 
         << "or N): ";
        cin >> choice;
        
        if(choice == 'y' || choice == 'Y')
            invArray[position].removeBook();
        } 
}

