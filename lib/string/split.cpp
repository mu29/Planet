#include "split.h"

std::vector<std::string> split(std::string source, char delimeter) {
    std::vector<std::string> result;
    std::string piece = "";
    for (int i = 0; i < source.size(); i++) {
        if (source[i] != delimeter) {
            piece += source[i];
        } else {
            result.push_back(piece);
            piece = "";
        }
    }

    return result;
}
