/*
    srcMLXPathCount_t.cpp

    Tests for srcMLXPathCount()
*/

#include "srcMLXPathCount.hpp"
#include <string>
#include <fstream>

int main() {

    {
        std::string srcml = R"(<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<unit xmlns="http://www.srcML.org/srcML/src" revision="1.0.0" language="C++"><decl_stmt><decl><type><name>int</name></type> <name>n</name></decl>;</decl_stmt></unit>
)";

        std::ofstream out("test1.xml");
        out << srcml;
        out.close();

        const char* xpath = "count(//src:decl)";

        assert(srcMLXPathCount("test1.xml", xpath) == 1);
    }

    return 0;
}
