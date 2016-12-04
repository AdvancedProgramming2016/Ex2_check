cmake_minimum_required(VERSION 3.6)
project(Ex2_check)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
set(SOURCE_FILES main.cpp Point.cpp Point.h Vertex.cpp Vertex.h
        Graph.cpp Graph.h Grid.cpp Grid.h Bfs.cpp Bfs.h Driver.cpp
        Driver.h Vehicle.cpp Vehicle.h LuxuryVehicle.cpp LuxuryVehicle.h
        StandardVehicle.cpp StandardVehicle.h IObserver.h ISubject.h MainFlow.cpp
        MainFlow.h Manufacturer.h MaritalStatus.h Passenger.cpp Passenger.h
        Taxi.cpp Taxi.h TaxiCenter.cpp TaxiCenter.h Trip.cpp Trip.h tests/PointTest.cpp
        tests/VertexTest.cpp tests/GridTest.cpp tests/GraphTest.cpp tests/BfsTest.cpp
        tests/DriverTest.cpp tests/MainFlowTest.cpp tests/PassengerTest.cpp
        tests/TaxiCenterTest.cpp tests/TaxiTest.cpp tests/TripTest.cpp tests/VehicleTest.cpp)
add_executable(Ex2_check ${SOURCE_FILES})
target_link_libraries(Ex2_check gtest gtest_main)
