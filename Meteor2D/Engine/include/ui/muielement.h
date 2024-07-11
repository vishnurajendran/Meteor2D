#pragma once
#include <meteorutils/suirect.h>
#include <entities/spatial.h>

namespace meteor{
    class MUIElement : public MSpatialEntity{
    private:
        SUIRect uiRect;
    protected:
        bool dirtyFlag;
    public:
        virtual void draw();
        virtual void build();
        inline bool isDirty() { return dirtyFlag; }
        inline bool markDirty() { dirtyFlag = true; }
        void onStart() override;
        void onUpdate(float deltaTime) override;
        void onExit() override;
    };
}