#include "factory_method.h"

void Creator::parseFileDir(fs::path path) {
    try {
        for (const auto& path_tmp : fs::recursive_directory_iterator(path)) {
            File file_tmp;
            fs::path p = path_tmp;

            file_tmp.setName(p.filename());
            file_tmp.setSize(static_cast<int>(path_tmp.file_size()));
            file_tmp.setExtension(p.extension());
            file_tmp.setRoot(p.root_name());

            vector_files.push_back(file_tmp);
        }
    }
    catch (fs::filesystem_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

void TxtCreator::factoryReports(fs::path path) {

    path /= "reports.txt";

    std::wofstream ofs(path);

    for (int i = 0; i < vector_files.size(); i++) {
        ofs << "name: " << vector_files[i].getName() << "\n";
        ofs << "size: " << vector_files[i].getSize() << "\n";
        ofs << "extension: " << vector_files[i].getExtension() << "\n";
        ofs << "root: " << vector_files[i].getRoot() << "\n\n";
    }

    ofs.close();
}

void JsonCreator::factoryReports(fs::path path) {

    path /= "reports.json";

    std::wofstream ofs(path);

    ofs << "[\n";

    for (int i = 0; i < vector_files.size(); i++) {
        ofs << "{\n";
        ofs << "    \"name\": \""  << vector_files[i].getName() << "\",\n";
        ofs << "    \"size\": " << vector_files[i].getSize() << ",\n";
        ofs << "    \"extension\": \"" << vector_files[i].getExtension() << "\",\n";
        ofs << "    \"root\": \"" << vector_files[i].getRoot() << "\"\n";

        i + 1 == static_cast<int>(vector_files.size()) ? ofs << "}\n" : ofs << "},\n";
    }

    ofs << "]\n";

    ofs.close();
}