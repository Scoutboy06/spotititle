#pragma once

#include <string>
#include <map>
#include <unordered_map>
#include <variant>
#include <fstream>
#include <exception>

using Value = std::variant<
	std::string,
	bool,
	uint32_t, int32_t, uint64_t, int64_t
>;

const std::string appDataFolder = "%appdata%/Spotititle/";

enum class File { Settings };
const std::unordered_map<File, std::string> files = {
	{File::Settings, "settings.json"}
};

class PersistentDataManager {
private:
	static void printValue(Value& value, std::ofstream& outfile);

public:
	static void saveToDisk(File file, std::map<std::string, Value>& map);

	static void saveToDisk(File file, std::vector<Value>& vec);
};

