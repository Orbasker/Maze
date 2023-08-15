// Or Basker   316388743
// Nave Maymon 318887965

#include "ShowDirCommand.h"
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void ShowDirCommand:: execute() {
    std::string path;
    std::cout << "Enter path: ";
    std::cin >> path;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    try {
    for (const auto & entry : fs::directory_iterator(path)) {
        std::cout <<UNDERLINE<<YELLOW<< entry.path() <<RESET <<std::endl;
    }
    } catch (fs::filesystem_error& e) {
        std::cout <<RED << "Error:try again" <<RESET<< std::endl;
        std::cout <<RED<< e.what() <<RESET<< std::endl;
    }

}