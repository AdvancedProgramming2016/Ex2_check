#include "gtest/gtest.h"
#include "../Driver.h"
#include "../TaxiCenter.h"
#include "../StandardVehicle.h"

class DriverTest : public ::testing::Test {
protected:
    Driver     driver;
    Taxi       taxi;
    Vehicle    *vehicle;
    Trip       *trip;
    TaxiCenter taxiCenter;
    Point *point;

    virtual void SetUp() {

        point = new Point(0,0);
        vehicle = new StandardVehicle(1, Manufacturer::HONDA, Color::BLUE, 4, 2, 90);
        trip    = new Trip(1, 2, 4, &taxi, taxi.getCurrentPosition(), Point(2, 3));
        taxi.setTrip(trip);
    }

    virtual void TearDown() {

        delete point;
        delete vehicle;
        delete trip;
    }

public:
    DriverTest() : driver(1, 45, MaritalStatus::MARRIED, 20), taxiCenter(point),
                   taxi(&driver, vehicle, Point(1, 2)) {}
};

/*
 * Checks the basic driver functionality.
 */
TEST_F(DriverTest, basicTest) {

    unsigned initialExp = 0;
    unsigned postExp    = 0;

    initialExp = driver.getYearsOfExperience();
    driver.increaseExperience();
    postExp = driver.getYearsOfExperience();

    ASSERT_EQ(initialExp + 1, postExp); // check that the experience increased by one.
}

/*
 * Check the updates the driver sends to the taxi center;
 */
TEST_F(DriverTest, TestObserver) {

    Point preLocation;
    Point postLocation;

    preLocation = taxi.getCurrentPosition();
    driver.update(&taxiCenter);                                        // driver sends update
    postLocation = taxiCenter.getTaxis().at(0)->getCurrentPosition(); // the driver's location according to taxi center

    ASSERT_EQ(preLocation, postLocation);                              // check that the driver correctly updated its location.

}

