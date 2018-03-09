// Drama.cpp
#include <string>
#include <iostream>
#include "FilmDrama.h"

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

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

      if (director == rhs.getDirector() && title == rhs.getTitle()) {
         return true;
      }
      else {
         return false;
      }
   }

   /**
    * <= & < operators
    * Desc: compares two films based on director & release date
    * Pre: assumes director and release data are populated
   **/
   bool Drama::operator<=(Film& rhs) {

      if (director < rhs.getDirector()) {
         return true;
      }
      else if (director == rhs.getDirector() && title <= rhs.getTitle()) {
         return true;
      }
      else {
         return false;
      }
   }
   bool Drama::operator<(Film& rhs) {

      if (director < rhs.getDirector()) {
         return true;
      }
      else if (director == rhs.getDirector() && title < rhs.getTitle()) {
         return true;
      }
      else {
         return false;
      }
   }

   /**
    * >= & > operators
    * Desc: compares two films based on director & release date
    * Pre: assumes director and release data are populated
   **/
   bool Drama::operator>=(Film& rhs) {

      if (director > rhs.getDirector()) {
            return true;
         }
         else if (director == rhs.getDirector() && title >= rhs.getTitle()) {
            return true;
         }
         else {
            return false;
         }
   }
   bool Drama::operator>(Film& rhs) {

      if (director > rhs.getDirector()) {
            return true;
         }
         else if (director == rhs.getDirector() && title > rhs.getTitle()) {
            return true;
         }
         else {
            return false;
         }
   }
