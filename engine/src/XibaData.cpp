#include <XibaData.hpp>

XibaData::XibaData()
{
}

bool XibaData::LoadData(const std::string &data_directory)
{
    struct stat buffer;
    std::cout << "Data Loading..." << std::endl;
    std::cout << "===========================" << std::endl;
    if (stat(data_directory.c_str(), &buffer) != 0)
    {
        std::cout << "Data not exist..." << std::endl;
        return false;
    };

    std::ifstream ifs("data/data.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj); // reader can also read strings

    // General Information
    std::cout << "Game: " << obj["title"].asString() << std::endl;
    std::cout << "Version: " << obj["version"].asString() << std::endl;

    // Loading Bootsplashs
    const Json::Value &bootsplashs = obj["bootsplah"]; // array of characters
    for (int i = 0; i < bootsplashs.size(); i++)
    {
        std::cout << "    file: " << bootsplashs[i]["src"].asString();
        std::cout << " time on: " << bootsplashs[i]["time"].asUInt();
        std::cout << std::endl;
    }

    return true;
}

XibaData::~XibaData()
{
}
