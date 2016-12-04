
#ifndef EX2_MAINFLOW_H
#define EX2_MAINFLOW_H


#include "TaxiCenter.h"
#include "Grid.h"

class MainFlow {

private:

    TaxiCenter *taxiCenter;
    Grid       *map;

public:

    /*
     * Constructor.
     */
    MainFlow(); //TODO maybe make as a singleton

    /*
     * Destructor.
     */
    virtual ~MainFlow();

    /*
     * Creates a map with obstacles.
     */
    void createMap(unsigned height, unsigned width, std::vector<Point> obstacles);

    /*
     * Creates a taxi center.
     */
    void createTaxiCenter(const Point &location);

    /*
     * Creates a new driver. TODO should it get parameters?
     */
    void createDriver(Driver *driver);

    /*
     * Creates a new vehicle. TODO should it get parameters?
     */
    void createVehicle(Vehicle *vehicle);

    /*
     * Returns the taxi center.
     */
    TaxiCenter *getTaxiCenter() const;

    /*
     * Returns the map.
     */
    Grid *getMap() const;
};


#endif //EX2_MAINFLOW_H
