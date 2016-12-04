
#include "Trip.h"

Trip::Trip(unsigned int rideId, unsigned int numOfPassengers, double tariff, Taxi *taxi, const Point &startPoint,
           const Point &endPoint) : rideId(rideId), numOfPassengers(numOfPassengers), tariff(tariff), taxi(taxi),
                                    startPoint(startPoint), endPoint(endPoint), totalMetersPassed(0) {}

Trip::~Trip() {

}

unsigned int Trip::getRideId() const {
    return rideId;
}

unsigned int Trip::getTotalMetersPassed() const {
    return totalMetersPassed;
}

unsigned int Trip::getNumOfPassengers() const {
    return numOfPassengers;
}

double Trip::getTariff() const {
    return tariff;
}

Taxi *Trip::getTaxi() const {
    return taxi;
}

const Point &Trip::getStartPoint() const {
    return startPoint;
}

const Point &Trip::getEndPoint() const {
    return endPoint;
}



