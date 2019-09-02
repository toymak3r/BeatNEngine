#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <json/json.h>
#include <json/json-forwards.h>

class XibaData
{
public:
    XibaData();
    bool LoadData(const std::string &data_directory);
    ~XibaData();
};
