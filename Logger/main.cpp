#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#include "logger.h"

int main() {
	Logger* one = new FileLogger("log.txt", DTLI), *two = new ConsoleLogger(STLI);
	one->log("helo");
	two->log("asdas");
	one->log("helo");
	two->log("asdas");

	delete one, two;

	_CrtDumpMemoryLeaks();
	return 0;
}
