/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-antoine.gavira-bottari
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
#include <vector>
#include <cstring>

namespace nts
{
        enum Tristate {
        UNDEFINED = ( - true ) ,
        TRUE = true ,
        FALSE = false
    };

    class IComponent
    {
        public :
            /*********** C/Dtor ***********/
            virtual ~ IComponent() = default ;

            /*********** Functions ***********/
            virtual void simulate (std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
    };
}

class logic_gate
{
    public:
        logic_gate() {}
        ~logic_gate(){}

        bool and_gate(nts::Tristate &a, nts::Tristate &b)
        {
            return (a & b);
        }
        bool or_gate(nts::Tristate &a, nts::Tristate &b)
        {
            return (a | b);
        }
        bool xor_gate(nts::Tristate &a, nts::Tristate &b)
        {
            return (a ^ b);
        }
        bool not_gate(nts::Tristate &a)
        {
            return !(a);
        }
        bool nand_gate(nts::Tristate &a, nts::Tristate &b)
        {
            if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
                return nts::Tristate::TRUE;
            return nts::Tristate::FALSE;
        }
        bool nor_gate(nts::Tristate &a, nts::Tristate &b)
        {
            return !(a + b);
        }
        bool xnor_gate(nts::Tristate &a, nts::Tristate &b)
        {
            return !(a ^ b);
        }
};

namespace Chipsets {
    class fourty_one : public nts::IComponent//4001
    {
        public:
        fourty_one(std::string name, Parser &parser)
        {
            _name = name;
            _parser = parser;
            get_link();
        }

        ~fourty_one()
        {
        }

        void get_link()
        {
            std::vector<std::string> input = _parser.get_special_input();
            std::vector<std::string> output = _parser.get_special_output();

            for (std::size_t i = 0; i < input.size(); i++)
            {
                if (i < 2)
                    _a.push_back(input[i]);
                if (i >= 2 && i < 4)
                    _b.push_back(input[i]);
                if (i >= 4 && i < 6)
                    _c.push_back(input[i]);
                if (i >= 6 && i < 8)
                    _d.push_back(input[i]);
            }
            for (std::size_t i = 0; i <output.size(); i++) {
                if (std::strncmp(output[i].c_str(), "out_", 4) == 0) {
                    if (i == 0)
                        _a.push_back(output[i]);
                    if (i == 1)
                        _b.push_back(output[i]);
                    if (i == 2)
                        _c.push_back(output[i]);
                    if (i == 3)
                        _d.push_back(output[i]);
                }
            }
            //debug();
        }

        void debug()
        {
            std::cout << "************** A SET_LINKS **************" << std::endl;
            for (std::size_t i = 0; i < _a.size(); ++i)
                std::cout << _a[i] << std::endl;
            std::cout << "************** B SET_LINKS **************" << std::endl;
            for (std::size_t i = 0; i < _b.size(); ++i)
                std::cout << _b[i] << std::endl;
            std::cout << "************** C SET_LINKS **************" << std::endl;
            for (std::size_t i = 0; i < _c.size(); ++i)
                std::cout << _c[i] << std::endl;
            std::cout << "************** D SET_LINKS **************" << std::endl;
            for (std::size_t i = 0; i < _d.size(); ++i)
                std::cout << _d[i] << std::endl;
        }

        void set_gate()
        {
            //_gate["1"](logic_gate::or_gate())
        }

        void simulate (std::size_t tick)
        {
            (void)tick;
            //std::cout << "4001 SIMULATE" << std::endl;
        }

        nts::Tristate compute(std::size_t pin) //return
        {
            (void)pin;
            return nts::Tristate::UNDEFINED;
            // do operation of the four OR gates and return the result
            // set the link ...
        }

        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {
            (void) pin;
            (void) other;
            (void) otherPin;
        }

        void dump() const
        {
            // ?????
        }

        private:
            std::map<std::string, bool (logic_gate::*)(nts::Tristate &, nts::Tristate &)> _gate;
            Parser _parser;
            std::string _name;
            std::vector<std::string> _a; //pin linked for the first and gate
            //in_01, in_02,out_03
            nts::Tristate return_a;
            std::vector<std::string> _b; //pin linked for the second and gate
            //in_05, in_6, out 04
            nts::Tristate return_b;
            std::vector<std::string> _c; //pin linked for the third and gate
            nts::Tristate return_c;
            std::vector<std::string> _d; //pin linked for the fourth and gate
            nts::Tristate return_d;
    };

    /*
    class fourty_eleven : public nts::IComponent //4011
    {
        public:
        fourty_eleven(std::string name, nts::Tristate a, nts::Tristate b)
        {
            _name = name;
            _a = a;
            _b = b;
        }
        ~fourty_eleven()
        {
        }
        void simulate (std::size_t tick)
        {}
        nts::Tristate compute(std::size_t pin)
        {}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {}
        void dump() const
        {}
        private:
            std::string _name;
            nts::Tristate _a;
            nts::Tristate _b;
    };
    */

    class fourty_thirty : public nts::IComponent //4030
    {
        public:
        fourty_thirty(std::string name, Parser &parser)
        {
            _name = name;
            _parser = parser;
            get_link();
        }

        ~fourty_thirty()
        {
        }

        void get_link()
        {
            std::vector<std::string> input = _parser.get_special_input();
            std::vector<std::string> output = _parser.get_special_output();

            for (std::size_t i = 0; i < input.size(); i++)
            {
                if (i < 2)
                    _a.push_back(input[i]);
                if (i >= 2 && i < 4)
                    _b.push_back(input[i]);
                if (i >= 4 && i < 6)
                    _c.push_back(input[i]);
                if (i >= 6 && i < 8)
                    _d.push_back(input[i]);
            }
            for (std::size_t i = 0; i <output.size(); i++) {
                if (std::strncmp(output[i].c_str(), "out_", 4) == 0) {
                    if (i == 0)
                        _a.push_back(output[i]);
                    if (i == 1)
                        _b.push_back(output[i]);
                    if (i == 2)
                        _c.push_back(output[i]);
                    if (i == 3)
                        _d.push_back(output[i]);
                }
            }
            //debug();
        }

        void debug()
        {
            std::cout << "************** A SET_LINKS **************" << std::endl;
            for (std::size_t i = 0; i < _a.size(); ++i)
                std::cout << _a[i] << std::endl;
            std::cout << "************** B SET_LINKS **************" << std::endl;
            for (std::size_t i = 0; i < _b.size(); ++i)
                std::cout << _b[i] << std::endl;
            std::cout << "************** C SET_LINKS **************" << std::endl;
            for (std::size_t i = 0; i < _c.size(); ++i)
                std::cout << _c[i] << std::endl;
            std::cout << "************** D SET_LINKS **************" << std::endl;
            for (std::size_t i = 0; i < _d.size(); ++i)
                std::cout << _d[i] << std::endl;
        }

        void simulate (std::size_t tick)
        {
            (void)tick;
            //std::cout << "4030 SIMULATE" << std::endl;
        }

        nts::Tristate compute(std::size_t pin) //return
        {
            (void)pin;
            return nts::Tristate::UNDEFINED;
            // do operation of the four OR gates and return the result
            // set the link ...
        }

        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {
            (void) pin;
            (void) other;
            (void) otherPin;
        }

        void dump() const
        {
            // ?????
        }

        private:
            Parser _parser;
            std::string _name;
            std::vector<std::string> _a; //pin linked for the first and gate
            //in_01, in_02,out_03
            nts::Tristate return_a;
            std::vector<std::string> _b; //pin linked for the second and gate
            //in_05, in_6, out 04
            nts::Tristate return_b;
            std::vector<std::string> _c; //pin linked for the third and gate
            nts::Tristate return_c;
            std::vector<std::string> _d; //pin linked for the fourth and gate
            nts::Tristate return_d;
    };

    class fourty_seventy_one : public nts::IComponent //4071
    {
        public:
        fourty_seventy_one(std::string name, Parser &parser)
        {
            _name = name;
            _parser = parser;
            get_link();
        }

        ~fourty_seventy_one()
        {
        }

        void get_link()
        {
            std::vector<std::string> input = _parser.get_special_input();
            std::vector<std::string> output = _parser.get_special_output();

            for (std::size_t i = 0; i < input.size(); i++)
            {
                if (i < 2)
                    _a.push_back(input[i]);
                if (i >= 2 && i < 4)
                    _b.push_back(input[i]);
                if (i >= 4 && i < 6)
                    _c.push_back(input[i]);
                if (i >= 6 && i < 8)
                    _d.push_back(input[i]);
            }
            for (std::size_t i = 0; i <output.size(); i++) {
                if (std::strncmp(output[i].c_str(), "out_", 4) == 0) {
                    if (i == 0)
                        _a.push_back(output[i]);
                    if (i == 1)
                        _b.push_back(output[i]);
                    if (i == 2)
                        _c.push_back(output[i]);
                    if (i == 3)
                        _d.push_back(output[i]);
                }
            }
            //debug();
        }

        void debug()
        {
            std::cout << "************** A SET_LINKS **************" << std::endl;
            for (std::size_t i = 0; i < _a.size(); ++i)
                std::cout << _a[i] << std::endl;
            std::cout << "************** B SET_LINKS **************" << std::endl;
            for (std::size_t i = 0; i < _b.size(); ++i)
                std::cout << _b[i] << std::endl;
            std::cout << "************** C SET_LINKS **************" << std::endl;
            for (std::size_t i = 0; i < _c.size(); ++i)
                std::cout << _c[i] << std::endl;
            std::cout << "************** D SET_LINKS **************" << std::endl;
            for (std::size_t i = 0; i < _d.size(); ++i)
                std::cout << _d[i] << std::endl;
        }

        void simulate (std::size_t tick)
        {
            (void)tick;
            //std::cout << "SIMULATE" << std::endl;
        }

        nts::Tristate compute(std::size_t pin) //return
        {
            (void)pin;
            return nts::Tristate::UNDEFINED;
            // do operation of the four OR gates and return the result
            // set the link ...
        }

        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {
            (void) pin;
            (void) other;
            (void) otherPin;
        }

        void dump() const
        {
            // ?????
        }

        private:
            std::map<int, std::vector<std::size_t>> _links;
            Parser _parser;
            std::string _name;
            std::vector<std::string> _a; //pin linked for the first and gate
            //in_01, in_02,out_03
            nts::Tristate return_a;
            std::vector<std::string> _b; //pin linked for the second and gate
            //in_05, in_6, out 04
            nts::Tristate return_b;
            std::vector<std::string> _c; //pin linked for the third and gate
            nts::Tristate return_c;
            std::vector<std::string> _d; //pin linked for the fourth and gate
            nts::Tristate return_d;
    };
    /*
    class fourty_eighty_one : public nts::IComponent //4081
    {
        public:
        fourty_eighty_one(std::string name, nts::Tristate a, nts::Tristate b)
        {
            _name = name;
            _a = a;
            _b = b;
        }
        ~fourty_eighty_one()
        {
        }
        void simulate (std::size_t tick)
        {}
        nts::Tristate compute(std::size_t pin)
        {}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {}
        void dump() const
        {}
        private:
            std::string _name;
            nts::Tristate _a;
            nts::Tristate _b;
    };
    */
    /****************************************************************************************/

    /*
    class fourty_sixty_nine : public nts::IComponent //4069
    {
        public:
        fourty_sixty_nine(std::string name, nts::Tristate a, nts::Tristate b)
        {
            _name = name;
            _a = a;
            _b = b;
        }
        ~fourty_sixty_nine()
        {
        }
        void simulate (std::size_t tick)
        {}
        nts::Tristate compute(std::size_t pin)
        {}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {}
        void dump() const
        {}
        private:
            std::string _name;
            nts::Tristate _a;
            nts::Tristate _b;
    };

    class fourty_eight : public nts::IComponent //4008
    {
        public:
        fourty_eight(std::string name, nts::Tristate a, nts::Tristate b)
        {
            _name = name;
            _a = a;
            _b = b;
        }
        ~fourty_eight()
        {
        }
        void simulate (std::size_t tick)
        {}
        nts::Tristate compute(std::size_t pin)
        {}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {}
        void dump() const
        {}
        private:
            std::string _name;
            nts::Tristate _a;
            nts::Tristate _b;
    };

    class fourty_thirteen : public nts::IComponent //4013
    {
        public:
        fourty_thirteen(std::string name, nts::Tristate a, nts::Tristate b)
        {
            _name = name;
            _a = a;
            _b = b;
        }
        ~fourty_thirteen()
        {
        }
        void simulate (std::size_t tick)
        {}
        nts::Tristate compute(std::size_t pin)
        {}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {}
        void dump() const
        {}
        private:
            std::string _name;
            nts::Tristate _a;
            nts::Tristate _b;
    };

    class fourty_seventeen : public nts::IComponent //4017
    {
        public:
        fourty_seventeen(std::string name, nts::Tristate a, nts::Tristate b)
        {
            _name = name;
            _a = a;
            _b = b;
        }
        ~fourty_seventeen()
        {
        }
        void simulate (std::size_t tick)
        {}
        nts::Tristate compute(std::size_t pin)
        {}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {}
        void dump() const
        {}
        private:
            std::string _name;
            nts::Tristate _a;
            nts::Tristate _b;
    };

    class fourty_fourty : public nts::IComponent //4040
    {
        public:
        fourty_fourty(std::string name, nts::Tristate a, nts::Tristate b)
        {
            _name = name;
            _a = a;
            _b = b;
        }
        ~fourty_fourty()
        {
        }
        void simulate (std::size_t tick)
        {}
        nts::Tristate compute(std::size_t pin)
        {}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {}
        void dump() const
        {}
        private:
            std::string _name;
            nts::Tristate _a;
            nts::Tristate _b;
    };

    class fourty_ninety_four : public nts::IComponent //4094
    {
        public:
        fourty_ninety_four(std::string name, nts::Tristate a, nts::Tristate b)
        {
            _name = name;
            _a = a;
            _b = b;
        }
        ~fourty_ninety_four()
        {
        }
        void simulate (std::size_t tick)
        {}
        nts::Tristate compute(std::size_t pin)
        {}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {}
        void dump() const
        {}
        private:
            std::string _name;
            nts::Tristate _a;
            nts::Tristate _b;
    };

    class fourty_five_twelve : public nts::IComponent //4512
    {
        public:
        fourty_five_twelve(std::string name, nts::Tristate a, nts::Tristate b)
        {
            _name = name;
            _a = a;
            _b = b;
        }
        ~fourty_five_twelve()
        {
        }
        void simulate (std::size_t tick)
        {}
        nts::Tristate compute(std::size_t pin)
        {}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {}
        void dump() const
        {}
        private:
            std::string _name;
            nts::Tristate _a;
            nts::Tristate _b;
    };

    class fourty_five_fourteen : public nts::IComponent //4514
    {
        public:
        fourty_five_fourteen(std::string name, nts::Tristate a, nts::Tristate b)
        {
            _name = name;
        }
        ~fourty_five_fourteen()
        {
        }
        void simulate (std::size_t tick)
        {}
        nts::Tristate compute(std::size_t pin)
        {}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {}
        void dump() const
        {}
        private:
            std::string _name;
            nts::Tristate _a;
            nts::Tristate _b;
    };

    class fourty_eight_one : public nts::IComponent //4801
    {
        public:
        fourty_eight_one(std::string name, nts::Tristate a, nts::Tristate b)
        {
            _name = name;
            _a = a;
            _b = b;
        }
        ~fourty_eight_one()
        {
        }
        void simulate (std::size_t tick)
        {}
        nts::Tristate compute(std::size_t pin)
        {}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {}
        void dump() const
        {}
        private:
            std::string _name;
            nts::Tristate _a;
            nts::Tristate _b;
    };

    class twenty_seven_sixteen : public nts::IComponent // 2716
    {
        public:
        twenty_seven_sixteen(std::string name, nts::Tristate a, nts::Tristate b)
        {
            _name = name;
            _a = a;
            _b = b;
        }
        ~twenty_seven_sixteen()
        {
        }
        void simulate (std::size_t tick)
        {}
        nts::Tristate compute(std::size_t pin)
        {}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
        {}
        void dump() const
        {}
        private:
            std::string _name;
            nts::Tristate _a;
            nts::Tristate _b;
    };
    */
}

#endif /* !ICOMPONENT_HPP_ */
