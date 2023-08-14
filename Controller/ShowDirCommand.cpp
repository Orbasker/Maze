#include "ShowDirCommand.h"
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void ShowDirCommand:: execute() {
    std::string path;
    std::cout << "Enter path: ";
    std::cin >> path;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (const auto & entry : fs::directory_iterator(path)) {
        std::cout << entry.path() << std::endl;
    }

}