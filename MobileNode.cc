#include "MobileNode.h"
#include "stdlib.h"
#include <time.h>

//namespace inet {

//Register_Class(MobileNode);
Define_Module(MobileNode);

void MobileNode::initialize(int stage) {
  // an example of reading new parameter in the first stage
  //if (stage == INITSTAGE_LOCAL) {
   std::cout << "foooooooooooooooo" << endl;
   std::cout  << "par1 = " << par("par1").intValue() << endl;
   par("par1").setIntValue(rand() % 10 + 1);
   std::cout  << "par1 = " << par("par1").intValue() << endl;

  //}
  // your code
}

void MobileNode::handleMessage(cMessage *msg) {
     // your code

}

//} //namespace
