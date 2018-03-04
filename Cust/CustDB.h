//-------------------------------------|
// Begin Student Code
//-------------------------------------|

// Requisite in the .h file
#pragma once

// Necessary for string operations
#include <string>

// Necessary for customer operations
#include "Cust.h"

// Necessary for transaction operations
#include "../Trans/Trans.h"


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CLASS CONSTANTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class

class CustDB {

private:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------|
// #custTable
//-----------------|
// Desc:   The customer database
// Invars: 10000 valid customer IDs, so 2x and nearest prime size
   Cust custTable[20011];



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------|
// #isValid
//-----------------|
// Desc:   Determines whether this string is a valid customerDB command
// Invars: Return value is variable based on state of
   bool isValid(std::string);

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

//-----------------|
// #toString()
//-----------------|
// Desc:   NULL
// Invars: NULL
   std::string toString();

//-----------------|
// #display()
//-----------------|
// Desc:   NULL
// Invars: NULL
   void display();

//-----------------|
// #getCustomerAt(int)
//-----------------|
// Desc:   NULL
// Invars: NULL
   Cust* getCustomerAt(int);

//-----------------|
// #appendHistory(Trans)
//-----------------|
// Desc:   NULL
// Invars: NULL
   void appendHistory(Trans);



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------|
// #CustDB()
//-----------------|
// Desc:   NULL
// Invars: NULL
   CustDB();

//-----------------|
// #~CustDB()
//-----------------|
// Desc:   NULL
// Invars: NULL
   ~CustDB();

}; // Closing class CustDB {}

// End of file - CustDB.h
