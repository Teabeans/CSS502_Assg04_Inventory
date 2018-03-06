//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// CustDB.cpp
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
// This is the implementation file for the CustDB.h header.
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

// Field and method declarations for the Cust (Customer) class
#include "CustDB.h"

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CLASS CONSTANTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
//
// Do not redeclare these variables in the .cpp.
// Included here only for reference
// See associated .h file for variable declarations

// (+) ------------|
// #MAXCUSTOMERS
//-----------------|
// Desc:   The maximum anticipated number customer spots needed
// Invars: Set to 20011
/// const static int MAXCUSTOMERS = 20011;



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
// #custTable
//-----------------|
// Desc:   The customer database
// Invars: Table size must not exceed 9999, nearest prime is 9973
///   Cust* custTable[MAXCUSTOMERS];

//-----------------|
// #custTableByID
//-----------------|
// Desc:   The customer database, sorted by customer ID number
// Invars: Table size to accommodate 
///   Cust* custTableByID[10000];



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (-) --------------------------------|
// #doesConflict(Cust*, int)
//-------------------------------------|
// Desc:    Determines whether this customer and index creates a collision
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
bool CustDB::doesConflict(Cust* custPtr, int query) {
   // Identity check - If the pointers are the same, this is not a collision.
   if (this->custTable[query] == custPtr) {
      return (false);
   }
   // Else, if anything is here, that's a collision.
   else if (this->custTable[query] != nullptr) {
      return (true);
   }
   // Nothing found at that location, so no conflict exists.
   return (false);
} // Closing doesConflict()

//-----------------|
// #isValid(string)
//-----------------|
// Desc:   Determines whether this string is a valid customerDB command
// Invars: Return value is variable based on state of DB
bool CustDB::isValid(std::string) {

} // Closing isValid()

// (-) --------------------------------|
// #hash(Cust*)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: Customer name ("F L") must contain at least 3 chars.
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
int CustDB::hash(Cust* custPtr) {
   std::string custName = custPtr->getName();
   char letter1 = custName[0]; // TODO: Verify that this is legal
   char letter2 = custName[1];
   char letter3 = custName[2];
   int intOf1 = letter1 * 1000000; // 123 goes to 123 000 000
   int intOf2 = letter2 * 1000;    // 456 goes to     456 000
   int intOf3 = letter3;           // 789 goes to         789
   int hash = ( letter1 + letter2 + letter3 ) % MAXCUSTOMERS;
   // If a conflict is identified
   if (this->doesConflict(custPtr, hash)) {
      // Probe until an open index is found
      hash = this->probe(custPtr, hash);
   }
   // Non-conflicting index guaranteed
   return(hash);
}

// (-) --------------------------------|
// #probe(Cust*)
//-------------------------------------|
// Desc:    Linear probe
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
int CustDB::probe(Cust* custPtr, int query) {
   int hash = query;
   while (this->doesConflict(custPtr, query)) {
      // Linear probe!
      hash++;
   }
   return(hash);
} // Closing probe()

// (-) --------------------------------|
// #obliviate()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void CustDB::obliviate() {
   for (int i = 0 ; i < MAXCUSTOMERS ; i++) {
      if (this->custTable[i] != nullptr) {
         delete custTable[i];
      }
   }
   for (int i = 0 ; i <= 9999 ; i++) {
      this->custTableByID[i] = nullptr;
   }
}



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
// #toString()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string CustDB::toString() {
   std::string retString = "CustDB::toString() \n";
   retString += "Customer Database:\n";
   retString += "ID        First Name           Last Name\n";
//               1234      01234567890123456789 01234567890123456789
   // Go down the custTable
   for (int i = 0 ; i < MAXCUSTOMERS ; i++) {
      // And for every valid Customer...
      if (custTable[i] != nullptr) {
         // Append them to the string
         retString += custTable[i]->toString() + "\n";
      }
   }
   return (retString);
} // Closing toString()

// (+) --------------------------------|
// #display()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void CustDB::display() {
   // TODO: Write display() function
   std::cout << "CustDB::display()" << std::endl;
   std::cout << this->toString() << std::endl;

} // Closing display()

// (+) --------------------------------|
// #insertCustomer(Cust&)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void CustDB::insertCustomer(Cust* custPtr) {
   int indexToInsertAt = this->hash(custPtr);
   // Add customer to table by name (hash)
   this->custTable[indexToInsertAt] = custPtr;
   // Add customer to table by ID
   this->custTableByID[custPtr->getID()] = custPtr;

} // Closing insertCustomer()

// (+) --------------------------------|
// #getCustomerAt(int)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Cust* CustDB::getCustomerAt(int query) {
   return (this->custTable[query]);
} // Closing getCustomerAt()

// (+) --------------------------------|
// #appendHistory(Trans)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
   void CustDB::appendHistory(Trans someTransaction) {
      // Gather requisite data for an appending action
      int         IDnum    = someTransaction.getCustID();
      Cust*       tgt      = this->custTableByID[IDnum];
      std::string appendix = someTransaction.toString();
      // Send to the target customer for history append
      tgt->appendHistory(appendix);
   }


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #CustDB()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
   CustDB::CustDB() {
      for (int i = 0 ; i < MAXCUSTOMERS ; i++) {
         this->custTable[i] = nullptr;
      }
      for (int i = 0 ; i <= 9999 ; i++) {
         this->CustTableByID[i] = nullptr;
      }
   }

// (+) --------------------------------|
// #~CustDB()
//-------------------------------------|
// Desc:    Deallocates memory and zeroes fields
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
   CustDB::~CustDB() {
      this->obliviate();
   }

// End of file - CustDB.cpp
