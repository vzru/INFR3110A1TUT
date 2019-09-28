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

	float GetX();
	float GetY();
	float GetZ();

	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);

private:
	float _x = 1.f;
	float _y = 2.f;
	float _z = 3.f;
};
