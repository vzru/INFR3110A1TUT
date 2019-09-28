#include "FileManager.h"

FileManager::FileManager()
{
}

//void FileManager::Save(float x, float y, float z)
//{
//	std::ofstream file("player_data.txt");
//	
//	if (file.is_open())
//	{
//		file.clear();
//		file << std::to_string(x) << "\n" << std::to_string(y) << "\n" << std::to_string(z);
//		file.close();
//	}
//}
//
//void FileManager::Load()
//{
//	std::string line;
//	std::string::size_type sz;
//	std::ifstream file("player_data.text");
//
//	if (file.is_open())
//	{
//		float x, y, z;
//		std::getline(file, line);
//		x = std::stof(line, &sz);
//		std::getline(file, line);
//		y = std::stof(line, &sz);
//		std::getline(file, line);
//		z = std::stof(line, &sz);
//
//		actionCall(x, y, z);
//
//		file.close();
//	}
//		
//}

void FileManager::Save(float x, float y, float z)
{
	std::ofstream file("player_data.txt");

	if (file.is_open())
	{
		file.clear();
		file << std::to_string(x) << "\n" << std::to_string(y) << "\n" << std::to_string(z);
		file.close();
	}
}

void FileManager::Load()
{
	std::string line;
	//std::string::size_type sz;
	std::ifstream file("player_data.text");

	if (file.is_open())
	{
		std::getline(file, line);
		//SetX(std::stof(line));
		_x = std::stof(line);

		std::getline(file, line);
		//SetY(std::stof(line));
		_y = std::stof(line);

		std::getline(file, line);
		//SetZ(std::stof(line));
		_z = std::stof(line);


		file.close();
	}
}

int FileManager::LoadInt()
{
	std::string line;
	std::ifstream file("player_data.text");

	if (file.is_open())
	{
		file.read(reinterpret_cast<char*>(&_x), sizeof(_x));

		file.close();
	}
	return (int)_x;
}

float FileManager::GetX()
{
	return _x;
}

float FileManager::GetY()
{
	return _y;
}

float FileManager::GetZ()
{
	return _z;
}

void FileManager::SetX(float x)
{
	_x = x;
}

void FileManager::SetY(float y)
{
	_y = y;
}

void FileManager::SetZ(float z)
{
	_z = z;
}



//PLUGIN_API void SetUpLoadPos(void(*action)(float x, float y, float z))
//{
//	actionCall = action;
//}
