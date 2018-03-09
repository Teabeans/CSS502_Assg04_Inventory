#pragma once
#include "Film.h"

class Drama : public Film {
public:

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       OPERATORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   /**
    * == operator
    * Desc: compares two films based on director & title
    * Pre: assumes director and title are populated
   **/
   virtual bool operator==(Film&);

   /**
    * <= operator
    * Desc: compares two films based on title & title
    * Pre: assumes director and title are populated
   **/
   virtual bool operator<=(Film&);
   virtual bool operator<(Film&);

   /**
    * >= operator
    * Desc: compares two films based on title & title
    * Pre: assumes director and title are populated
   **/
   virtual bool operator>=(Film&);
   virtual bool operator>(Film&);

   // char getGenre();
   // void setGenre(char);
   Drama();
   Drama(std::string);
   ~Drama();
private:
};
