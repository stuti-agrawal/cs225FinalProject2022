#include "../lib/motionPlanning/pointCloud.h"

#include <iostream>
#include <fstream>
#include <cmath>

// PointCloud<LidarPoint<double>> 
PointCloud<float> readFile(std::string filename);