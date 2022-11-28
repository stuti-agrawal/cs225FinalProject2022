#include "lidarPoint.h"
#include <vector>

const unsigned short Dimension = 3;
const unsigned int DefaultChunkSizeAsPointCount = 2000;

template <typename T>
class PointCloud {
public:
    PointCloud(unsigned int chunkSizeAsPointCount = DefaultChunkSizeAsPointCount);
    virtual ~PointCloud();
    const std::vector<LidarPoint<T>> cloud() const;
    unsigned long numberOfLidarPoints() const;
    bool pointExists(T x, T y, T z) const;
    bool addLidarPoint(T x, T y, T z, T r);
    const T* min() const;
    const T* max() const;
private:
    LidarPoint<T> accessPoint(T x, T y, T z) const;
public:

private:
    std::vector<LidarPoint<T>> cloud_;
    unsigned long pointCount_;
    T pointMin_[Dimension];
    T pointMax_[Dimension];