#ifndef SCRIBE_HPP
#define SCRIBE_HPP

#include <ctime>
#include <string>

enum struct LOG_OUTPUT
{
    TERMINAL,
    FILE
};

enum struct LOG_LEVEL
{
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Scribe
{
  private:
    LOG_OUTPUT m_outputMode;

    time_t GetCurrentTimestamp();
    const std::string FormatLogTimestamp(time_t time);
    const std::string FormatFileTimestamp(time_t time);

  public:
    Scribe(LOG_OUTPUT outputMode = LOG_OUTPUT::TERMINAL);
    ~Scribe();
};

#endif // SCRIBE_HPP
