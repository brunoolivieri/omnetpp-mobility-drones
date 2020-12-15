#include "GotoWaypointMobility.h"
#include "stdlib.h"
#include <time.h>
#include <iostream>

namespace inet {

Define_Module(GotoWaypointMobility);

GotoWaypointMobility::GotoWaypointMobility()
{
    nextMoveIsWait = false;

    //std::cout  << "GotoWaypointMobility() " << endl;


}

void GotoWaypointMobility::setTargetPosition()
{

    if (nextMoveIsWait) {
        simtime_t waitTime = waitTimeParameter->doubleValue();
        nextChange = simTime() + waitTime;
        nextMoveIsWait = false;
    }
    else {

        /////////////////// Olivieri ///////////////////
        std::cout  << "getParentModule: "  <<  this->getParentModule() << endl;
        auto myParentNode = this->getParentModule();

        auto nextWayPonint = myParentNode->par("wayPointIndex").intValue();
        std::cout  << "Setando o wayPointIndex " << nextWayPonint << endl;

        std::string tmp = std::to_string(nextWayPonint);
        std::string axisX = "nextX_" + tmp;
        std::string axisY = "nextY_" + tmp;
        std::string axisZ = "nextZ_" + tmp;

        auto nextX = myParentNode->par(axisX.c_str()).doubleValue();
        auto nextY = myParentNode->par(axisY.c_str()).doubleValue();
        auto nextZ = myParentNode->par(axisZ.c_str()).doubleValue();

        Coord playTargetPosition;
        playTargetPosition.setX(nextX);
        playTargetPosition.setY(nextY);
        playTargetPosition.setZ(nextZ);

        int nextWP = ++nextWayPonint % 4;
        myParentNode->par("wayPointIndex").setIntValue(nextWP);

        std::cout << "playTargetPosition = " << playTargetPosition.getXyz() << endl;

        targetPosition = playTargetPosition;
        /////////////////// Olivieri ///////////////////

        //targetPosition = getRandomPosition();
        double speed = speedParameter->doubleValue();
        double distance = lastPosition.distance(targetPosition);
        simtime_t travelTime = distance / speed;
        nextChange = simTime() + travelTime;
        nextMoveIsWait = hasWaitTime;

    }
}



} // namespace inet

