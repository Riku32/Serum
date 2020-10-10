#include "Layer.h"

#include <utility>

namespace Serum {
    Layer::Layer(std::string name) : layerName(std::move(name)) {}
}
