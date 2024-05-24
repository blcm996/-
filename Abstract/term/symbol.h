#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

// 基类 Symbol，用于所有类型的符号
class Symbol {
public:
    virtual void print() const = 0;
    virtual ~Symbol() {}
};

// 具体符号类，例如 Boolean 符号
class BooleanSymbol : public Symbol {
private:
    std::string value;  // "TRUE" 或 "FALSE"
public:
    BooleanSymbol(const std::string& val) : value(val) {}
    void print() const override {
        std::cout << value;
    }
};

// 算术符号，例如 PLUS, MINUS
class ArithmeticSymbol : public Symbol {
private:
    std::string operation;  // "PLUS", "MINUS" 等
public:
    ArithmeticSymbol(const std::string& op) : operation(op) {}
    void print() const override {
        std::cout << operation;
    }
};

// 符号表，用于管理和共享符号实例
class SymbolTable {
private:
    std::unordered_map<std::string, std::shared_ptr<Symbol>> symbols;
public:
    std::shared_ptr<Symbol> getSymbol(const std::string& key) {
        auto it = symbols.find(key);
        if (it != symbols.end()) {
            return it->second;
        } else {
            // 根据 key 创建新符号，这里简化处理
            std::shared_ptr<Symbol> newSymbol;
            if (key == "TRUE" || key == "FALSE") {
                newSymbol = std::make_shared<BooleanSymbol>(key);
            } else {
                newSymbol = std::make_shared<ArithmeticSymbol>(key);
            }
            symbols[key] = newSymbol;
            return newSymbol;
        }
    }
};

// 主函数
int main() {
    SymbolTable table;
    auto sym1 = table.getSymbol("TRUE");
    auto sym2 = table.getSymbol("PLUS");
    auto sym3 = table.getSymbol("TRUE");  // 应返回相同的实例

    sym1->print();  // 输出: TRUE
    sym2->print();  // 输出: PLUS
    std::cout << (sym1 == sym3 ? " Same instance" : " Different instance") << std::endl;  // 输出: Same instance

    return 0;
}
/*
Symbol 类：这是一个抽象基类，用于表示所有类型的符号。
BooleanSymbol 和 ArithmeticSymbol 类：这些是具体的符号类，分别表示布尔符号和算术符号。
SymbolTable 类：这个类用于管理符号的实例，确保相同的符号只创建一次，实现了类似于 OCaml 中的哈希共享机制。
main 函数：创建了一个符号表，并从中获取了几个符号实例，演示了符号共享的功能。
这个示例展示了如何在 C++ 中使用面向对象的方法来模拟 OCaml 中的符号处理和共享机制。通过这种方式，我们可以在 C++ 中构建复杂的符号处理逻辑，类似于在 src/utils/symbol.ml 文件中实现的功能。
*/