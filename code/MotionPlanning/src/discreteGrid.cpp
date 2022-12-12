// #include "discreteGrid.h"
// #include <limits>

// std::pair<int, int> PAIR_NULL = std::pair<int, int>(std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
// /**
//  * Default iterator constructor.
//  */
// discreteGrid::Iterator::Iterator() {
//   /** @todo [Part 1] */
//   discreteGrid_ = nullptr;
// }

// discreteGrid::Iterator::Iterator(discreteGrid* discreteGrid, LidarPoint startPoint, std::vector<std::vector<LidarPoint>> grid) {
//   /** @todo [Part 1] */
//   discreteGrid_ = discreteGrid;
//   start_ = startPoint;
//   currentPoint_ = start_;
//   grid_ = grid;
// }


// /**
//  * Iterator increment opreator.
//  *
//  * Advances the traversal of the image.
//  */
// discreteGrid::Iterator & discreteGrid::Iterator::operator++() {
//   /** @todo [Part 1] */
//   // Add current and neighbours
//   discreteGrid_->visited_[currentPoint_[0]][currentPoint_[1]] = true;

//   if (currentPoint_[0] < discreteGrid_->width_ - 1) discreteGrid_->add(LidarPoint(currentPoint_[0] + 1, currentPoint_[1], 0.0));
//   if (currentPoint_[1] < discreteGrid_->height_ - 1) discreteGrid_->add(LidarPoint(currentPoint_[0], currentPoint_[1] + 1, 0.0));
//   if (currentPoint_[0] >= 1) discreteGrid_->add(LidarPoint(currentPoint_[0] - 1, currentPoint_[1], 0.0));
//   if (currentPoint_[1] >= 1) discreteGrid_->add(LidarPoint(currentPoint_[0], currentPoint_[1] - 1, 0.0));
//   LidarPoint pointPop = discreteGrid_->pop();
//   while (!discreteGrid_->empty()) {
//     pointPop = discreteGrid_->pop();
//   }
//   if (!discreteGrid_->empty()) {
//     currentPoint_ = pointPop;
//   }
//   return *this;
// }

// /**
//  * Iterator accessor opreator.
//  *
//  * Accesses the current Point in the discreteGrid.
//  */
// LidarPoint discreteGrid::Iterator::operator*() {
//   /** @todo [Part 1] */
//   return currentPoint_;
// }

// /**
//  * Iterator inequality operator.
//  *
//  * Determines if two iterators are not equal.
//  */
// bool discreteGrid::Iterator::operator!=(const discreteGrid::Iterator &other) {
//   /** @todo [Part 1] */
//   bool thisEmpty = false; 
//   bool otherEmpty = false;

//   if (discreteGrid_ == NULL) { thisEmpty = true; }
//   if (other.discreteGrid_ == NULL) { otherEmpty = true; }

//   if (!thisEmpty)  { thisEmpty = discreteGrid_->empty(); }
//   if (!otherEmpty) { otherEmpty = other.discreteGrid_->empty(); }

//   if (thisEmpty && otherEmpty) return false; // both empty then the discreteGrids are equal, return true
//   else if ((!thisEmpty)&&(!otherEmpty)) return (discreteGrid_ != other.discreteGrid_); //both not empty then compare the traversals
//   else return true; // one is empty while the other is not, return true
// }


// BFS::BFS(const LidarPoint& startPoint, const std::vector<std::vector<LidarPoint>>& grid) {  
//   grid_ = grid;
//   startPoint_ = startPoint;
// }


// discreteGrid::Iterator BFS::begin() {
//   return discreteGrid::Iterator(this, startPoint_, grid_);
// }

// discreteGrid::Iterator BFS::end() {
//   return discreteGrid::Iterator();
// }


// void BFS::add(const LidarPoint& point) {
//   BFS_queue_.push(point);
// }

// LidarPoint BFS::pop() {
//   LidarPoint firstPoint = BFS_queue_.front();
//   BFS_queue_.pop();
//   return firstPoint;
// }

// LidarPoint BFS::peek() const {
//   return BFS_queue_.front();
// }

// bool BFS::empty() const {
//   return BFS_queue_.empty();
// }


// DFS::DFS(const LidarPoint& startPoint, const std::vector<std::vector<LidarPoint>>& grid) {  
//   grid_  = grid;
//   startPoint_ = startPoint;
// }


// discreteGrid::Iterator DFS::begin() {
//   return discreteGrid::Iterator(this, startPoint_, grid_);
// }

// discreteGrid::Iterator DFS::end() {
//   return discreteGrid::Iterator();
// }


// void DFS::add(const LidarPoint& point) {
//   DFS_stack_.push(point);
// }

// LidarPoint DFS::pop() {
//   LidarPoint topPoint = DFS_stack_.top();
//   DFS_stack_.pop();
//   return topPoint;
// }

// LidarPoint DFS::peek() const {
//   return DFS_stack_.top();
// }

// bool DFS::empty() const {
//   return DFS_stack_.empty();
// }


// // Utility DFS function -- returns DFS Path if it exists, -1 if not exists
// std::vector<std::pair<int, int>> dfs_util(std::vector<std::pair<int, int>> path, std::pair<int, int> target, std::vector<std::vector<int>> &grid, int depth)
// {
//     std::pair<int, int> curr_cell = path.back();
//     if (curr_cell == target)
//         return path;
//     if (depth <= 0)
//     {
//         std::vector<std::pair<int, int>> tmp;
//         tmp.push_back(PAIR_NULL);
//         return tmp;
//     }
//     std::vector<std::pair<int, int>> children;
//     if (curr_cell.first > 0 && grid[curr_cell.first-1][curr_cell.second]) children.push_back(std::make_pair(curr_cell.first-1, curr_cell.second));
//     if (curr_cell.second+1 < (int)grid.size() && grid[curr_cell.first][curr_cell.second+1]) children.push_back(std::make_pair(curr_cell.first, curr_cell.second+1));
//     if (curr_cell.first+1 < (int)grid[0].size() && grid[curr_cell.first+1][curr_cell.second]) children.push_back(std::make_pair(curr_cell.first+1, curr_cell.second));
//     if (curr_cell.second > 0 && grid[curr_cell.first][curr_cell.second-1]) children.push_back(std::make_pair(curr_cell.first, curr_cell.second-1));
//     for (auto neighbour : children)
//     {
//         std::vector<std::pair<int, int>> new_path = path;
//         new_path.push_back(neighbour);
//         std::vector<std::pair<int, int>> result = dfs_util(new_path, target, grid, depth - 1);
//         if (result.back() != PAIR_NULL)
//         {
//             return result;
//         }
//     }
//     children.clear();
//     std::vector<std::pair<int, int>> tmp;
//     tmp.push_back(PAIR_NULL);
//     return tmp;
// }

// // IDDFS Function -- returns IDDFS Path if it exists, -1 if not
// std::vector<std::pair<int, int>> iddfs(std::vector<std::vector<int>> &grid,std::pair<int, int> src,std::pair<int, int> target, int max_depth)
// {
//     std::vector<std::pair<int, int>> result;
//     max_depth++;
//     for (int depth = 0; depth < max_depth; depth++)
//     {
//         std::vector<std::pair<int, int>> path;
//         path.push_back(src);

//         result = dfs_util(path, target, grid, depth);

//         if (result.back() == PAIR_NULL || result.size() == 0)
//             continue;
//         int final_index = 0;
//         int idx_count = 0;
//         for (auto item : result)
//         {
//             if (item == src)
//                 final_index = std::max(final_index, idx_count);
//             idx_count++;
//         }
//         result = std::vector<std::pair<int, int>>(result.begin() + final_index, result.end());
//     }
//     return result;
// }
