#pragma once

#include "Pattern.hpp"

class PatternGosperGliderGun : public Pattern
{
  public:
    virtual std::uint8_t getSizeX() const override { return 36; }
    virtual std::uint8_t getSizeY() const override { return 9; }
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override;
};