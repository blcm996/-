#include <iostream>
#include <vector>
#include <memory>
#include <string>

// 基类：所有术语类型的基础
class Term {
public:
    virtual void print() const = 0;
    virtual ~Term() {}
};

// 符号术语
class SymbolTerm : public Term {
private:
    std::string symbol;
public:
    SymbolTerm(const std::string& sym) : symbol(sym) {}
    void print() const override {
        std::cout << symbol;
    }
};

// 变量术语
class VariableTerm : public Term {
private:
    std::string variable;
public:
    VariableTerm(const std::string& var) : variable(var) {}
    void print() const override {
        std::cout << variable;
    }
};

// 函数应用术语
class FunctionTerm : public Term {
private:
    std::string functionName;
    std::vector<std::shared_ptr<Term>> arguments;
public:
    FunctionTerm(const std::string& funcName, const std::vector<std::shared_ptr<Term>>& args)
        : functionName(funcName), arguments(args) {}
    void print() const override {
        std::cout << functionName << "(";
        for (size_t i = 0; i < arguments.size(); ++i) {
            arguments[i]->print();
            if (i < arguments.size() - 1) std::cout << ", ";
        }
        std::cout << ")";
    }
};

// 创建和使用术语
int main() {
    std::shared_ptr<Term> sym = std::make_shared<SymbolTerm>("x");
    std::shared_ptr<Term> var = std::make_shared<VariableTerm>("y");
    std::vector<std::shared_ptr<Term>> args = {sym, var};
    std::shared_ptr<Term> func = std::make_shared<FunctionTerm>("f", args);

    func->print();  // 输出: f(x, y)
    return 0;
}