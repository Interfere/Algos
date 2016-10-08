#include <iostream>
#include "Trie.hpp"

int main() {
    std::vector<std::string> words{ "cat", "one", "something", "someone" };
    Trie tr(words);

    if (tr.find("a")) {
        std::cerr << "Failed: a" << std::endl;
        return 1;
    }

    if (tr.find("ca")) {
        std::cerr << "Failed: ca" << std::endl;
        return 1;
    }

    if (!tr.find("cat")) {
        std::cerr << "Failed: cat" << std::endl;
        return 1;
    }

    std::cout << "Success!" << std::endl;
    return 0;
}
