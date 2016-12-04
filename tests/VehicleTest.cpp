#include "gtest/gtest.h"
#include "../Vehicle.h"
#include "../StandardVehicle.h"
#include "../LuxuryVehicle.h"

class VehicleTest : public ::testing::Test {
protected:
    Vehicle *standardVehicle;
    Vehicle *luxuryVehicle;

    virtual void SetUp() {

        standardVehicle = new StandardVehicle(1,Manufacturer::FIAT, Color::BLUE, 4, 2, 90);
        luxuryVehicle   = new LuxuryVehicle(2, Manufacturer::TESLA, Color::WHITE, 3, 5, 200);
    }

    virtual void TearDown() {

        delete standardVehicle;
        delete luxuryVehicle;
    }
};

/*
 * Test that the basic vehicle methods work
 */
TEST_F(VehicleTest, basicCheck) {

    int kmPassedFirst = 0;
    int kmPassedLater = 0;

    kmPassedFirst = standardVehicle->getKmPassed();
    standardVehicle->increaseKmPassed();
    kmPassedLater = standardVehicle->getKmPassed();

    ASSERT_EQ(kmPassedFirst + 1, kmPassedLater); // check that the km counter increases by one.

}

/*
 * Compare between the different vehicles.
 */
TEST_F(VehicleTest, vehicleComparison) {

    double regularTariff = 0;
    double luxuryTariff  = 0;

    regularTariff = standardVehicle->getTariff();
    luxuryTariff  = luxuryVehicle->getTariff();

    ASSERT_LT(regularTariff , luxuryTariff); //TODO wrong test, check how to use the trip coefficient
}



