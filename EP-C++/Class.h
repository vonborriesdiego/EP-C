#include <iostream>
//#include "Bateria.h"
//#include "Drone.h"
#include "Outdoor.h"
using namespace std;

//int main() {
    int position[2] = {};
    
    Bateria bateria (2000, 2000);
    Drone myDrone(0.8, position, true, 2000, 2000);
    Outdoor outdoor(300.0, 0.8, position, true, 2000, 2000);

//    return 0;

//};