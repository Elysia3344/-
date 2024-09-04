#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

struct Edge {
    std::string destination;
    int time;
};

class RailwaySystem {
public:
    void addStation(std::string station) {
        graph[station] = std::vector<Edge>();
    }

    void addConnection(std::string source, std::string destination, int time) {
        graph[source].push_back({ destination, time });
        graph[destination].push_back({ source, time });
    }

    /*最短路径是按站点数计算的，而不是按路径长度（即边权重）计算的。
     因此，确认站点数最少的最短路径的过程就是找到从源站点到目标站点的最短路径，其中经过的站点数最少。*/

    //这段代码实现了按照站点数来计算最短路径的 Dijkstra 算法，具体分析如下：

    //    该算法使用了图来表示地铁线路，每个节点表示一个地铁站，每条边表示两个相邻的地铁站之间的连接关系。同时，使用了三个辅助数据结构来记录信息：distances 记录当前已知的从起点到各个节点的最短距离；previous 记录每个节点在最短路径上的前驱节点；visited 记录已经访问过的节点。

    //    1. 初始化
    //    首先将 distances 中所有节点的距离初始化为 INT_MAX，表示当前还不知道从起点到这些节点的最短距离。将起点的距离初始化为 0。

    //    2. 确认起点
    //    在 while 循环中，每次找到 distances 中未被访问过且距离最小的节点作为当前节点。如果当前节点就是终点，则说明已经找到了最短路径，退出循环。否则将当前节点标记为 visited。

    //    3. 更新距离
    //    遍历当前节点的所有邻居节点，计算从起点到这些邻居节点的距离（即经过当前节点再到达邻居节点的距离），如果计算出来的距离比 distances 中保存的距离更短，则更新 distances 和 previous。

    //    4. 输出路径
    //    最后，根据 previous 从终点往回找到起点，并将路径反转后输出。

    //    该算法的时间复杂度为 O(V ^ 2)，其中 V 为节点数。

    void shortestPathByStations(std::string source, std::string destination) {
        std::map<std::string, int> distances;
        std::map<std::string, std::string> previous;
        std::set<std::string> visited;

        for (auto it : graph) {
            distances[it.first] = INT_MAX;
        }
        distances[source] = 0;
        //初始化

        //for(auto it : graph)语句块中的每个it都是一个节点名称以及对应的相邻节点列表。
        //通过it.first获取当前遍历到的节点名称，通过it.second获取当前节点的相邻节点列表。

        while (!visited.count(destination)) {
            std::string current;
            int minDistance = INT_MAX;
            for (auto it : graph) {
                if (!visited.count(it.first) && distances[it.first] < minDistance) {
                    current = it.first;
                    minDistance = distances[it.first];
                }
            }
            //确认起点

            //!visited.count(it.first) 表示判断当前节点名称
            //    it.first 是否在 visited 中不存在，即判断当前节点是否还未被访问过。
            //    如果返回 true，则说明该节点还未被访问过，需要进行进一步处理；
            //    如果返回 false，则说明该节点已经被访问过，无需再次处理。

            visited.insert(current);//标记起点已被访问过

            for (auto neighbor : graph[current]) {
                int altDistance = distances[current] + 1;
                //因为最短路径是指经过的站点数而不是路径权重长度，所以直接统一默认长度为1即可
                if (altDistance < distances[neighbor.destination]) {
                    distances[neighbor.destination] = altDistance;
                    previous[neighbor.destination] = current;
                }
            }
        }

        std::cout << "从 " << source << " 到 " << destination << " 的最短路径（按站点数计算）：" << std::endl;
        std::vector<std::string> path;
        for (std::string vertex = destination; vertex != source; vertex = previous[vertex]) {
            path.push_back(vertex);
        }
        path.push_back(source);
        std::reverse(path.begin(), path.end());
        for (auto it : path) {
            std::cout << it << " -> ";
        }
        std::cout << std::endl;     
    }

    /*例如，在地铁路线图中，如果要从A站到B站，
    有时候需要换乘其他线路才能到达目的地。
    如果我们选择了一条从A站到B站的路径，
    而这条路径经过了C站、D站等多个中转站，则这条路径的换乘次数就是中转站的个数。*/


    // 以最少换乘次数为标准计算从起点到终点的最短路径
    void shortestPathByTransfers(std::string source, std::string destination) {
        // 初始化距离、换乘次数和前驱节点
        std::map<std::string, int> distances;
        std::map<std::string, int> transfers;
        std::map<std::string, std::string> previous;

        // 记录已访问过的节点
        std::set<std::string> visited;

        // 初始化距离和换乘次数，将起点的距离和换乘次数都设置为0
        for (auto it : graph) {
            distances[it.first] = INT_MAX;
            transfers[it.first] = INT_MAX;
        }
        distances[source] = 0;
        transfers[source] = 0;

        // 主循环，直到找到终点或者所有节点都被访问为止
        while (!visited.count(destination)) {
            std::string current;
            int minTransfers = INT_MAX;
            int minDistance = INT_MAX;

            // 选取当前节点，即未访问过的距离+换乘次数最小的节点
          /*  distances[source] = 0;
            transfers[source] = 0;*/
            //寻找这个当前的结点，即遍历起点
            for (auto it : graph) {
                if (!visited.count(it.first) &&
                    ((transfers[it.first] < minTransfers) ||
                        (transfers[it.first] == minTransfers && distances[it.first] < minDistance))) {
                    current = it.first;
                    minTransfers = transfers[it.first];
                    minDistance = distances[it.first];
                }
            }

            // 标记当前节点为已访问
            visited.insert(current);

            // 遍历当前节点的邻居节点，更新它们的距离、换乘次数和前驱节点
            for (auto neighbor : graph[current]) {
                int altDistance = distances[current] + neighbor.time;//时间最短的路径选取
                //最少换乘次数中，现在已经不是站点为最短路径了
                //而是时间，时间最短即最短路径(这是默认的，只不过前面的题目要求是要以站点为最短路径而已)
                //我们选取最最佳的最少换乘次数路径，也就是如果两条路径换乘次数相同，那我们选择时间最短的那条！

                int altTransfers = transfers[current] + (current != source && current != destination);
                //换乘次数最短的路径选取
                //关键代码：
                // 这个布尔值表示是否需要进行换乘，即如果当前节点不是起点或终点，
                // 则需要进行换乘（布尔值为1），否则不需要进行换乘（布尔值为0）。

                if (altDistance < distances[neighbor.destination] ||
                    (altDistance == distances[neighbor.destination] &&
                        altTransfers < transfers[neighbor.destination])) {
                    distances[neighbor.destination] = altDistance;
                    transfers[neighbor.destination] = altTransfers;
                    previous[neighbor.destination] = current;
                }//选出同时满足时间和换乘最少的路径作为输出结果
            }
        }

        // 回溯路径，输出从起点到终点的最短路径
        std::cout << "从 " << source << " 到 " << destination << " 的最短路径（按换乘次数计算）：" << std::endl;
        std::vector<std::string> path;
        for (std::string vertex = destination; vertex != source; vertex = previous[vertex]) {
            path.push_back(vertex);
        }
        path.push_back(source);
        std::reverse(path.begin(), path.end());
        for (auto it : path) {
            std::cout << it << " -> ";
        }
        std::cout << std::endl;
    }



    void shortestPathByTime(std::string source, std::string destination) {
        std::map<std::string, int> distances;
        std::map<std::string, std::string> previous;
        std::set<std::string> visited;

        for (auto it : graph) {
            distances[it.first] = INT_MAX;
        }
        distances[source] = 0;

        while (!visited.count(destination)) {
            std::string current;
            int minDistance = INT_MAX;
            for (auto it : graph) {
                if (!visited.count(it.first) && distances[it.first] < minDistance) {
                    current = it.first;
                    minDistance = distances[it.first];
                }
            }

            visited.insert(current);
            for (auto neighbor : graph[current]) {
                int altDistance = distances[current] + neighbor.time;
                if (altDistance < distances[neighbor.destination]) {
                    distances[neighbor.destination] = altDistance;
                    previous[neighbor.destination] = current;
                }
            }
        }

        std::cout << "从 " << source << " 到 " << destination << " 的最短路径（按时间计算）：" << std::endl;
        std::vector<std::string> path;
        for (std::string vertex = destination; vertex != source; vertex = previous[vertex]) {
            path.push_back(vertex);
        }
        path.push_back(source);
        std::reverse(path.begin(), path.end());
        for (auto it : path) {
            std::cout << it << " -> ";
        }
        std::cout << std::endl;
    }

private:
    std::map<std::string, std::vector<Edge>> graph;
};


int main() {
    RailwaySystem rs;

    // 添加车站
    rs.addStation("北京");
    rs.addStation("上海");
    rs.addStation("广州");
    rs.addStation("成都");
    rs.addStation("重庆");
    rs.addStation("武汉");
    rs.addStation("南京");
    rs.addStation("西安");
    rs.addStation("杭州");
    rs.addStation("郑州");
    rs.addStation("长沙");
    rs.addStation("福州");
    rs.addStation("深圳");
    rs.addStation("青岛");
    rs.addStation("天津");
    rs.addStation("沈阳");
    rs.addStation("哈尔滨");
    rs.addStation("石家庄");
    rs.addStation("太原");
    rs.addStation("合肥");
    rs.addStation("南昌");
    rs.addStation("济南");
    rs.addStation("呼和浩特");
    rs.addStation("兰州");
    rs.addStation("银川");
    rs.addStation("乌鲁木齐");
    rs.addStation("西宁");
    rs.addStation("拉萨");
    rs.addStation("南宁");
    rs.addStation("昆明");
    rs.addStation("贵阳");
    rs.addStation("长春");
    rs.addStation("南通");
    rs.addStation("常州");
    rs.addStation("徐州");
    rs.addStation("苏州");
    rs.addStation("无锡");
    rs.addStation("厦门");
    rs.addStation("南宁");
    rs.addStation("海口");
    rs.addStation("西安北");
    rs.addStation("阜阳");
    rs.addStation("安庆");
    rs.addStation("怀化");
    rs.addStation("衡阳");
    rs.addStation("邵阳");
    rs.addStation("张家界");
    rs.addStation("岳阳");
    rs.addStation("盐城");
    rs.addStation("扬州");

    // 添加连接关系
    rs.addConnection("北京", "上海", 5);
    rs.addConnection("北京", "广州", 10);
    rs.addConnection("上海", "广州", 8);
    rs.addConnection("广州", "成都", 12);
    rs.addConnection("成都", "重庆", 2);
    rs.addConnection("重庆", "武汉", 6);
    rs.addConnection("武汉", "南京", 3);
    rs.addConnection("南京", "上海", 2);
    rs.addConnection("上海", "杭州", 1);
    rs.addConnection("杭州", "福州", 3);
    rs.addConnection("福州", "广州", 4);
    rs.addConnection("广州", "长沙", 2);
    rs.addConnection("长沙", "武汉", 2);
    rs.addConnection("武汉", "郑州", 3);
    rs.addConnection("郑州", "北京", 5);
    rs.addConnection("北京", "西安", 6);
    rs.addConnection("西安", "成都", 4);
    rs.addConnection("北京", "天津", 1);
    rs.addConnection("天津", "青岛", 3);
    rs.addConnection("青岛", "济南", 2);
    rs.addConnection("济南", "合肥", 5);
    rs.addConnection("合肥", "南昌", 3);
    rs.addConnection("南昌", "福州", 3);
    rs.addConnection("北京", "石家庄", 3);
    rs.addConnection("石家庄", "太原", 2);
    rs.addConnection("太原", "呼和浩特", 5);
    rs.addConnection("呼和浩特", "银川", 6);
    rs.addConnection("银川", "兰州", 3);
    rs.addConnection("兰州", "西宁", 2);
    rs.addConnection("西宁", "乌鲁木齐", 5);
    rs.addConnection("乌鲁木齐", "拉萨", 12);
    rs.addConnection("广州", "南宁", 4);
    rs.addConnection("南宁", "昆明", 9);
    rs.addConnection("昆明", "贵阳", 6);
    rs.addConnection("长春", "哈尔滨", 3);
    rs.addConnection("哈尔滨", "沈阳", 5);
    rs.addConnection("南通", "常州", 1);
    rs.addConnection("常州", "徐州", 2);
    rs.addConnection("徐州", "苏州", 3);
    rs.addConnection("苏州", "无锡", 1);
    rs.addConnection("福州", "厦门", 2);
    rs.addConnection("南宁", "海口", 7);
    rs.addConnection("西安", "西安北", 1);
    rs.addConnection("合肥", "阜阳", 2);
    rs.addConnection("阜阳", "安庆", 3);
    rs.addConnection("常州", "扬州", 2);
    rs.addConnection("长沙", "怀化", 2);
    rs.addConnection("衡阳", "邵阳", 4);
    rs.addConnection("邵阳", "张家界", 3);
    rs.addConnection("张家界", "岳阳", 5);
    rs.addConnection("岳阳", "武汉", 4);
    rs.addConnection("盐城", "南通", 2);
    rs.addConnection("扬州", "盐城", 3);

    rs.shortestPathByStations("武汉", "西安");
    rs.shortestPathByTransfers("武汉", "西安");
    rs.shortestPathByTime("武汉", "西安");

    return 0;
}
