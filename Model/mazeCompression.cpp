// Or Basker   316388743
// Nave Maymon 318887965

#ifndef MAZE_COMPRESSION_CPP
#define MAZE_COMPRESSION_CPP
#include <vector>
#include <fstream>
#include "maze2d.h"
#include <sys/stat.h>

class MazeCompression
{
public:
    static void compressAndWriteToFile(const Maze2d &maze, const std::string &filename)
    {
        std::vector<int> compressedData = compressMazeData(maze);
        std::string path = "Mazes/" + filename;
        std::ofstream outFile(path, std::ios::binary);
        if (outFile.is_open())
        {
            outFile.write(reinterpret_cast<const char *>(compressedData.data()), compressedData.size() * sizeof(int));
            outFile.close();
        }
    }

    static Maze2d decompressAndReadFromFile(const std::string &filename)
    {
        std::string path = "Mazes/" + filename;
        std::ifstream inFile(path, std::ios::binary | std::ios::ate);
        if (inFile.is_open())
        {
            std::streampos size = inFile.tellg();
            std::vector<int> compressedData(size / sizeof(int));
            inFile.seekg(0, std::ios::beg);
            inFile.read(reinterpret_cast<char *>(compressedData.data()), size);
            inFile.close();

            std::vector<int> decompressedData = decompress(compressedData);

            Maze2d decompressedMaze = Maze2d::createFromData(decompressedData);

            return decompressedMaze;
        }

        return Maze2d();
    }
    long long getFileDetails(const std::string &filename)
    {
        struct stat stat_buf;
        int rc = stat(filename.c_str(), &stat_buf);
        return rc == 0 ? stat_buf.st_size : -1;
    }

private:
    static std::vector<int> compressMazeData(const Maze2d &maze)
    {
        std::vector<int> mazeData = maze.getData();
        std::vector<int> compressedData;

        for (size_t i = 0; i < mazeData.size();)
        {
            int count = 1;
            int value = mazeData[i];
            while (i + 1 < mazeData.size() && mazeData[i] == mazeData[i + 1])
            {
                count++;
                i++;
            }
            compressedData.push_back(value);
            compressedData.push_back(count);
            i++;
        }

        return compressedData;
    }

    static std::vector<int> decompress(const std::vector<int> &compressedData)
    {
        std::vector<int> decompressedData;

        for (size_t i = 0; i < compressedData.size(); i += 2)
        {
            int value = compressedData[i];
            int count = compressedData[i + 1];
            for (int j = 0; j < count; j++)
            {
                decompressedData.push_back(value);
            }
        }

        return decompressedData;
    }
};

#endif // !MAZE_COMPRESSION_CPP