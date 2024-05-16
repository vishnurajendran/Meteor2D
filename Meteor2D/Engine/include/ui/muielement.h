#pragma once
#include <meteorutils/suirect.h>
#include <entities/entity.h>

namespace meteor{
    class MUIElement : public MEntity{
    private:
        SUIRect uiRect;
        virtual void Draw();
        virtual void Build(); 
    };
}