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

#include <string>
#include <iostream>
#include "Film.h"


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS/DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

Film::Film() {
   title = "Placeholder Title";
   stock = 0;
   releaseDate = 2000;
   director = "Placeholder Director";
   genre = ' ';
}

Film::Film(std::string data) {
   // std::cerr << "creating film";
   // std::cerr << data << std::endl;

   // split the data string by commas and parse into object data
   std::string delim = ", ";
   std::string items[5];

   for (int i = 0; i < 5; i++) {
      items[i] = data.substr(0, data.find(delim));
      data.erase(0, data.find(delim) + delim.length());
   }

   genre = items[0][0]; // char
   stock = std::stoi(items[1]); // int
   director = items[2];
   title = items[3];
   releaseDate = std::stoi(items[4]); // int

}

Film::~Film() {

}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|
// TODO: Add virtual to all methods we expect to be overriden by child classes
// TODO: Check if virtual should be added to all methods irregardless
// title
std::string Film::getTitle() {
   return title;
}

void Film::setTitle(std::string data) {
   title = data;
}

// stock
int Film::getStock() {
   return stock;
}

void Film::setStock(int data) {
   stock = data;
}

// release date
int Film::getReleaseDate() {
   return releaseDate;
}

void Film::setReleaseDate(int data) {
   releaseDate = data;
}

// genre
char Film::getGenre() {
   return genre;
}

void Film::setGenre(char data) {
   genre = data;
}

// director
std::string Film::getDirector() {
   return director;
}

void Film::setDirector(std::string data) {
   director = data;
}

// actors
bool Film::hasActor(std::string actor) {

   // if the specified actor is present in the list, return true
   for (int i = 0; i < actors.size(); i++) {
      if (actors.at(i) == actor) {
         return true;
      }
   }
   return false;
}

void Film::appendActor(std::string actor) {
   actors.push_back(actor);
}


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       OPERATORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

/**
 * == operator
 * Desc: compares two films based on title & release date
 * Pre: assumes title and release data are populated
**/
bool Film::operator==(Film& rhs) {

   if (title == rhs.title && releaseDate == rhs.releaseDate) {
      return true;
   }
   else {
      return false;
   }
}

/**
 * <= & < operators
 * Desc: compares two films based on title & release date
 * Pre: assumes title and release data are populated
**/
bool Film::operator<=(Film& rhs) {

   if (title < rhs.title) {
      return true;
   }
   else if (title == rhs.title && releaseDate <= rhs.releaseDate) {
      return true;
   }
   else {
      return false;
   }
}
bool Film::operator<(Film& rhs) {

   if (title < rhs.title) {
      return true;
   }
   else if (title == rhs.title && releaseDate < rhs.releaseDate) {
      return true;
   }
   else {
      return false;
   }
}

/**
 * >= & > operators
 * Desc: compares two films based on title & release date
 * Pre: assumes title and release data are populated
**/
bool Film::operator>=(Film& rhs) {

   if (title > rhs.title) {
         return true;
      }
      else if (title == rhs.title && releaseDate >= rhs.releaseDate) {
         return true;
      }
      else {
         return false;
      }
}
bool Film::operator>(Film& rhs) {

   if (title > rhs.title) {
         return true;
      }
      else if (title == rhs.title && releaseDate > rhs.releaseDate) {
         return true;
      }
      else {
         return false;
      }
}
