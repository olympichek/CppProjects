#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

vector<vector<string>> input(const string &filename) {
    vector<vector<string>> text;
    string line;
    ifstream fin(filename);
    while(!fin.eof()) {
        getline(fin, line);
        istringstream ss(line);
        vector<string> words;
        string word;
        while(getline(ss, word, ' '))
            words.push_back(word);
        text.push_back(words);
    }
    fin.close();
    return text;
}

void modify(vector<vector<string>> &text) {
    for(int i = 0, n = text.size(); i < n; i++) {
        for(int j = 0, m = text[i].size(); j < m; j++) {
            if(text[i][j] == "a" || text[i][j] == "an" || text[i][j] == "the") {
                if((j + 1) != m) {
                    text[i][j + 1][0] = toupper(text[i][j + 1][0]);
                }
                else {
                    if((i + 1) != n)
                        text[i + 1][0][0] = toupper(text[i + 1][0][0]);
                }
            }
        }
    }
}

void output(const string &filename, const vector<vector<string>> &text) {
    ofstream fout(filename);
    for(const auto &line : text) {
        for(const auto &word : line)
            fout << word << " ";
        fout << "\n";
    }
    fout.close();
}

int main() {
    string filename;
    cout << "Enter input file's name: ";
    cin >> filename;
    auto text = input(filename);
    modify(text);
    cout << "Enter output file's name: ";
    cin >> filename;
    output(filename, text);
    cout << "Done!" << endl;
    return 0;
}
