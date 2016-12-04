//
// Created by redperov on 12/1/16.
//

#include "Driver.h"


Driver::Driver(unsigned int driverId, unsigned int age, MaritalStatus maritalStatus, unsigned int yearsOfExperience)
        : driverId(driverId), age(age),
          yearsOfExperience(yearsOfExperience),
          avgSatisfaction(0),
          counterOfCustomers(0),
          maritalStatus(maritalStatus),
          taxi(0) {}

unsigned int Driver::getDriverId() const {
    return driverId;
}

unsigned int Driver::getYearsOfExperience() const {
    return yearsOfExperience;
}

unsigned int Driver::getCounterOfCustomers() const {
    return counterOfCustomers;
}

void Driver::increaseExperience() {

    yearsOfExperience++;
}

void Driver::setCounterOfCustomers(unsigned int counterOfCustomers) {
    Driver::counterOfCustomers = counterOfCustomers;
}

Taxi *Driver::getTaxi() const {
    return taxi;
}

void Driver::setTaxi(Taxi *taxi) {
    Driver::taxi = taxi;
}

unsigned int Driver::getAvgSatisfaction() const {
    return avgSatisfaction;
}

Driver::~Driver() {
    delete taxi;
}

void Driver::update(ISubject *subject) {

}
