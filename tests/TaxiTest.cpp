#include "gtest/gtest.h"
#include "../Taxi.h"
#include "../StandardVehicle.h"

class TaxiTest : public ::testing::Test {
protected:
    Taxi    taxi;
    Driver  *driver;
    Vehicle *vehicle;
    Trip    *trip;

    virtual void SetUp() {

        driver  = new Driver(1, 45, MaritalStatus::MARRIED, 20);
        vehicle = new StandardVehicle(1, Manufacturer::HONDA, Color::BLUE, 4, 2, 90);
        trip    = new Trip(1, 2, 4, &taxi, taxi.getCurrentPosition(), Point(2, 3));
        taxi.setTrip(trip);
    }

    virtual void TearDown() {

        delete driver;
        delete vehicle;
        delete trip;
    }

public:
    TaxiTest() : taxi(driver, vehicle, Point(1, 2)) {}
};

TEST_F(TaxiTest, basicTest) {

    unsigned initSatisfaction = 0;
    unsigned newSatisfaction  = 0;

    initSatisfaction = taxi.getDriver()->getAvgSatisfaction();
    taxi.endTrip();
    newSatisfaction = taxi.getDriver()->getAvgSatisfaction();

    ASSERT_TRUE(taxi.getTrip() == 0);                 //check that the trip was set to NULL
    EXPECT_NE(initSatisfaction, newSatisfaction); //check that the average satisfaction was changed, not mandatory

}

