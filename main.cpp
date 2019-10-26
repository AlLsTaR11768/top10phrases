#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    map<string, int> huckBook, tomBook;

    ifstream huckFile; //Huck Finn File
    ifstream tomFile;  //Tom Sawyer File

    string parsedLine = "";
    vector<string> phrases;

    huckFile.open("huckFinn.txt");
    tomFile.open("tomSawyer.txt");

    string content((istreambuf_iterator<char>(huckFile)), (istreambuf_iterator<char>()));
    //content.erase(remove(content.begin(), content.end(), '\n'), content.end());
    replace(content.begin(), content.end(), '\n', ' ');

    for (int i = 0; i < content.size(); i++)
    {
        if (!(content[i] == '.') && !(content[i] == ',') && !(content[i] == ';') && !(content[i] == '!'))
        {
            parsedLine += content[i]; //APPEND chars to parsed line
        }
        else
        {
            parsedLine.erase(remove(parsedLine.begin(), parsedLine.end(), '"'), parsedLine.end()); //Remove "" from the line
            parsedLine += content[i];                                                              //ADD chars to parsed phrases
            phrases.push_back(parsedLine);                                                         //PUSH to vector of phrases
            parsedLine = "";                                                                       //CLEAR the string
            while (content[i + 1] == ' ')
            {
                i++;
            }
        }
    }

    int lines = 0;
    for (string i : phrases)
    {
        lines++;
        cout << i << endl;
    }

    huckFile.close();
    tomFile.close();
    return 0;
}