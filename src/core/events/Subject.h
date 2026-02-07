#ifndef SPACESHOOTER_SUBJECT_H
#define SPACESHOOTER_SUBJECT_H

#include <vector>

#include "Observer.h"
template <typename T>
class Subject {

public:
    void addObserver(Observer<T>* observer);
    void removeObserver(Observer<T>* observer);

private:
    std::vector<Observer<T>*> observers;

protected:
    void notify(T& data, Event event);
};


#endif //SPACESHOOTER_SUBJECT_H