#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout <<"enter how many matrix you want to generate : " << endl;
    int t;
    cin >> t;

    srand( time(NULL) );
    while(t--)
    {
        int vertex, edges;
        vertex = (rand()%5 + 5);
        edges = (rand()%(vertex*(vertex-1)));
        int graph[vertex][edges];
        int AdjMatrix[vertex][vertex];
        for(int i = 0; i < vertex; i++)
        {
            for(int j = 0; j < edges; j++)
            {
                graph[i][j] = 0;
            }
        }
        for(int i = 0; i < vertex; i++)
        {
            for(int j = i; j < vertex; j++)
            {
                AdjMatrix[i][j] = 0; AdjMatrix[j][i] = 0;
            }
        }
        for(int i = 0; i < edges; i++)
        {
            int s = rand()%vertex;
            int d = rand()%vertex;
            while(s == d)
            {
                d = rand()%vertex;
            }
            graph[s][i]++;graph[d][i]++;
        }
        for(int i = 0; i < edges; i++)
        {
            int firstOne, lastOne;
            bool flag = true;
            for(int j = 0; j < vertex; j++)
            {
                if( graph[j][i] == 1 && flag)
                {
                    firstOne = j;
                    flag = false;
                }
                if( graph[j][i] == 1 && !flag)
                {
                    lastOne = j;
                }
            }
            AdjMatrix[firstOne][lastOne]++;
            AdjMatrix[lastOne][firstOne]++;
        }
        cout << "Incidence Matrix : " << endl;
        for(int i = 0; i < vertex; i++)
        {
            for(int j = 0; j < edges; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
        cout<<"------------------------------------------"<<endl;
        cout << "Adj Matrix : " << endl;
        for(int i = 0; i < vertex; i++)
        {
            for(int j = 0; j < vertex; j++)
            {
                cout << AdjMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << "********************************************" << endl;
    }
    return 0;
}
