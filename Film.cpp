//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// Film.cpp
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
// This is the implementation file for the Film.h header.
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

// Field and method declarations for the Film class
#include "Film.h"

// Necessary for factory method
#include "FilmClassic.h"
#include "FilmDrama.h"
#include "FilmComedy.h"

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
//       PROTECTED FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|
//
// Do not redeclare these variables in the .cpp.
// Included here only for reference
// See associated .h file for variable declarations


//-----------------|
// #title
//-----------------|
// Desc:   The film's title
// Invars: Must contain at least one character
///   std::string title;

//-----------------|
// #stock
//-----------------|
// Desc:   The film's stock value
// Invars: None
///   int stock;

//-----------------|
// #releaseYear
//-----------------|
// Desc:   The film's release date (year)
// Invars: None
///   int releaseYear;

//-----------------|
// #director
//-----------------|
// Desc:   The name of the film's director
// Invars: Must contain at least one character
///   std::string director;

//-----------------|
// #genre
//-----------------|
// Desc:   A single-character code indicating the film's genre
// Invars: Must contain at least one character
///   char genre;

//-----------------|
// #actor
//-----------------|
// Desc:   The name of the film's major actor
// Invars: Must contain at least one character
///   std::string actor;



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
// #equals(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's title & year
// Params:  NULL
// PreCons: Title and release date must be populated
// PosCons: NULL
// RetVal:  True or False
// MetCall: NULL
bool Film::equals(Film& rhs) {

   return (title == rhs.title && releaseYear == rhs.releaseYear);
}

// (+) --------------------------------|
// #isLessThan(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's title & year
// Params:  NULL
// PreCons: Title and release date must be populated
// PosCons: NULL
// RetVal:  True or False
// MetCall: NULL
bool Film::isLessThan(Film& rhs) {

   if (title < rhs.title) {
      return true;
   }
   else if (title == rhs.title && releaseYear < rhs.releaseYear) {
      return true;
   }
   else {
      return false;
   }
}

// (+) --------------------------------|
// #isGreaterThan(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's title & year
// Params:  NULL
// PreCons: Title and release date must be populated
// PosCons: NULL
// RetVal:  True or False
// MetCall: NULL
bool Film::isGreaterThan(Film& rhs) {

   return (!isLessThan(rhs) && !equals(rhs));
}

// (+) --------------------------------|
// #makeFilm(string)
//-------------------------------------|
// Desc:    Factory method: Returns a film subclass depending on input
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  Film - A Film Subclass
// MetCall: NULL
Film* Film::makeFilm(std::string command) {
   Film* retFilm;
   // Sample input: 'F, 10, Nora Ephron, You've Got Mail, 1998'
   if (command[0] == 'C') {
      retFilm = new Classic(command);
      return(retFilm);
   }
   if (command[0] == 'D') {
      retFilm = new Drama(command);
      return(retFilm);
   }
   if (command[0] == 'F') {
      retFilm = new Comedy(command);
      return(retFilm);
   }
   return(nullptr);
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|
// TODO: Add virtual to all methods we expect to be overriden by child classes
// TODO: Check if virtual should be added to all methods irregardless

// (+) --------------------------------|
// #getActor()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string Film::getActor() {
   return actor;
} // Closing getActor()

// (+) --------------------------------|
// #getDirector()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string Film::getDirector() {
   return director;
} // Closing getDirector()

// (+) --------------------------------|
// #getGenre()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
char Film::getGenre() {
   return genre;
} // Closing getGenre()

// (+) --------------------------------|
// #getreleaseMonth()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
int Film::getReleaseMonth() {
   return releaseMonth;
} // Closing getreleaseMonth()

// (+) --------------------------------|
// #getreleaseYear()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
int Film::getReleaseYear() {
   return releaseYear;
} // Closing getreleaseYear()

// (+) --------------------------------|
// #getStock()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
int Film::getStock() {
   return stock;
} // Closing getStock()

// (+) --------------------------------|
// #getTitle()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string Film::getTitle() {
   return title;
} // Closing getTitle()



// (+) --------------------------------|
// #setActor()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Film::setActor(std::string data) {
   actor = data;
} // Closing setActor()

// (+) --------------------------------|
// #setDirector()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Film::setDirector(std::string data) {
   director = data;
} // Closing setDirector()

// (+) --------------------------------|
// #setGenre()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Film::setGenre(char data) {
   genre = data;
} // Closing setGenre()

// (+) --------------------------------|
// #setreleaseMonth()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Film::setReleaseMonth(int data) {
   releaseMonth = data;
} // Closing setreleaseMonth()

// (+) --------------------------------|
// #setreleaseYear()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Film::setReleaseYear(int data) {
   releaseYear = data;
} // Closing setreleaseYear()

// (+) --------------------------------|
// #setStock()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Film::setStock(int data) {
   stock = data;
} // Closing setStock()

// (+) --------------------------------|
// #setTitle()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Film::setTitle(std::string data) {
   title = data;
} // Closing setTitle()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       OPERATORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #operator==(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's title & year
// Params:  NULL
// PreCons: Title and release date must be populated
// PosCons: NULL
// RetVal:  True or False
// MetCall: NULL
bool Film::operator==(Film& rhs) {
   std::cout << "(Film::operator==() called)" << std::endl;
   return equals(rhs);
}

// (+) --------------------------------|
// #operator<(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's title & year
// Params:  NULL
// PreCons: Title and release date must be populated
// PosCons: NULL
// RetVal:  True or False
// MetCall: NULL
bool Film::operator<(Film& rhs) {
   return isLessThan(rhs);
}
bool Film::operator<=(Film& rhs) {
   return (isLessThan(rhs) || equals(rhs));
}

// (+) --------------------------------|
// #operator>(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's title & year
// Params:  NULL
// PreCons: Title and release date must be populated
// PosCons: NULL
// RetVal:  True or False
// MetCall: NULL
bool Film::operator>(Film& rhs) {
   return isGreaterThan(rhs);
}
bool Film::operator>=(Film& rhs) {
   return (isGreaterThan(rhs) || equals(rhs));
}




//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS/DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #Film()
//-------------------------------------|
// Desc:    Populate data-members with placeholder data
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Film::Film() {
   title = "";
   stock = 0;
   releaseYear = 0;
   director = "";
   genre = ' ';
   actor = "";
}

// (+) --------------------------------|
// #Film(string)
//-------------------------------------|
// Desc:    Take in a string and generate the appropriate data-members
// Params:  Comma-delimited string
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Film::Film(std::string data) {

   // split the data string by commas and parse into object data
   std::string delim = ", ";
   std::string items[5];

   for (int i = 0; i < 5; i++) {
      items[i] = data.substr(0, data.find(delim));
      data.erase(0, data.find(delim) + delim.length());
   }

   // set data members based on data segments
   genre = items[0][0]; // char
   stock = std::stoi(items[1]); // int
   director = items[2];
   title = items[3];
   releaseYear = std::stoi(items[4]); // int

}

// (+) --------------------------------|
// #~Film()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Film::~Film() {

}
