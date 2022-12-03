// #pragma once

// #include "../lib/motionPlanning/lidarPoint.h"

// #include <vector>
// #include <iterator>
// #include <stack>
// #include <queue>


// class discreteGrid {
// public:
//   /**
//    * A forward iterator through an ImageTraversal.
//    */
//   class Iterator : std::iterator<std::forward_iterator_tag, LidarPoint<int>> {
//   public:
//     Iterator();
//     Iterator(discreteGrid* discreteGrid, LidarPoint<int> point,  std::vector<std::vector<LidarPoint<int>> grid_);
//     Iterator & operator++();
//     LidarPoint operator*();
//     bool operator!=(const Iterator &other);

//   private:
//     discreteGrid* discreteGrid_;
//     LidarPoint<int> currentPoint_;
//     LidarPoint<int> start_;
//     std::vector<std::vector<LidarPoint<int>> grid_;
//   };

//   /**
//    * The begining of an iterator
//    */
//   virtual Iterator begin() = 0;

//   /**
//    * The end of an iterator
//    */
//   virtual Iterator end() = 0;

//   /**
//    * Add new point to the traversal
//    */
//   virtual void add(const LidarPoint<int> & t) = 0;
//   /**
//    * Remove and return the next point of the traversal
//    */
//   virtual LidarPoint<int> pop() = 0;
//   /**
//    * Return but not remove the next point of the traversal
//    */
//   virtual LidarPoint<int> peek() const = 0;
//   /**
//    * To see if the traversal has no points left
//    */
//   virtual bool empty() const = 0;

// private:
//   bool isNotVisited(LidarPoint<int> currPoint);
//   std::vector<std::vector<bool>> visited_;
//   int height_;
//   int width_;
// };


// class BFS : public discreteGrid {
// public:
//   BFS(const LidarPoint<int>& startPoint, const std::vector<std::vector<LidarPoint<int>>& grid);

//   discreteGrid::Iterator begin();
//   discreteGrid::Iterator end();

//   void add(const LidarPoint<int>& point);
//   LidarPoint<int> pop();
//   LidarPoint<int> peek() const;
//   bool empty() const;

// private:
//   std::queue<LidarPoint<int>> BFS_queue_;
//   LidarPoint<int>& startPoint_;
//   const std::vector<std::vector<LidarPoint<int>>& grid_;
// };


// class IDDFS : public discreteGrid {
// public:
//   IDDFS(const LidarPoint<int>& startPoint, const std::vector<std::vector<LidarPoint<int>>& grid);

//   discreteGrid::Iterator begin();
//   discreteGrid::Iterator end();

//   void add(const LidarPoint<int>& point);
//   LidarPoint<int> pop();
//   LidarPoint<int> peek() const;
//   bool empty() const;

// private:
//   std::stack<LidarPoint<int>> DFS_stack_;
//   LidarPoint<int>& startPoint_;
//   const std::vector<std::vector<LidarPoint<int>>& grid_;
// };



