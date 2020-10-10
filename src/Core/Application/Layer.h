#pragma once

#include <string>

#include "DeltaTime.h"

namespace Serum {
    class Layer {
    public:
        explicit Layer(std::string name = "Layer");
        virtual ~Layer() = default;

        virtual void OnCreate() {}
        virtual void OnDestroy() {}

        virtual void OnUpdate(DeltaTime dt) {}

        std::string GetLayerName() { return layerName; }
    protected:
        std::string layerName;
    };
}