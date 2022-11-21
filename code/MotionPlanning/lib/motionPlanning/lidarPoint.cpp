#include "lidarPoint.h"

template <typename T>
LidarPoint::LidarPoint() : x_(0.0), y_(0.0), z_(0.0), r_(0,0) {}

template <typename T>
LidarPoint::LidarPoint(T x, T y, T z): x_(x), y_(y), z_(z), r_(1.0) {}

template <typename T>
LidarPoint::LidarPoint(T x, T y, T z, T r): x_(x), y_(y), z_(z), r_(r) {}

template <typename T>
bool LidarPoint::operator==(LidarPoint const & other) const {
    return (x_ == other.x_ && y_ == other.y_ && z_ == other.z_ && r_ == other.r_)
}

template <typename T>
bool LidarPoint::operator!=(LidarPoint const & other) const {
    return !(*this == other);
}