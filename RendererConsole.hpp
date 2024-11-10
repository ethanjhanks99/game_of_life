#pragma once

#include "Renderer.hpp"

#include <iostream>

class RendererConsole : public Renderer
{
  public:
    RendererConsole(std::uint8_t sizeX, std::uint8_t sizeY);

    void render(const LifeSimulator& simulation) override;

  private:
    std::vector<std::vector<bool>> m_previousState;
    bool m_firstRender;
};