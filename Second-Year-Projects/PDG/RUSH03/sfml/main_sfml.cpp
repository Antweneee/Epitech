/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-illyas.chihi
** File description:
** main
*/

#include "includes/Display.hpp"
#include "includes/sfml.hpp"
#include "includes/Display.hpp"

info_t *set()
{
    info_t *fill = new info_t;

    fill->Window.create(sf::VideoMode(1920, 1080), "MyGKrellm");
    fill->text.loadFromFile("sfml/assets/bg.jpg");
    fill->bg.setTexture(fill->text);
    fill->check1 = false;
    fill->check2 = false;
    fill->check3 = false;
    fill->check4 = false;
    return fill;
}

void draw(info_t *info, manip mem, manip core0, manip core1, manip core2, manip core3, manip core4, manip core5, manip core6, manip core7, IMonitorModule data, Display disp)
{
    info->Window.draw(info->bg);
    if (info->check1 == false) {
        mem.bar(&(info->Window), ((data.VirtualMem_used * 1000) / data.VirtualMem_tot), 60, 200, 1);
        info->Window.draw(mem.rect);
    }
    if (info->check2 == false) {
        core0.bar(&(info->Window), data.cpu0, 200, 430, 5);
        core1.bar(&(info->Window), data.cpu1, 200, 470, 5);
        core2.bar(&(info->Window), data.cpu2, 200, 510, 5);
        core3.bar(&(info->Window), data.cpu3, 200, 550, 5);
        core4.bar(&(info->Window), data.cpu4, 200, 590, 5);
        core5.bar(&(info->Window), data.cpu5, 200, 630, 5);
        core6.bar(&(info->Window), data.cpu6, 200, 670, 5);
        core7.bar(&(info->Window), data.cpu7, 200, 710, 5);
        info->Window.draw(core0.rect);
        info->Window.draw(core1.rect);
        info->Window.draw(core2.rect);
        info->Window.draw(core3.rect);
        info->Window.draw(core4.rect);
        info->Window.draw(core5.rect);
        info->Window.draw(core6.rect);
        info->Window.draw(core7.rect);
    }
}

void engine(info_t *info)
{
    IMonitorModule data;
    Display disp;
    Network network;
    Sys_infos sysinf;
    Button butt1("sfml/assets/butt1.png", "sfml/assets/but1.png", sf::Vector2f{1000, 600}, 300, 100);
    Button butt2("sfml/assets/butt2.png", "sfml/assets/but2.png", sf::Vector2f{1400, 600}, 300, 100);
    Button butt3("sfml/assets/butt3.png", "sfml/assets/but3.png", sf::Vector2f{1000, 850}, 300, 100);
    Button butt4("sfml/assets/butt4.png", "sfml/assets/but4.png", sf::Vector2f{1400, 850}, 300, 100);
    manip mem(1000, 30);
    manip core0(500, 30);
    manip core1(500, 30);
    manip core2(500, 30);
    manip core3(500, 30);
    manip core4(500, 30);
    manip core5(500, 30);
    manip core6(500, 30);
    manip core7(500, 30);
    sf::Text _txt;

    while (info->Window.isOpen())
    {
        while(info->Window.pollEvent(info->evt))
        {
            if (info->evt.type == sf::Event::Closed || info->evt.type == sf::Event::KeyPressed && info->evt.key.code==sf::Keyboard::Escape)
                info->Window.close();
        }
        info->Window.clear();
        data.get_info();
        butt1.pass_by(info->mouse.getPosition());
        butt2.pass_by(info->mouse.getPosition());
        butt3.pass_by(info->mouse.getPosition());
        butt4.pass_by(info->mouse.getPosition());
        info->time = info->clock.getElapsedTime();
        info->sec = info->time.asMicroseconds() / 1000000.0;
        if (butt1.check(info->mouse.getPosition(), info->mouse) == true && info->sec > 1) {
            (info->check1 == true ? info->check1 = false: info->check1 = true);
            info->sec = 0;
            info->clock.restart();
        }
        if (butt2.check(info->mouse.getPosition(), info->mouse) == true && info->sec > 1) {
            (info->check2 == true ? info->check2 = false: info->check2 = true);
            info->sec = 0;
            info->clock.restart();
        }
        if (butt3.check(info->mouse.getPosition(), info->mouse) == true && info->sec > 1) {
            (info->check3 == true ? info->check3 = false: info->check3 = true);
            info->sec = 0;
            info->clock.restart();
        }
        if (butt4.check(info->mouse.getPosition(), info->mouse) == true && info->sec > 1) {
            (info->check4 == true ? info->check4 = false: info->check4 = true);
            info->sec = 0;
            info->clock.restart();
        }
        draw(info, mem, core0, core1, core2, core3, core4, core5, core6, core7, data, disp);
        if (info->check1 == false)
            disp.setupMem(disp.convertFloat((float) (data.VirtualMem_used * 100) / data.VirtualMem_tot), info);
        if (info->check2 == false) {
            disp.setupCpu0(disp.convertFloat(data.cpu0), info);
            disp.setupCpu1(disp.convertFloat(data.cpu1), info);
            disp.setupCpu2(disp.convertFloat(data.cpu2), info);
            disp.setupCpu3(disp.convertFloat(data.cpu3), info);
            disp.setupCpu4(disp.convertFloat(data.cpu4), info);
            disp.setupCpu5(disp.convertFloat(data.cpu5), info);
            disp.setupCpu6(disp.convertFloat(data.cpu6), info);
            disp.setupCpu7(disp.convertFloat(data.cpu7), info);
        }
        disp.genericsetu(_txt, "CPU :", 60, 170, info, sf::Color::Red);
        disp.genericsetu(_txt, "CPU's Cores :", 110, 390, info, sf::Color::Red);
        if (info->check2 == false) {
            disp.genericsetu(_txt, "CPU 1:", 110, 430, info, sf::Color::Black);
            disp.genericsetu(_txt, "CPU 2:", 110, 470, info, sf::Color::Black);
            disp.genericsetu(_txt, "CPU 3:", 110, 510, info, sf::Color::Black);
            disp.genericsetu(_txt, "CPU 4:", 110, 550, info, sf::Color::Black);
            disp.genericsetu(_txt, "CPU 5:", 110, 590, info, sf::Color::Black);
            disp.genericsetu(_txt, "CPU 6:", 110, 630, info, sf::Color::Black);
            disp.genericsetu(_txt, "CPU 7:", 110, 670, info, sf::Color::Black);
            disp.genericsetu(_txt, "CPU 8:", 110, 710, info, sf::Color::Black);
        }

        disp.genericsetu(_txt, "Network:", 110, 810, info, sf::Color::Red);
        if (info->check3 == false) {
            disp.genericsetu(_txt, "nom de network: ", 110, 860, info, sf::Color::Black);
            disp.genericsetu(_txt, network.getName(), 400, 860, info, sf::Color::Black);
            disp.genericsetu(_txt, "addresse IP: ", 110, 900, info, sf::Color::Black);
            disp.genericsetu(_txt, network.getAdress(), 400, 900, info, sf::Color::Black);
            disp.genericsetu(_txt, "package received: ", 110, 940, info, sf::Color::Black);
            disp.genericsetu(_txt, std::to_string(network.getRxBytes()), 400, 940, info, sf::Color::Black);
            disp.genericsetu(_txt, "package sent: ", 110, 980, info, sf::Color::Black);
            disp.genericsetu(_txt, std::to_string(network.getTxBytes()), 400, 980, info, sf::Color::Black);
        }

        if (info->check4 == false) {
            disp.genericsetu(_txt, sysinf.getUserName(), 1400, 170, info, sf::Color::Red);
            disp.genericsetu(_txt, "How are you on this", 1250, 210, info, sf::Color::Black);
            disp.genericsetu(_txt, sysinf.getDate(), 1550, 210, info, sf::Color::Black);
            disp.genericsetu(_txt, "machine name :", 1250, 250, info, sf::Color::Black);
            disp.genericsetu(_txt, sysinf.getMachineName(), 1550, 250, info, sf::Color::Black);
            disp.genericsetu(_txt, "os :", 1250, 290, info, sf::Color::Black);
            disp.genericsetu(_txt, sysinf.getOperating_Sys(), 1550, 290, info, sf::Color::Black);
            disp.genericsetu(_txt, "kernel version :", 1250, 330, info, sf::Color::Black);
            disp.genericsetu(_txt, sysinf.getKernel(), 1550, 330, info, sf::Color::Black);
            disp.genericsetu(_txt, "time :", 1250, 370, info, sf::Color::Black);
            disp.genericsetu(_txt, sysinf.getHour(), 1550, 370, info, sf::Color::Black);
        }
        info->Window.draw(butt1.sprite);
        info->Window.draw(butt2.sprite);
        info->Window.draw(butt3.sprite);
        info->Window.draw(butt4.sprite);
        info->Window.display();
    }
}

int main_sfml(void)
{
    info_t *info = set();

    engine(info);
    return 0;
}

