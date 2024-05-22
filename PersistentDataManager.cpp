#include "PersistentDataManager.h"

void PersistentDataManager::printValue(Value& value, std::ofstream& outfile) {
	if (auto* val = std::get_if<std::string>(&value)) {
		outfile << val;
	} else if (auto* val = std::get_if<bool>(&value)) {
		if (*val == true)
			outfile << "true";
		else
			outfile << "false";
	} else if (auto* n = std::get_if<uint32_t>(&value)) {
		outfile << *n;
	} else if (auto* n = std::get_if<int32_t>(&value)) {
		outfile << *n;
	} else if (auto* n = std::get_if<uint64_t>(&value)) {
		outfile << *n;
	} else if (auto* n = std::get_if<int64_t>(&value)) {
		outfile << *n;
	}
}

void PersistentDataManager::saveToDisk(
	File file,
	std::map<std::string, Value>& map
) {
	std::string filePath = appDataFolder + files.at(file);
	std::ofstream outfile(filePath);

	if(!outfile.is_open())
		throw std::exception("Failed to open output file");

	for (auto& [key, value] : map) {
		outfile << key << ": ";
		printValue(value, outfile);
	}

	outfile.close();
}

void PersistentDataManager::saveToDisk(
	File file,
	std::vector<Value>& vec
) {
	std::string filePath = appDataFolder + files.at(file);
	std::ofstream outfile(filePath);

	if (!outfile.is_open())
		throw std::exception("Failed to open output file");

	for (auto& val : vec) {
		printValue(val, outfile);
	}

	outfile.close();
}