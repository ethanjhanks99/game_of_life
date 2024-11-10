#include "PatternGlider.hpp"

#include <vector>

bool PatternGlider::getCell(std::uint8_t x, std::uint8_t y) const
{
    const std::vector<std::vector<bool>> gliderPattern = {
        { 1, 0, 1 },
        { 0, 0, 1 },
        { 0, 1, 1 }
    };
    return gliderPattern[y][x];
}
