#include <string>
#include <fstream>

class LoggerInterface;

// ����������� �����
// ������ ������� ��� ������� ���� �������

class Logger {
protected:
	LoggerInterface* ptr;
public:
	Logger(LoggerInterface* _ptr);
	virtual void log(const std::string) = 0;
	virtual ~Logger();
};

// ��������������� ���������� ��� ���� ���
class FileLogger : public Logger {
private:
	std::string path;
	std::ofstream fout;
public:
	FileLogger(const std::string filename);
	void log(const std::string message);
	~FileLogger();
};

// ��������������� ���������� ��� ���� ���
class ConsoleLogger : public Logger {
public:
	ConsoleLogger();
	void log(const std::string message);
};
