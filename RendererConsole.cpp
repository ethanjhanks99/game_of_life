#include "RendererConsole.hpp"

#include "rlutil.h"

RendererConsole::RendererConsole(std::uint8_t sizeX, std::uint8_t sizeY) :
    m_previousState(sizeY, std::vector<bool>(sizeX, false)), m_firstRender(true) {}

void RendererConsole::render(const LifeSimulator& simulation)
{
    std::uint8_t sizeX = simulation.getSizeX();
    std::uint8_t sizeY = simulation.getSizeY();

    if (m_firstRender)
    {
        rlutil::cls();
        rlutil::hidecursor();
        m_firstRender = false;
    }

    for (std::uint8_t y = 0; y < sizeY; ++y)
    {
        for (std::uint8_t x = 0; x < sizeX; ++x)
        {
            bool currentCell = simulation.getCell(x, y);
            bool previousCell = m_previousState[y][x];

            if (currentCell != previousCell)
            {
                rlutil::locate(x + 1, y + 1);

                if (currentCell)
                {
                    rlutil::setChar('O');
                }
                else
                {
                    rlutil::setChar(' ');
                }

                m_previousState[y][x] = currentCell;
            }
        }
    }

    rlutil::showcursor();
    std::cout << std::flush;
}
