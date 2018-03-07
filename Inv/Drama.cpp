// Drama.cpp
#include <string>
#include <iostream>
#include "Drama.h"

Drama::Drama() {

}

Drama::Drama(std::string data) : Film(data) {
	// std::cerr << "creating Drama: ";
}

Drama::~Drama() {
   // std::cerr << "destruct Drama" << std::endl;

}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       OPERATORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

/**
 * == operator
 * Desc: compares two films based on director & release date
 * Pre: assumes director and release data are populated
**/
bool Drama::operator==(Film& rhs) {

   if (director == rhs.director && title == rhs.title) {
      return true;
   }
   else {
      return false;
   }
}

/**
 * <= & < operators
 * Desc: compares two films based on director and director
 * Pre: assumes director and director are populated
**/
bool Drama::operator<=(Film& rhs) {

   if (director < rhs.director) {
      return true;
   }
   else if (director == rhs.director && title <= rhs.title) {
      return true;
   }
   else {
      return false;
   }
}
bool Drama::operator<(Film& rhs) {

   if (director < rhs.director) {
      return true;
   }
   else if (director == rhs.director && title < rhs.title) {
      return true;
   }
   else {
      return false;
   }
}

/**
 * >= & > operators
 * Desc: compares two films based on director and director
 * Pre: assumes director and director are populated
**/
bool Drama::operator>=(Film& rhs) {

   if (director > rhs.director) {
         return true;
      }
      else if (director == rhs.director && title >= rhs.title) {
         return true;
      }
      else {
         return false;
      }
}
bool Drama::operator>(Film& rhs) {

   if (director > rhs.director) {
         return true;
      }
      else if (director == rhs.director && title > rhs.title) {
         return true;
      }
      else {
         return false;
      }
}