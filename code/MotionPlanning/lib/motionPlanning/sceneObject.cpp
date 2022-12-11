#include "sceneObject.h"

SceneObject::SceneObject(float cx, float cy, float cz, float l, float w, float h, float theta) {
    data_ = {cx, cy, cz, l, w, h, theta};
}

float SceneObject::operator[](int nSubscript) const {
    static int iErr = -1;

    if(nSubscript >= 0 && nSubscript < Dim)
        return data_[nSubscript];
    else {
        return iErr;
    }
}