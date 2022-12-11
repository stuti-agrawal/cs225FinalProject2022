#pragma once

#include "../lib/motionPlanning/pointCloud.h"
#include "../lib/motionPlanning/sceneObject.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>

PointCloud readDataFile(std::string filename);

vector<SceneObject> readAnnotFile(std::string filename);