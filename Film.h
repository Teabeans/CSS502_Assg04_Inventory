//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// Film.h
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
// This is the header file for the parent Film class, representing a single film
// with some basic member data
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

// Requisite in the .h file
#pragma once

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INCLUDE STATEMENTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// necessary for string operations
#include <string>

class Film {

protected:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PROTECTED FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   //-----------------|
   // #title
   //-----------------|
   // Desc:   The film's title
   // Invars: Must contain at least one character
   std::string title;

   //-----------------|
   // #stock
   //-----------------|
   // Desc:   The film's stock value
   // Invars: None
   int stock;

   //-----------------|
   // #releaseYear
   //-----------------|
   // Desc:   The film's release year
   // Invars: None
   int releaseYear;

   //-----------------|
   // #releaseMonth
   //-----------------|
   // Desc:   The release month for the film
   // Invars: None
   int releaseMonth;

   //-----------------|
   // #director
   //-----------------|
   // Desc:   The name of the film's director
   // Invars: Must contain at least one character
   std::string director;

   //-----------------|
   // #genre
   //-----------------|
   // Desc:   A single-character code indicating the film's genre
   // Invars: Must contain at least one character
   char genre;

   //-----------------|
   // #actor
   //-----------------|
   // Desc:   The name of the film's major actor
   // Invars: Must contain at least one character
   std::string actor;



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

// Full comments in Film.cpp - omitted here for clarity

   // (+) --------------------------------|
   // #equals(Film&)
   //-------------------------------------|
   // Desc:   Tests the film against another based on it's title & year
   // Invars: None
   virtual bool equals(Film&);
   
   // (+) --------------------------------|
   // #isGreaterThan(Film&)
   //-------------------------------------|
   // Desc:   Tests the film against another based on it's title & year
   // Invars: None
   virtual bool isGreaterThan(Film&);

   // (+) --------------------------------|
   // #isLessThan(Film&)
   //-------------------------------------|
   // Desc:   Tests the film against another based on it's title & year
   // Invars: None
   virtual bool isLessThan(Film&);

   // (+) --------------------------------|
   // #makeFilm(string)
   //-------------------------------------|
   // Desc:   Factory method; Returns a film of differing types based on input
   // Invars: The command is legal
   Film* makeFilm(std::string command);



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   //-----------------|
   // #getActor()
   // #getDirector()
   // #getGenre()
   // #getreleaseMonth()
   // #getreleaseYear()
   // #getStock()
   // #getTitle()
   //-----------------|
   // Desc:   Field accessors
   // Invars: None
   std::string getActor();
   std::string getDirector();
   char getGenre();
   int getReleaseMonth(); 
   int getReleaseYear();
   int getStock();
   std::string getTitle();


   //-----------------|
   // #setActor(string)
   // #setDirector(string)
   // #setGenre(char)
   // #setReleaseMonth(int)
   // #setreleaseYear(int)
   // #setStock(int)
   // #setTitle(string)
   //-----------------|
   // Desc:   Field setters
   // Invars: None
   void setActor(std::string);
   void setDirector(std::string);
   void setGenre(char);
   void setReleaseMonth(int);
   void setReleaseYear(int);
   void setStock(int);
   void setTitle(std::string);



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       OPERATOR OVERLOADS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   //-----------------|
   // #operator==(Film&)
   //-----------------|
   // Desc:   Tests the film against another based on it's title & release date
   // PreCon: Title and release date must be populated
   // Invars: None
   bool operator==(Film&);

   //-----------------|
   // #operator<(Film&)
   // #operator<=(Film&)
   //-----------------|
   // Desc:   Tests the film against another based on it's title & release date
   // PreCon: Title and release date must be populated
   // Invars: None
   bool operator<(Film&);
   bool operator<=(Film&);

   //-----------------|
   // #operator>(Film&)
   // #operator>=(Film&)
   //-----------------|
   // Desc:   Tests the film against another based on it's title & release date
   // PreCon: Title and release date must be populated
   // Invars: None
   bool operator>(Film&);
   bool operator>=(Film&);

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   //-----------------|
   // #Film()
   //-----------------|
   // Desc:   Default film constructor
   // Invars: NULL
   Film();

   //-----------------|
   // #Film(string)
   //-----------------|
   // Desc:   Constructor that builds a Drama Film subclass by string
   //         FOR TESTING PURPOSES ONLY
   // Invars: None
   Film(std::string);

   //-----------------|
   // #~Film()
   //-----------------|
   // Desc:   Deconstructor for the Film class
   // Invars: Fields have been zeroed
   ~Film();

}; // Closing class Film {}

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of File - Film.h
