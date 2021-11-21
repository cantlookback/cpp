#ifndef LOGGER_H
#define LOGGER_H
class Logger{
public:
    Logger(const std::string &m_runningMethod);

    ~Logger();

private:
    std::string runningMethod;
};

#endif