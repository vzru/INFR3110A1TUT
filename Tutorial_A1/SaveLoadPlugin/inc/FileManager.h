#pragma once

#include "PluginSettings.h"
#include <iostream>
#include <fstream>
#include <string>

class PLUGIN_API FileManager
{
public:
	FileManager();
	~FileManager()
	{
	};

	void Save(float, float, float);
	void Load();

	int LoadInt();

	//void Save(std::string fileName);
	//void Load(std::string fileName);

	float GetX();
	float GetY();
	float GetZ();

	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);

//private:
	float _x = 1.f;
	float _y = 2.f;
	float _z = 3.f;
};

//#ifdef __cplusplus
//extern "C"
//{
//#endif
//	void (*actionCall)(float, float, float);
//
//	// Put your functions here
//	//PLUGIN_API int SimpleFunction();
//	PLUGIN_API void SavePos(float x, float y, float z);
//	PLUGIN_API void SetUpLoadPos(void(*action)(float x, float y, float z));
//	PLUGIN_API void Load();
//
//#ifdef __cplusplus
//}
//#endif