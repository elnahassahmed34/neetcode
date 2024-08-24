#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    // Encode a list of strings to a single string
    std::string encode(std::vector<std::string>& strs) {
        std::string encoded = "";
        for (const std::string& str : strs) {
            encoded += std::to_string(str.size()) + "#" + str;
        }
        return encoded;
    }

    // Decode a single string back to a list of strings
    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> decoded;
        size_t i = 0;
        while (i < s.size()) {
            // Find the position of the delimiter '#'
            size_t pos = s.find('#', i);
            // Get the length of the string
            int len = std::stoi(s.substr(i, pos - i));
            // Extract the string of length 'len' after the delimiter
            decoded.push_back(s.substr(pos + 1, len));
            // Move the index to the next string's length
            i = pos + 1 + len;
        }
        return decoded;
    }
};

// Example usage
int main() {
    Solution solution;

    // Example 1
    std::vector<std::string> input1 = {"neet", "code", "love", "you"};
    std::string encoded1 = solution.encode(input1);
    std::vector<std::string> decoded1 = solution.decode(encoded1);

    std::cout << "Encoded: " << encoded1 << std::endl;
    std::cout << "Decoded: ";
    for (const std::string& str : decoded1) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    // Example 2
    std::vector<std::string> input2 = {"we", "say", ":", "yes"};
    std::string encoded2 = solution.encode(input2);
    std::vector<std::string> decoded2 = solution.decode(encoded2);

    std::cout << "Encoded: " << encoded2 << std::endl;
    std::cout << "Decoded: ";
    for (const std::string& str : decoded2) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
