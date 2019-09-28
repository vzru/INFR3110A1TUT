#pragma once
#include "PluginSettings.h"
#include "FileManager.h"

#ifdef __cplusplus
extern "C"
{
#endif
	PLUGIN_API FileManager *CreateManager();
	PLUGIN_API void Save(float x, float y, float z, FileManager*);
	PLUGIN_API void Load(FileManager*);
	PLUGIN_API float GetXPos(FileManager*);
	PLUGIN_API float GetYPos(FileManager*);
	PLUGIN_API float GetZPos(FileManager*);


#ifdef __cplusplus
}
#endif