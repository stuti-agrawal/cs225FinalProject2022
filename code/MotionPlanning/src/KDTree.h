#pragma once

#include "../lib/motionPlanning/pointCloud.h"

#pragma once

#include <vector>
#include <string>

using namespace std;

/**
 * KDTree class to store 3D points. Enables faster search for
 * clutering and creation of SceneObjects
 */
// template <typename T, int Dim>

class KDTree {
    public:

        struct KDTreeNode {
            LidarPoint point;
            KDTreeNode* left;
            KDTreeNode* right;
            KDTreeNode() : point(), left(NULL), right(NULL) {}
            KDTreeNode(const LidarPoint &point) : point(point), left(NULL), right(NULL) {}
        };


        bool smallerDimVal(const LidarPoint& first, const LidarPoint& second,
                       int curDim) const;
        bool shouldReplace(const LidarPoint& target, const LidarPoint& currentBest,
                       const LidarPoint& potential) const;
        KDTree(const vector<LidarPoint>& newPoints);
        KDTree(const PointCloud& cloud);
        KDTree(const KDTree& other);
        KDTree const &operator=(const KDTree& rhs);
        ~KDTree();
        LidarPoint findNearestNeighbor(const LidarPoint& query) const;
        void findNearestNeighorsInTolerance(KDTreeNode*& currentNode, LidarPoint searchPoint, float tolerance, int depth, vector<LidarPoint>& nearestNeighbors) const;
        KDTreeNode* root() const;     
    private:

        
        double euclideanDistanceSqrd(const LidarPoint &first, const LidarPoint &second) const;
        KDTreeNode* KDTreeRecursiveHelper(vector<LidarPoint>& newPoints, int dim);
        LidarPoint select(vector<LidarPoint>& list, int left, int right, int k, int dim);
        int partition(vector<LidarPoint>& list, int left, int right, int pivotIdx, int dim);
        void swap(LidarPoint& first, LidarPoint& second);
        KDTreeNode* dfs(KDTreeNode* node, KDTreeNode* tmp_bn, const LidarPoint& query, int dim) const;
        bool spInRadius(const LidarPoint& pt, const LidarPoint& query, int dim, double min_distance) const;
    
    public:

    private:
        KDTreeNode* root_;

        // size_t size_;
        // KDTreeNode* best_node_;
        // double min_distance_;

};