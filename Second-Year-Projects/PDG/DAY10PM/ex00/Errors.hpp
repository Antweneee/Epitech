#pragma once

#include <string>

class NasaError : public std::exception
{
    private:
        std::string _message;
        std::string _component;

    public:
        NasaError(std::string const &message, std::string const &component = "Unknown");
        virtual ~NasaError() throw() {}
        std::string const &getComponent() const noexcept;
        const char *what() const noexcept;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component = "Unknown") : NasaError(message, component) {}
        virtual ~MissionCriticalError() throw() {}
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message, std::string const &component = "Unknown") : NasaError(message, component) {}
        virtual ~LifeCriticalError() throw() {}
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message, std::string const &component = "Unknown") : NasaError(message, component) {}
        virtual ~UserError() throw() {}
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message) : NasaError(message, std::string("CommunicationDevice")) {}
        virtual ~CommunicationError() throw() {}
};
