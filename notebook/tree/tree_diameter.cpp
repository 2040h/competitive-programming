// Versión con DFS

// Tengo que tener calculado previamente el nivel de cada vértica para una raíz cualquiera

struct TreeDiameter{
    vector<vector<int>> adjList;
    vector<int> levelOfNode;
    vector<bool> visited;

    TreeDiameter(vector<vector<int>> &adjListArg){
        adjList = adjListArg;
        levelOfNode.resize(SIZE(adjList), UNDEFINED);
        visited.resize(SIZE(adjList), false);
    }

    void calculateLevels(int v, int currentLevel){
        levelOfNode[v] = currentLevel;
        visited[v] = true;

        for (int u : adjList[v]){
            if (!visited[u]) calculateLevels(u, currentLevel+1);
        }
    }


    int getOneVertexOfDiameter(){
        visited.assign(n, false); // Por las dudas marco todo como no visitado antes de correr el DFS
        calculateLevelsFrom(0, 0);
        int res = UNDEFINED;
        int currentLevel = -1;

        forn(i, SIZE(adjList)){
            if (visited[i] && levelOfNode[i] > currentLevel){
                currentLevel = levelOfNode[i];
                res = i;
            }
        }

        return res;
    }

    int treeDiameter(){
        int vertexOfDiameter = 
    }

}





vector<int> getOneVertexOfDiameter(vector<int> &adjList){
    int maxLevel = levelOfNode[0];
    int res = 0;

    forn(i, SIZE(levelOfNode)){
        if (levelOfNode[i] > levelOfNode[res]) res = i;
    }

    return res;
}

int getDiameterOfVertex(vector<vector<int>> &adjList, vector<int> &levelOfNode){
    int vertexOfDiameter = getOneVertexOfDiameter(levelOfNode);
    calculateLevels()

}


