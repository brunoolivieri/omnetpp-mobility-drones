#ifndef __MOBILENODE_H_
#define __MOBILENODE_H_

#include <omnetpp.h>
//#include <cModule.h>

using namespace omnetpp;

//namespace inet {

class MobileNode : public cModule  {
  protected:
    //virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg);
};

//} //namespace
#endif
