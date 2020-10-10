#pragma once

namespace Serum {
    class DeltaTime {
    public:
        explicit DeltaTime(float time = 0) : time(time) {}

        explicit operator float() const { return time; }

        float GetSeconds() const { return time; }
        float GetMilliseconds() const { return time * 1000.0f; }
    private:
        float time;
    };
}