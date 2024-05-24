// Graph.h
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Node {
public:
    std::string name;
    std::vector<Node*> edges;

    Node(const std::string& name) : name(name) {}
    void addEdge(Node* node) {
        edges.push_back(node);
    }
};

class Graph {
    std::unordered_map<std::string, Node*> nodes;

public:
    Graph() {
        // 构造函数中不再直接初始化，而是留给一个专门的方法
    }

    ~Graph() {
        // 清理所有节点
        for (auto& pair : nodes) {
            delete pair.second;
        }
        nodes.clear();
    }

    void addNode(const std::string& nodeName) {
        if (nodes.find(nodeName) == nodes.end()) {
            nodes[nodeName] = new Node(nodeName);
        }
    }

    void addEdge(const std::string& from, const std::string& to) {
        if (nodes.find(from) != nodes.end() && nodes.find(to) != nodes.end()) {
            nodes[from]->addEdge(nodes[to]);
        }
    }

    void buildGraph() {
        // 模拟从系统模型中提取数据并构建图
        addNode("A");
        addNode("B");
        addNode("C");

        addEdge("A", "B");
        addEdge("B", "C");
        addEdge("C", "A");  // 创建一个简单的循环
    }

    void stabilize() {
        std::cout << "Stabilizing the graph with " << nodes.size() << " nodes..." << std::endl;
        // 模拟图的稳定化过程
    }

    void extractInvariants() {
        std::cout << "Extracting invariants from the graph..." << std::endl;
        // 模拟从图中提取不变式的过程
    }
};