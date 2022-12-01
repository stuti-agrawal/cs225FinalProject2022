#include "../lib/motionPlanning/sceneObject.h"
#include "../lib/motionPlanning/pointCloud.h"

// TODO: decide whether to keep a templated class or not?
using namespace std;

vector<SceneObject<double>> cluster(PointCloud& cloud, float tolerance, int minSize, int maxSize); //TODO: does this need to return point cloud instead?

void clusterHelper(PointCloud& cloud, KDTree& tree, int idx, vector<int>& cluster, vector<bool>& processed, float tolerance, int minSize, int maxSize);

vector<> euclideanCluster(PointCloud& cloud, KDTree& tree, float tolerance, int minSize, int maxSize);
