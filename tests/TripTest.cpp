#include "gtest/gtest.h"
#include "../Trip.h"
#include "../StandardVehicle.h"

/**
 * The class performs unit tests upon the Trip class.
 */
class TripTest : public ::testing::Test {
protected:
    Trip    trip;
    Taxi    *taxi;
    Driver  *driver;
    Vehicle *vehicle;

    virtual void SetUp() {

        driver  = new Driver(2, 40, SINGLE, 20);
        vehicle = new StandardVehicle(1, SUBARU, BLUE, 4, 2, 95);
        taxi    = new Taxi(driver, vehicle, Point(0, 1));
    }

    virtual void TearDown() {

        delete driver;
        delete vehicle;
        delete taxi;
    }

public:
    TripTest() : trip(1, 4, 2, taxi, Point(2, 1), Point(3, 4)) {}
};

//TODO add checks.



