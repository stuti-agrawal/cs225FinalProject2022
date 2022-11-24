#include "../lib/motionPlanning/lidarPoint.h"

#pragma once

#include <vector>
#include <string>

using namespace std;

template <typename T, int Dim>
class KDTree {
    public:
        bool smallerDimVal(const LidarPoint<T>& first, const LidarPoint<T>& second,
                       int curDim) const;
        bool shouldReplace(const LidarPoint<T>& target, const LidarPoint<T>& currentBest,
                       const LidarPoint<T>& potential) const;
        KDTree(const vector<LidarPoint<T>>& newPoints);
        KDTree(const KDTree<T, Dim>& other);
        KDTree const &operator=(const KDTree<T, Dim>& rhs);
        ~KDTree();
        LidarPoint<T> findNearestNeighbor(const LidarPoint<T>& query) const;

    private:

        struct KDTreeNode {
            LidarPoint<T> point;
            KDTreeNode* left;
            KDTreeNode* right;
            KDTreeNode() : point(), left(NULL), right(NULL) {}
            KDTreeNode(const LidarPoint<T> &point) : point(point), left(NULL), right(NULL) {}
        };

        double euclideanDistanceSqrd(const LidarPoint<T> &first, const LidarPoint<T> &second) const;
        KDTreeNode* KDTreeRecursiveHelper(vector<LidarPoint<T>>& newPoints, int dim);
        LidarPoint<T> select(vector<LidarPoint<T>>& list, int left, int right, int k, int dim);
        int partition(vector<LidarPoint<T>>& list, int left, int right, int pivotIdx, int dim);
        void swap(LidarPoint<T>& first, LidarPoint<T>& second);
        KDTreeNode* dfs(KDTreeNode* node, KDTreeNode* tmp_bn, const LidarPoint<T>& query, int dim) const;
        bool spInRadius(const LidarPoint<T>& pt, const LidarPoint<T>& query, int dim, double min_distance) const;
    
    public:

    private:
        KDTreeNode* root_;
        size_t size_;
        KDTreeNode* best_node_;
        double min_distance_;

};