//-------------------------------------|
// Begin Student Code
//-------------------------------------|

// Requisite in the .h file
#pragma once

// Necessary for string operations
#include <string>

// Necessary for rental tracking
#include <queue>

// Necessary for transaction operations
#include "Trans.h"


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CLASS CONSTANTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class


class Cust {

private:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------|
// #firstName
//-----------------|
// Desc:   The customer's first name
// Invars: Must contain at least one character
   std::string firstName;

//-----------------|
// #lastName
//-----------------|
// Desc:   The customer's last name
// Invars: Must contain at least one character
   std::string lastName;

//-----------------|
// #custID
//-----------------|
// Desc:   The customer's ID number
// Invars: Initializes to junk values - set by hashing
   int custID;

//-----------------|
// #history
//-----------------|
// Desc:   The customer's history
// Invars: May be an empty string
   std::string history;

//-----------------|
// #numRentals
//-----------------|
// Desc:   The number of titles this customer has checked out
// Invars: Must be 0 or more, cannot be negative
   int checkouts;

//-----------------|
// #rentals
//-----------------|
// Desc:   The titles the customer currently has checked out
// Invars: May be empty
   std::queue<std::string> rentals;



public:
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

// Full comments in Cust.cpp - omitted here for clarity

//-----------------|
// #appendHistory(string)
//-----------------|
// Desc:   Appends values to the customer history
// Invars: May be called with faulty transaction information
//         GIGO - No error checking is performed by appendHistory()
   void appendHistory(std::string someTransaction);

//-----------------|
// #isCheckedOut(string)
//-----------------|
// Desc:   Returns whether this title is among those currently checked out by the customer
// Invars: GIGO - No error checking is performed by isCheckedOut()
   bool const isCheckedOut(std::string aTitle);

//-----------------|
// #addToCheckouts(string)
//-----------------|
// Desc:   Appends title to the list of current rentals by this customer
// Invars: GIGO - No error checking is performed by addToCheckouts()
   void addToCheckouts(std::string aTitle);

//-----------------|
// #removeFromCheckouts(string)
//-----------------|
// Desc:   Removes the earliest occurrence of this title from the current rentals
// Invars: GIGO - No error checking is performed by removeFromCheckouts()
   void removeFromCheckouts(std::string aTitle);

//-----------------|
// #toString()
//-----------------|
// Desc:   Converts the customer object to its string representation
// Invars: None
   std::string toString();



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Full comments in Cust.cpp - omitted here for clarity

//-----------------|
// #getFirstName()
// #getLastName()
// #getName()
//-----------------|
// Desc:   Returns the customer name
// Invars: None
   std::string getFirstName(); // First name only
   std::string getLastName();  // Last name only
   std::string getName();      // First and last name, concatenated

//-----------------|
// #getID()
//-----------------|
// Desc:   Returns the customer ID number
// Invars: None
   int getID();

//-----------------|
// #getHistory
//-----------------|
// Desc:   Returns the customer history
// Invars: GIGO - No alterations or filtering is applied to the history
   std::string getHistory();

//-----------------|
// #setFirstName()
// #setLastName()
// #setName()
//-----------------|
// Desc:   Sets the customer name
// Invars: None
   void setFirstName(std::string nameF);
   void setLastName(std::string nameL);
   void setName(std::string nameF, std::string nameL);

//-----------------|
// #setID()
//-----------------|
// Desc:   Sets the customer ID number
// Invars: None
   void setID(int IDnum);



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------|
// #Cust()
//-----------------|
// Desc:   Customer default constructor
// Invars: None
   Cust();

//-----------------|
// #Cust(string, string, int)
//-----------------|
// Desc:   Customer constructor by name and ID
// Invars: None
   Cust(std::string nameF, std::string nameL, int IDnum);

//-----------------|
// #~Cust()
//-----------------|
// Desc:   Customer deconstructor
// Invars: None
   ~Cust();



}; // Closing class Cust{}
