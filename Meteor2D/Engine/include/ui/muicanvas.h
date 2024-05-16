#pragma once
#include <vector>
#include <entities/spatial.h>
#include <ui/muielement.h>

namespace meteor{
    class MUICanvas : public MSpatialEntity {
        private:
        std::vector<MUIElement> uiElements;
        void TryBuildingCanvas();
        void Draw();
        
        public:
        void onStart() override;
        void onUpdate(float deltaTime) override;
        void onExit() override;
    };
}