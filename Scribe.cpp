#include "Scribe.hpp"

#include <iomanip>
#include <iostream>

Scribe::Scribe(LOG_OUTPUT outputMode) : m_outputMode(outputMode)
{
    if (m_outputMode == LOG_OUTPUT::FILE)
    {
        std::cerr << "Hello File \n";
    }
    else
    {
        std::cerr << "Hello Terminal \n";
    }
};

Scribe::~Scribe() {};

time_t Scribe::GetCurrentTimestamp()
{
    time_t currentTimestamp = std::time(NULL);
    return currentTimestamp;
}

const std::string Scribe::FormatLogTimestamp(time_t time)
{
    std::tm tm = *std::localtime(&time);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%x %T ->");
    std::string str(oss.str());

    return str;
}

const std::string Scribe::FormatFileTimestamp(time_t time)
{
    std::tm tm = *std::localtime(&time);

    std::ostringstream oss;
    oss << std::put_time(&tm, "[%x]");
    std::string str(oss.str());

    return str;
}
