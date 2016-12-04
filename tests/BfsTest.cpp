
#include <iostream>
#include <gtest/gtest.h>
#include "../Bfs.h"
#include "../Grid.h"


class BfsTest : public :: testing::Test {

protected:

    Graph *graph;

public:

    virtual void SetUp(){

            Graph *graph = new Grid(3, 2);
    };

    virtual void TearDown(){

            delete graph;

    };

};

TEST_F(BfsTest, basicTests){

    // Init params
    Point startPt(0, 0);
    Point endPt(1, 1);
    Bfs bfs(graph, startPt, endPt);

    // Builds the shortest path
    bfs.get_route();

    std::ostringstream  out;
    out<<   startPt;
    EXPECT_EQ(out.str(), "(0,0)"); //TODO check that it works

}