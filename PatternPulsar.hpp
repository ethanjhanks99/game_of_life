#pragma once

#include "Pattern.hpp"

class PatternPulsar : public Pattern
{
  public:
    virtual std::uint8_t getSizeX() const override { return 13; }
    virtual std::uint8_t getSizeY() const override { return 13; }
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override;
};