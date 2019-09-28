#include "Wrapper.h"

//int SimpleFunction()
//{
//	return 0;
//}

//PLUGIN_API void SetUpLoadPos(void(*action)(float x, float y, float z))
//{
//	actionCall = action;
//}

PLUGIN_API FileManager* CreateManager()
{
	return new FileManager();
}

PLUGIN_API void Save(float x, float y, float z, FileManager* fm)
{
	return fm->Save(x, y, z);
}

PLUGIN_API void Load(FileManager* fm)
{
	fm->Load();
}

PLUGIN_API float GetXPos(FileManager* fm)
{
	return fm->GetX();
}

PLUGIN_API float GetYPos(FileManager* fm)
{
	return fm->GetY();
}

PLUGIN_API float GetZPos(FileManager* fm)
{
	return fm->GetZ();
}
