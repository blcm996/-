#include <iostream>
#include <stdexcept>
#include <string>
#include <variant>

// 定义可能的值类型
using Value = std::variant<bool, int, double, std::string>;

// 打印值
void printValue(const Value& value) {
    std::visit([](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, bool>) {
            std::cout << (arg ? "true" : "false");
        } else if constexpr (std::is_same_v<T, int>) {
            std::cout << arg;
        } else if constexpr (std::is_same_v<T, double>) {
            std::cout << arg;
        } else if constexpr (std::is_same_v<T, std::string>) {
            std::cout << arg;
        }
    }, value);
    std::cout << std::endl;
}

// 从值中提取布尔值
bool boolFromValue(const Value& value) {
    if (std::holds_alternative<bool>(value)) {
        return std::get<bool>(value);
    } else {
        throw std::invalid_argument("Value is not a boolean");
    }
}

// 从值中提取整数
int intFromValue(const Value& value) {
    if (std::holds_alternative<int>(value)) {
        return std::get<int>(value);
    } else {
        throw std::invalid_argument("Value is not an integer");
    }
}

// 从值中提取浮点数
double doubleFromValue(const Value& value) {
    if (std::holds_alternative<double>(value)) {
        return std::get<double>(value);
    } else {
        throw std::invalid_argument("Value is not a double");
    }
}

// 主函数
int main() {
    try {
        Value v1 = true;
        Value v2 = 42;
        Value v3 = 3.14;
        Value v4 = std::string("Hello");

        printValue(v1);
        printValue(v2);
        printValue(v3);
        printValue(v4);

        std::cout << "Boolean from v1: " << boolFromValue(v1) << std::endl;
        std::cout << "Integer from v2: " << intFromValue(v2) << std::endl;
        std::cout << "Double from v3: " << doubleFromValue(v3) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
/*
代码解释
Value 类型：使用 std::variant 来定义一个可以存储布尔值、整数、浮点数或字符串的类型。
printValue 函数：使用 std::visit 和 lambda 表达式来根据存储的值类型打印不同的输出。
boolFromValue, intFromValue, doubleFromValue 函数：这些函数尝试从 Value 中提取特定类型的值，如果类型不匹配，则抛出异常。
main 函数：创建不同类型的值，演示如何打印和提取这些值，并处理可能的异常。
*/