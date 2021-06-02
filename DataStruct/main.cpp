
#include <memory>

#include <iostream>
#include <map>
#include <list>
#include <bitset>
#include <set>
#include <queue>

using namespace std;

#pragma region   图遍历
//邻接矩阵
template< uint32_t N>
class GraphMatrix
{
public:
    //展示
    void display()const
    {
        for(uint32_t i = 0; i < N; ++i)
        {
            for(uint32_t j = 0; j < N; ++j)
            {
                  if(_graph[i][j])
                  {
                      cout << std::to_string(i) << "," << std::to_string(j) << "   ";
                  }
            }
        }
        cout << endl;
    }
    //添加边
    void addEdge(uint32_t from, uint32_t to)
    {
        if((from < N) && (to < N))
        {
            _graph[from][to] = 1;
        }
    }

    //深度遍历 O(n^2)
    void dfs()
    {
        for(uint32_t i = 0; i < N; ++i)
        {
            if(!_visible[i])
                dfs_step(i);
        }
        cout << endl;
    }
    //广度遍历
    void bfs()
    {
        cout << _graph[0][0] << " ";
        for(uint32_t i = 0; i < N; ++i)
        {
            if(!_visible[i])
            {
                _queue.push(i);
                while(!_queue.empty())
                {
                    bfs_step(_queue.front());
                    _queue.pop();
                }
                    
            }
        }
    }

protected:
    void dfs_step(uint32_t i)
    {
        cout <<  i << " ";
        _visible[i] = 1;
        for(uint32_t j = 0; j < N; ++j)
        {
            if(_graph[i][j] && !_visible[j])
                dfs_step(j);
        }
    }

    void bfs_step(uint32_t i)
    {
        for(uint32_t j = 0 ; j < N; ++j)
        {
            if(_graph[i][j] && !_visible[j])
            {
                cout << j << " ";
                _visible[j] = 1;
                _queue.push(j);
            }
        }
    }
protected:
    uint8_t                 _graph[N][N] = {{0}};
    std::bitset<N>          _visible     = {0};  
    std::queue<uint32_t>    _queue;
};


//邻接链表
class GraphList
{
public:
    using ItemType = map<uint32_t, list<uint32_t> > ;
    //展示
    void display() const
    {
        for(auto item : _graph)
        {
            for(auto va : item.second)
            {
                cout << std::to_string(item.first) << "," << std::to_string(va) << "   ";
            }
        }
        cout << endl;
    }
    //添加边 //深度遍历 O(n + e)
    void addEdge(uint32_t from, uint32_t to)
    {
        _graph[from].emplace_back(to);
    }

    //深度遍历
    void dfs()
    {    
        for(auto item : _graph)
        {
            if(!_visible.count(item.first))
                dfs_step(item.first);
        }
        cout << endl;
    }
    //广度遍历
    void bfs()
    {
        if(_graph.empty())return;
        for(auto item : _graph)
        {
            _queue.push(item.first);
            while(!_queue.empty())
            {
                bfs_step(_queue.front());
                _queue.pop();
            }
            
        }
    }

protected:
    void dfs_step(uint32_t i)
    {
        _visible.insert(i);
        cout << i << " ";
        for(auto iter : _graph[i])
        {
            if(!_visible.count(iter))
                dfs_step(iter);
        }
    }

    void bfs_step(uint32_t i)
    {
        for(auto iter : _graph[i])
        {
            if(!_visible.count(iter))
            {
                _visible.insert(iter);
                cout << iter << " ";
                _queue.push(iter);
            }
        }
    }

protected:
    ItemType        _graph;
    set<uint8_t>    _visible;
    queue<uint32_t> _queue;
};

#pragma unregion


int main(int argc, char **argv)
{
    GraphMatrix<9> graphmtx;
    GraphList      graphlst;

    graphlst.addEdge(0, 1);
    graphlst.addEdge(1, 2);
    graphlst.addEdge(5, 4);
    graphlst.addEdge(4, 3);
    graphlst.addEdge(5, 6);
    graphlst.addEdge(0, 5);
    graphlst.addEdge(6, 7);
    graphlst.addEdge(7, 3);
    graphlst.addEdge(1, 8);
    graphlst.display();
    // graphlst.dfs();
    graphlst.bfs();

    return 0;
}