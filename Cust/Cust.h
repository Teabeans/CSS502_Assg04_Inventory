//-------------------------------------|
// Begin Student Code
//-------------------------------------|

// Requisite in the .h file
#pragma once

// Necessary for string operations
#include <string>

// Necessary for transaction operations
#include "../Trans/Trans.h"


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
// #appendHistory()
//-----------------|
// Desc:   Appends values to the customer history
// Invars: May be called with faulty transaction information
//         GIGO - No error checking is performed by appendHistory()
   void appendHistory(std::string someTransaction);
   void appendHistory(Trans someTransaction);

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
   void setFirstName(std::string firstName);
   void setLastName(std::string lastName);
   void setName(std::string first, std::string last);

//-----------------|
// #setID()
//-----------------|
// Desc:   Sets the customer ID number
// Invars: None
   void setID(int custID);



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
   Cust(std::string firstName, std::string lastName, int custID);

//-----------------|
// #~Cust()
//-----------------|
// Desc:   Customer deconstructor
// Invars: None
   ~Cust();



}; // Closing class Cust{}
