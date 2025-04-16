#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int max_lines = 100;
const int max_TAGS = 100;

class TagStack {
    char name[max_TAGS][50];
    int line[max_TAGS];
    int top;

public:
    TagStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(const char* tagName, int lineNum) {
        if (top < max_TAGS - 1) {
            ++top;
            strcpy_s(name[top], tagName);  
            line[top] = lineNum;
        }
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        }
    }

    const char* peekName() {
        if (!isEmpty()) {
            return name[top];
        }
        return "";
    }

    int peekLine() {
        if (!isEmpty()) {
            return line[top];
        }
        return -1;
    }
};

bool isOpeningTag(const char* tag) {
    return tag[0] != '/';
}

void extractTagName(const char* fullTag, char* tagName) {
    if (fullTag[0] == '/') {
        strcpy_s(tagName, 50, fullTag + 1);
    }
    else {
        strcpy_s(tagName, 50, fullTag);
    }
}

void validateHTMLFromFile(const char* filename) {
    TagStack stack;
    char line[256];
    int lineNum = 0;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open the file.\n";
        return;
    }

    while (file.getline(line, sizeof(line)) && lineNum < max_lines) {
        lineNum++;
        size_t len = strlen(line);

        for (size_t i = 0; i < len; ++i) {
            if (line[i] == '<') {
                char tag[50] = "";
                size_t j = i + 1, k = 0;

                while (j < len && line[j] != '>') {
                    if (k < 49) tag[k++] = line[j++];
                    else break; 
                }
                tag[k] = '\0';

                if (strlen(tag) == 0) continue;

                char tagName[50];
                extractTagName(tag, tagName);

                if (isOpeningTag(tag)) {
                    stack.push(tagName, lineNum);
                }
                else {
                    if (!stack.isEmpty() && strcmp(stack.peekName(), tagName) == 0) {
                        stack.pop();
                    }
                    else {
                        cout  << tagName << "> has no matching opening tag (Line " << lineNum << ")\n";
                    }
                }

                i = j;
            }
        }
    }

    while (!stack.isEmpty()) {
        cout << stack.peekName() << "> opened on line " << stack.peekLine() << " was not closed.\n";
        stack.pop();
    }

    file.close();
}

int main() {
    const char* filename = "filename.txt";
    validateHTMLFromFile(filename);
    return 0;
}

