#include "InvDB.h"
#include <string>

std::string InvDB::toString() {
   std::string retString = "";
   retString = "This is the parent specific toString test";
   return (retString);
}

void InvDB::display() {

}



std::string InvDB::toString() {
   std::string retString = "";
   retString = "This is the parent's toString";
   return (retString);
}

InvDB::InvDB() {

}

InvDB::~InvDB() {

}
