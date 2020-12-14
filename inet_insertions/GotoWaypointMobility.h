#ifndef __INET_GOTOWPMOBILITY_H
#define __INET_GOTOWPMOBILITY_H

#include "inet/common/INETDefs.h"
#include "inet/mobility/single/RandomWaypointMobility.h"


namespace inet {

class INET_API GotoWaypointMobility : public RandomWaypointMobility
{
  protected:


  protected:
    virtual void setTargetPosition() override;

  public:
    GotoWaypointMobility();
};

} // namespace inet

#endif // ifndef __INET_GOTOWPMOBILITY_H

