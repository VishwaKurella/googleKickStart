#include <climits>
#include <cmath>
#include <iostream>
#include <string>

int minimumNumber(int N) {
    std::string N_str = std::to_string(N);
    int sum = 0;
    for (char c : N_str) {
        sum += (c - '0');
    }
    int min_number = INT_MAX;
    int required_digit = (9 - (sum % 9)) % 9;
    for (int i = 0; i <= N_str.size(); ++i) {
        if (i == 0 && required_digit == 0 && N_str.size() > 1) continue;
        std::string new_number_str = N_str.substr(0, i) + std::to_string(required_digit) + N_str.substr(i);
        int new_number = std::stoi(new_number_str);
        min_number = std::min(min_number, new_number);
    }
    return min_number;
}

int main() {
    int t;
    std::cin >> t;
    int c = 1;

    while (t-- > 0) {
        int N;
        std::cin >> N;
        int result = minimumNumber(N);

        std::cout << "Case #" << c << ": " << result << "\n";
        c++;
    }

    return 0;
}
