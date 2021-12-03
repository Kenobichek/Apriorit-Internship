#pragma once
#include <string>

class File {
public:

	void setName(std::wstring name);
	void setSize(int size);
	void setExtension(std::wstring extension);
	void setRoot(std::wstring created);

	std::wstring getName();
	int getSize();
	std::wstring getExtension();
	std::wstring getRoot();

private:
	std::wstring name_;
	int size_;
	std::wstring extension_;
	std::wstring root_;
};