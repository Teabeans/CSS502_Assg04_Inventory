//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// Trans.cpp
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
// This is the implementation file for the Trans.h header, representing a
// transaction class of objects
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

// Necessary for string operations
#include <string>

// Necessary for input-output operations
#include <iostream>

// Field and method declarations for the Trans (Transaction) class
#include "Trans.h"

// Field and method declarations for the Borrow subclass
#include "Borrow.h"

// Field and method declarations for the Return subclass
#include "Return.h"



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
// #type
// #typeAsString
//-----------------|
// Desc:   The transaction type (borrow or return)
// Invars: Initializes to junk values
///   char type;
///   std::string typeAsString;

//-----------------|
// #genre
// #genreAsString
//-----------------|
// Desc:   Genre of the thing transacted
// Invars: Initializes to junk values
///   char genre;
///   std::string genreAsString;

//-----------------|
// #title
//-----------------|
// Desc:   Identifier of the thing transacted
// Invars: Initializes to junk values
///   std::string title;

//-----------------|
// #identifier1
// #identifier2
//-----------------|
// Desc:   Unique identifiers of the transaction
// Invars: Initializes to junk values
///   std::string identifier1; //first identifier (eg. title or major actor)
///   std::string identifier2; //second identifier (eg. year or release date)

//-----------------|
// #customerID
//-----------------|
// Desc:   The transaction type
// Invars: Initializes to junk values
///   int customerID; // To whom it was transacted

//-----------------|
// #qty
//-----------------|
// Desc:   The quantity of the transaction
// Invars: Initializes to junk values
///   int qty;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class



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
// Desc:    Outputs a string representation of the transaction
// Params:  NULL
// PreCons: NULL
// PosCons: Formatted to match the Customer History requirements
// RetVal:  NULL
// MetCall: NULL
std::string Trans::toString() {
   std::string retString = "";
   // TODO: Code composition of the release date string
   // "January 1937" for classics
   // "1937" for everything else
   std::string releaseString = "1993";
// Sample output:
// (ID: <customerID>) <type> - '<title>' (<genre>), <release>
// (ID: 1234) Borrow - 'Jurassic Park' (Drama), 1993 (-1)
   retString += "(ID: " + this->customerID + ") " + this->typeAsString + " - '"
              + this->title + "' (" + this->genreAsString + "), "
              + releaseString;
   return(retString);
}

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #getType()
// #getTypeAsString()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
char Trans::getType() {
   return(this->type);
}
std::string Trans::getTypeAsString() {
   return(this->typeAsString);
}

// (+) --------------------------------|
// #getGenre()
// #getGenreAsString()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
char Trans::getGenre() {
   return(this->genre);
}
std::string Trans::getGenreAsString() {
   return(this->genreAsString);
}

// (+) --------------------------------|
// #getTitle()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string Trans::getTitle() {
   return(this->title);
}

// (+) --------------------------------|
// #getIdentifier1()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string Trans::getIdentifier1() {
   return(this->identifier1);
}

// (+) --------------------------------|
// #getIdentifier2()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string Trans::getIdentifier2() {
   return(this->identifier2);
}

// (+) --------------------------------|
// #getCustID()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
int Trans::getCustID() {
   return(this->customerID);
}

// (+) --------------------------------|
// #getQty()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
int Trans::getQty() {
   return(this->qty);
}

// (+) --------------------------------|
// #setType(char)
// #setTypeAsString(string)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Trans::setType(char transType) {
   this->type = transType;
}
void Trans::setTypeAsString(std::string transType) {
   this->typeAsString = transType;
}

// (+) --------------------------------|
// #setGenre(char)
// #setGenreAsString(string)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Trans::setGenre(char theGenre) {
   this->genre = theGenre;
}
void Trans::setGenreAsString(std::string theGenre) {
   this->genreAsString = theGenre;
}

// (+) --------------------------------|
// #setTitle(string)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Trans::setTitle(std::string theTitle) {
   this->title = theTitle;
}


// (+) --------------------------------|
// #setIdentifier1(string)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Trans::setIdentifier1(std::string trait) {
   this->identifier1 = trait;
}

// (+) --------------------------------|
// #setIdentifier2(string)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Trans::setIdentifier2(std::string trait) {
   this->identifier2 = trait;
}

// (+) --------------------------------|
// #setCustID(int)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Trans::setCustID(int IDnum) {
   this->customerID = IDnum;
}

// (+) --------------------------------|
// #setQty(int)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Trans::setQty(int quantity) {
   this->qty = quantity;
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// TODO: Resolve @MG - Factory method logic is the same as Trans(string) constructor? Should the Trans(string) call this method, or would you rather have it packed right into the constructor?
// (+) --------------------------------|
// #factory(string)
//-------------------------------------|
// Desc:    Generates a transaction using a factory procedure
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Trans* Trans::factory(std::string command) {

   // create borrow object and run transaction
   if (command[0] == 'B') {
      std::cerr << " Borrow" << std::endl;
      return new Borrow(command);
   }

   // create return object and run transaction
   else if (command[0] == 'R') {
      std::cerr << " Return" << std::endl;
      return new Return(command);
   }

   // else if (command[0] == 'H') {
      // std::cerr << " Show History" << std::endl;
      // return new History;
   // }

   // otherwise, this is an invalid command

/* - TODO: Resolve @MG: Error checking should be performed by isLegal() function before this point is reached. If factory() is called, the command should be guaranteed to be a valid one.
   else {
      std::cerr << "Invalid command: " << command.at(0) << std::endl;
      return new Trans(command);
   }
*/
}

// (+) --------------------------------|
// #Trans()
//-------------------------------------|
// Desc:    Defaults Transaction constructor
// Params:  NULL
// PreCons: Should not be called under normal circumstances
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Trans::Trans() {

}

// (+) --------------------------------|
// #Trans(string)
//-------------------------------------|
// Desc:    Constructor of Transaction object by string
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Trans::Trans(std::string command) {

}

// (+) --------------------------------|
// #~Trans()
//-------------------------------------|
// Desc:    Trans deconstructor
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Trans::~Trans() {

}

// End of file - Trans.cpp
