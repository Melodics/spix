/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include "ClickOnItem.h"

#include <Scene/Scene.h>

namespace spix {
namespace cmd {

ClickOnItem::ClickOnItem(ItemPosition path, MouseButton mouseButton)
: m_position(std::move(path))
, m_mouseButton(mouseButton)
{
}

void ClickOnItem::execute(CommandEnvironment& env)
{
    auto path = m_position.itemPath();
    auto item = env.scene().itemAtPath(path);

    if (!item) {
        env.state().reportError("ClickOnItem: Item not found: " + path.string());
        return;
    }

    auto size = item->size();
    auto mousePoint = m_position.positionForItemSize(size);
#ifdef SPIX_USE_QTEST_EVENTS
    env.scene().events().mouseClick(item.get(), mousePoint, m_mouseButton);
#else
    env.scene().events().mouseDown(item.get(), mousePoint, m_mouseButton);
    env.scene().events().mouseUp(item.get(), mousePoint, m_mouseButton);
#endif
}

} // namespace cmd
} // namespace spix
