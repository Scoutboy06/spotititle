#include "Settings.h"

void Settings::saveToDisk() {
	std::map<std::string, Value> map;

	map["SP_DC"] = _SP_DC;
	map["lyricsVisible"] = _lyricsVisible;
	map["theme"] = themeMap.at(_theme);
	map["imagePath"] = _imagePath;
	map["fps"] = _fps;
	map["fontSize"] = _fontSize;
	map["idleUpdateDelay"] = _idleUpdateDelay;
	map["delayOffset"] = _delayOffset;

	PersistentDataManager::saveToDisk(File::Settings, map);
}