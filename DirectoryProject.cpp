#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

using namespace std;

void usage();

int main(int argc, char* argv[])
{   
    std::string directorypath;

    if(argc < 2 || argc > 2){
        usage();
        return 1;
    }

    directorypath = argv[1];
    cout << "{\n";
    cout << "    " << "\"" << "files:" << "\"\n";
    cout << "    " << "[\n";

    for (std::filesystem::recursive_directory_iterator end, dir_iterator(directorypath); dir_iterator != end; dir_iterator++){
        if (!is_directory(dir_iterator->path())){
            cout << "     " << "{" << dir_iterator->path() << "," << " " << dir_iterator->file_size() << "}," << "\n";
        }
    }

    cout << "    " << "]," << "\n";
    cout << "}" << "\n";

}

void usage(){
    cout << "DirectoryProject v1.0.0.0 \n \n";
    cout << "Usage: \n";
    cout << "DirectoryProject <path> \n";
}