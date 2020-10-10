#pragma once

#include "KeyCodes.h"
#include "Event.h"

namespace Serum {
    struct KeyEvent : public Event {
        KeyCode GetKeyCode() const { return key_code; }

        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_KEYBOARD | EVENT_CATEGORY_INPUT)
    protected:
        KeyEvent(const KeyCode keycode) : key_code(keycode) {}

        KeyCode key_code;
    };

    struct KeyPressedEvent : public KeyEvent {
        KeyPressedEvent(const KeyCode keycode, const int repeatCount) : KeyEvent(keycode), repeat_count(repeatCount) {}

        int GetRepeatCount() const { return repeat_count; }

        EVENT_CLASS_TYPE(KEY_PRESSED)
    private:
        int repeat_count;
    };

    struct KeyReleasedEvent : public KeyEvent {
        KeyReleasedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

        EVENT_CLASS_TYPE(KEY_RELEASED)
    };

    struct KeyTypedEvent : public KeyEvent {
        KeyTypedEvent(const KeyCode keycode): KeyEvent(keycode) {}

        EVENT_CLASS_TYPE(KEY_TYPED)
    };
}