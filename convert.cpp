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

	myfile.close();
	std::ofstream write("yo.txt");
	for(int i = 0; i < words.size(); i++)
		write << words.at(i) << std::endl;
	write.close();

	std::cout << words.size() << "\n";

return 0;
}
