// #pragma once

// #include <vector>
// #include <iterator>
// #include <stack>
// #include <queue>
// #include "../lib/motionPlanning/lidarPoint.h"

// class discreteGrid {
// public:
//   /**
//    * A forward iterator through an ImageTraversal.
//    */
//   class Iterator : std::iterator<std::forward_iterator_tag, LidarPoint> {
//   public:
//     Iterator();
//     Iterator(discreteGrid* discreteGrid, LidarPoint point,  std::vector<std::vector<LidarPoint>> grid_);
//     Iterator & operator++();
//     LidarPoint operator*();
//     bool operator!=(const Iterator &other);

//   private:
//     discreteGrid* discreteGrid_;
//     LidarPoint currentPoint_;
//     LidarPoint start_;
//     std::vector<std::vector<LidarPoint>> grid_;
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
//   virtual void add(const LidarPoint &point) = 0;
//   /**
//    * Remove and return the next point of the traversal
//    */
//   virtual LidarPoint pop() = 0;
//   /**
//    * Return but not remove the next point of the traversal
//    */
//   virtual LidarPoint peek() const = 0;
//   /**
//    * To see if the traversal has no points left
//    */
//   virtual bool empty() const = 0;

// private:
//   bool isNotVisited(LidarPoint currPoint);
//   std::vector<std::vector<bool>> visited_;
//   int height_;
//   int width_;
// };


// class BFS : public discreteGrid {
// public:
//   BFS(const LidarPoint& startPoint, const std::vector<std::vector<LidarPoint>>& grid);

//   discreteGrid::Iterator begin();
//   discreteGrid::Iterator end();

//   void add(const LidarPoint& point);
//   LidarPoint pop();
//   LidarPoint peek() const;
//   bool empty() const;

// private:
//   std::queue<LidarPoint> BFS_queue_;
//   LidarPoint& startPoint_;
//   std::vector<std::vector<LidarPoint>>& grid_;
// };


// class DFS : public discreteGrid {
// public:
//   DFS(const LidarPoint& startPoint, const std::vector<std::vector<LidarPoint>>& grid);

//   discreteGrid::Iterator begin();
//   discreteGrid::Iterator end();

//   void add(const LidarPoint& point);
//   LidarPoint pop();
//   LidarPoint peek() const;
//   bool empty() const;

// private:
//   std::stack<LidarPoint> DFS_stack_;
//   LidarPoint& startPoint_;
//   std::vector<std::vector<LidarPoint>>& grid_;
// };