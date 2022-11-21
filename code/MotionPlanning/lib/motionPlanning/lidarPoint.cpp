#include "lidarPoint.h"

LidarPoint::LidarPoint() : x_(0.0), y_(0.0), z_(0.0), r_(0,0) {}

LidarPoint::LidarPoint(double x, double y, double z): x_(x), y_(y), z_(z), r_(1.0) {}

LidarPoint::LidarPoint(double x, double y, double z, double r): x_(x), y_(y), z_(z), r_(r) {}