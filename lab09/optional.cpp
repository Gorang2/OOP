#include <iostream>
#include <fstream>

using namespace std;

istream& operator>> (istream &fin, string& s)
{
	return getline(fin, s);
}

bool	digit(char c)
{
	return ('0' <= c && c <= '9');
}

bool	atoi(istream& fin, ostream& fout)
{
	bool flag = false;
	bool is_file = false;
	string s;
	
	if (string(typeid(fin).name()).find("ifstream") != string::npos)
		is_file = true;
	while (fin >> s)
	{
		int i = 0;
		while ((!digit(s[i]) || s[i] == ' ' || s[i] == '0') && i < s.length())
			i++;
		while (digit(s[i]) && i < s.length())
		{
			flag = true;
			fout << s[i++];
		}
		if (flag)
			fout << endl;
		if (is_file && flag)
			break;
	}
	return flag;
}

int main()
{
    // std::cin, std::cout 매개변수로 줄 시
    std::cout << "Please enter anything: " << std::endl;

    bool bHasDecimal = atoi(std::cin, std::cout);


    if (bHasDecimal)
    {
        std::cout << "We Found Decimal!" << std::endl;
    }
    else
    {
        std::cout << "No Decimal Found." << std::endl;
    }

    // file 매개변수로 줄 시
    std::ifstream inputFile;
    inputFile.open("input.txt");
    std::ofstream outputFile;
    outputFile.open("output.txt");


    bHasDecimal = atoi(inputFile, outputFile);


    if (bHasDecimal)
    {
        std::cout << "We Found Decimal!" << std::endl;
    }
    else
    {
        std::cout << "No Decimal Found." << std::endl;
    } 


    inputFile.close();
    outputFile.close();


    return 0;
}
