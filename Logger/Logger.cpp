#include "logger.h"
#include "loggerImpl.h"
#include <iostream>

Logger::Logger(LoggerInterface* _ptr) : ptr(_ptr) { }

Logger::~Logger() {
	delete ptr;
}

FileLogger::FileLogger(const std::string filename) : Logger(new DT_LoggerImpl()), path(filename) {
	fout.open(path);
	fout << "D.M.Y - H:M:S# log data" << std::endl;
	fout << "-----------------------" << std::endl;
}

void FileLogger::log(const std::string message) {
	ptr->fileLog(fout, message);
}

FileLogger::~FileLogger() {
	fout.close();
}

ConsoleLogger::ConsoleLogger() : Logger(new DT_LoggerImpl()) {
	std::cout << "D.M.Y - H:M:S# log data" << std::endl;
	std::cout << "-----------------------" << std::endl;
}

void ConsoleLogger::log(const std::string message) {
	ptr->consoleLog(message);
}
