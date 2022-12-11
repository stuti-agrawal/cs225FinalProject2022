#include "cluster.h"
#include <vector>
#include <stack>

// PointCloud<float> filterCloud(PointCloud<float> cloud, float filterRes, LidarPoint minPoint, LidarPoint maxPoint) {

// }

// pair<PointCloud<float>, PointCloud<float>> seperateClouds() {

// }

// pair<PointCloud<float>, PointCloud<float>> segmentPlant() {

// }

// pair<PointCloud<float>, PointCloud<float>> ransacPlane() {

// }

// vector<SceneObject<double>> cluster(PointCloud<double>& cloud, float tolerance, int minSize, int maxSize) {
// //TODO: does this need to return point cloud instead?
// } 

// void clusterHelper(PointCloud<float>& cloud, KDTree<double, 3>& tree, int idx, vector<int>& cluster, vector<bool>& processed, float tolerance, int minSize, int maxSize) {

// }

// vector<int> euclideanCluster(PointCloud<double>& cloud, KDTree<double, 3>& tree, float tolerance, int minSize, int maxSize) {

// }

// vector<SceneObject> euclideanCluster(const PointCloud& cloud, const KDTree& tree, float tolerance, int minSize, int maxSize) {
//     vector<SceneObject> clusters;
//     // for (const auto& point : cloud.cloud()) {
//     //     cout << point << endl;
//     // }
//     // std::map<vector<float>, bool> processedMap;
//     // for (const auto& point : cloud.cloud()) {
//     //     processedMap.insert({{point[0], point[1], point[2]}, false});
//     // }
//     // int i = 0;
//     // for (const auto& point : cloud.cloud()) {
//     //     LidarPoint pt = point;
//     //     if (!processedMap.at({point[0], point[1], point[2]})) {
//     //         cout << count++ << endl;
//     //         SceneObject baseCluster({});
//     //         if (i % 5 == 0) {
//     //             findClusters(tree, pt, baseCluster, tolerance, minSize, maxSize, processedMap);
//     //             if ((int) baseCluster.numberOfLidarPoints() > minSize) {
//     //                 clusters.push_back(baseCluster);
//     //             }
//     //         }
//     //     }
//     // }
//     // return clusters;

//     vector<LidarPoint> nearbyPoints;
//     KDTree::KDTreeNode* root = tree.root();
//     tree.findNearestNeighorsInTolerance(root, LidarPoint(40, 40, 0), 100, 0, nearbyPoints);
//     // cout << "size: " << nearbyPoints.size() << endl;
//     SceneObject baseCluster({});
//     for (auto& point : nearbyPoints) {
//         baseCluster.addLidarPoint(point[0], point[1], point[2], 0.0);
//     }
//     clusters.push_back(baseCluster);
//     return clusters;
// }

// // get nearest neighbors

// void findClusters(const KDTree& tree, LidarPoint& currentPoint, SceneObject& baseCluster, float tolerance, int minSize, int maxSize, map<vector<float>, bool>& processedMap) {
//     // stack<LidarPoint> pending;
//     // processedMap.at({currentPoint[0], currentPoint[1], currentPoint[2]}) = true;

//     // baseCluster.addLidarPoint(currentPoint[0], currentPoint[1], currentPoint[2], 0.0);
//     // pending.push(currentPoint);
//     // while (!pending.empty()) {
//     //     // cout << currentPoint << endl;
//     //     // cout << pending.size() << endl;
//     //     LidarPoint query = pending.top();
//     //     pending.pop();
//     //     processedMap.at(query) = true;

        
//     //     // cout << "size of nearest neighbors: " << nearbyPoints.size() << endl;
//     //     if (nearbyPoints.empty()) {
//     //         // cout << "no neighbors" << endl;
//     //         return; 
//     //     }
//     //     // cout << "YES neighbors!" << endl;
//     //     // cout << nearbyPoints.size() << endl;
//     //     for (auto& point : nearbyPoints) {
//     //         if (!processedMap.at(point)) {
//     //             processedMap.at(point) = true;
//     //             baseCluster.addLidarPoint(point[0], point[1], point[2], 0.0);
//     //         }
//     //     }
//     // vector<LidarPoint> nearbyPoints;
//     // KDTree::KDTreeNode* root = tree.root();
//     // tree.findNearestNeighorsInTolerance(root, currentPoint, tolerance, 0, nearbyPoints);
//     // for (auto& point : nearbyPoints) {
//     //     if (!processedMap.at({point[0], point[1], point[2]})) {
//     //         processedMap.at({point[0], point[1], point[2]}) = true;
//     //         baseCluster.addLidarPoint(point[0], point[1], point[2], 0.0);
//     //     }
//     // }

    


    
// }


// void findClusters(const KDTree& tree, LidarPoint& currentPoint, SceneObject& baseCluster, float tolerance, int minSize, int maxSize) {
//     if (!currentPoint.processed_) {
//         currentPoint.processed_ = true;
//         baseCluster.addLidarPoint(currentPoint[0], currentPoint[1], currentPoint[2], 0.0);
//         vector<LidarPoint> nearbyPoints;
//         KDTree::KDTreeNode* root = tree.root();
//         tree.findNearestNeighorsInTolerance(root, currentPoint, tolerance, 0, nearbyPoints);
//         if (!(nearbyPoints.empty())) {
//             for (auto& point : nearbyPoints) {
//                 if (!point.processed_) {
                
//                     cout << "run" << endl;
//                     cout << count << endl;
//                     findClusters(tree, point, baseCluster, tolerance, minSize, maxSize);
                    
//                 }
//             }
//         }
//     }
// }

