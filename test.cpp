#include <iostream>
#include <set>

int main() {
    // 初始化包含重复元素的 set
    std::set<int> mySet = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    // 遍历 set 并输出元素
    for (const auto& element : mySet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}