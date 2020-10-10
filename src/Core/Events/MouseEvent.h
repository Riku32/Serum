#pragma once

#include "Event.h"
#include "MouseCodes.h"

namespace Serum {
    struct MouseMovedEvent : public Event {
        MouseMovedEvent(const float x, const float y) : mouse_x(x), mouse_y(y) {}

        float GetX() const { return mouse_x; }
        float GetY() const { return mouse_y; }

        EVENT_CLASS_TYPE(MOUSE_MOVED)
        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)
    private:
        float mouse_x, mouse_y;
    };

    struct MouseScrolledEvent : public Event {
        MouseScrolledEvent(const float x, const float y) : x_offset(x), y_offset(y) {}

        float GetXOffset() const { return x_offset; }
        float GetYOffset() const { return y_offset; }

        EVENT_CLASS_TYPE(MOUSE_SCROLLED)
        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)
    private:
        float x_offset, y_offset;
    };

    struct MouseButtonEvent : public Event {
        MouseCode GetMouseButton() const { return button; }

        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT | EVENT_CATEGORY_MOUSE_BUTTON)
    protected:
        explicit MouseButtonEvent(const MouseCode button) : button(button) {}

        MouseCode button;
    };

    struct MouseButtonPressedEvent : public MouseButtonEvent {
        explicit MouseButtonPressedEvent(const MouseCode button) : MouseButtonEvent(button) {}

        EVENT_CLASS_TYPE(MOUSE_BUTTON_PRESSED)
    };

    struct MouseButtonReleasedEvent : public MouseButtonEvent {
        explicit MouseButtonReleasedEvent(const MouseCode button) : MouseButtonEvent(button) {}

        EVENT_CLASS_TYPE(MOUSE_BUTTON_RELEASED)
    };
}