//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// Drama.cpp
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

#include <string>
#include <sstream>
#include <iostream>
#include "FilmDrama.h"



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #equals(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's release date, then 
//          major actor
// Params:  None
// PreCon:  Release date and release month, and actor must be populated
// PosCons: NULL
// RetVal:  True or False
// MetCall: NULL
bool Drama::equals(Film& rhs) {
   if (this->getDirector() == rhs.getDirector() && this->getTitle() == rhs.getTitle()) {
      return true;
   }
   else {
      return false;
   }
}

// (+) --------------------------------|
// #isLessThan(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's release date, then 
//          major actor
// Params:  None
// PreCon:  Release date and release month, and actor must be populated
// PosCons: NULL
// RetVal:  True or False
// MetCall: NULL
bool Drama::isLessThan(Film& rhs) {
   // If the director is lesser...
   if (this->getDirector() < rhs.getDirector()) {
      return(true);
   }
   // If the director matches
   else if (this->getDirector() == rhs.getDirector()) {
      // Then compare titles
      if (this->getTitle() < rhs.getTitle()) {
         return(true);
      }
      // Greater than or equal to case
      return(false);
   }
   // Director must by greater than
   else {
      return(false);
   }
}

// (+) --------------------------------|
// #isGreaterThan(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's release date, then 
//          major actor
// Params:  None
// PreCon:  Release date and release month, and actor must be populated
// PosCons: NULL
// RetVal:  True or False
// MetCall: NULL
bool Drama::isGreaterThan(Film& rhs) {
   std::cout << "(Drama::isGreaterThan() called)" << std::endl;

   return(!isLessThan(rhs));
}


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS/DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #Drama()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Drama::Drama() {

}

// (+) --------------------------------|
// #Drama(string)
//-------------------------------------|
// Desc:    Overrides the Film(string) constructor, adding logic to parse director and title
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
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
}

// (+) --------------------------------|
// #~Drama()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Drama::~Drama() {

}

// End of File - FilmDrama.cpp
