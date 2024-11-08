#include<iostream>

int findTotalNumbers(int a, int b) {
    int count = 0;
    for (int i = a; i <= b; i++) {
        int temp = i;
        int sum = 0;
        int product = 1;

        while (temp > 0) {
            int digit = temp % 10;
            sum += digit;
            product *= digit;
            temp /= 10;
        }

        if (product%sum == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    std::cin >> t;
    while (t-- > 0) {
        int a, b;
        std::cin >> a >> b;
        int n = findTotalNumbers(a, b);
        std::cout << n << "\n";
    }
}
