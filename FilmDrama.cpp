//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// FilmDrama.cpp
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
// This is the implementation file for the Drama.h header.
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

// Necessary for string stream operations
#include <sstream>

// Necessary for input-output operations
#include <iostream>

// Field and method declarations for the Drama class
#include "FilmDrama.h"



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #equals(Film&)
//-------------------------------------|
// Desc:    Compares 'this' Film against another by it's director and title
// Params:  Film& arg1 - The Film to compare against
// PreCon:  Director and title must be initialized
// PosCons: None
// RetVal:  bool True - 'This' comedy is equal to arg1
//          bool False - 'This' comedy is not equal to arg1
// MetCall: Film::getDirector()
//          Film::getTitle()
bool Drama::equals(Film& rhs) {
   return (this->getDirector() == rhs.getDirector() &&
           this->getTitle()    == rhs.getTitle());
} // Closing equals()

// (+) --------------------------------|
// #isLessThan(Film&)
//-------------------------------------|
// Desc:    Compares 'this' Film against another by it's title and year
// Params:  Film& arg1 - The Film to compare against
// PreCon:  Release year and title must be initialized
// PosCons: None
// RetVal:  bool True - 'This' comedy is less than arg1
//          bool False - 'This' comedy is not less than arg1
// MetCall: Film::getDirector()
//          Film::getTitle()
bool Drama::isLessThan(Film& rhs) {
   // If this director is less than RHS director...
   if (this->getDirector() < rhs.getDirector()) {
      return true;
   }
   // If the directors are the same...
   else if (this->getDirector() == rhs.getDirector()) {
      // Then compare titles
      // If this title is less than RHS title
      if (this->getTitle() < rhs.getTitle()) {
         return true;
      }
      // Otherwise, LHS is greater than or equal to RHS
      // So return false
      return false;
   }
   // Otherwise, this director must be greater than RHS director
   else {
      return false;
   }
} // Closing isLessThan()

// (+) --------------------------------|
// #isGreaterThan(Film&)
//-------------------------------------|
// Desc:    Compares 'this' Film against another by it's title and year
// Params:  Film& arg1 - The Film to compare against
// PreCon:  Release year and title must be initialized
// PosCons: None
// RetVal:  bool True - 'This' comedy is less than arg1
//          bool False - 'This' comedy is not less than arg1
// MetCall: Drama::isLessThan()
//          Drama::equals()
bool Drama::isGreaterThan(Film& rhs) {
   return (!isLessThan(rhs) && !equals(rhs));
} // Closing isGreaterThan()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS/DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #Drama()
//-------------------------------------|
// Desc:    Default constructor for the Drama class
// Params:  None
// PreCons: Fields are zeroed by Film superclass constructor
// PosCons: None
// RetVal:  None
// MetCall: None
Drama::Drama() {
   // Initialize fields
   // None for this class
} // Closing Drama()

// (+) --------------------------------|
// #Drama(string)
//-------------------------------------|
// Desc:    Drama constructor by string
// Params:  string arg1 - The command to build a Drama film from
// PreCons: GIGO - No error checking is performed by this method
//          Command must be correctly formatted
// PosCons: The inventory command has been parsed and integrated to 'this' Film
// RetVal:  None
// MetCall: std::noskipws
//          Film::setDirector()
//          Film::setTitle()
//          Film::setReleaseYear()
Drama::Drama(std::string data) {
   // Sample input
   // "D, 10, Clint Eastwood, Unforgiven, 1992"
   // split the regular film data items by commans and insert those to 
   // the appropriate data members

   std::stringstream stream(data);
   stream>>std::noskipws;

   char temp;

   // Capture the first letter
   stream >> this->genre;
   // D, 10, Clint Eastwood, Unforgiven, 1992
   // ^

   // Remove the ", "
   stream >> temp;
   stream >> temp;
   // D, 10, Clint Eastwood, Unforgiven, 1992
   //   ^

   // Capture the stock amount
   stream >> this->stock;
   // D, 10, Clint Eastwood, Unforgiven, 1992
   //   ^  -

   // Remove the ", "
   stream >> temp;
   stream >> temp;
   // D, 10, Clint Eastwood, Unforgiven, 1992
   //       ^

   // Capture the first letter of the director
   stream >> temp;
   // D, 10, Clint Eastwood, Unforgiven, 1992
   //        ^

   // Capture the director
   std::string theDirector;
   while (temp != ',') {
     theDirector += temp;
     stream >> temp;
   }
   // Assign the director
   this->setDirector(theDirector);
   // D, 10, Clint Eastwood, Unforgiven, 1992
   //                      ^

   // Remove the ", "
   stream >> temp;
   stream >> temp;

   // D, 10, Clint Eastwood, Unforgiven, 1992
   //                        ^

   std::string theTitle;
   while (temp != ',') {
      theTitle += temp;
      stream >> temp;
   }
   // Assign the title
   this->setTitle(theTitle);
   // D, 10, Clint Eastwood, Unforgiven, 1992
   //                                  ^


   // Remove the ", "
   stream >> temp;
   // D, 10, Clint Eastwood, Unforgiven, 1992
   //                                   ^

   int theYear;
   stream >> theYear;

   //Capture the releaseYear
   this->setReleaseYear(theYear);
} // Closing Drama(string)

// (+) --------------------------------|
// #~Drama()
//-------------------------------------|
// Desc:    Destructor for the Drama class
// Params:  None
// PreCons: None
// PosCons: Fields have been zeroed
// RetVal:  None
// MetCall: None
Drama::~Drama() {
   // None specific to this subclass
} // Closing ~Drama()

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of File - FilmDrama.cpp
