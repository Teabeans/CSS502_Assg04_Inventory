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
   // #isLessThan(Film&)
   //-------------------------------------|
   // Desc:   Tests the film against another based on it's title & year
   // Invars: None
   virtual bool isLessThan(Film&);

   // (+) --------------------------------|
   // #isGreaterThan(Film&)
   //-------------------------------------|
   // Desc:   Tests the film against another based on it's title & year
   // Invars: None
   virtual bool isGreaterThan(Film&);

   //-----------------|
   // #getTitle()
   //-----------------|
   // Desc:   Returns the film's title
   // Invars: None
   std::string getTitle();

   //-----------------|
   // #setTitle(string)
   //-----------------|
   // Desc:   sets the film's title
   // Invars: None
   void setTitle(std::string);

   //-----------------|
   // #getStock()
   //-----------------|
   // Desc:   Returns the film's stock value
   // Invars: None
   int getStock();

   //-----------------|
   // #setStock(int)
   //-----------------|
   // Desc:   sets the film's stock value
   // Invars: None
   void setStock(int);

   //-----------------|
   // #getreleaseYear()
   //-----------------|
   // Desc:   Returns the film's release date
   // Note:   Can't be Virtual as the return type for Classic differs, causing an error
   // Invars: None
   int getReleaseYear();

   //-----------------|
   // #setreleaseYear(int)
   //-----------------|
   // Desc:   sets the film's release date
   // Invars: None
   void setReleaseYear(int);

   //-----------------|
   // #getreleaseYear()
   //-----------------|
   // Desc:   NULL
   // Note:   Overrides Film::getreleaseYear()
   // Invars: NULL
   int getReleaseMonth(); 

   //-----------------|
   // #setReleaseMonth()
   //-----------------|
   // Desc:   NULL
   // Invars: NULL
   void setReleaseMonth(int);

   //-----------------|
   // #getGenre()
   //-----------------|
   // Desc:   Returns the film's genre
   // Invars: None
   char getGenre();

   //-----------------|
   // #setGenre(char)
   //-----------------|
   // Desc:   sets the film's grenre (backup for the object type)
   // Invars: None
   void setGenre(char);

   //-----------------|
   // #getDirector()
   //-----------------|
   // Desc:   Returns the film's director
   // Invars: None
   std::string getDirector();

   //-----------------|
   // #setTitle(string)
   //-----------------|
   // Desc:   sets the film's title
   // Invars: None
   void setDirector(std::string);

   //-----------------|
   // #getActor()
   //-----------------|
   // Desc:   returns the film's major actor
   // Invars: None
   std::string getActor();

   //-----------------|
   // #setActor(string)
   //-----------------|
   // Desc:   sets the film's major actor
   // Invars: None
   void setActor(std::string);


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       OPERATORS
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
   //-----------------|
   // Desc:   Tests the film against another based on it's title & release date
   // PreCon: Title and release date must be populated
   // Invars: None
   bool operator<(Film&);

   //-----------------|
   // #operator>(Film&)
   //-----------------|
   // Desc:   Tests the film against another based on it's title & release date
   // PreCon: Title and release date must be populated
   // Invars: None
   bool operator>(Film&);

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   //-----------------|
   // #Film()
   //-----------------|
   // Desc:   NULL
   // Invars: NULL
   Film();

   //-----------------|
   // #Film(string)
   //-----------------|
   // Desc:   NULL
   // Invars: NULL
   Film(std::string);

   //-----------------|
   // #~Film()
   //-----------------|
   // Desc:   NULL
   // Invars: NULL
   ~Film();
}; // Closing class Film {}

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of File - Film.h