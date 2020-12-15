#include "MobileNode.h"
#include "stdlib.h"
#include <time.h>

//namespace inet {

//Register_Class(MobileNode);
Define_Module(MobileNode);

void MobileNode::initialize(){

    //   std::cout << "foooooooooooooooo" << endl;
    //   std::cout  << "par1 = " << par("par1").intValue() << endl;
    //   par("par1").setIntValue(rand() % 10 + 1);
    //   std::cout  << "par1 = " << par("par1").intValue() << endl;


    internalMobNodeId = (rand() % 50 +1) * 10;
    par("mobNodeId").setIntValue(internalMobNodeId);

    for (int n= 0; n< par("wayPointSetSize").intValue(); n++){
        waypoints[n].x = n * 100 + internalMobNodeId;
        waypoints[n].y = n * 100 + internalMobNodeId;
        waypoints[n].z = 100 + internalMobNodeId;
    }

    par("nextX_0").setDoubleValue(0);// * 100 + internalMobNodeId);
    par("nextY_0").setDoubleValue(0);// * 100 + internalMobNodeId);
    par("nextZ_0").setDoubleValue(10);

    par("nextX_1").setDoubleValue(0 * 100 + internalMobNodeId);
    par("nextY_1").setDoubleValue(2 * 100 + internalMobNodeId);
    par("nextZ_1").setDoubleValue(10);

    par("nextX_2").setDoubleValue(2 * 100 + internalMobNodeId);
    par("nextY_2").setDoubleValue(2 * 100 + internalMobNodeId);
    par("nextZ_2").setDoubleValue(10);

    par("nextX_3").setDoubleValue(2 * 100 + internalMobNodeId);
    par("nextY_3").setDoubleValue(0 * 100 + internalMobNodeId);
    par("nextZ_3").setDoubleValue(10);



}

void MobileNode::handleMessage(cMessage *msg) {
     // your code

}

//} //namespace
