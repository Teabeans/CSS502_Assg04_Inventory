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
// Modified: 2018.03.14
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
// Params:  string arg1 - The command to reference for building a Film
// PreCons: GIGO - No error checking is performed by this method
//          Received argument must be formatted properly
// PosCons: A new Film Subclass has been created
// RetVal:  Film* - A pointer to a new Film Subclass
// MetCall: Classic::Classic(string)
//          Drama::Drama(string)
//          Comedy::Comedy(string)
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
   // This should never be hit
   return(nullptr);
} // Closing makeFilm()



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
// Desc:    Returns the Actor of 'this' Film
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  string - The Actor of 'this' Film
// MetCall: None
std::string Film::getActor() {
   return this->actor;
} // Closing getActor()

// (+) --------------------------------|
// #getDirector()
//-------------------------------------|
// Desc:    Returns the Director of 'this' Film
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  string - The Director of 'this' Film
// MetCall: None
std::string Film::getDirector() {
   return this->director;
} // Closing getDirector()

// (+) --------------------------------|
// #getGenre()
//-------------------------------------|
// Desc:    Returns the Genre of 'this' Film
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  char - The Genre of 'this' Film
// MetCall: None
char Film::getGenre() {
   return this->genre;
} // Closing getGenre()

// (+) --------------------------------|
// #getreleaseMonth()
//-------------------------------------|
// Desc:    Returns the ReleaseMonth of 'this' Film
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  int - The ReleaseMonth of 'this' Film
// MetCall: None
int Film::getReleaseMonth() {
   return this->releaseMonth;
} // Closing getreleaseMonth()

// (+) --------------------------------|
// #getreleaseYear()
//-------------------------------------|
// Desc:    Returns the ReleaseYear of 'this' Film
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  int - The ReleaseYear of 'this' Film
// MetCall: None
int Film::getReleaseYear() {
   return this->releaseYear;
} // Closing getreleaseYear()

// (+) --------------------------------|
// #getStock()
//-------------------------------------|
// Desc:    Returns the stock of 'this' Film
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  int - The stock of 'this' Film
// MetCall: None
int Film::getStock() {
   return this->stock;
} // Closing getStock()

// (+) --------------------------------|
// #getTitle()
//-------------------------------------|
// Desc:    Returns the title of 'this' Film
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  string - The title of 'this' Film
// MetCall: None
std::string Film::getTitle() {
   return this->title;
} // Closing getTitle()



// (+) --------------------------------|
// #setActor()
//-------------------------------------|
// Desc:    Sets the actor of 'this' Film
// Params:  string arg1 - A starring actor of this Film
// PreCons: GIGO - No error checking is performed for valid entries
// PosCons: The actor has been set
// RetVal:  None
// MetCall: None
void Film::setActor(std::string anActor) {
   this->actor = anActor;
} // Closing setActor()

// (+) --------------------------------|
// #setDirector()
//-------------------------------------|
// Desc:    Sets the director of 'this' Film
// Params:  string arg1 - The director of this Film
// PreCons: GIGO - No error checking is performed for valid entries
// PosCons: The director has been set
// RetVal:  None
// MetCall: None
void Film::setDirector(std::string theDirector) {
   this->director = theDirector;
} // Closing setDirector()

// (+) --------------------------------|
// #setGenre()
//-------------------------------------|
// Desc:    Sets the genre of 'this' Film
// Params:  char arg1 - The month this Film was released
// PreCons: GIGO - No error checking is performed for valid months (1-12)
// PosCons: The release month has been set
// RetVal:  None
// MetCall: None
void Film::setGenre(char gen) {
   this->genre = gen;
} // Closing setGenre()

// (+) --------------------------------|
// #setreleaseMonth()
//-------------------------------------|
// Desc:    Sets the release month of 'this' Film
// Params:  int arg1 - The month this Film was released
// PreCons: GIGO - No error checking is performed for valid months (1-12)
// PosCons: The release month has been set
// RetVal:  None
// MetCall: None
void Film::setReleaseMonth(int month) {
   this->releaseMonth = month;
} // Closing setreleaseMonth()

// (+) --------------------------------|
// #setreleaseYear()
//-------------------------------------|
// Desc:    Sets the release year of 'this' Film
// Params:  int arg1 - The year this Film was released
// PreCons: GIGO - No error checking is performed for valid years (1888-2018)
// PosCons: The release year has been set
// RetVal:  None
// MetCall: None
void Film::setReleaseYear(int year) {
   this->releaseYear = year;
} // Closing setreleaseYear()

// (+) --------------------------------|
// #setStock()
//-------------------------------------|
// Desc:    Sets the Film stock of 'this' Film
// Params:  int arg1 - The number of this Film object remaining in stock
// PreCons: GIGO - No error checking is performed against out-of-bound values
// PosCons: The quantity has been set
// RetVal:  None
// MetCall: None
void Film::setStock(int qty) {
   this->stock = qty;
} // Closing setStock()

// (+) --------------------------------|
// #setTitle()
//-------------------------------------|
// Desc:    Sets the title of this film to the received string
// Params:  string arg1 - The film title to set
// PreCons: None
// PosCons: This film's title has been set to arg1
// RetVal:  None
// MetCall: None
void Film::setTitle(std::string data) {
   this->title = data;
} // Closing setTitle()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       OPERATOR OVERLOADS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #operator==(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's title & year
// Params:  Film& arg1 - The reference film to compare against 'this' film
// PreCons: Title and release date must be populated
// PosCons: None
// RetVal:  bool True -  'this' is equal to 'arg1'
//          bool False - 'this' is not equal to 'arg1'
// MetCall: Film::equals()
bool Film::operator==(Film& rhs) {
   return (this->equals(rhs));
} // Closing operator==()

// (+) --------------------------------|
// #operator<(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's title & year
// Params:  Film& arg1 - The reference film to compare against 'this' film
// PreCons: Title and release date must be populated
// PosCons: None
// RetVal:  bool True -  'this' is less than (or equal to) 'arg1'
//          bool False - 'this' is greater than 'arg1'
// MetCall: Film::isLessThan()
//          Film::equals()
bool Film::operator<(Film& rhs) {
   return (this->isLessThan(rhs));
} // Closing operator<()
bool Film::operator<=(Film& rhs) {
   return (this->isLessThan(rhs) || this->equals(rhs));
} // Closing operator<=()

// (+) --------------------------------|
// #operator>(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's title & year
// Params:  Film& arg1 - The reference film to compare against 'this' film
// PreCons: Title and release date must be populated
// PosCons: None
// RetVal:  bool True -  'this' is greater than 'arg1'
//          bool False - 'this' is less than (or equal to) 'arg1'
// MetCall: Film::isGreaterThan()
//          Film::equals()
bool Film::operator>(Film& rhs) {
   return (this->isGreaterThan(rhs));
} // Closing operator>()
bool Film::operator>=(Film& rhs) {
   return ((this->isGreaterThan(rhs) || this->equals(rhs)));
} // Closing operator>=()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS/DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #Film()
//-------------------------------------|
// Desc:    Default Film constructor
// Params:  None
// PreCons: None
// PosCons: A default Film object has been created
// RetVal:  None
// MetCall: None
Film::Film() {
   // Initialize all fields
   this->actor = "";
   this->director = "";
   this->genre = ' ';
   this->releaseMonth = 0;
   this->releaseYear = 0;
   this->stock = 0;
   this->title = "";
} // Closing Film()

// (+) --------------------------------|
// #Film(string)
//-------------------------------------|
// Desc:    Take in a string and generate the appropriate data-members
// Params:  string arg1 - A properly formatted and legal inventory command
// PreCons: GIGO - No error checking is performed by this method
// PosCons: A Film object has been created and its fields populated
// RetVal:  None
// MetCall: std::string.substr()
//          std::string.find()
//          std::string.erase()
//          std::string.length()
//          std::stoi()
Film::Film(std::string data) {
   // Prepare to store 5 fields
   std::string items[5];

   // Sample input:
   // D, 10, Steven Spielberg, Schindler's List, 1993

   // Set the ", " as a delimiter
   std::string delim = ", ";

   // For 5 iterations...
   for (int i = 0; i < 5; i++) {
      // Store a delimited substring to the array
      items[i] = data.substr(0, data.find(delim));
      // And consume the original data
      data.erase(0, data.find(delim) + delim.length());
   } // Closing for - All fields have been captured

   // Set data members based on data segments
   this->genre       = items[0][0];         // char @ index[0] of a string
   this->stock       = std::stoi(items[1]); // int converted from string
   this->director    = items[2];            // string
   this->title       = items[3];            // string
   this->releaseYear = std::stoi(items[4]); // int converted from string

} // Closing Film(string)

// (+) --------------------------------|
// #~Film()
//-------------------------------------|
// Desc:    Deconstructor for the Film class
// Params:  None
// PreCons: None
// PosCons: Fields have been zeroed
// RetVal:  None
// MetCall: None
Film::~Film() {
   // Null all fields
   this->actor = "";
   this->director = "";
   this->genre = 'X';
   this->releaseMonth = 0;
   this->releaseYear = 0;
   this->stock = 0;
   this->title = "";
} // Closing ~Film()

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of file - Film.cpp
