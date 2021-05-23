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

#include "entities/Entity.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

namespace renderers
{
    // --------------------------------------------------------------
    //
    // Some things are general enough this Sprite renderer is enough
    // to render them.
    //
    // --------------------------------------------------------------
    class Sprite
    {
      public:
        Sprite(std::shared_ptr<sf::Texture> texture);

        void render(entities::Entity& entity, sf::RenderTarget& renderTarget);

        template <typename T>
        void render(std::unordered_map<entities::Entity::IdType, std::shared_ptr<T>>& entities, sf::RenderTarget& renderTarget);

      private:
        std::shared_ptr<sf::Sprite> m_sprite;
    };

    template <typename T>
    void Sprite::render(std::unordered_map<entities::Entity::IdType, std::shared_ptr<T>>& entities, sf::RenderTarget& renderTarget)
    {
        for (auto&& [id, entity] : entities)
        {
            render(*entity, renderTarget);
        }
    }

} // namespace renderers
