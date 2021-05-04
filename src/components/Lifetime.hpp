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

#include "Component.hpp"

#include <chrono>
#include <functional>

namespace components
{
    class Lifetime : public Component
    {
      public:
        Lifetime(std::chrono::microseconds lifetime) :
            m_lifetime(lifetime),
            m_endOfLife([]() {})
        {
        }
        Lifetime(std::chrono::microseconds lifetime, std::function<void()> endOfLife) :
            m_lifetime(lifetime),
            m_endOfLife(endOfLife)
        {
        }

        auto get() { return m_lifetime; }
        void update(std::chrono::microseconds elapsedTime) { m_lifetime -= elapsedTime; }
        bool isAlive() { return m_lifetime.count() > 0; }
        void endOfLife() { m_endOfLife(); }

      private:
        std::chrono::microseconds m_lifetime;
        std::function<void()> m_endOfLife;
    };
} // namespace components
