#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>


//create an enum class called TokenType with the values: Article,Subject,Verb,Preposition,Object
enum class TokenType {
    Article,
    Noun,
    Pronoun,
    AuxiliaryVerb,
    Verb,
    Preposition,
};

// Function to find the index of an element in a vector
//int findIndex(const std::vector<TokenType>& vec, const TokenType &target) {
//    auto it = std::find_if(vec.begin(), vec.end(), [&target](const TokenType& token){ return token == target; });
//    if (it != vec.end()) {
//        return std::distance(vec.begin(), it); // Calculate index if found
//    } else {
//        return -1; // Return -1 if not found
//    }
//}

//create a class called Tokenizer
//class Tokenizer {
//private:
//    std::unordered_map<std::string, TokenType> wordTokenTypeMap;
//
//public:
//    Tokenizer() {}
//
//    // Add a word and its corresponding token type
//    void addWord(const std::string& word, TokenType type) {
//        wordTokenTypeMap[word] = type;
//    }
//
//    // Load mappings from a file
//    void loadMappingsFromFile(const std::string& filename) {
//        std::ifstream file(filename);
//        if (!file.is_open()) {
//            std::cerr << "Failed to open file: " << filename << std::endl;
//            return;
//        }
//
//        std::string word;
//        std::string tokenTypeStr;
//        while (file >> word >> tokenTypeStr) {
//            TokenType type;
//            if (tokenTypeStr == "Article") {
//                type = TokenType::Article;
//            } else if (tokenTypeStr == "Noun") {
//                type = TokenType::Noun;
//            }else if (tokenTypeStr == "Pronoun") {
//                type = TokenType::Pronoun;
//            }else if (tokenTypeStr == "Auxiliaryverb") {
//                type = TokenType::AuxiliaryVerb;
//            } else if (tokenTypeStr == "Verb") {
//                type = TokenType::Verb;
//            } else if (tokenTypeStr == "Preposition") {
//                type = TokenType::Preposition;
//            } else {
//                std::cerr << "Invalid token type: " << tokenTypeStr << std::endl;
//                continue;
//            }
//            addWord(word, type);
//        }
//        file.close();
//    }
//
//    // Tokenize a sentence
//    std::vector<TokenType> tokenize(const std::string& sentence) const {
//        std::vector<TokenType> tokens;
//        std::string word;
//        for (char c : sentence) {
//            if (std::isspace(c)) {
//                if (!word.empty()) {
//                    auto it = wordTokenTypeMap.find(word);
//                    if (it != wordTokenTypeMap.end()) {
//                        tokens.push_back(it->second);
//                    }
//                    word.clear();
//                }
//            } else {
//                word.push_back(c);
//            }
//        }
//        if (!word.empty()) {
//            auto it = wordTokenTypeMap.find(word);
//            if (it != wordTokenTypeMap.end()) {
//                tokens.push_back(it->second);
//            }
//        }
//        return tokens;
//    }
//};

//bool is_valid_sentence(const Tokenizer& tokenizer, const std::string& sentence) {
//    auto tokens = tokenizer.tokenize(sentence);
//    if (std::find_if(tokens.begin(), tokens.end(), [](const TokenType& token){ return token == TokenType::Noun; }) == tokens.end() ||
//        std::find_if(tokens.begin(), tokens.end(), [](const TokenType& token){ return token == TokenType::Verb; }) == tokens.end()) {
//        return false;
//    }else if (std::find_if(tokens.begin(), tokens.end(), [](const TokenType& token){ return token == TokenType::Noun; }) != tokens.end()) {
//        int main_verb = findIndex(tokens, TokenType::Verb);
//        int object_index = findIndex(tokens, TokenType::Noun);
//        if (main_verb > object_index) {
//            return false;
//        }
//    }else if (std::find_if(tokens.begin(), tokens.end(), [](const TokenType& token){ return token == TokenType::Article; }) != tokens.end()) {
//        int article_index = findIndex(tokens, TokenType::Article);
//        int object_index = findIndex(tokens, TokenType::Noun);
//        if (article_index >= object_index) {
//            return false;
//        }
//    }
//    return true;
//}




////create a struct called Token with the following fields: type, value
//struct Token {
//    TokenType type;
//    std::string lexeme;
//};

////create a function called lex that takes a string and returns a vector of Tokens
//std::vector<Token> lex(const std::string &input) {
//    std::vector<Token> tokens;
//    std::string word;
//    for (char c : input) {
//        if (c == ' ') {
//            if (word == "the" || word == "a" || word == "an" || word == "The" || word == "A" || word == "An") {
//                tokens.push_back({TokenType::Article, word});
//            } else if (word == "cat" || word == "dog") {
//                tokens.push_back({TokenType::Subject, word});
//            } else if (word == "ran" || word == "ate") {
//                tokens.push_back({TokenType::Verb, word});
//            } else if (word == "on" || word == "under") {
//                tokens.push_back({TokenType::Preposition, word});
//            } else if (word == "mat" || word == "dog") {
//                tokens.push_back({TokenType::Object, word});
//            }
//            word = "";
//        } else {
//            word += c;
//        }
//    }
//    return tokens;
//}

////create a function called parse that takes a vector of Tokens and returns a boolean
//bool parse(const std::vector<Token> &tokens) {
//    if (tokens.size() != 5) {
//        return false;
//    }
//    if (tokens[0].type != TokenType::Article) {
//        return false;
//    }
//    if (tokens[1].type != TokenType::Subject) {
//        return false;
//    }
//    if (tokens[2].type != TokenType::Verb) {
//        return false;
//    }
//    if (tokens[3].type != TokenType::Preposition) {
//        return false;
//    }
//    if (tokens[4].type != TokenType::Object) {
//        return false;
//    }
//    return true;
//}
//
////create a function called print that takes a vector of Tokens and returns nothing
//void print(const std::vector<Token> &tokens) {
//    for (const Token &token : tokens) {
//        std::cout << token.lexeme << " ";
//    }
//    std::cout << std::endl;
//}

//create a function called main that takes no arguments and returns an int

int main() {
    // Create a Tokenizer
//    Tokenizer tokenizer;
//    tokenizer.loadMappingsFromFile("mappings.txt");
//    tokenizer.tokenize("the cat ran on the mat");
//    tokenizer.tokenize("the cat is going to school ");
//    is_valid_sentence(tokenizer, "the cat is going to school");
    return 0;
}
