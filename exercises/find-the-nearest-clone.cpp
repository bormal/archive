// https://www.hackerrank.com/challenges/find-the-nearest-clone/problem


#include <algorithm>
#include <iterator>

using namespace std;

class Graph {
    private:
        vector<vector<int>> graph;
        vector<int> colors;
        int color;

        set<int> clones;

        set<int> discovered;
        deque<int> queue;
        vector<int> distance;


        void fillShortestPathes(int node) {
            distance.resize(graph.size());
            for(auto &d: distance) {
                d = -1;
            }
            discovered.clear();

            discovered.insert(node);
            distance[node] = 0;
            queue.push_back(node);

            while(! queue.empty()) {
                int v = queue.front();
                queue.pop_front();

                for(int w: graph[v]) {
                    if(discovered.count(w) == 0) {
                        discovered.insert(w);
                        distance[w] = distance[v] + 1;
                        queue.push_back(w);

                    }
                }
            }

            trace(node, distance);
        }


    public:
        Graph(int n) { graph.resize(n); }

        void add(int v, int u) {
            graph[v].emplace_back(u);
            graph[u].emplace_back(v);
        }

        void setColors(vector<int> colors) {
            copy(begin(colors), end(colors), back_inserter(this->colors));
        }

        int setClones(int color) {
            for(size_t i = 0; i != colors.size(); ++i) {
                if(colors[i] == color) {
                    clones.insert(i);
                }
            }
            trace(clones);

            return clones.size();
        }

        int findMinClonePath(int node) {
            fillShortestPathes(node);

            //find min path to a clone node
            int minDist = graph.size() + 1;
            for(int c: clones) {
                if(c != node) {
                    minDist = min(minDist, distance[c]);
                }
            }

            if(minDist == (graph.size() + 1)) {
                minDist = -1;
            }

            return minDist;
        }

        int nearestClone(int color) {
            this->color = color; 
            if(setClones(color) < 2) {
                return -1;
            }

            int minPath = graph.size() + 1;
            for(int node: clones) {
                minPath = min(minPath, findMinClonePath(node));
            }

            return minPath;
        }
};

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n, m;

    cin >> n >> m;
    trace(n, m);
    Graph graph(n);

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        graph.add(v, u);
    }

    vector<int> colors(n);
    for(int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    trace(colors);

    graph.setColors(colors);

    // trace(colors);

    int color;
    cin >> color;
    fout << graph.nearestClone(color) << endl;

    fout.close();
    return 0;
}
