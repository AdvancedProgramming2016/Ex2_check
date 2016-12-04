#include "gtest/gtest.h"
#include "../TaxiCenter.h"

/**
 * The class performs unit tests upon the Taxi center class.
 */
class TaxiCenterTest : public ::testing::Test {
protected:

    TaxiCenter               taxiCenter;
    std::vector<Passenger *> passengerList;
    Point * point;

    virtual void SetUp() {
        point = new Point(0,0);
        passengerList = {new Passenger(Point(1, 1), Point(2, 1))};
    }

    virtual void TearDown() {

        delete point;

        for (int i = 0; i < passengerList.size(); ++i) {
            delete passengerList.at(i);
        }
    }

public:
    TaxiCenterTest() : taxiCenter(point) {}

};

/*
 * Checks that the standard TaxiCenter methods work.
 */
TEST_F(TaxiCenterTest, basicTest) {

    unsigned initTaxisSize = 0;
    unsigned postTaxisSize = 0;

    initTaxisSize = (int) taxiCenter.getTaxis().size();
    taxiCenter.answerCall(passengerList);
    postTaxisSize = (int) taxiCenter.getTaxis().size();

    //EXPECT_EQ(initTaxisSize, postTaxisSize); //check that a taxi was added to the taxi center

    //ASSERT_NE(taxiCenter.answerCall(passengerList), 0); // check that a new trip was sent
}

/*
 * Check that the observer methods work.
 */
TEST_F(TaxiCenterTest, observerTest) {

    int       initObserverNum = 0;
    int       postObserverNum = 0;
    IObserver *observer;

    initObserverNum = (int) taxiCenter.getObservers().size();
    taxiCenter.registerObserver(observer);
    postObserverNum = (int) taxiCenter.getObservers().size();

    ASSERT_EQ(initObserverNum + 1, postObserverNum); //check that adding an observer works

    taxiCenter.unregisterObserver(observer);

    //TODO make sure by searching the observers vector that the correct observer was deleted.

    postObserverNum = (int) taxiCenter.getObservers().size();

    ASSERT_EQ(initObserverNum, postObserverNum); //check that removing an observer works
}
