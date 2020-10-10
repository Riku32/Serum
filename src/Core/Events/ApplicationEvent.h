#pragma once

#include "Event.h"

namespace Serum {
    struct WindowResizeEvent : public Event {
        WindowResizeEvent(float width, float height) : width(width), height(height) {}

        float GetWidth() const { return width; }
        float GetHeight() const { return height; }

        EVENT_CLASS_TYPE(WINDOW_RESIZE)
        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
    private:
        float width, height;
    };

    struct WindowCloseEvent : public Event {
        WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(WINDOW_CLOSE)
        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
    };

    struct AppTickEvent : Event {
        AppTickEvent() = default;

        EVENT_CLASS_TYPE(APP_TICK)
        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
    };

    struct AppUpdateEvent : public Event {
        AppUpdateEvent() = default;

        EVENT_CLASS_TYPE(APP_UPDATE)
        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
    };

    struct AppRenderEvent : public Event {
        AppRenderEvent() = default;

        EVENT_CLASS_TYPE(APP_RENDER)
        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
    };
}