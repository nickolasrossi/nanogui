#if !defined(__PYTHON_H)
#define __PYTHON_H

#include <pybind/stl.h>
#include <pybind/operators.h>
#include <pybind/functional.h>
#include "py_doc.h"

#define D(...) DOC(nanogui, __VA_ARGS__ )

#define WIDGET_OVERLOADS(Parent) \
    bool mouseButtonEvent(const Vector2i &p, int button, bool down, int modifiers) { \
        PYBIND_OVERLOAD(bool, Parent, mouseButtonEvent, p, button, down, modifiers); \
    } \
    bool mouseMotionEvent(const Vector2i &p, const Vector2i &rel, int button, int modifiers) { \
        PYBIND_OVERLOAD(bool, Parent, mouseMotionEvent, p, rel, button, modifiers); \
    } \
    bool mouseDragEvent(const Vector2i &p, const Vector2i &rel, int button, int modifiers) { \
        PYBIND_OVERLOAD(bool, Parent, mouseDragEvent, p, rel, button, modifiers); \
    } \
    bool mouseEnterEvent(const Vector2i &p, bool enter) { \
        PYBIND_OVERLOAD(bool, Parent, mouseEnterEvent, p, enter); \
    } \
    bool scrollEvent(const Vector2i &p, const Vector2f &rel) { \
        PYBIND_OVERLOAD(bool, Parent, scrollEvent, p, rel); \
    } \
    bool focusEvent(bool focused) { \
        PYBIND_OVERLOAD(bool, Parent, focusEvent, focused); \
    } \
    bool keyboardEvent(int key, int scancode, int action, int modifiers) { \
        PYBIND_OVERLOAD(bool, Parent, keyboardEvent, key, scancode, action, modifiers); \
    } \
    bool keyboardCharacterEvent(unsigned int codepoint) { \
        PYBIND_OVERLOAD(bool, Parent, keyboardCharacterEvent, codepoint); \
    } \
    Vector2i preferredSize(NVGcontext *ctx) const { \
        PYBIND_OVERLOAD(Vector2i, Parent, preferredSize, ctx); \
    } \
    void performLayout(NVGcontext *ctx) { \
        PYBIND_OVERLOAD(void, Parent, performLayout, ctx); \
    } \
    void draw(NVGcontext *ctx) { \
        PYBIND_OVERLOAD(void, Parent, draw, ctx); \
    }

#define LAYOUT_OVERLOADS(Parent) \
    Vector2i preferredSize(NVGcontext *ctx, const Widget *widget) const { \
        PYBIND_OVERLOAD(Vector2i, Parent, preferredSize, ctx, widget); \
    } \
    void performLayout(NVGcontext *ctx, Widget *widget) const { \
        PYBIND_OVERLOAD(void, Parent, performLayout, ctx, widget); \
    }

#define SCREEN_OVERLOADS(Parent) \
    virtual void drawAll() { \
        PYBIND_OVERLOAD(void, Parent, drawAll); \
    } \
    virtual void drawContents() { \
        PYBIND_OVERLOAD(void, Parent, drawContents); \
    } \
    virtual void framebufferSizeChanged() { \
        PYBIND_OVERLOAD(void, Parent, framebufferSizeChanged); \
    } \
    virtual bool dropEvent(const std::vector<std::string> &filenames) { \
        PYBIND_OVERLOAD(bool, Parent, dropEvent, filenames); \
    }

#define DECLARE_LAYOUT(Name) \
    class Py##Name : public Name { \
    public: \
        using Name::Name; \
        LAYOUT_OVERLOADS(Name); \
    }

#define DECLARE_WIDGET(Name) \
    class Py##Name : public Name { \
    public: \
        using Name::Name; \
        WIDGET_OVERLOADS(Name); \
    }

#define DECLARE_SCREEN(Name) \
    class Py##Name : public Name { \
    public: \
        using Name::Name; \
        WIDGET_OVERLOADS(Name); \
        SCREEN_OVERLOADS(Name); \
    }

#endif /* __PYTHON_H */
