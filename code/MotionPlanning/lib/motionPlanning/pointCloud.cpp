#include "pointCloud.h"
#include <limits>
#include <algorithm>

template <typename T>
PointCloud<T>::PointCloud(unsigned int chunkSizeAsPointCount)
  : pointCount_(0) {

    cloud_.reserve(chunkSizeAsPointCount);

    T min = std::numeric_limits<T>::min();
    T max = std::numeric_limits<T>::max();

    for (auto _ = Dimension; _--;) {
        pointMin_[_] = max;
        pointMax_[_] = min;
    }
}

template <typename T>
PointCloud<T>::~PointCloud() {
    delete[] cloud_;
}

template <typename T>
const std::vector<LidarPoint<T>> PointCloud<T>::cloud() const {
    return cloud_;
}

template <typename T>
unsigned long PointCloud<T>::numberOfLidarPoints() const {
    return pointCount_;
}

template <typename T>
bool PointCloud<T>::pointExists(T x, T y, T z) const {
    return (accessPoint(x, y, z) != NULL);
}

template <typename T>
bool PointCloud<T>::addLidarPoint(T x, T y, T z, T r) {
    if (pointExists(x, y, z)) {
        return false;
    }

    LidarPoint lP(x, y, z, r);
    cloud_.push_back(lP);
    
    T point[Dimension] = {x, y, z};
    for (auto _ = Dimension; _--;) {
        if (pointMin_[_] > point[_]) pointMin_[_] = point[_];
        if (pointMax_[_] < point[_]) pointMax_[_] = point[_];
    }

    pointCount_++;
    return true;
}

template <typename T>
const T* PointCloud<T>::min() const {
    return pointMin_;
}

template <typename T>
const T* PointCloud<T>::max() const {  
    return pointMax_;
}

template <typename T>
LidarPoint<T> PointCloud<T>::accessPoint(T x, T y, T z) const {

    std::for_each(cloud_.begin(), cloud_.end(), [x, y, z](const T& point) {
        if (point.x_ == x && point.y_ == y && point.z_ == z)
        {
            return point;
        }
    });
    return NULL;
}