// #include "discreteGrid.h"


/**
 * Default iterator constructor.
 */
discreteGrid::Iterator::Iterator() {
  /** @todo [Part 1] */
  discreteGrid_ = nullptr;
}

discreteGrid::Iterator::Iterator(discreteGrid* discreteGrid, LidarPoint startPoint,std::vector<std::vector<LidarPoint> grid) : discreteGrid() {
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
  discreteGrid->visited_[currentPoint_[0]][currentPoint_[1]] = true;

  if (currentPoint_[0] < discreteGrid->width_ - 1) discreteGrid->add(LidarPoint(currentPoint_[0] + 1, currentPoint_[1]));
  if (currentPoint_[1] < discreteGrid->height_ - 1) discreteGrid->add(LidarPoint(currentPoint_[0], currentPoint_[1] + 1));
  if (currentPoint_[0] >= 1) discreteGrid->add(LidarPoint(currentPoint_[0] - 1, currentPoint_[1]));
  if (currentPoint_[1] >= 1) discreteGrid->add(LidarPoint(currentPoint_[0], currentPoint_[1] - 1));
  LidarPoint pointPop = discreteGrid->pop();
  while (!discreteGrid->empty()) {
    pointPop = discreteGrid->pop();
  }
  if (!discreteGrid->empty()) {
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
  return currentPoint;
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
  if (!otherEmpty) { otherEmpty = other.discreteGrid->empty(); }

  if (thisEmpty && otherEmpty) return false; // both empty then the discreteGrids are equal, return true
  else if ((!thisEmpty)&&(!otherEmpty)) return (discreteGrid_ != other.discreteGrid_); //both not empty then compare the traversals
  else return true; // one is empty while the other is not, return true
}


BFS::BFS(const LidarPoint& startPoint, const std::vector<std::vector<LidarPoint>& grid) {  
  /** @todo [Part 1] */
  grid_ = grid;
  startPoint_ = startPoint;
}


// discreteGrid::Iterator BFS::begin() {
//   return discreteGrid::Iterator(this, start_, grid_);
// }

// discreteGrid::Iterator BFS::end() {
//   return discreteGrid::Iterator();
// }


void BFS::add(const LidarPoint& point) {
  BFS_queue_.push(point);
}

LidarPoint BFS::pop(); {
  LidarPoint firstPoint = BFS_queue_.front();
  BFS_queue_.pop();
  return firstPoint;
}

LidarPoint BFS::peek() const {
  return BFS_queue_.front();
}

// bool BFS::empty() const {
//   return BFS_queue_.empty();
// }


IDDFS::IDDFS(const LidarPoint& startPoint, const std::vector<std::vector<LidarPoint>& grid) {  
  /** @todo [Part 1] */
  grid_ = grid;
  startPoint_ = startPoint;
}


// discreteGrid::Iterator IDDFS::begin() {
//   return discreteGrid::Iterator(this, start_, grid_);
// }

// discreteGrid::Iterator IDDFS::end() {
//   return discreteGrid::Iterator();
// }


void IDDFS::add(const LidarPoint& point) {
  IDDFS_stack_.push(point);
}

LidarPoint IDDFS::pop(); {
  LidarPoint topPoint = IDDFS_stack_.top();
  IDDFS_stack_.pop();
  return topPoint;
}

LidarPoint IDDFS::peek() const {
  return IDDFS_stack_.top();
}

// bool IDDFS::empty() const {
//   return IDDFS_stack_.empty();
// }
