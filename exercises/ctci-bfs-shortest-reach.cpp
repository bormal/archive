/*
https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach
https://en.wikipedia.org/wiki/Breadth-first_search
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;


class Graph {
  private:
    int n;
    int s;

    multimap<int, int> edges;
    vector<int> path;
    set<int> discovered;
    deque<int> queue;

  public:
    Graph(int n) : n(n) {
        path.reserve(n);
        path.resize(n);
        for(auto &p: path) {
            p = -1;
        }
    }

    void addEdge(int u, int v) {
        edges.insert({u-1, v-1});
    }

    void fillPath(int s) {
      s = s - 1;
      this->s = s;

      discovered.insert(s);
      queue.push_back(s);

      while (!queue.empty()) {
        int v = queue[0];
        queue.pop_front();

        auto p = edges.equal_range(v);
        for (auto it = p.first; it != p.second; it++) {
          int w = it->second;

          if (discovered.count(w) == 0) {
            discovered.insert(w);

            path[w] = v;
            // printf("discover: %d <- %d\n", w, v);
            queue.push_back(w);
          }
        }
      }
    }

    void printV(vector<int> const & vect, string const & str) {
        cout << str << " ";
        for(auto const &v : vect)
            cout << v << " ";
        cout << endl;
    }

    vector<int> processPath() {
        vector<int> length;
        // printV(path, "path");
        for(size_t i = 0; i != path.size(); i++) {
            if(i != s) {
                if(path[i] == -1) {
                    length.push_back(-1);
                }
                else {
                    int count = 0;
                    for(size_t index = path[i]; index != -1; index = path[index]) {
                        count++;
                    }
                    length.push_back(count * 6);
                }
            }
        }
        
        return length;
    }
};

int main() {
    int q;
    cin >> q;

    for(int itQ = 0; itQ < q; itQ++) {
        int n, m;
        cin >> n >> m;
        Graph graph(n);

        for(int itM = 0; itM < m; itM++) {
            int u, v;
            cin >> u >> v;
            graph.addEdge(u, v);
            graph.addEdge(v, u);
        }

        int s;
        cin >> s;

        graph.fillPath(s);

        auto lengths = graph.processPath();

        for (size_t i = 0; i != lengths.size(); i++) {
          cout << lengths[i] << " ";
        }
        cout << endl;
    }
}
