//convert a bunch of different duplicated strings into a set of unique strings to another text file 
#include<string>
#include<iostream>
#include<fstream>
#include <algorithm>
#include<vector>

template <typename T>
void remove_duplicates(std::vector<T>& vec)
{
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

int main()
{

	std::ifstream myfile ("table.txt");
	std::vector<std::string> words;
	std::string str;
	
	while(myfile >> str)
	{
		words.push_back(str);
	}

	remove_duplicates(words);

	for(int i = 0; i < words.size(); i++)
	{
		if(words.at(i).size() > 5)
		{
			str = words.at(i);
			if(str[0] == '\"')
			{
				str.erase(0,1);
				words.at(i) = str;
			}
			if(str[6] == ',' || str[6] == '\"')
			{

				str.erase(6,1);
				words.at(i) = str;
			}
		}
	}

	remove_duplicates(words);
	myfile.close();
	std::ofstream write("table_converted.txt");
	for(int i = 0; i < words.size(); i++)
		write << words.at(i) << std::endl;
	write.close();

	std::cout << words.size() << "\n";

return 0;
}
