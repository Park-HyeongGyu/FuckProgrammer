#pragma once

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class ReadCode{
  private:
    string file_name;
    vector<string> file_lines;

    ReadCode(const string file_name_) : file_name(file_name_)
    {
        readFromFile();
    }
    ReadCode(const char *file_name_) : file_name(file_name_)
    {
        readFromFile();
    }

    void readFromFile()
    {
        ifstream reader;
        reader.open(file_name.c_str());
        
        if(!reader.is_open())
        {
            while(!reader.eof())
            {
                string line_readed;
                getline(reader, line_readed);
                file_lines.push_back(line_readed);
            }
        }
    }

  public:
    vector<string> get()
    {
        return file_lines;
    }
};

int read()
{
    ifstream readFile;
    string file_name;
    // file.c_str()
    readFile.open(file_name.c_str());

    if(!readFile.is_open())
    {
        while(!readFile.eof())
        {
            // std::getline
            string a;
            getline(readFile, a);
            cout << a << endl;
        }
    }

    readFile.close();
    return 0;
}