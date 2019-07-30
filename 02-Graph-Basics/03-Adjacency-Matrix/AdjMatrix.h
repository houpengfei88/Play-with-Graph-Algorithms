//
// Created by 候鹏飞 on 2019-07-30.
//

#ifndef GRAPH_ADJMATRIX_H
#define GRAPH_ADJMATRIX_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

class AdjMatrix {
public:
    AdjMatrix(std::string filename) {
        V = 0;
        E = 0;
        OK = false;
        adj = nullptr;
        std::string str;
        std::stringstream ss;
        int a = 0, b = 0;
        std::ifstream fin(filename);
        if (!fin.is_open()) {
            std::cout << "Open File Failed!" << std::endl;
            return;
        }

        if (std::getline(fin, str)) {
            ss << str;
            ss >> V >> E;
            ss.clear();
        } else {
            std::cout << "File is Empty!" << std::endl;
            return;
        }

        if (V <= 0) {
            std::cout << "V is less than or equal to 0!" << std::endl;
            return;
        }
        adj = new int *[V];
        for (int i = 0; i < V; ++i) {
            adj[i] = new int[V];
        }
        for (int j = 0; j < V; ++j) {
            for (int i = 0; i < V; ++i) {
                adj[j][i] = 0;
            }
        }
        for (int k = 0; k < E; ++k) {
            if(!std::getline(fin, str)) {
                std::cout << "Read Empty!" << std::endl;
                return;
            }
            ss << str;
            ss >> a >> b;
            adj[a][b] = 1;
            adj[b][a] = 1;
            ss.clear();
        }
        OK = true;
        fin.close();

    }

    void print() {
        if(!OK){
            std::cout << "Error!" << std::endl;
            return;
        }
        std::cout << "V = " << V << ", E = " << E << std::endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                std::cout << adj[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int V;
    int E;
    bool OK;
    int **adj;
};

#endif //GRAPH_ADJMATRIX_H
