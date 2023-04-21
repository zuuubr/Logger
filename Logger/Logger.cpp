#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

class MT_LoggerImpl;
class ST_LoggerImpl;
class LoggerInterface;
class Logger;

// Класс интерфейса логгера
class LoggerInterface {
public:
	virtual void fileLog(std::ofstream& fout, const std::string message) const = 0;
	virtual void consoleLog(const std::string message) const = 0;
	virtual ~LoggerInterface() { }
};

// Абстрактный класс
class Logger {
protected:
	LoggerInterface* ptr;
public:
	Logger(LoggerInterface* _ptr) : ptr(_ptr) { }
	virtual void log(std::string) = 0;
	virtual ~Logger() {
		delete ptr;
	}
};

class DT_LoggerImpl : public LoggerInterface {
public:
	void fileLog(std::ofstream &fout, const std::string message) const {
		tm ptr;
		time_t lt = time(nullptr);
		localtime_s(&ptr, &lt);

		fout	<< ptr.tm_mday << "." << 1 + ptr.tm_mon << "." << 1900 + ptr.tm_year << " - " << ptr.tm_hour << ":"
				<< ptr.tm_min << ":" << ptr.tm_sec << "# " << message << std::endl;
	}

	void consoleLog(const std::string message) const {
		tm ptr;
		time_t lt = time(nullptr);
		localtime_s(&ptr, &lt);

		std::cout	<< ptr.tm_mday << "." << 1 + ptr.tm_mon << "." << 1900 + ptr.tm_year << " - " << ptr.tm_hour << ":"
					<< ptr.tm_min << ":" << ptr.tm_sec << "# " << message << std::endl;
	}
};

class ST_LoggerImpl : public LoggerInterface {
	void fileLog(std::ofstream& fout, const std::string message) const {
		fout << message << std::endl;
	}

	void consoleLog(const std::string message) const {
		std::cout << message << std::endl;
	}
};

class FileLogger : public Logger {
private:
	std::string path;
	std::ofstream fout;
public:
	FileLogger(std::string filename) : Logger(new DT_LoggerImpl()), path(filename) {
		fout.open(path);
		fout << "D.M.Y - H:M:S# log data" << std::endl;
		fout << "-----------------------" << std::endl;
	}

	void log(std::string message) {
		ptr->fileLog(fout, message);
	}

	~FileLogger() {
		fout.close();
	}
};

class ConsoleLogger : public Logger {
public:
	ConsoleLogger() : Logger(new DT_LoggerImpl()) { 
		std::cout << "D.M.Y - H:M:S# log data" << std::endl;
		std::cout << "-----------------------" << std::endl;
	}

	void log(std::string message) {
		ptr->consoleLog(message);
	}
};



int main() {
	Logger* one = new FileLogger("log.txt"), *two = new ConsoleLogger();
	one->log("helo");
	two->log("asdas");
	system("pause");
	one->log("helo");
	two->log("asdas");
	return 0;
}
