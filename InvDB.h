//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// InvDB.h
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
// This is the header file for the InvDB class, representing a database of
// film objects
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

#pragma once

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INCLUDE STATEMENTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

#include <iostream>
#include <string>
#include <vector>
#include "Trans.h"
#include "Film.h" // TODO: Omittable? Does the InvDB know about films due to child classes?
#include "FilmClassic.h"
#include "FilmComedy.h"
#include "FilmDrama.h"

class InvDB {

private:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------|
// #comedies
//-----------------|
// Desc:   List of all comedies
// Invars: NULL
std::vector<Comedy> comedies;

//-----------------|
// #dramas
//-----------------|
// Desc:   List of all dramas
// Invars: NULL
std::vector<Drama> dramas;

//-----------------|
// #classics
//-----------------|
// Desc:   List of all classics
// Invars: NULL
std::vector<Classic> classics;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|


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

   // (+) --------------------------------|
   // #addFilm(Film*)
   //-------------------------------------|
   // Desc:    Adds a new generic film object to the list
   // Invars:  NULL
   bool addFilm(std::string);

   // (+) --------------------------------|
   // #adjustStock(Trans&)
   //-------------------------------------|
   // Desc:    Updates the stock value of a film based on the arg transaction
   // Invars:  NULL
   bool adjustStock(const Trans&);

   // (+) --------------------------------|
   // #display()
   //-------------------------------------|
   // Desc:    Displays to cout the status of the InvDB by calling toString
   // Invars:  NULL
   void const display();

   // (+) --------------------------------|
   // #isLegal()
   //-------------------------------------|
   // Desc:    Tests the legality of a received command string
   //          Outputs an error to cout for illegal conditions
   // Invars:  NULL
   bool isLegal(std::string);

   bool isValidTransCmd(std::string);
   
   // (+) --------------------------------|
   // #runCmd(Film*)
   //-------------------------------------|
   // Desc:    Accepts a line of command and executes it
   // Invars:  GIGO - No error checking is performed by acceptCmd
   //          Format and content are verified to be correct before being sent
   // void runCmd(std::string);

   // (+) --------------------------------|
   // #toString()
   //-------------------------------------|
   // Desc:    Outputs a string representation of the InvDB
   // Invars:  NULL
   std::string const toString();



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   // (+) --------------------------------|
   // #getCTitleByTuple()
   //-------------------------------------|
   // Desc:    Outputs a string representation of the InvDB
   // Invars:  NULL
   std::string getCTitleByTuple(int month, int year, std::string actor);

   // (+) --------------------------------|
   // #getDYearByTuple()
   //-------------------------------------|
   // Desc:    Outputs a string representation of the InvDB
   // Invars:  NULL
   int getDYearByTuple(std::string director, std::string title);



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   InvDB();

   InvDB(std::ifstream&);

   ~InvDB();

};

// End of file - InvDB.h