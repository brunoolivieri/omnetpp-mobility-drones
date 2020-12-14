#include "GotoWaypointMobility.h"
#include "stdlib.h"
#include <time.h>
#include <iostream>

namespace inet {

Define_Module(GotoWaypointMobility);

GotoWaypointMobility::GotoWaypointMobility()
{
    nextMoveIsWait = false;
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
        // How to get .NED parameters:
        //std::cout  << "numOfWaypoint do ned= " << getParentModule()->par("numOfWaypoint").intValue() << endl;

        // Simulations is the three in left panel on the "run" screen
        auto simulation = getSimulation();
        // you can get some id:
        // auto teste = simulation->getModule(4)->getId();
        // get some parameters as well
        // auto teste = simulation->getModule(6)->par("mobNodeId").intValue();
        // auto teste2 = simulation->getModule(7)->par("mobNodeId").intValue();
        // std::cout  << "o id deste node eh 6 e o id eh " << teste << endl;
        // std::cout  << "o id deste node eh 7 e o id eh " << teste2 << endl;

        auto nextWayPonint = simulation->getModule(6)->par("wayPointIndex").intValue();
        std::cout  << "Setando o ponto " << nextWayPonint << endl;

        std::string tmp = std::to_string(nextWayPonint);
        std::string axisX = "nextX_" + tmp;
        std::string axisY = "nextY_" + tmp;
        std::string axisZ = "nextZ_" + tmp;

        auto nextX = simulation->getModule(6)->par(axisX.c_str()).doubleValue();
        auto nextY = simulation->getModule(6)->par(axisY.c_str()).doubleValue();
        auto nextZ = simulation->getModule(6)->par(axisZ.c_str()).doubleValue();

        Coord playTargetPosition;
        playTargetPosition.setX(nextX);
        playTargetPosition.setY(nextY);
        playTargetPosition.setZ(nextZ);

        int foo = ++nextWayPonint % 4;
        simulation->getModule(6)->par("wayPointIndex").setIntValue(foo);

        std::cout << "playTargetPosition = " << playTargetPosition.getXyz() << endl;

//        for (int i = 0; i < 4; i++) {
//            std::string tmp = std::to_string(i);
//
//            std::string axisX = "nextX_" + tmp;
//            std::string axisY = "nextY_" + tmp;
//            std::string axisZ = "nextZ_" + tmp;
//
//            auto nextX = simulation->getModule(6)->par(axisX.c_str()).doubleValue();
//            auto nextY = simulation->getModule(6)->par(axisY.c_str()).doubleValue();
//            auto nextZ = simulation->getModule(6)->par(axisZ.c_str()).doubleValue();
//
//            std::cout  << axisX << " i: " << i << " - x = " << nextX << "  -  y = " << nextY << "  -  z = " << nextZ << endl;
//        }


        /////////////////// Olivieri ///////////////////

        //targetPosition = getRandomPosition();
        targetPosition = playTargetPosition;

        double speed = speedParameter->doubleValue();
        double distance = lastPosition.distance(targetPosition);
        simtime_t travelTime = distance / speed;
        nextChange = simTime() + travelTime;
        nextMoveIsWait = hasWaitTime;

    }
}



} // namespace inet

