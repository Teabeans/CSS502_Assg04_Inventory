//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// Comedy.cpp
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
// This is the implementation file for the Comedy.h header.
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

// Field and method declarations for the Comedy class
#include "FilmComedy.h"



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #equals(Film&)
//-------------------------------------|
// Desc:    Compares 'this' Film against another by it's title and year
// Params:  Film& arg1 - The Film to compare against
// PreCon:  Release year and title must be initialized
// PosCons: None
// RetVal:  bool True - 'This' comedy is equal to arg1
//          bool False - 'This' comedy is not equal to arg1
// MetCall: Film::getReleaseYear()
//          Film::getTitle()
bool Comedy::equals(Film& rhs) {
   return (this->getTitle()       == rhs.getTitle() &&
           this->getReleaseYear() == rhs.getReleaseYear());
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
// MetCall: Film::getReleaseYear()
//          Film::getTitle()
bool Comedy::isLessThan(Film& rhs) {
   // If this title is less than RHS title...
   if (this->getTitle() < rhs.getTitle()) {
      return(true);
   }
   // If the titles are equal...
   else if (this->getTitle() == rhs.getTitle()) {
      // Then compare release
      // If this release year is less than RHS release year,
      if (this->getReleaseYear() < rhs.getReleaseYear()) {
         // Return true
         return(true);
      }
      // Otherwise, LHS is greater than or equal to RHS
      // So return false
      return(false);
   }
   // Otherwise, this title must be greater than RHS title
   else {
      // So return false
      return(false);
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
// MetCall: Comedy::isLessThan()
//          Comedy::equals()
bool Comedy::isGreaterThan(Film& rhs) {
   return (!this->isLessThan(rhs) && !this->equals(rhs));
} // Closing isGreaterThan()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS/DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #Comedy()
//-------------------------------------|
// Desc:    Default constructor for the Comedy class
// Params:  None
// PreCons: Fields are zeroed by Film superclass constructor
// PosCons: None
// RetVal:  None
// MetCall: None
Comedy::Comedy() {
   // Initialize fields
   // None for this class
} // Closing Comedy()

// (+) --------------------------------|
// #Comedy(string)
//-------------------------------------|
// Desc:    Comedy constructor by string
// Params:  string arg1 - The command to build a Comedy film from
// PreCons: GIGO - No error checking is performed by this method
//          Command must be correctly formatted
// PosCons: The inventory command has been parsed and integrated to 'this' Film
// RetVal:  None
// MetCall: std::noskipws
//          std::string.find()
//          std::string.erase()
//          std::string.find()
//          std::string.length()
//          std::stoi()
Comedy::Comedy(std::string data) {
   // Sample input:
   // "F, 10, Nora Ephron, You've Got Mail, 1998"
   // Split input by commas and load to internal variables

   // Generate a stream using the data argument
   std::stringstream stream(data);
   // Set stream to acknowledge whitespaces
   stream >> std::noskipws;

   // Temporary holder for iterating over stream character by character
   char temp;

   // Capture the first letter
   stream >> this->genre;
   // String status:
   // F, 10, Nora Ephron, You've Got Mail, 1998
   // ^

   // Remove the ", "
   stream >> temp;
   stream >> temp;
   // String status:
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //   ^

   // Capture the stock amount
   stream >> this->stock;
   // String status:
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //   ^  -

   // Remove the ", "
   stream >> temp;
   stream >> temp;
   // String status:
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //       ^

   // Capture the first letter of the director
   stream >> temp;
   // String status:
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //        ^

   // Capture the director
   std::string theDirector;
   while (temp != ',') {
     theDirector += temp;
     stream >> temp;
   }
   // Assign the director
   this->setDirector(theDirector);
   // String status:
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //                   ^

   // Remove the ", "
   stream >> temp;
   stream >> temp;

   // String status:
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //                     ^

   std::string theTitle;
   while (temp != ',') {
      theTitle += temp;
      stream >> temp;
   }
   // Assign the title
   this->setTitle(theTitle);
   // String status:
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //                                    ^


   // Remove the ", "
   stream >> temp;
   // String status:
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //                                     ^

   int theYear;
   stream >> theYear;

   //Capture the releaseYear
   this->setReleaseYear(theYear);
}

// (+) --------------------------------|
// #~Comedy()
//-------------------------------------|
// Desc:    Destructor for the Comedy class
// Params:  None
// PreCons: None
// PosCons: Fields have been zeroed
// RetVal:  None
// MetCall: None
Comedy::~Comedy() {
   // None specific to this subclass
} // Closing ~Comedy()

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of File - FilmDrama.cpp
