#pragma once
#include "Film.h"

class Drama : public Film {
public:
   
   /**
    * == operator
    * Desc: compares two films based on title & release date
    * Pre: assumes title and release data are populated
   **/
   bool operator==(Film&);

   /**
    * <= operator
    * Desc: compares two films based on title & release date
    * Pre: assumes title and release data are populated
   **/
   bool operator<=(Film&);
   bool operator<(Film&);

   /**
    * >= operator
    * Desc: compares two films based on title & release date
    * Pre: assumes title and release data are populated
   **/
   bool operator>=(Film&);
   bool operator>(Film&);

   Drama();
   Drama(std::string);
   ~Drama();
private:
};
