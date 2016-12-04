
#include "StandardVehicle.h"

StandardVehicle::StandardVehicle(unsigned int vehicleId, Manufacturer carManufacturer, Color color, unsigned int maxCapacity, double tariff,
                                 unsigned int speedLimit) : Vehicle(vehicleId, carManufacturer, color, maxCapacity, tariff,
                                                                    speedLimit) {}
