#pragma once

#include <CS2/Panorama/CPanel2D.h>

template <typename Context>
struct PanoramaUiPanel;

template <typename HookContext>
struct ClientPanel {
    ClientPanel(HookContext& hookContext, cs2::CPanel2D* panel) noexcept
        : hookContext{hookContext}
        , panel{panel}
    {
    }

    [[nodiscard]] decltype(auto) uiPanel() const noexcept
    {
        return hookContext.template make<PanoramaUiPanel>(panel->uiPanel);
    }

    template <template <typename> typename T>
    [[nodiscard]] decltype(auto) as() const noexcept
    {
        return hookContext.template make<T>(panel);
    }

private:
    HookContext& hookContext;
    cs2::CPanel2D* panel;
};
