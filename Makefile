cmake_minimum_required(VERSION 3.6)
project(Ex2_check)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread ")
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
set(SOURCE_FILES main.cpp Point.cpp Point.h Vertex.cpp Vertex.h
                         Graph.cpp Graph.h Grid.cpp Grid.h Bfs.cpp Bfs.h Driver.cpp
                         Driver.h Vehicle.cpp Vehicle.h LuxuryVehicle.cpp LuxuryVehicle.h
                         StandardVehicle.cpp StandardVehicle.h IObserver.h ISubject.h MainFlow.cpp
                         MainFlow.h Manufacturer.h MaritalStatus.h Passenger.cpp Passenger.h
                         Taxi.cpp Taxi.h TaxiCenter.cpp TaxiCenter.h Trip.cpp Trip.h PointTest.cpp
                         VertexTest.cpp GridTest.cpp GraphTest.cpp BfsTest.cpp
                         DriverTest.cpp MainFlowTest.cpp PassengerTest.cpp
                         TaxiCenterTest.cpp TaxiTest.cpp TripTest.cpp VehicleTest.cpp)
add_executable(ex11 ${SOURCE_FILES})
target_link_libraries(Ex2_check gtest gtest_main gmock core)
add_test(Ex2_check Ex2_check)
