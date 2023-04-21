#include <string>
#include <fstream>

class LoggerInterface;
enum Interfaces { DTLI, STLI};

// Абстрактный класс
// Задает функции для каждого вида логгера

class Logger {
protected:
	LoggerInterface* ptr;
public:
	Logger(Interfaces);
	virtual void log(const std::string) = 0;
	virtual ~Logger();
};

// Переопределение интерфейса под свой вид
class FileLogger : public Logger {
private:
	std::string path;
	std::ofstream fout;
public:
	FileLogger(const std::string filename, Interfaces);
	void log(const std::string message);
	~FileLogger();
};

// Переопределение интерфейса под свой вид
class ConsoleLogger : public Logger {
public:
	ConsoleLogger(Interfaces);
	void log(const std::string message);
};
