#ifndef SPACESHOOTER_OBSERVER_H
#define SPACESHOOTER_OBSERVER_H

#include "Event.h"

template <typename T>
class Observer {
public:
    virtual ~Observer() = default;

    virtual void onNotify(const T& data, Event event) = 0;
};


#endif //SPACESHOOTER_OBSERVER_H