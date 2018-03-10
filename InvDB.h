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
std::vector<Film> comedies;

//-----------------|
// #dramas
//-----------------|
// Desc:   List of all dramas
// Invars: NULL
std::vector<Film> dramas;

//-----------------|
// #classics
//-----------------|
// Desc:   List of all classics
// Invars: NULL
std::vector<Film> classics;

//-----------------|
// #classics
//-----------------|
// Desc:   List of films of any other type
// Invars: NULL
std::vector<Film> otherFilms;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   int hashTitle(std::string someTitle);

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

   // bool addClassic(Classic*);

   // bool addComedy(Comedy*);

   // bool addDrama(Drama*);

   bool addFilm(Film*);

   void adjustStock(Trans&);

   bool contains(Film*);

   void display();

   bool isLegal(std::string);

   bool isValid(std::string);

   Film* retrieve(Film*);

   std::string const toString();

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

   InvDB();

   InvDB(std::ifstream&);

   ~InvDB();

};

// End of file - InvDB.h
