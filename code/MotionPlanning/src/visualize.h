#include "../lib/motionPlanning/HSLAPixel.h"
#include "../lib/motionPlanning/PNG.h"
#include "../lib/motionPlanning/pointCloud.h"
#include "filereader.h"
#include "../lib/motionPlanning/sceneObject.h"

using namespace cs225;
void test();

// paint the map base on the file imported in this method
PNG paintWithPointCloud(PointCloud cloud);

void paintClusters(PointCloud cloud, std::vector<LidarPoint> vertex);

PNG paintLine(LidarPoint x, LidarPoint y, cs225::PNG canvass);

// Paint a single rectangle base on the single sceneojb input
PNG paintSceneObj(SceneObject sceneobj, PNG canvass);

void paintWithSceneOjb_test();