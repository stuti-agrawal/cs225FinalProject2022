#include "sceneObject.h"

template <typename T>
SceneObject<T>::SceneObject(PointCloud<LidarPoint<T>> cloud, T centerX, T centerY, T centerZ): centerX_(centerX), centerY_(centerY), centerZ_(centerZ) {
    this(cloud);
}

template <typename T>
const T* SceneObject<T>::getCenter() {
    T centerPoint[3] = {centerX_, centerX_, centerZ_};
    return centerPoint;
}   