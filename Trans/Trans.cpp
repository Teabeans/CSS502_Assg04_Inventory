// Trans.cpp
#include <string>
#include <iostream>
#include "Trans.h"
#include "Borrow.h"
#include "Return.h"

/**
 * factory method
 * Desc: generates and returns a type of transaction based on the type string
**/
Trans* Trans::factory(std::string command) {

   // create borrow object and run transaction
   if (command[0] == 'B') {
      std::cerr << " Borrow" << std::endl;
      return new Borrow(command);
   }

   // create return object and run transaction
   else if (command[0] == 'R') {
      std::cerr << " Return" << std::endl;
      return new Return(command);
   }

   // else if (command[0] == 'H') {
      // std::cerr << " Show History" << std::endl;
      // return new History;
   // }

   // otherwise, this is an invalid command
   else {
      std::cerr << "Invalid command: " << command.at(0) << std::endl;
      return new Trans(command);
   }
}

Trans::Trans() {

}

Trans::Trans(std::string command) {

}

Trans::~Trans() {

}