/*
** EPITECH PROJECT, 2022
** POOL
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem
{
    class QuantumReactor;
    class Core;
};

namespace WarpSystem
{
    class QuantumReactor
    {
        public:
        bool _stability;

        QuantumReactor();
        ~QuantumReactor();
        bool isStable();
        void setStability(bool stability);
    };
    class Core
    {
        public:
        QuantumReactor *_coreReactor;

        Core(QuantumReactor *ptr);
        ~Core();

        QuantumReactor *checkReactor();
    };
};

#endif /* !WARPSYSTEM_HPP_ */