// #include "discreteGrid.h"


// BFS::BFS(const LidarPoint<int>& startPoint, const std::vector<std::vector<LidarPoint<int>>& grid) {  
//   /** @todo [Part 1] */
//   grid_ = grid;
//   startPoint_ = startPoint;
// }


// discreteGrid::Iterator BFS::begin() {
//   return discreteGrid::Iterator(this, start_, grid_);
// }

// discreteGrid::Iterator BFS::end() {
//   return discreteGrid::Iterator();
// }


// void BFS::add(const LidarPoint<int>& point) {
//   BFS_queue_.push(point);
// }

// LidarPoint<int> BFS::pop(); {
//   LidarPoint<int> firstPoint = BFS_queue_.front();
//   BFS_queue_.pop();
//   return firstPoint;
// }

// LidarPoint<int> BFS::peek() const {
//   return BFS_queue_.front();
// }

// bool BFS::empty() const {
//   return BFS_queue_.empty();
// }


// IDDFS::IDDFS(const LidarPoint<int>& startPoint, const std::vector<std::vector<LidarPoint<int>>& grid) {  
//   /** @todo [Part 1] */
//   grid_ = grid;
//   startPoint_ = startPoint;
// }


// discreteGrid::Iterator IDDFS::begin() {
//   return discreteGrid::Iterator(this, start_, grid_);
// }

// discreteGrid::Iterator IDDFS::end() {
//   return discreteGrid::Iterator();
// }


// void IDDFS::add(const LidarPoint<int>& point) {
//   IDDFS_stack_.push(point);
// }

// LidarPoint<int> IDDFS::pop(); {
//   LidarPoint<int> topPoint = IDDFS_stack_.top();
//   IDDFS_stack_.pop();
//   return topPoint;
// }

// LidarPoint<int> IDDFS::peek() const {
//   return IDDFS_stack_.top();
// }

// bool IDDFS::empty() const {
//   return IDDFS_stack_.empty();
// }
