#include "pointCloud.h"

template <typename T>
class SceneObject : public PointCloud<T> {
    public:
        SceneObject(PointCloud<LidarPoint<T>>, T centerX, T centerY, T centerZ);
        const T* getCenter();        
    public:
    private:
        T centerX_;
        T centerY_;
        T centerZ_;
};