#include <fstream>
#include <string>

// ���� ��������
class LoggerInterface {
public:
	virtual void fileLog(std::ofstream& fout, const std::string message) const = 0;
	virtual void consoleLog(const std::string message) const = 0;
	virtual ~LoggerInterface();
};

// ���������� �������� � ������������� ����-�������
class DT_LoggerImpl : public LoggerInterface {
public:
	void fileLog(std::ofstream& fout, const std::string message) const;
	void consoleLog(const std::string message) const;
};

// ���������� �������� ��� ����������� ����-�������
class ST_LoggerImpl : public LoggerInterface {
public:
	void fileLog(std::ofstream& fout, const std::string message) const;
	void consoleLog(const std::string message) const;
};
