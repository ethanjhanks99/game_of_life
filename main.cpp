#include "LifeSimulator.hpp"
#include "PatternAcorn.hpp"
#include "PatternBlinker.hpp"
#include "PatternBlock.hpp"
#include "PatternGlider.hpp"
#include "PatternGosperGliderGun.hpp"
#include "PatternPulsar.hpp"
#include "RendererConsole.hpp"
#include "rlutil.h"

#include <chrono>
#include <thread>

int main()
{
    const std::uint8_t width = static_cast<std::uint8_t>(rlutil::tcols());
    const std::uint8_t height = static_cast<std::uint8_t>(rlutil::trows());

    RendererConsole renderer(width, height);

    const int numSteps = 50;

    LifeSimulator acornSim(width, height);
    acornSim.insertPattern(PatternAcorn(), 2, 2);

    std::cout << "Acorn pattern:" << std::endl;
    for (int step = 0; step < numSteps; ++step)
    {
        if (step == 0)
            rlutil::cls();
        renderer.render(acornSim);
        acornSim.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    LifeSimulator blinkerSim(width, height);
    blinkerSim.insertPattern(PatternBlinker(), 2, 2);

    std::cout << "Blinker pattern:" << std::endl;
    for (int step = 0; step < numSteps; ++step)
    {
        if (step == 0)
            rlutil::cls();
        renderer.render(blinkerSim);
        blinkerSim.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    LifeSimulator blockSim(width, height);
    blockSim.insertPattern(PatternBlock(), width / 2, height / 2);

    std::cout << "Block pattern:" << std::endl;
    for (int step = 0; step < numSteps; ++step)
    {
        if (step == 0)
            rlutil::cls();
        renderer.render(blockSim);
        blockSim.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    LifeSimulator gliderSim(width, height);
    gliderSim.insertPattern(PatternGlider(), 2, 2);

    std::cout << "Glider pattern:" << std::endl;
    for (int step = 0; step < numSteps; ++step)
    {
        if (step == 0)
            rlutil::cls();
        renderer.render(gliderSim);
        gliderSim.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    LifeSimulator gosperGliderGunSim(width, height);
    gosperGliderGunSim.insertPattern(PatternGosperGliderGun(), 2, 2);

    std::cout << "Gosper Glider Gun pattern:" << std::endl;
    for (int step = 0; step < numSteps; ++step)
    {
        if (step == 0)
            rlutil::cls();
        renderer.render(gosperGliderGunSim);
        gosperGliderGunSim.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    LifeSimulator pulsarSim(width, height);
    pulsarSim.insertPattern(PatternPulsar(), 2, 2);

    std::cout << "Pulsar pattern:" << std::endl;
    for (int step = 0; step < numSteps; ++step)
    {
        if (step == 0)
            rlutil::cls();
        renderer.render(pulsarSim);
        pulsarSim.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}