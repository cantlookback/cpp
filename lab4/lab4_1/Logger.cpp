#include <iostream>
#include "Logger.h"

Logger::Logger(const std::string &m_runningMethod) : runningMethod(m_runningMethod){
    std::cout << "Starting " << runningMethod << std::endl;
}

Logger::~Logger(){
    std::cout << "Ending " << runningMethod << std::endl;
}