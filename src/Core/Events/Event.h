#pragma once

#include <string>

#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Serum {
    enum class EventType {
        NO_EVENT = 0,
        WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_FOCUS, WINDOW_UN_FOCUS, WINDOW_MOVED,
        KEY_PRESSED, KEY_RELEASED, KEY_TYPED,
        APP_TICK, APP_UPDATE, APP_RENDER,
        MOUSE_MOVED, MOUSE_SCROLLED, MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED
    };

    enum EventCategory
    {
        NO_EVENT_CATEGORY = 0,
        EVENT_CATEGORY_APPLICATION,
        EVENT_CATEGORY_INPUT,
        EVENT_CATEGORY_KEYBOARD,
        EVENT_CATEGORY_MOUSE,
        EVENT_CATEGORY_MOUSE_BUTTON,
    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    // Base event type
    struct Event {
        virtual ~Event() = default;

        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        bool IsInCategory(EventCategory category) const { return GetCategoryFlags() & category; }
    };

    struct EventDispatcher {
        explicit EventDispatcher(Event& event) : event(event) {}

        template<typename T, typename F>
        void Dispatch(const F& func) {
            if (event.GetEventType() == T::GetStaticType()) {
                func(static_cast<T &>(event));
            }
        }
    private:
        Event& event;
    };
}