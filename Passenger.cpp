
#include "Passenger.h"

Passenger::Passenger(const Point &sourcePoint, const Point &destinationPoint) : sourcePoint(sourcePoint),
                                                                                destinationPoint(destinationPoint) {}

const Point &Passenger::getSourcePoint() const {
    return sourcePoint;
}

const Point &Passenger::getDestinationPoint() const {
    return destinationPoint;
}

unsigned Passenger::generateSatisfaction() {

    /*
    srand(time(NULL));

    return (unsigned)(rand() % 5) + 1;
     */
    return 1;
}
