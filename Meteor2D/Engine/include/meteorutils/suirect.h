#pragma once
#include <meteorutils/vector2d.h>

namespace meteor{
    struct  SUIRect {
    private:
        // local position
        SVector2 anchoredPosition;
        // normalised vector
        SVector2 pivot;
        // normalised vector
        SVector2 parentAnchor;
        SVector2 size;
    public:
       SVector2 getSize() const;
       SVector2 getAnchor() const;
       SVector2 getPivot() const;
       SVector2 getAnchoredPosition() const; 
       
       void setAnchor(SVector2 anchorPosition);
       void setPivot (SVector2 pivot);
       void setAnchoredPosition(SVector2 position);
       void setSize(SVector2 size);
    };
}