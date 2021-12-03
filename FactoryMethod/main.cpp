#include <iostream>
#include <memory>
#include <windows.h>

#include "factory_method.h"
#include "class_file.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "specify the path to the folder: ";
	fs::path path;

	std::wcin >> path;

	
	std::unique_ptr<TxtCreator> txt_creator = std::make_unique<TxtCreator>();
	std::unique_ptr<JsonCreator> json_creator = std::make_unique<JsonCreator>();
	

	txt_creator->parseFileDir(path);
	txt_creator->factoryReports(path);
	
	json_creator->parseFileDir(path);
	json_creator->factoryReports(path);
	
	return 0;
}