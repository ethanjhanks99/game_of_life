#include "PatternBlinker.hpp"

#include <vector>

bool PatternBlinker::getCell(std::uint8_t x, std::uint8_t y) const
{
    const std::vector<std::vector<bool>> blinkerPattern = {
        { 1 },
        { 1 },
        { 1 }
    };
    return blinkerPattern[y][x];
}
