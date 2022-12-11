#include "../lib/motionPlanning/HSLAPixel.h"
#include "../lib/motionPlanning/PNG.h"
#include "../lib/motionPlanning/pointCloud.h"
#include "filereader.h"

using namespace cs225;

void test();

// paint the map base on the file imported in this method
void paintWithPointCloud(PointCloud cloud);

void paintClusters(PointCloud cloud, std::vector<LidarPoint> vertex);

PNG paintLine(LidarPoint x, LidarPoint y, cs225::PNG canvass);