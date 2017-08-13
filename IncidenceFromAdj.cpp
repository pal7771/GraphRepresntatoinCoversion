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
        vertex = (rand()%10 + 5);
        int graph[vertex][vertex];
        for(int i = 0; i < vertex; i++)
        {
            for(int j = i; j < vertex; j++)
            {
                graph[i][j] = 0;graph[j][i]=0;
            }
        }
        edges = (rand()%(vertex*(vertex-1)));
        for(int i = 0; i < edges; i++)
        {
            int s = rand()%vertex;
            int d = rand()%vertex;
            while(s == d)
            {
                d = rand()%vertex;
            }
            graph[s][d]++;graph[d][s]++;
        }

        int IncidenceMatrix[vertex][edges];

        for(int i = 0; i < vertex; i++)
        {
            for(int j = 0; j < edges; j++)
            {
                IncidenceMatrix[i][j] = 0;
            }
        }
        int index = 0;
        for(int i = 0; i < vertex; i++)
        {
            for(int j = i+1; j < vertex; j++)
            {
                int cnt = graph[i][j];
                while( cnt > 0 )
                {
                    IncidenceMatrix[i][index]++;
                    IncidenceMatrix[j][index]++;
                    cnt--;
                    index++;
                }
            }
        }
        cout << "Adj Matrix : " << endl;
        for(int i = 0; i < vertex; i++)
        {
            for(int j = 0; j < vertex; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-----------------------------------" << endl;
        cout << "Incidence Matrix : " << endl;
        for(int i = 0; i < vertex; i++)
        {
            for(int j = 0; j < edges; j++)
            {
                cout << IncidenceMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << "*********************************************" << endl;
    }
    return 0;
}
