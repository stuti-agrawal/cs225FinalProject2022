#include "KDTree.h"

#include <utility>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;


// template <typename T, int Dim>
bool KDTree::smallerDimVal(const LidarPoint& first,
                                const LidarPoint& second, int curDim) const {
    /**
     * @todo Implement this function!
     */
    if (first[curDim] == second[curDim]) return (first < second);

    return (first[curDim] < second[curDim]);
}

// template <typename T, int Dim>
bool KDTree::shouldReplace(const LidarPoint& target,
                                const LidarPoint& currentBest,
                                const LidarPoint& potential) const {
    /**
     * @todo Implement this function!
     */
     // check if distance b/w target and potential is less than distance between target and currentbest.
     // calculate euclidean distances for both pairs
    double query_distsqrd = euclideanDistanceSqrd(target, potential);
    double cbest_distsqrd = euclideanDistanceSqrd(target, currentBest);
    if (query_distsqrd==cbest_distsqrd) return (potential < currentBest);
    return (query_distsqrd < cbest_distsqrd);
}

// template <typename T, int Dim>
KDTree::KDTree(const vector<LidarPoint>& newPoints) {
    /**
     * @todo Implement this function!
     */
     vector<LidarPoint> points = newPoints;
     root_ = KDTreeRecursiveHelper(points, 0);
}
KDTree::KDTree(const PointCloud& cloud) {
    /**
     * @todo Implement this function!
     */
     vector<LidarPoint> points = cloud.cloud();
     root_ = KDTreeRecursiveHelper(points, 0);
}

// template <typename T, int Dim>
typename KDTree::KDTreeNode* KDTree::KDTreeRecursiveHelper(vector<LidarPoint>& newPoints, int dim) {
  //find median index i.e. we want to find the m=⌊(a+b)/2⌋'th smallest element
  if (dim == (int) Dim) dim = 0;

  if (newPoints.size() == 0) {
    return NULL;
  }
  if (newPoints.size() == 1) {
    return new KDTreeNode(newPoints[0]);
  }

  int a = 0;
  int b = newPoints.size()-1;

  int m = floor((a+b)/2); // this is where the median should go.
  // std::cout << m << std::endl;
  select(newPoints, a, b, m, dim); // this should satify the constraints of step 2 as well.

  //TODO: migrate to diff function whenever
  // vector<Point<Dim>>::const_iterator left_begin = newPoints.begin();
  // vector<Point<Dim>>::const_iterator left_end = newPoints.begin() + med_idx; //TODO: i'd be worried about this

  // vector<Point<Dim>>::const_iterator right_begin = newPoints.begin()+med_idx+1;
  // vector<Point<Dim>>::const_iterator right_end = newPoints.end();

  vector<LidarPoint> leftPoints(newPoints.begin(), newPoints.begin() + m);
  vector<LidarPoint> rightPoints(newPoints.begin()+m+1, newPoints.end());

  KDTreeNode* root = new KDTreeNode(newPoints[m]);
  dim++;
  root->left = KDTreeRecursiveHelper(leftPoints, dim);
  root->right = KDTreeRecursiveHelper(rightPoints, dim);
  return root;
}

// template <typename T, int Dim>
KDTree::KDTree(const KDTree& other) {
  /**
   * @todo Implement this function!
   */
}

// template <typename T, int Dim>
const KDTree& KDTree::operator=(const KDTree& rhs) {
  /**
   * @todo Implement this function!
   */

  return *this;
}

// template <typename T, int Dim>
KDTree::~KDTree() {
  /**
   * @todo Implement this function!
   */
}

// template <typename T, int Dim>
LidarPoint KDTree::findNearestNeighbor(const LidarPoint& query) const
{
    /**
     * @todo Implement this function!
     */
    KDTreeNode* curr = root_;
    KDTreeNode* best_node = dfs(curr, curr, query, 0);

    return best_node->point;
}


// helpers
// returns the point closest
// template <typename T, int Dim>
typename KDTree::KDTreeNode* KDTree::dfs(KDTreeNode* node, KDTreeNode* prev_bn, const LidarPoint& query, int dim) const {
  if (dim == Dim) dim = 0;
  KDTreeNode* best_node = prev_bn;
  
  int dim_increment = dim + 1;
  bool left_accessed = false; // 0 for left subtree, 1 for right subtree
  
   // keep track of which dimension we are in i.e. which n mod k level of tree we're at
  if (node == NULL) return prev_bn; // source of memleak?
  
  if (smallerDimVal(query, node->point, dim)) {
    std::cout << "go left" << std::endl;
    left_accessed = true;
    best_node = dfs(node->left, best_node, query, dim_increment);
  } else if (query[dim] > node->point[dim]) {
    best_node = dfs(node->right, best_node, query, dim_increment);
  }
  

  // leaf node
  if (node->right == NULL && node->left == NULL) {
    if (shouldReplace(query, best_node->point, node->point)) best_node = node; 
    // min_distance_ = sqrt(euclideanDistanceSqrd(query, best_node_->point));
    return best_node;
  }

  // non-leaf
  if (shouldReplace(query, best_node->point, node->point)) {
    best_node = node; // if it is closer than the leaf, check for distance
    // double min_distance = sqrt(euclideanDistanceSqrd(query, best_node->point));
  }
    
  double min_distance = sqrt(euclideanDistanceSqrd(query, best_node->point));
  if (spInRadius(node->point, query, dim, min_distance)) {
    std::cout << "spInRadius" << std::endl;
    if (left_accessed) {
      // go to right subtree
      best_node = dfs(node->right, best_node, query, dim_increment);
    } else {
      // go to left subtree
      best_node = dfs(node->left, best_node, query, dim_increment);
    }
    //call dfs on other subtree
    
  }
  return best_node;
}


// template <typename T, int Dim>
LidarPoint KDTree::select(vector<LidarPoint>& list, int left, int right, int k, int dim) {
  if (left == right) return list[left];
  int pivotIdx = left + floor(rand() % (right - left + 1));
  pivotIdx = partition(list, left, right, pivotIdx, dim);
  if (k == pivotIdx) {
    return list[k];
  } else if (k < pivotIdx) {
    return select(list, left, pivotIdx-1, k, dim);
  } else {
    return select(list, pivotIdx+1, right, k, dim);
  }
}

//TODO: check whether vector copying will screw up runtime
// template <typename T, int Dim>
int KDTree::partition(vector<LidarPoint>& list, int left, int right, int pivotIdx, int dim) {
  LidarPoint pivotVal = list[pivotIdx];
  swap(list[pivotIdx], list[right]);
  int storeIdx = left;
  for (int i = left; i < right; i++) {
    if (smallerDimVal(list[i], pivotVal, dim)) {
      swap(list[storeIdx], list[i]);
      storeIdx++;
    }
  }
  swap(list[right], list[storeIdx]);
  return storeIdx;
}

// template <typename T, int Dim>
void KDTree::swap(LidarPoint& first, LidarPoint& second) {
  LidarPoint temp(first);
  first = second;
  second = temp;
}

// template <typename T, int Dim>
double KDTree::euclideanDistanceSqrd(const LidarPoint &first, const LidarPoint &second) const {
  double dist_sqrd = 0.0;
  int idx = 0;
  for (int idx = 0; idx < Dim; idx++) {
    dist_sqrd += pow(first[idx]-second[idx], 2);
  }
  return dist_sqrd;
}

// template <typename T, int Dim>
bool KDTree::spInRadius(const LidarPoint& pt, const LidarPoint& query, int dim, double min_distance) const {
  if (abs(pt[dim]-query[dim]) <= min_distance) return true;
  return false;
}