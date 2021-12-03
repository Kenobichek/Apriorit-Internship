#pragma once

#include <vector>
#include <filesystem>

#include <fstream>
#include <iostream>

#include "class_file.h"

namespace fs = std::filesystem;

class Creator {
public:
	void parseFileDir(fs::path path);
	virtual void factoryReports(fs::path path) = 0;
protected:
	std::vector<File> vector_files;
};

class TxtCreator : public Creator {
public:
	void factoryReports(fs::path path) override;
};

class JsonCreator : public Creator {
public:
	void factoryReports(fs::path path) override;
};