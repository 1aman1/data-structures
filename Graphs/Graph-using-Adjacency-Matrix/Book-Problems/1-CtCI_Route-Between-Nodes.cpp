/*
This graph uses fixed size matrix

#implements:

>function() routeBetweenNodes
-> checks if path exists from one node to the other
*/
#include <iostream>

#define DEBUG false

class graph
{
private:
    bool _visited[4];
    void initGraphwithFalse();

public:
    bool matGraph[4][4];
    void print();
    bool routeBetweenNodes(int source, int target);
    graph()
    {
        initGraphwithFalse();
    }
};

void graph::print()
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            std::cout << matGraph[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void graph::initGraphwithFalse()
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            matGraph[row][col] = false;
        }
        std::cout << std::endl;
    }
}

bool graph::routeBetweenNodes(int source, int target)
{
    if (source == target)
        return true;
    if (_visited[source] != true)
    {
        _visited[source] = true;

        for (int col = 0; col < 4; ++col)
        {
            if (matGraph[source][col] == true)
            {
                // path exists
                if (col == target)
                    return true;

                return routeBetweenNodes(col, target);
            }
        }
        // path doesn't exist
        return false;
    }
    else
    { // path doesn't exist
        return false;
    }
}

int main()
{
    graph obj;

    obj.matGraph[0][1] = true;
    obj.matGraph[1][2] = true;
    obj.matGraph[2][0] = true;
    obj.matGraph[3][2] = true;

    obj.print();

    int source = 0;
    int target = 2;
    std::cout << "Is " << source << " and " << target << " connected "
              << std::boolalpha
              << obj.routeBetweenNodes(source, target);

    return 0;
}