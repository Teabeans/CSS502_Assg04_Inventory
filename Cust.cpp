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
// Modified: 2018.03.--
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
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
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
// Desc:    Returns whether this title is among those currently checked out by the customer
// Params:  NULL
// PreCons: GIGO - No error checking is performed by isCheckedOut()
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
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
}

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
   this->rentals.push(aTitle);
   this->checkouts++;
}

// (+) --------------------------------|
// #removeFromCheckouts(string)
//-------------------------------------|
// Desc:    Removes the earliest occurrence of this title from the current rentals
// Params:  NULL
// PreCons: GIGO - No error checking is performed by removeFromCheckouts()
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Cust::removeFromCheckouts(std::string aTitle) {
   int counter = 0;
   while (counter < this->checkouts) {
      // If the element has been found...
      if (this->rentals.front() == aTitle) {
         // Remove it
         this->rentals.pop();
         break;
      }
      // Otherwise, move to the next element
      this->rentals.push(rentals.front());
      this->rentals.pop();
      // And increment the counter so we loop through just once
      counter++;
   }
   // Decrement the number of elements checked out
   this->checkouts--;
}

// (+) --------------------------------|
// #toString()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
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
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #getFirstName()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string Cust::getFirstName() {
   return (this->firstName);
} // Closing getFirstName()

// (+) --------------------------------|
// #getLastName()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string Cust::getLastName() {
   return (this->lastName);
} // Closing getLastName()

// (+) --------------------------------|
// #getName()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
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
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
int Cust::getID() {
   return (this->custID);
} // Closing getID()

// (+) --------------------------------|
// #getHistory()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string Cust::getHistory() {
   std::string retString = this->historyHeader + this->history;
   return(retString);
} // Closing getHistory()

// (+) --------------------------------|
// #setFirstName(string)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Cust::setFirstName(std::string nameF) {
   this->firstName = nameF;
}

// (+) --------------------------------|
// #setFirstName(string)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Cust::setLastName(std::string nameL) {
   this->lastName = nameL;
}

// (+) --------------------------------|
// #setName(string)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Cust::setName(std::string nameF, std::string nameL) {
   this->setFirstName(nameF);
   this->setLastName(nameL);
}

// (+) --------------------------------|
// #setID(int)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Cust::setID(int IDnum) {
   this->custID = IDnum;
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #Cust()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Cust::Cust() {
   std::cout << "(ERROR! Default customer constructor called)";
   this->firstName = "(firstName == NULL)";
   this->lastName  =  "(lastName == NULL)";
   this->history   =   "(history == NULL)";
   this->custID    = 99999; // Number out-of-bounds
}
// (+) --------------------------------|
// #Cust(string)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Cust::Cust(std::string command) {
   std::string nameF = "";
   std::string nameL = "";
   int IDnum = 0;

   std::stringstream stream(command);

   stream >> nameF;
   stream >> nameL;
   stream >> IDnum;

   this->firstName = nameF;
   this->lastName  = nameL;
   this->custID    = IDnum;
   this->historyHeader = "Transaction history for ";
   this->historyHeader += this->firstName + " " + this->lastName + " (ID ";
   // Convert the ID integer to a 4-wide formatted string
   std::ostringstream tempStream;
   tempStream << std::setw(4) << std::setfill('0') << this->custID;
   std::string tempString(tempStream.str());
   // Append that string to the history header
   this->historyHeader += tempString + "): \n";
}

// (+) --------------------------------|
// #Cust(string, string, int)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Cust::Cust(std::string nameF, std::string nameL, int IDnum) {
   this->firstName = nameF;
   this->lastName  = nameL;
   this->custID    = IDnum;
   this->historyHeader = "Transaction history for ";
   this->historyHeader += this->firstName + " " + this->lastName + " (ID ";
   // Convert the ID integer to a 4-wide formatted string
   std::ostringstream tempStream;
   tempStream << std::setw(4) << std::setfill('0') << this->custID;
   std::string tempString(tempStream.str());
   // Append that string to the history header
   this->historyHeader += tempString + "): \n";
}

// (+) --------------------------------|
// #~Cust()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Cust::~Cust() {
   this->firstName = "";
   this->lastName  = "";
   this->history   = "";
   this->custID    = 99999; // Number out-of-bounds
}

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of file - Cust.cpp
//Testing!