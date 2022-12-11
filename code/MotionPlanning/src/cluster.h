#include "../lib/motionPlanning/sceneObject.h"
#include "KDTree.h"

// TODO: decide whether to keep a templated class or not?
using namespace std;

PointCloud<float> filterCloud(PointCloud<float> cloud, float filterRes, LidarPoint minPoint, LidarPoint maxPoint);

pair<PointCloud<float>, PointCloud<float>> seperateClouds();
pair<PointCloud<float>, PointCloud<float>> segmentPlant();
pair<PointCloud<float>, PointCloud<float>> ransacPlane();

vector<SceneObject<double>> cluster(PointCloud<double>& cloud, float tolerance, int minSize, int maxSize); //TODO: does this need to return point cloud instead?

void clusterHelper(PointCloud<float>& cloud, KDTree<double, 3>& tree, int idx, vector<int>& cluster, vector<bool>& processed, float tolerance, int minSize, int maxSize);

vector<int> euclideanCluster(PointCloud<double>& cloud, KDTree<double, 3>& tree, float tolerance, int minSize, int maxSize);
