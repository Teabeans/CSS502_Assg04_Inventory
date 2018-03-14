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
// Modified: 2018.03.14
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

// Field and method declarations for the Cust (Customer) class
#include "Cust.h"

// Field and method declarations for the CustDB (Customer Database) class
#include "CustDB.h"

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
// Params:  Cust* arg1 - The customer to check a collision on
//          int arg2 - The index to examine
// PreCons: None
// PosCons: None
// RetVal:  bool True - The customer and position creates a conflict
//          bool False - No conflict detected
// MetCall: None
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

// (-) --------------------------------|
// #hash(Cust*)
//-------------------------------------|
// Desc:    Determines a hash value for a given customer
// Params:  Cust* arg1 - The customer to determine a hash for
// PreCons: Customer name ("F L") must contain at least 3 chars.
// PosCons: None
// RetVal:  int - The first available table index
// MetCall: Cust::getName()
//          CustDB::doesConflict()
//          CustDB::probe()
int CustDB::hash(Cust* custPtr) {
   std::string custName = "";
   char letter1 = 'X';
   char letter2 = 'X';
   char letter3 = 'X';
   int intOf1 = 0;
   int intOf2 = 0;
   int intOf3 = 0;
   int hash = 0;

   custName = custPtr->getName();
   letter1 = custName[0]; // TODO: Verify that this is legal
   letter2 = custName[1];
   letter3 = custName[2];
   intOf1 = letter1 * 1000000; // 123 goes to 123 000 000
   intOf2 = letter2 * 1000;    // 456 goes to     456 000
   intOf3 = letter3;           // 789 goes to         789
   hash = ( intOf1 + intOf2 + intOf3) % MAXCUSTOMERS;
   // If a conflict is identified
   if (this->doesConflict(custPtr, hash)) {
      // Probe until an open index is found
      hash = this->probe(custPtr, hash);
   }
   // Non-conflicting index guaranteed
   return(hash);
} // Closing hash()

// (-) --------------------------------|
// #probe(Cust*)
//-------------------------------------|
// Desc:    Linear probe, helper method for the Hash() function
// Params:  Cust* arg1 - The customer being hashed
//          int arg2 - The hash position in question
// PreCons: Hash() has been called
// PosCons: None
// RetVal:  int - The first non-conflicting index found by this probe method
// MetCall: CustDB::doesConflict()
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
// Desc:    Deallocates all customers in the table
// Params:  None
// PreCons: None
// PosCons: All customers have been deallocated
// RetVal:  None
// MetCall: None
void CustDB::obliviate() {
   for (int i = 0 ; i < MAXCUSTOMERS ; i++) {
      if (this->custTable[i] != nullptr) {
         delete this->custTable[i];
      }
   }
   for (int i = 0 ; i <= 9999 ; i++) {
      this->custTableByID[i] = nullptr;
   }
} // Closing obliviate()



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
// Desc:    Generates a string representation of the database
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  string - A string representation of the database
// MetCall: Cust::toString()
std::string CustDB::toString() {
   std::string retString = "CustDB::toString() \n";
   retString += "Customer Database:\n";
   retString += "ID        First Name           Last Name\n";
   retString += "--------- -------------------- --------------------\n";
//               1234      01234567890123456789 01234567890123456789
   // Go down the custTable
   for (int i = 0 ; i < 10000 ; i++) {
      // And for every valid Customer...
      if (this->custTableByID[i] != nullptr) {
         // Append them to the string
         retString += this->custTableByID[i]->toString() + "\n";
      }
   }
   return (retString);
} // Closing toString()

// (+) --------------------------------|
// #display()
//-------------------------------------|
// Desc:    Displays the toString() representation of this database
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  None
// MetCall: CustDB::toString()
void CustDB::display() {
   std::cout << "CustDB::display()" << std::endl;
   std::cout << this->toString() << std::endl;
} // Closing display()

// (+) --------------------------------|
// #doesContain()
//-------------------------------------|
// Desc:    Confirms whether a customer exists (by Cust ID)
// Params:  int arg1 - The Customer ID to search
// PreCons: None
// PosCons: None
// RetVal:  bool True - The customer was found
//          bool False - No such customer exists
// MetCall: None
bool const CustDB::doesContain(int custID) {
   // If the customer table by ID contains anything other than nullptr...
   if (this->custTableByID[custID] != nullptr) {
      // A customer has been assigned that position, so
      return(true);
   }
   // Otherwise
   return(false);
} // Closing doesContain()

// (+) --------------------------------|
// #insertCustomer(Cust&)
//-------------------------------------|
// Desc:    Inserts a customer to the database
// Params:  Cust* arg1 - A pointer to the customer to insert
// PreCons: GIGO - No error checking is performed by this method
// PosCons: The customer has been inserted to the database
// RetVal:  None
// MetCall: CustDB::hash()
//          Cust::getID()
void CustDB::insertCustomer(Cust* custPtr) {
   // Hash the customer's name
   int indexToInsertAt = this->hash(custPtr);
   // Add customer to table by name (hash)
   this->custTable[indexToInsertAt] = custPtr;
   // Add customer to table by ID
   this->custTableByID[custPtr->getID()] = custPtr;

} // Closing insertCustomer()

// (+) --------------------------------|
// #isValid(Cust&)
//-------------------------------------|
// Desc:    Examine a command and confirm whether it is legal or not
// Params:  string arg1 - The command to examine
// PreCons: NULL
// PosCons: If illegal conditions are found, errors are reported
// RetVal:  bool True - No conflicts found
//          bool False - Conflicts found
// MetCall: Cust::getFirstName()
//          Cust::getLastName()
bool CustDB::isValid(std::string command) {
   std::string errorLog = "";
   bool isValid = true;

   // Sample input
   // 6666 Donkey Darrell

   // Load string to stream
   std::stringstream stream(command);

   // Capture the first number
   int custID;
   std::string lName;
   std::string fName;

   // Capture the customer ID
   stream >> custID;
   stream >> lName;
   stream >> fName;

//   std::cout << command << ":" << custID << ":" << fName << ":" << lName << std::endl; // DEBUG

   Cust* theCust = this->custTableByID[custID];

   // If there's something at the custID position already...
   if (theCust != nullptr) {
      // Append the error log
      errorLog = errorLog + "   - Customer ID already in use" + "\n";
      // And toggle the flag
      isValid = false;

      // If the customer fName and lName match...
      if ((theCust->getFirstName() == fName) && (theCust->getLastName() == lName)) {
         // Append the error log
         errorLog = errorLog + "   - Repeat customer entry" + "\n";
      }
   }
         // If any test has failed, report as much
   if (isValid == false) {
      std::cout << "Customer Database error ('" << command << "'):" << std::endl;
      std::cout << errorLog << std::endl;
      return(isValid);
   }

   return(isValid);
} // Closing isValid()

// (+) --------------------------------|
// #isValidTransCmd(int, string)
//-------------------------------------|
// Desc:    Determines whether this transaction is in conflict with the Database state
// Params:  int arg1 - The Customer ID of the transaction
//          string arg2 - The title of the film being transacted
//          string arg3 - The transaction type
// PreCons: None
// PosCons: None
// RetVal:  bool True - No conflicts with the transaction detected
//          bool False - Conflict with the transaction detected
// MetCall: Cust::isCheckedOut()
bool CustDB::isValidTransCmd(int custID, std::string title, char type) {
   // Sample input:
   // 1000 Good Morning Vietnam,
   bool isValid = true;

   // If it's an attempted return...
   if (type == 'R') {
      // Confirm that the customer by this ID has the title checkd out
      isValid = custTableByID[custID]->isCheckedOut(title);
   }

   // Other checks that the CustDB state is relevant to?

   return (isValid);
} // Closing isValidTransCmd()

// (+) --------------------------------|
// #getCustomerAt(int)
//-------------------------------------|
// Desc:    Returns a customer, searched by customer ID
// Params:  int arg1 - The CustomerID to search for
// PreCons: None
// PosCons: None
// RetVal:  Cust* - A pointer to the customer at this ID
// MetCall: None
Cust* CustDB::getCustomerAt(int query) {
   return (this->custTableByID[query]);
} // Closing getCustomerAt()

// (+) --------------------------------|
// #appendHistory(Trans)
//-------------------------------------|
// Desc:    Appends a transaction to the history of the involved customer
// Params:  Trans arg1 - The transaction to append
// PreCons: GIGO - No error checking is performed by this function
//          Transaction must be legal and properly formatted upon receipt
// PosCons: The transaction has been appended to the customer history
// RetVal:  None
// MetCall: Cust::appendHistory()
//          Cust::getCustID()
//          Trans::toString()
//          Trans::getType()
//          Trans::getTitle()
void CustDB::appendHistory(Trans someTransaction) {
   // Gather requisite data for an appending action
   int         IDnum    = someTransaction.getCustID();
   Cust*       tgt      = this->custTableByID[IDnum];
   std::string appendix = someTransaction.toString();
   // Send to the target customer for history append and checkout correction
   tgt->appendHistory(appendix, someTransaction.getType(), someTransaction.getTitle());
} // Closing appendHistory()


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
// Desc:    Default constructor for a Customer Database
// Params:  None
// PreCons: None
// PosCons: All table entries initialized to nullptr
// RetVal:  None
// MetCall: None
CustDB::CustDB() {
   for (int i = 0 ; i < MAXCUSTOMERS ; i++) {
      this->custTable[i] = nullptr;
   }
   for (int i = 0 ; i <= 9999 ; i++) {
      this->custTableByID[i] = nullptr;
   }
} // Closing CustDB()

// (+) --------------------------------|
// #~CustDB()
//-------------------------------------|
// Desc:    Deallocates memory and zeroes fields
// Params:  None
// PreCons: None
// PosCons: All memory has been deallocated
// RetVal:  None
// MetCall: CustDB::obliviate()
CustDB::~CustDB() {
   this->obliviate();
} // Closing ~CustDB()

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of file - CustDB.cpp
