
// Фабричный метод.
// Написать программу, которая
//   - получает на вход полный путь к папке
//   - собирает список всех файлов в этой папке (можно нерекурсивно), а также их
//     свойства (размер/ время создания, модификации, доступа/ архивный, только для
//     чтения и т.д.), список свойств на Ваш выбор, минимум 2 помимо имени файла.
//   - выводит «отчет» по содержимому папки в файл в формате txt, csv, xml, json –
//     любые 2 или больше на Ваш выбор.
// Используйте фабричный метод.

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
