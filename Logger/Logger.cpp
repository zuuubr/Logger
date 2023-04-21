#include "logger.h"
#include "loggerImpl.h"
#include <iostream>



Logger::Logger(Interfaces type) { 
	switch (type)
	{
	case DTLI:
		ptr = new DT_LoggerImpl;
		break;
	case STLI:
		ptr = new ST_LoggerImpl;
		break;
	default:
		ptr = new DT_LoggerImpl;
		break;
	}
}

Logger::~Logger() {
	delete ptr;
}

FileLogger::FileLogger(const std::string filename, Interfaces type) : Logger(type), path(filename) {
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

ConsoleLogger::ConsoleLogger(Interfaces type) : Logger(type) {
	std::cout << "D.M.Y - H:M:S# log data" << std::endl;
	std::cout << "-----------------------" << std::endl;
}

void ConsoleLogger::log(const std::string message) {
	ptr->consoleLog(message);
}
