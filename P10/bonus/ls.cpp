#include "ls.h"
#include <glob.h> // see https://en.wikipedia.org/wiki/Glob_(programming)
#include <string>
#include <vector>

// Return a vector of filenames matching filespec
//   (In C++ 20, std::filesystem will provide an OOP interface at last!)
std::vector<std::string> ls(std::string filespec) {
    glob_t globbuf;
    std::vector<std::string> files;

    if (glob(filespec.c_str(), 0, NULL, &globbuf)) return files;
    for (int i=0;  i<globbuf.gl_pathc; i++) { 
        files.push_back(globbuf.gl_pathv[i]);
    }
    globfree(&globbuf);
    return files;
}

