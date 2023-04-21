#include "loggerImpl.h"
#include <ctime>
#include <iostream>

LoggerInterface::~LoggerInterface() { }

void DT_LoggerImpl::fileLog(std::ofstream& fout, const std::string message) const {
	tm ptr;
	time_t lt = time(nullptr);
	localtime_s(&ptr, &lt);

	fout << ptr.tm_mday << "." << 1 + ptr.tm_mon << "." << 1900 + ptr.tm_year << " - " << ptr.tm_hour << ":"
		<< ptr.tm_min << ":" << ptr.tm_sec << "# " << message << std::endl;
}

void DT_LoggerImpl::consoleLog(const std::string message) const {
	tm ptr;
	time_t lt = time(nullptr);
	localtime_s(&ptr, &lt);

	std::cout << ptr.tm_mday << "." << 1 + ptr.tm_mon << "." << 1900 + ptr.tm_year << " - " << ptr.tm_hour << ":"
		<< ptr.tm_min << ":" << ptr.tm_sec << "# " << message << std::endl;
}


void ST_LoggerImpl::fileLog(std::ofstream& fout, const std::string message) const {
	fout << message << std::endl;
}

void ST_LoggerImpl::consoleLog(const std::string message) const {
	std::cout << message << std::endl;
}
