#pragma once

#include "Pattern.hpp"

class PatternAcorn : public Pattern
{
  public:
    virtual std::uint8_t getSizeX() const override { return 7; }
    virtual std::uint8_t getSizeY() const override { return 3; }
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override;
};