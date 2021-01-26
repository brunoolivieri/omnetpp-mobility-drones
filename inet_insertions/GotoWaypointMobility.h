#ifndef __INET_GOTOWPMOBILITY_H
#define __INET_GOTOWPMOBILITY_H

#include "inet/common/INETDefs.h"
#include "inet/mobility/single/RandomWaypointMobility.h"
#include "MobileNode.h"

namespace inet {

class INET_API GotoWaypointMobility : public RandomWaypointMobility
{
  protected:


  protected:
    virtual void setTargetPosition() override;
    virtual void setInitialPosition() override;

  public:
    GotoWaypointMobility();
    //MobileNode * myParentNode;

};

} // namespace inet

#endif // ifndef __INET_GOTOWPMOBILITY_H

