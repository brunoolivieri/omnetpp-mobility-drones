#ifndef __MOBILENODE_H_
#define __MOBILENODE_H_

#include <omnetpp.h>
//#include <cModule.h>
#include "inet/common/ModuleAccess.h"
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo_m.h"
#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UdpSocket.h"
#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UdpSocket.h"
#include <iostream>
#include <algorithm>
#include <iterator>

using std::cout; using std::endl;
using std::string; using std::reverse;


using namespace omnetpp;

//namespace inet {

class WayPoint {
  public:
    double x;
    double y;
    double z;
};


class MobileNode : public cModule  {
  protected:
    virtual void initialize() override;//(int stage) override;
    virtual void handleMessage(cMessage *msg);
  public:
    int refreshNextWayPoint();
    int processMessage(inet::Packet *msg);
    string generateNextPacketToSend();
    WayPoint waypoints[4];
    int internalMobNodeId;

};

//} //namespace
#endif
