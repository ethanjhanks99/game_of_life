#include "PatternBlock.hpp"

#include <vector>

bool PatternBlock::getCell(std::uint8_t x, std::uint8_t y) const
{
    const std::vector<std::vector<bool>> blockPattern = {
        { 1, 1 },
        { 1, 1 }
    };
    return blockPattern[y][x];
}
