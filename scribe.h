#ifndef SCRIBE_H
#define SCRIBE_H

#include <iostream>

namespace LOG_COLOR
{
constexpr const char *DEFAULT = "0";
constexpr const char *COLOR_BLUE = "34";
constexpr const char *COLOR_GREEN = "32";
constexpr const char *COLOR_YELLOW = "33";
constexpr const char *COLOR_RED = "31";
} // namespace LOG_COLOR

enum struct LOG_LEVEL
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
};

class Scribe
{
  private:
    template <typename... Args> static void Log(Args... args)
    {
        (std::cout << ... << args) << std::endl;
    };
    static void SetLogType(LOG_LEVEL logLevel, const char *logDescription)
    {
        switch (logLevel)
        {
        case LOG_LEVEL::DEBUG:
            SetLogColor(LOG_COLOR::COLOR_BLUE);
            std::cout << "[DEBUG]: ";

            break;
        case LOG_LEVEL::INFO:
            SetLogColor(LOG_COLOR::COLOR_GREEN);
            std::cout << "[INFO]: ";
            break;
        case LOG_LEVEL::WARNING:
            SetLogColor(LOG_COLOR::COLOR_YELLOW);
            std::cout << "[WARNING]: ";
            break;
        case LOG_LEVEL::ERROR:
            SetLogColor(LOG_COLOR::COLOR_RED);
            std::cout << "[ERROR]: ";
            break;
        }

        SetLogColor(LOG_COLOR::DEFAULT);
        std::cout << logDescription << ": ";
    };
    static void SetLogColor(const char *logColor)
    {
        std::cout << "\033[1;" << logColor << "m";
    };

  public:
    template <typename... Args> static void Debug(const char *logDescription, Args... args)
    {
        SetLogType(LOG_LEVEL::DEBUG, logDescription);
        Log(args...);
    };
    template <typename... Args> static void Info(const char *logDescription, Args... args)
    {
        SetLogType(LOG_LEVEL::INFO, logDescription);
        Log(args...);
    };
    template <typename... Args> static void Warning(const char *logDescription, Args... args)
    {
        SetLogType(LOG_LEVEL::WARNING, logDescription);
        Log(args...);
    };
    template <typename... Args> static void Error(const char *logDescription, Args... args)
    {
        SetLogType(LOG_LEVEL::ERROR, logDescription);
        Log(args...);
    };
};

#endif // SCRIBE_H
