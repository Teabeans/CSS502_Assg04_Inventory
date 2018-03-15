//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// Cust.cpp
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------------------------------------------------------------------|
// Authorship
//-----------------------------------------------------------------------------|
//
// Matt Gross & Tim Lum
// mattgrosspersonal@gmail.com + twhlum@gmail.com
// Created:  2018.03.03
// Modified: 2018.03.14
// For the University of Washington Bothell, CSS 502A
// Winter 2018, Graduate Certificate in Software Design & Development (GCSDD)
//

//-----------------------------------------------------------------------------|
// File Description
//-----------------------------------------------------------------------------|
//
// This is the implementation file for the Cust.h header.
//

//-----------------------------------------------------------------------------|
// Package Files
//-----------------------------------------------------------------------------|
//
// See Github repository
// https://github.com/Teabeans/CSS502_Assg04_Inventory
//

//-------------------------------------|
// Begin Student Code
//-------------------------------------|

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INCLUDE STATEMENTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Field and method declarations for the Cust (Customer) class
#include "Cust.h"

// Necessary for transaction operations
#include "Trans.h"

// Necessary for input-output operations
#include <iostream>

// Necessary for string formatting operations
#include <iomanip>

// Necessary for string stream buffering operations
#include <sstream>

// Necessary for string operations
#include <string>

// Necessary for breadth-first tree traversal
#include <queue>

// For tracing visitation routes
#include <stack>



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CLASS CONSTANTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
//
// Do not redeclare these variables in the .cpp.
// Included here only for reference
// See associated .h file for variable declarations
//
// None for this class
//

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|
//
// Do not redeclare these variables in the .cpp.
// Included here only for reference
// See associated .h file for variable declarations

//-----------------|
// #firstName
//-----------------|
// Desc:   The customer's first name
// Invars: Must contain at least one character
///   std::string firstName;

//-----------------|
// #lastName
//-----------------|
// Desc:   The customer's last name
// Invars: Must contain at least one character
///   std::string lastName;

//-----------------|
// #custID
//-----------------|
// Desc:   The customer's ID number
// Invars: Initializes to junk values - set by hashing
///   int custID;

//-----------------|
// #history
//-----------------|
// Desc:   The customer's history
// Invars: May be an empty string
///   std::string history;

//-----------------|
// #historyHeader
//-----------------|
// Desc:   The customer's history header
// Invars: May not be an empty string
///   std::string historyHeader;

//-----------------|
// #numRentals
//-----------------|
// Desc:   The number of titles this customer has checked out
// Invars: Must be 0 or more, cannot be negative
///   int checkouts;

//-----------------|
// #rentals
//-----------------|
// Desc:   The titles the customer currently has checked out
// Invars: May be empty
///   std::queue<std::string> rentals;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC FIELDS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #appendHistory(String)
//-------------------------------------|
// Desc:    Appends values to the customer history
// Params:  string arg1 - The transaction to append
// PreCons: String configuration should be handled by the Trans::toString() method
//          May be called with faulty transaction information
//          GIGO - No error checking is performed by appendHistory()
// PosCons: The transaction has been added to 'this' history
//          The title of the Film has been added or removed from the checkouts
// RetVal:  None
// MetCall: Cust::addToCheckouts()
//          Cust::removeFromCheckouts()
void Cust::appendHistory(std::string someTransaction, char type, std::string title){
   // Add or remove from customer checkouts
   if (type == 'B') {
      this->addToCheckouts(title);
   }
   if (type == 'R') {
      this->removeFromCheckouts(title);
   }
   // Append history
   this->history = someTransaction + "\n" + this->history;
}

// (+) --------------------------------|
// #isCheckedOut(string)
//-------------------------------------|
// Desc:    Returns whether 'this' customer has the title checked out
// Params:  string arg1 - The title in question
// PreCons: GIGO - No error checking is performed by isCheckedOut()
//          Search is not deeper than the level of the Film title
// PosCons: None
// RetVal:  bool True - The title was found
//          bool False - The title was not found
// MetCall: queue::front()
//          queue::pop()
//          queue::push()
bool const Cust::isCheckedOut(std::string aTitle) {
   bool wasFound = false;
   int counter = 0;
   while (counter < this->checkouts) {
      // If the first queue element matches the title we're looking for
      if (this->rentals.front() == aTitle) {
         // Toggle the flag
         wasFound = true;
      }
      // Either way, move to the next element
      this->rentals.push(rentals.front());
      this->rentals.pop();
      // And increment the counter so we loop through just once
      counter++;
   }
   return(wasFound);
} // Closing isCheckedOut()

// (+) --------------------------------|
// #addToCheckouts(string)
//-------------------------------------|
// Desc:    Appends title to the list of current rentals by this customer
// Params:  NULL
// PreCons: GIGO - No error checking is performed by addToCheckouts()
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Cust::addToCheckouts(std::string aTitle) {
   // Place the title into the checkout queue
   this->rentals.push(aTitle);
   // Increment the number of titles checked out
   this->checkouts++;
} // Closing addToCheckouts()

// (+) --------------------------------|
// #removeFromCheckouts(string)
//-------------------------------------|
// Desc:    Removes the earliest occurrence of this title from the current rentals
// Params:  string arg1 - The title to remove
// PreCons: GIGO - No error checking is performed by removeFromCheckouts()
// PosCons: If found, the title has been removed from 'this' customer's rental list
// RetVal:  None
// MetCall: queue::front()
//          queue::pop()
//          queue::push()
void Cust::removeFromCheckouts(std::string aTitle) {
   // Start a counter
   int counter = 0;

   // Begin examining the rentals
   while (counter < this->checkouts) {
      // If the element has been found...
      if (this->rentals.front() == aTitle) {
         // Remove it
         this->rentals.pop();
         // Decrement the number of elements checked out
         this->checkouts--;
         // And exit
         return;
      }
      // Otherwise, put the front element at the back of the queue
      this->rentals.push(rentals.front());
      // And remove it from the front
      this->rentals.pop();
      // And increment the counter so we loop through just once
      counter++;
   } // Closing while - All items checked out have been examined
} // Closing removeFromCheckouts()

// (+) --------------------------------|
// #toString()
//-------------------------------------|
// Desc:    Returns a string representation of 'this' customer
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  string - A string representation of 'this' customer
// MetCall: std::setw()
//          std::setfill()
//          std::left
//          Cust::getLastName()
//          stringstream::str()
std::string Cust::toString() {
   std::string retString = "";
// retString += "ID        First Name           Last Name\n";
//               1234      01234567890123456789 01234567890123456789
   // Generate a temporary stream for appending
   std::stringstream tempStream;
   // Append all values, properly formatted
   // TODO: Test this from driver
   tempStream << std::setw(4) << std::setfill('0') << this->custID << "      ";
   tempStream << std::setw(20) << std::setfill(' ') << std::left << this->getFirstName() << " ";
   tempStream << std::setw(20) << this->getLastName();
   // Assign the temporary stream to the return string
   retString = tempStream.str();
   // Return the result
   return (retString);
} // Closing toString()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #getFirstName()
//-------------------------------------|
// Desc:    Getter for the Customer's first name
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  string - The customer's first name
// MetCall: None
std::string Cust::getFirstName() {
   return (this->firstName);
} // Closing getFirstName()

// (+) --------------------------------|
// #getLastName()
//-------------------------------------|
// Desc:    Getter for the Customer's last name
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  string - The customer's last name
// MetCall: None
std::string Cust::getLastName() {
   return (this->lastName);
} // Closing getLastName()

// (+) --------------------------------|
// #getName()
//-------------------------------------|
// Desc:    Getter for the Customer's full name
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  string - The customer's full name
// MetCall: None
std::string Cust::getName() {
   std::string retString = "";
   retString += this->firstName;
   retString += " ";
   retString += this->lastName;
   return (retString);
} // Closing getName()

// (+) --------------------------------|
// #getID()
//-------------------------------------|
// Desc:    Getter for the Customer's ID number
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  int - The customer ID
// MetCall: None
int Cust::getID() {
   return (this->custID);
} // Closing getID()

// (+) --------------------------------|
// #getHistory()
//-------------------------------------|
// Desc:    Acquires the string representation of 'this' customer's history
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  string - The string representation of the customer's history
// MetCall: None
std::string Cust::getHistory() {
   std::string retString;
   if (this->history != "") {
      retString = this->historyHeader + this->history;
   }
   else {
      retString = this->historyHeader;
      retString += "   - No transactions for this customer.\n";
   }
   return(retString);
} // Closing getHistory()

// (+) --------------------------------|
// #setFirstName(string)
//-------------------------------------|
// Desc:    Sets the Customer first name to a received string value
// Params:  string arg1 - The desired Customer first name
// PreCons: GIGO - No error checking is handled by this method.
// PosCons: The first name has been set
// RetVal:  None
// MetCall: None
void Cust::setFirstName(std::string nameF) {
   this->firstName = nameF;
}

// (+) --------------------------------|
// #setLastName(string)
//-------------------------------------|
// Desc:    Sets the Customer last name to a received string value
// Params:  string arg1 - The desired Customer last name
// PreCons: GIGO - No error checking is handled by this method.
// PosCons: The last name has been set
// RetVal:  None
// MetCall: None
void Cust::setLastName(std::string nameL) {
   this->lastName = nameL;
}

// (+) --------------------------------|
// #setName(string)
//-------------------------------------|
// Desc:    Sets the Customer name to a received string values
// Params:  string arg1 - The desired Customer first name
//          string arg2 - The desired Customer last name
// PreCons: GIGO - No error checking is handled by this method
// PosCons: The name has been set
// RetVal:  None
// MetCall: None
void Cust::setName(std::string nameF, std::string nameL) {
   this->setFirstName(nameF);
   this->setLastName(nameL);
} // Closing setName()

// (+) --------------------------------|
// #setID(int)
//-------------------------------------|
// Desc:    Sets the Customer ID to a received int value
// Params:  int arg1 - The desired Customer ID
// PreCons: GIGO - No error checking is handled by this method.
// PosCons: The ID has been set
// RetVal:  None
// MetCall: None
void Cust::setID(int IDnum) {
   this->custID = IDnum;
} // Closing setID()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #Cust()
//-------------------------------------|
// Desc:    Default Customer constructor
// Params:  None
// PreCons: Should not be used under normal circumstances
// PosCons: A default (error state) customer has been allocated
// RetVal:  None
// MetCall: None
Cust::Cust() {
   std::cout << "(ERROR! Default customer constructor called)";
   this->firstName = "(firstName == NULL)";
   this->lastName  =  "(lastName == NULL)";
   this->history   =   "(history == NULL)";
   this->custID    = 99999; // Number out-of-bounds
} // Closing Cust()

// (+) --------------------------------|
// #Cust(string)
//-------------------------------------|
// Desc:    Customer constructor by name and ID
// Params:  string arg1 - A line of command describing a Customer
// PreCons: GIGO - No error checking is performed by this method
//          The input must be properly formatted upon receipt
// PosCons: A customer represented by the received command has been allocated
// RetVal:  None
// MetCall: std::setw()
//          std::setfill()
//          stringstream::str()
Cust::Cust(std::string command) {
   std::string nameF = "";
   std::string nameL = "";
   int IDnum = 0;

   std::stringstream stream(command);

   // Sample input: 9000 Lizard Larry
   stream >> IDnum;
   stream >> nameL;
   stream >> nameF;

   this->custID    = IDnum;
   this->lastName  = nameL;
   this->firstName = nameF;


   this->historyHeader = "Transaction history for ";
   this->historyHeader += this->firstName + " " + this->lastName + " (ID ";
   // Convert the ID integer to a 4-wide formatted string
   std::stringstream tempStream;
   tempStream << std::setw(4) << std::setfill('0') << this->custID;
   std::string tempString(tempStream.str());
   // Append that string to the history header
   this->historyHeader += tempString + "): \n";
} // Closing Cust(string)

// (+) --------------------------------|
// #Cust(string, string, int)
//-------------------------------------|
// Desc:    Customer constructor by name and ID
// Params:  string arg1 - The Customer's first name
//          string arg2 - The Customer's last name
//          int arg3 - The Customer's ID number
// PreCons: None
// PosCons: A new customer holding the received fields has been allocated
// RetVal:  None
// MetCall: std::setw()
//          std::setfill()
//          stringstream::str()
Cust::Cust(std::string nameF, std::string nameL, int IDnum) {

   this->custID    = IDnum;
   this->lastName  = nameL;
   this->firstName = nameF;

   this->historyHeader = "Transaction history for ";
   this->historyHeader += this->firstName + " " + this->lastName + " (ID ";

   // Convert the ID integer to a 4-wide formatted string
   std::stringstream tempStream;
   tempStream << std::setw(4) << std::setfill('0') << this->custID;
   std::string tempString(tempStream.str());

   // Append that string to the history header
   this->historyHeader += tempString + "): \n";
} // Closing Cust(string, string, int)

// (+) --------------------------------|
// #~Cust()
//-------------------------------------|
// Desc:    Customer deconstructor
// Params:  None
// PreCons: None
// PosCons: All fields have been zeroed
// RetVal:  None
// MetCall: None
Cust::~Cust() {
   this->firstName = "";
   this->lastName  = "";
   this->history   = "";
   this->custID    = 99999; // Number out-of-bounds
} // Closing ~Cust()

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of file - Cust.cpp
