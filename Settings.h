#pragma once

#include <variant>
#include <string>
#include <map>
#include <unordered_map>

#include "PersistentDataManager.h"

/*
Settings:
 - SP_DC (string)
 - lyrics visible (bool)
 - theme (Enum { Purple | Green | Orange | Blue | Red | Pink | Image })
 - (optional: imagePath (string))
 - fps (unsigned int)
 - font size (unsigned int)
 - idleUpdateDelay (unsigned int)
 - delayOffset (int)
*/

enum class Theme { Purple, Green, Orange, Blue, Red, Pink, Image };
const std::unordered_map<Theme, std::string> themeMap = {
	{Theme::Purple, "Purple"},
	{Theme::Green, "Green"},
	{Theme::Orange, "Orange"},
	{Theme::Blue, "Blue"},
	{Theme::Red, "Red"},
	{Theme::Pink, "Pink"},
	{Theme::Image, "Image"},
};

class Settings {
private:
	std::string _SP_DC			= "";
	bool _lyricsVisible			= true;
	Theme _theme				= Theme::Purple;
	std::string _imagePath		= "";
	uint32_t _fps				= 5;
	uint32_t _fontSize			= 30;
	uint32_t _idleUpdateDelay	= 2000;
	int32_t _delayOffset		= 0;

	void saveToDisk();

	// Default constructor
	Settings() {}
public:

	// Delete copy constructor
	Settings(const Settings& obj) = delete;

	// Delete assignment operator
	void operator=(Settings const&) = delete;

	// Singleton instance method
	static Settings& instance() {
		static Settings instance;
		return instance;
	}

	// Getters
	static std::string SP_DC() {
		return Settings::instance()._SP_DC;
	}
	static bool lyricsVisible() {
		return Settings::instance()._lyricsVisible;
	}
	static Theme theme() {
		return Settings::instance()._theme;
	}
	static std::string imagePath() {
		return Settings::instance()._imagePath;
	}
	static uint32_t fps() {
		return Settings::instance()._fps;
	}
	static uint32_t fontSize() {
		return Settings::instance()._fontSize;
	}
	static uint32_t idleUpdateDelay() {
		return Settings::instance()._idleUpdateDelay;
	}
	static int32_t delayOffset() {
		return Settings::instance()._delayOffset;
	}

	// Setters
	static void setSP_DC(std::string& value) {
		Settings::instance()._SP_DC = value;
	}
	static void setLyricsVisible(bool value) {
		Settings::instance()._lyricsVisible = value;
	}
	static void setTheme(Theme theme) {
		Settings::instance()._theme = theme;
	}
	static void setImagePath(std::string& value) {
		Settings::instance()._imagePath = value;
	}
	static void setFps(uint32_t value) {
		Settings::instance()._fps = value;
	}
	static void setFontSize(uint32_t value) {
		Settings::instance()._fontSize = value;
	}
	static void setIdleUpdateDelay(uint32_t value) {
		Settings::instance()._idleUpdateDelay = value;
	}
	static void setDelayOffset(int32_t value) {
		Settings::instance()._delayOffset = value;
	}
};