#include "gtest/gtest.h"
#include "../MainFlow.h"
#include "../StandardVehicle.h"

class MainFlowTest : public ::testing::Test {

protected:

    MainFlow mainFlow;
    Driver   *driver;
    Vehicle  *vehicle;

    virtual void SetUp() {
        mainFlow.createMap(5, 5, std::vector<Point> {Point(3, 3)});
        mainFlow.createTaxiCenter(Point(0, 0));
        driver  = new Driver(1, 23, SINGLE, 3);
        vehicle = new StandardVehicle(1, FIAT, BLUE, 4, 2, 90);
    }

    virtual void TearDown() {
        delete driver;
        delete vehicle;
    }

public:
    MainFlowTest() : mainFlow() {}

};

/*
 * Check that the main flow methods work correctly.
 */
TEST_F(MainFlowTest, basicTest) {

    int  preDriversNum  = 0;
    int  postDriverNum  = 0;
    int  preVehicleNum  = 0;
    int  postVehicleNum = 0;
    bool foundDriver    = false;
    bool foundVehicle   = false;

    //TODO make the pointer == work
    ASSERT_TRUE(mainFlow.getMap() == 0);        // make sure a map exists
    ASSERT_TRUE(mainFlow.getTaxiCenter() == 0); // make sure a taxi center exists

    preDriversNum = (int) mainFlow.getTaxiCenter()->getDrivers().size();
    mainFlow.createDriver(driver);

    for (int i = 0; i < mainFlow.getTaxiCenter()->getDrivers().size(); ++i) {

        if (mainFlow.getTaxiCenter()->getDrivers().at(i)->getDriverId() == driver->getDriverId()) {
            foundDriver = true;
        }
    }

    ASSERT_TRUE(foundDriver); // make sure that the correct driver was added to the list.

    postDriverNum = (int) mainFlow.getTaxiCenter()->getDrivers().size();

    ASSERT_EQ(preDriversNum + 1, postDriverNum); // check that a new driver was created

    preVehicleNum = (int) mainFlow.getTaxiCenter()->getVehicles().size();
    mainFlow.createVehicle(vehicle);

    for (int j = 0; j < mainFlow.getTaxiCenter()->getVehicles().size(); ++j) {

        if (mainFlow.getTaxiCenter()->getVehicles().at(j)->getVehicleId() == vehicle->getVehicleId()) {

            foundVehicle = true;
        }
    }

    ASSERT_TRUE(foundVehicle); // check that the correct vehicle was added to the list.

    postVehicleNum = (int) mainFlow.getTaxiCenter()->getVehicles().size();

    ASSERT_EQ(preVehicleNum + 1, postVehicleNum); // check that a new vehicle was created
}



