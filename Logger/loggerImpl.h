#include <fstream>
#include <string>

// Виды логгеров
class LoggerInterface {
public:
	virtual void fileLog(std::ofstream& fout, const std::string message) const = 0;
	virtual void consoleLog(const std::string message) const = 0;
	virtual ~LoggerInterface();
};

// Реализация логгеров с логгированием даты-времени
class DT_LoggerImpl : public LoggerInterface {
public:
	void fileLog(std::ofstream& fout, const std::string message) const;
	void consoleLog(const std::string message) const;
};

// Реализация логгеров без логирования даты-времени
class ST_LoggerImpl : public LoggerInterface {
public:
	void fileLog(std::ofstream& fout, const std::string message) const;
	void consoleLog(const std::string message) const;
};
