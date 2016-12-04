

#include "LuxuryVehicle.h"

LuxuryVehicle::LuxuryVehicle(unsigned int vehicleId, Manufacturer carManufacturer, Color color, unsigned int maxCapacity, double tariff,
                             unsigned int speedLimit) : Vehicle(vehicleId, carManufacturer, color, maxCapacity, tariff,
                                                                speedLimit) {
    speedLimit *= 2;
    //tariff = trip coefficient TODO add this attribute
}
