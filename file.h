#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class File
{
    public:
    static void WriteAfterToken(string filename, string token, string content)
    {
        cout << "0";
        // Read the file into a string
        std::ifstream inputFile(filename);
        if (!inputFile)
        {
            std::cerr << "Could not open file!" << std::endl;
            return;
        }

        cout << "1";
        std::stringstream buffer;
        buffer << inputFile.rdbuf();
        std::string bufferstring = buffer.str();
        inputFile.close();

        cout << "2";
        // Find the target string
        size_t pos = bufferstring.find(token);

        if (pos != std::string::npos)
        {
            string htmlContent = "<p>" + content + "</p>\n";
            
            // 3. Insert the new text
            bufferstring.insert(pos, htmlContent);

            // 4. Write the modified content back to the file
            std::ofstream outputFile(filename);
            outputFile << content;
            outputFile.close();
            
            std::cout << "Text inserted successfully." << std::endl;
        }
        else
        {
            std::cout << "Target string not found." << std::endl;
        }
    }
};