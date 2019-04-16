#ifndef A_PATHFINDING_H
#define A_PATHFINDING_H

#ifndef CORDINATE_H
#define CORDINATE_H
#pragma once

#include <stack>
#include <vector>
#include <array>

#define X_MAX 1000
#define X_STEP 20
#define Y_MAX 500
#define Y_STEP 20

struct Node
{
    int y;
    int x;
    int parentX;
    int parentY;
    float gCost;
    float hCost;
    float fCost;
};

inline bool operator < (const Node& lhs, const Node& rhs){
    /*! Necesitamos sobrecargar "<" para poner nuestra estructura en un conjunto*/
    return lhs.fCost < rhs.fCost;
}

class Pathfinding {

    public:
        static bool isValid(int x, int y);
        static bool isDestination(int x, int y, Node dest);
        double calculateH(int x, int y, Node dest);
        static vector<Node> makePath(array<array<Node, (Y_MAX / Y_STEP)>, (X_MAX / X_STEP)> map, Node dest);
        static vector<Node> Pathfinding::aStar(Node player, Node dest);
};


#endif //A_PATHFINDING_H
