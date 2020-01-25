#include <string>
#include <fstream>
#include "map.h"
using namespace std;

#ifndef _FILEIO_H_
#define _FILEIO_H_

class FileIO
{

public:
    //添加文件 追加模式
    static void AppFile(string text, string fileName = "text.txt");

    //覆写文件
    static void OverFile(string text, string fileName = "text.txt");

    //保存Map
    static void SaveMap(Map *map);
};

void FileIO::AppFile(string text, string fileName)
{
    ofstream outfile(fileName, _S_app);
    outfile << text << endl;
    outfile.close();
}

void FileIO::OverFile(string text, string fileName)
{
    ofstream outfile(fileName);
    outfile << text << endl;
    outfile.close();
}

void FileIO::SaveMap(Map *map)
{
    AppFile(std::to_string(map->GetX()));
    AppFile(std::to_string(map->GetY()));

    //输出地图
    for (int i = 0; i < map->GetX(); i++)
    {
        string str = "";
        char ch;
        for (int j = 0; j < map->GetY(); j++)
        {
            DisplayType type = map->GetGrid(i, j);
            if (type == SPACE)
            {
                ch = '_';
            }
            else if (type == BLOCK)
            {
                ch = '#';
            }
            else if (type == GOAL)
            {
                ch = 'G';
            }
            else if (type == ZOMBIE)
            {
                ch = 'Z';
            }
            else if (type == ZOMBIE2)
            {
                ch = 'Y';
            }
            else if (type == PLANT)
            {
                ch = 'P';
            }
            else if (type == OVER)
            {
                ch = 'O';
            }
            else
            {
                ch = '_';
            }
            str += ch;
        }
        AppFile(str);
    }

    AppFile(std::to_string(map->GetRound()));
    AppFile(std::to_string(map->GetZNum()));
    AppFile(std::to_string(map->GetPNum()));
}
#endif
