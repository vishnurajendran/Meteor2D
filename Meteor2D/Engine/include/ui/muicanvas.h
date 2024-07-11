#pragma once
#include <vector>
#include <2d/texrendercmd.h>
#include <entities/spatial.h>
#include <ui/muielement.h>
#include <pugixml/pugixml.hpp>

namespace meteor{
    class MUICanvas : public MSpatialEntity {
    private:
        MTexRenderCmd* command;
        std::vector<MUIElement> uiElements;
        void buildCanvas();
        void draw();
        void initialise();
    public:
        MUICanvas();
        MUICanvas(MSpatialEntity* parent);
        void onStart() override;
        void onUpdate(float deltaTime) override;
        void onExit() override;
    };
}