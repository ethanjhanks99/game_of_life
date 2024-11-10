#include "PatternAcorn.hpp"

#include <vector>

bool PatternAcorn::getCell(std::uint8_t x, std::uint8_t y) const
{
    const std::vector<std::vector<bool>> acornPattern = {
        { 0, 1, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0 },
        { 1, 1, 0, 0, 1, 1, 1 }
    };
    return acornPattern[y][x];
}
