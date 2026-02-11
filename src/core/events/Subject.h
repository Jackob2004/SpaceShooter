#ifndef SPACESHOOTER_SUBJECT_H
#define SPACESHOOTER_SUBJECT_H

#include <vector>

#include "Observer.h"

template <typename T>
class Subject {
public:
    void addObserver(Observer<T>* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer<T>* observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

private:
    std::vector<Observer<T>*> observers;

protected:
    void notify(const T& data, Event event) {
        for (Observer<T>* observer : observers) {
            observer->onNotify(data, event);
        }
    }
};


#endif //SPACESHOOTER_SUBJECT_H