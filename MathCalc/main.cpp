#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>

double solve_mul_div(const std::string &str) {
    std::vector<std::string> substrings;
    std::string operations;
    std::string current;

    std::string error = "Function solve_mul_div(): invalid expression";

    for(const char &ch : str) {
        if(ch == '*' || ch == '/') {
            //std::cout << current << std::endl;
            if(current.empty())
                throw std::invalid_argument(error);
            substrings.push_back(current);
            operations.push_back(ch);
            current = "";
        }
        else if(std::isdigit(ch) || ch == '.' || ch == '-') {
            current.push_back(ch);
        }
    }
    //std::cout << current << std::endl;
    if(current.empty())
        throw std::invalid_argument(error);
    substrings.push_back(current);

    double res = std::stod(substrings[0]);
    for(int i = 0; i < operations.size(); i++) {
        if(operations[i] == '*')
            res *= std::stod(substrings[i+1]);
        else if(operations[i] == '/')
            res /= std::stod(substrings[i+1]);
    }
    return res;
}

double solve_sum_diff(const std::string &str) {
    std::vector<std::string> substrings;
    std::string operations;
    std::string current;

    std::string error = "Function solve_sum_diff(): invalid expression";

    for(const char &ch : str) {
        if(ch == '+' || ch == '-') {
            if(current.empty())
                current.push_back('0');
            substrings.push_back(current);
            operations.push_back(ch);
            current = "";
        }
        else if(std::isdigit(ch) || ch == '.' || ch == '*' || ch == '/') {
            current.push_back(ch);
        }
    }
    if(current.empty())
        throw std::invalid_argument(error);
    substrings.push_back(current);

    double res = solve_mul_div(substrings[0]);
    for(int i = 0; i < operations.size(); i++) {
        if(operations[i] == '+')
            res += solve_mul_div(substrings[i+1]);
        else if(operations[i] == '-')
            res -= solve_mul_div(substrings[i+1]);
    }
    return res;
}

void replace_brackets(std::string &str) {
    for(char &ch : str) {
        if(ch == '[' || ch == '{')
            ch = '(';
        else if(ch == ']' || ch == '}')
            ch = ')';
    }
}

bool check_correct_brackets(const std::string &str) {
    int count_open = 0, count_close = 0;
    for(const char &ch : str) {
        if(ch == '(')
            count_open++;
        else if(ch == ')')
            count_close++;
    }
    return count_open == count_close;
}

bool search_brackets(const std::string &str) {
    for(const char &ch : str) {
        if(ch == '(' || ch == ')')
            return true;
    }
    return false;
}

std::string solve_round_brackets(const std::string &str) {
    if(search_brackets(str)) {
        std::string new_str, inner_str;
        int index = 0;
        while(str[index] != '(') {
            new_str.push_back(str[index]);
            index++;
        }
        index++;
        int count_brackets = 0;
        while(str[index] != ')' || count_brackets != 0) {
            if(str[index] == '(')
                count_brackets++;
            else if(str[index] == ')')
                count_brackets--;
            //std::cout << str[index] << "\n";
            inner_str.push_back(str[index]);
            index++;
        }
        index++;
        new_str += solve_round_brackets(inner_str);
        while(index < str.size()) {
            new_str.push_back(str[index]);
            index++;
        }
        return solve_round_brackets(new_str);
    }
    else {
        return std::to_string(solve_sum_diff(str));
    }
}

double solve(std::string &str) {
    replace_brackets(str);
    std::string error = "Function check_correct_brackets(): invalid expression";
    if(!check_correct_brackets(str))
        throw std::invalid_argument(error);
    return std::stod(solve_round_brackets(str));
}

int main() {
    std::string str;
    std::cout << "Enter expression: ";
    std::getline(std::cin, str);
    try {
        double res = solve(str);
        std::cout << "Result: " << res << std::endl;
    }
    catch(std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
