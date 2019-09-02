#include <XibaOfDevs.hpp>

int main(int, char **)
{

	XibaEngine *xibaengine = new XibaEngine();
	xibaengine->Start("Xiba of Devs", 1024, 768, "data");
	xibaengine->Quit();
}