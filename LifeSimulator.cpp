#include "LifeSimulator.hpp"

#include "rlutil.h"

LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY) :
    m_sizeX(sizeX),
    m_sizeY(sizeY),
    m_currentState(sizeY, std::vector<bool>(sizeX, false))
{
}

void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY)
{
    for (std::uint8_t y = 0; y < pattern.getSizeY(); ++y)
    {
        for (std::uint8_t x = 0; x < pattern.getSizeX(); ++x)
        {
            if (startX + x < m_sizeX && startY + y < m_sizeY)
            {
                m_currentState[startY + y][startX + x] = pattern.getCell(x, y);
            }
        }
    }
}

void LifeSimulator::update()
{
    std::vector<std::vector<bool>> nextState = m_currentState;

    for (std::uint8_t y = 0; y < m_sizeY; ++y)
    {
        for (std::uint8_t x = 0; x < m_sizeX; ++x)
        {
            int liveNeighbors = countLiveNeighbors(x, y);

            if (m_currentState[y][x])
            {
                if (liveNeighbors < 2 || liveNeighbors > 3)
                {
                    nextState[y][x] = false;
                }
            }
            else
            {
                if (liveNeighbors == 3)
                {
                    nextState[y][x] = true;
                }
            }
        }
    }

    m_currentState = nextState;
}

bool LifeSimulator::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x >= m_sizeX || y >= m_sizeY)
        return false;
    return m_currentState[y][x];
}

int LifeSimulator::countLiveNeighbors(std::uint8_t x, std::uint8_t y)
{
    int liveCount = 0;
    for (int deltaY = -1; deltaY <= 1; ++deltaY)
    {
        for (int deltaX = -1; deltaX <= 1; ++deltaX)
        {
            if (deltaX == 0 && deltaY == 0)
                continue;

            int neighborX = x + deltaX;
            int neighborY = y + deltaY;

            if (neighborX >= 0 && neighborX < m_sizeX && neighborY >= 0 && neighborY < m_sizeY)
            {
                liveCount += m_currentState[neighborY][neighborX] ? 1 : 0;
            }
        }
    }
    return liveCount;
}
