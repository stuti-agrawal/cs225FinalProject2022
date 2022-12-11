#include "discreteGrid.h"


/**
 * Default iterator constructor.
 */
discreteGrid::Iterator::Iterator() {
  /** @todo [Part 1] */
  discreteGrid_ = nullptr;
}

discreteGrid::Iterator::Iterator(discreteGrid* discreteGrid, LidarPoint startPoint, std::vector<std::vector<LidarPoint>> grid) {
  /** @todo [Part 1] */
  discreteGrid_ = discreteGrid;
  start_ = startPoint;
  currentPoint_ = start_;
  grid_ = grid;
}


/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
discreteGrid::Iterator & discreteGrid::Iterator::operator++() {
  /** @todo [Part 1] */
  // Add current and neighbours
  discreteGrid_->visited_[currentPoint_[0]][currentPoint_[1]] = true;

  if (currentPoint_[0] < discreteGrid_->width_ - 1) discreteGrid_->add(LidarPoint(currentPoint_[0] + 1, currentPoint_[1], 0.0));
  if (currentPoint_[1] < discreteGrid_->height_ - 1) discreteGrid_->add(LidarPoint(currentPoint_[0], currentPoint_[1] + 1, 0.0));
  if (currentPoint_[0] >= 1) discreteGrid_->add(LidarPoint(currentPoint_[0] - 1, currentPoint_[1], 0.0));
  if (currentPoint_[1] >= 1) discreteGrid_->add(LidarPoint(currentPoint_[0], currentPoint_[1] - 1, 0.0));
  LidarPoint pointPop = discreteGrid_->pop();
  while (!discreteGrid_->empty()) {
    pointPop = discreteGrid_->pop();
  }
  if (!discreteGrid_->empty()) {
    currentPoint_ = pointPop;
  }
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the discreteGrid.
 */
LidarPoint discreteGrid::Iterator::operator*() {
  /** @todo [Part 1] */
  return currentPoint_;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool discreteGrid::Iterator::operator!=(const discreteGrid::Iterator &other) {
  /** @todo [Part 1] */
  bool thisEmpty = false; 
  bool otherEmpty = false;

  if (discreteGrid_ == NULL) { thisEmpty = true; }
  if (other.discreteGrid_ == NULL) { otherEmpty = true; }

  if (!thisEmpty)  { thisEmpty = discreteGrid_->empty(); }
  if (!otherEmpty) { otherEmpty = other.discreteGrid_->empty(); }

  if (thisEmpty && otherEmpty) return false; // both empty then the discreteGrids are equal, return true
  else if ((!thisEmpty)&&(!otherEmpty)) return (discreteGrid_ != other.discreteGrid_); //both not empty then compare the traversals
  else return true; // one is empty while the other is not, return true
}


BFS::BFS(const LidarPoint& startPoint, const std::vector<std::vector<LidarPoint>>& grid) {  
  BFS::grid_ = grid;
  BFS::startPoint_ = startPoint;
}


discreteGrid::Iterator BFS::begin() {
  return discreteGrid::Iterator(this, startPoint_, grid_);
}

discreteGrid::Iterator BFS::end() {
  return discreteGrid::Iterator();
}


void BFS::add(const LidarPoint& point) {
  BFS_queue_.push(point);
}

LidarPoint BFS::pop() {
  LidarPoint firstPoint = BFS_queue_.front();
  BFS_queue_.pop();
  return firstPoint;
}

LidarPoint BFS::peek() const {
  return BFS_queue_.front();
}

bool BFS::empty() const {
  return BFS_queue_.empty();
}


DFS::DFS(const LidarPoint& startPoint, const std::vector<std::vector<LidarPoint>>& grid) {  
  grid_  = grid;
  startPoint_ = startPoint;
}


discreteGrid::Iterator DFS::begin() {
  return discreteGrid::Iterator(this, startPoint_, grid_);
}

discreteGrid::Iterator DFS::end() {
  return discreteGrid::Iterator();
}


void DFS::add(const LidarPoint& point) {
  DFS_stack_.push(point);
}

LidarPoint DFS::pop() {
  LidarPoint topPoint = DFS_stack_.top();
  DFS_stack_.pop();
  return topPoint;
}

LidarPoint DFS::peek() const {
  return DFS_stack_.top();
}

bool DFS::empty() const {
  return DFS_stack_.empty();
}

// bool IDDFS(src, target, max_depth)
//     for limit from 0 to max_depth
//        if DLS(src, target, limit) == true
//            return true
//     return false   

// bool DLS(src, target, limit)
//     if (src == target)
//         return true;

//     // If reached the maximum depth, 
//     // stop recursing.
//     if (limit <= 0)
//         return false;   

//     foreach adjacent i of src
//         if DLS(i, target, limit?1) 
//             return true

//     return false