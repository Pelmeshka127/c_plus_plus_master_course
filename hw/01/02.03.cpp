#include <iostream>
#include <print>

int main() {
    char symbol = 0;
    if (!std::cin.get(symbol)) {
        return 1;
    }
    switch (symbol) {
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
        case 'G': case 'H': case 'I': case 'J': case 'K': case 'L':
        case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R':
        case 'S': case 'T': case 'U': case 'V': case 'W': case 'X':
        case 'Y': case 'Z':
            std::print("Uppercase letter\n");
            break;

        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
        case 'g': case 'h': case 'i': case 'j': case 'k': case 'l':
        case 'm': case 'n': case 'o': case 'p': case 'q': case 'r':
        case 's': case 't': case 'u': case 'v': case 'w': case 'x':
        case 'y': case 'z':
            std::print("Lowercase letter\n");
            break;

        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            std::print("Digit\n");
            break;

        case '!': case '"': case '#': case '$': case '%': case '&':
        case '\'': case '(': case ')': case '*': case '+': case ',':
        case '-': case '.': case '/': case ':': case ';': case '<':
        case '=': case '>': case '?': case '@': case '[': case '\\':
        case ']': case '^': case '_': case '`': case '{': case '|':
        case '}': case '~':
            std::print("Punctuation\n");
            break;

        default:
            std::print("Other\n");
            break;
    }
}
