//
// Created by redperov on 12/2/16.
//

#ifndef EX2_VEHICLE_H
#define EX2_VEHICLE_H

#include "Manufacturer.h"
#include "Color.h"

/**
 * The class represents an abstract vehicle.
 */
//TODO decide how to make it an abstract class
class Vehicle {

private:
    unsigned        vehicleId;
    unsigned        kmPassed;
    Manufacturer    carManufacturer;
    Color           color;

protected:
    unsigned maxCapacity;
    double   tariff;
    unsigned speedLimit; //TODO not sure this is necessary, the vehicle just moves twice the speed

public:

    /*
     * Constructor
     */
    Vehicle(unsigned int vehicleId, Manufacturer carManufacturer, Color color, unsigned int maxCapacity, double tariff,
            unsigned int speedLimit);

    /*
     * Returns the vehicle id.
     */
    unsigned int getVehicleId() const;

    /*
     * Returns the number of kilometers a vehicle has passed
     */
    unsigned int getKmPassed() const;

    /*
     * Returns the type(enum) of the car manufacturer
     */
    Manufacturer getCarManufacturer() const;

    /*
     * Returns the color(enum) of the vehicle
     */
    Color getColor() const;

    /*
     * Returns the number of the maximum passenger capacity a vehicle can hold.
     */
    unsigned int getMaxCapacity() const;

    /*
     * Returns the vehicle tariff
     */
    double getTariff() const;

    /*
     * Returns the vehicle's speed limit.
     */
    unsigned int getSpeedLimit() const;

    /*
     * Increases the number of kilometers passed by the vehicle by one.
     */
    void increaseKmPassed();

};

#endif //EX2_VEHICLE_H
