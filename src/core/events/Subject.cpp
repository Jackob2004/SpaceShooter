#include "Subject.h"

#include "entities/Entity.h"

template <typename T>
void Subject<T>::addObserver(Observer<T>* observer) {
    observers.push_back(observer);
}

template <typename T>
void Subject<T>::removeObserver(Observer<T>* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

template <typename T>
void Subject<T>::notify(T& data, Event event) {
    for (Observer<T>* observer : observers) {
        observer->onNotify(data, event);
    }
}

template class Subject<Entity>;