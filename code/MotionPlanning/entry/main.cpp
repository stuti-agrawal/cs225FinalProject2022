// it all begins here...
#include "filereader.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include "../lib/motionPlanning/HSLAPixel.h"
#include "../lib/motionPlanning/PNG.h"
#include "visualize.h"
using namespace std;
using namespace cs225;

int main() {
    PointCloud cloud = readFile("/workspaces/cs225FinalProject2022/data/1616100800400.bin");
    
    // visualization test
    test();
    return 0;
}