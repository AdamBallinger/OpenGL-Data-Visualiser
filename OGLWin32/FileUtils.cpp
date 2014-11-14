#include "FileUtils.h"

#include <fstream>

//Simple method to check if a file exists in a given directory.
bool FileUtils::FileExists(std::string fileDir)
{
	std::ifstream file(fileDir);

	if (file.good())
		return true;
	else
		return false;
}