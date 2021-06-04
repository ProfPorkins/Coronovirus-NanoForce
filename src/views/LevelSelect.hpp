/*
Copyright (c) 2021 James Dean Mathias

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#pragma once

#include "MenuView.hpp"
#include "UIFramework/MenuItem.hpp"
#include "UIFramework/Text.hpp"
#include "services/Configuration.hpp"
#include "services/Content.hpp"

#include <cstdint>
#include <vector>

namespace views
{
    // --------------------------------------------------------------
    //
    // The player chooses from the training or patient levels from here
    //
    // --------------------------------------------------------------
    class LevelSelect : public MenuView
    {
      public:
        using MenuView::MenuView;
        virtual bool start() override;
        virtual void stop() override;

        virtual ViewState update(const std::chrono::microseconds elapsedTime, const std::chrono::system_clock::time_point now) override;
        virtual void render(sf::RenderTarget& renderTarget, const std::chrono::microseconds elapsedTime) override;

      private:
        bool m_initialized{ false };
        ViewState m_nextState{ ViewState::LevelSelect };
        std::uint32_t m_mouseMovedHandlerId{ 0 };
        std::uint32_t m_mouseReleasedHandlerId{ 0 };

        ui::Text m_titleTraining{ 0.0f, 0.0f, "Training", Content::get<sf::Font>(content::KEY_FONT_LEVEL_SELECT), sf::Color(51, 102, 255), sf::Color::Black, Configuration::get<std::uint8_t>(config::FONT_LEVEL_SELECT_TITLE_SIZE) };
        ui::Text m_titlePatient{ 0.0f, 0.0f, "Patient Simulations", Content::get<sf::Font>(content::KEY_FONT_LEVEL_SELECT), sf::Color(51, 102, 255), sf::Color::Black, Configuration::get<std::uint8_t>(config::FONT_LEVEL_SELECT_TITLE_SIZE) };

        std::vector<std::shared_ptr<ui::MenuItem>> m_menuItems;
        std::int8_t m_activeMenuItem{ 0 };

        void onMouseMoved(math::Point2f point, const std::chrono::microseconds elapsedTime);
        void onMouseReleased(sf::Mouse::Button button, math::Point2f point, const std::chrono::microseconds elapsedTime);
    };
} // namespace views
