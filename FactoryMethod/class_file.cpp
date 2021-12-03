#include "class_file.h"

void File::setName(std::wstring name) {
	name_ = name;
}

void File::setSize(int size) {
	size_ = size;
}

void File::setExtension(std::wstring extension) {
	extension_ = extension;
}

void File::setRoot(std::wstring root) {
	root_ = root;
}

std::wstring File::getName() {
	return name_;
}

int File::getSize() {
	return size_;
}

std::wstring File::getExtension() {
	return extension_;
}

std::wstring File::getRoot() {
	return root_;
}
