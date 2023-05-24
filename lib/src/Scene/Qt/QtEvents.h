/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#pragma once

#include <Scene/Events.h>

namespace spix {

class QtEvents : public Events {
public:
#ifdef SPIX_USE_QTEST_EVENTS
    void mouseClick(Item* item, Point loc, MouseButton button) override;
#endif
    void mouseDown(Item* item, Point loc, MouseButton button) override;
    void mouseUp(Item* item, Point loc, MouseButton button) override;
    void mouseMove(Item* item, Point loc) override;
    void stringInput(Item* item, const std::string& text) override;
    void keyPress(Item* item, int keyCode, KeyModifier mod) override;
    void keyRelease(Item* item, int keyCode, KeyModifier mod) override;
    void extMouseDrop(Item* item, Point loc, PasteboardContent& content) override;
    void quit() override;

private:
    /// Keep track of which buttons are currently pressed
    MouseButton m_pressedMouseButtons = MouseButtons::None;
};

} // namespace spix
