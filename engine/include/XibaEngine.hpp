/*
    XibaEgnine - Simple Engine Beat'n'Up
 */
#include <string>

class XibaEngine
{
public:
    int Start(const char *title, int width, int height, const std::string &data_directory);
    void Quit();
};
