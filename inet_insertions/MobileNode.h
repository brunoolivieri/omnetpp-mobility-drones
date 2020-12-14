#ifndef __MOBILENODE_H_
#define __MOBILENODE_H_

#include <omnetpp.h>
//#include <cModule.h>

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
    //virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void initialize() override;//(int stage) override;
    virtual void handleMessage(cMessage *msg);
  public:
    WayPoint waypoints[4];
    int internalMobNodeId;

};

//} //namespace
#endif
