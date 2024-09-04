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

    /*���·���ǰ�վ��������ģ������ǰ�·�����ȣ�����Ȩ�أ�����ġ�
     ��ˣ�ȷ��վ�������ٵ����·���Ĺ��̾����ҵ���Դվ�㵽Ŀ��վ������·�������о�����վ�������١�*/

    //��δ���ʵ���˰���վ�������������·���� Dijkstra �㷨������������£�

    //    ���㷨ʹ����ͼ����ʾ������·��ÿ���ڵ��ʾһ������վ��ÿ���߱�ʾ�������ڵĵ���վ֮������ӹ�ϵ��ͬʱ��ʹ���������������ݽṹ����¼��Ϣ��distances ��¼��ǰ��֪�Ĵ���㵽�����ڵ����̾��룻previous ��¼ÿ���ڵ������·���ϵ�ǰ���ڵ㣻visited ��¼�Ѿ����ʹ��Ľڵ㡣

    //    1. ��ʼ��
    //    ���Ƚ� distances �����нڵ�ľ����ʼ��Ϊ INT_MAX����ʾ��ǰ����֪������㵽��Щ�ڵ����̾��롣�����ľ����ʼ��Ϊ 0��

    //    2. ȷ�����
    //    �� while ѭ���У�ÿ���ҵ� distances ��δ�����ʹ��Ҿ�����С�Ľڵ���Ϊ��ǰ�ڵ㡣�����ǰ�ڵ�����յ㣬��˵���Ѿ��ҵ������·�����˳�ѭ�������򽫵�ǰ�ڵ���Ϊ visited��

    //    3. ���¾���
    //    ������ǰ�ڵ�������ھӽڵ㣬�������㵽��Щ�ھӽڵ�ľ��루��������ǰ�ڵ��ٵ����ھӽڵ�ľ��룩�������������ľ���� distances �б���ľ�����̣������ distances �� previous��

    //    4. ���·��
    //    ��󣬸��� previous ���յ������ҵ���㣬����·����ת�������

    //    ���㷨��ʱ�临�Ӷ�Ϊ O(V ^ 2)������ V Ϊ�ڵ�����

    void shortestPathByStations(std::string source, std::string destination) {
        std::map<std::string, int> distances;
        std::map<std::string, std::string> previous;
        std::set<std::string> visited;

        for (auto it : graph) {
            distances[it.first] = INT_MAX;
        }
        distances[source] = 0;
        //��ʼ��

        //for(auto it : graph)�����е�ÿ��it����һ���ڵ������Լ���Ӧ�����ڽڵ��б�
        //ͨ��it.first��ȡ��ǰ�������Ľڵ����ƣ�ͨ��it.second��ȡ��ǰ�ڵ�����ڽڵ��б�

        while (!visited.count(destination)) {
            std::string current;
            int minDistance = INT_MAX;
            for (auto it : graph) {
                if (!visited.count(it.first) && distances[it.first] < minDistance) {
                    current = it.first;
                    minDistance = distances[it.first];
                }
            }
            //ȷ�����

            //!visited.count(it.first) ��ʾ�жϵ�ǰ�ڵ�����
            //    it.first �Ƿ��� visited �в����ڣ����жϵ�ǰ�ڵ��Ƿ�δ�����ʹ���
            //    ������� true����˵���ýڵ㻹δ�����ʹ�����Ҫ���н�һ������
            //    ������� false����˵���ýڵ��Ѿ������ʹ��������ٴδ���

            visited.insert(current);//�������ѱ����ʹ�

            for (auto neighbor : graph[current]) {
                int altDistance = distances[current] + 1;
                //��Ϊ���·����ָ������վ����������·��Ȩ�س��ȣ�����ֱ��ͳһĬ�ϳ���Ϊ1����
                if (altDistance < distances[neighbor.destination]) {
                    distances[neighbor.destination] = altDistance;
                    previous[neighbor.destination] = current;
                }
            }
        }

        std::cout << "�� " << source << " �� " << destination << " �����·������վ�������㣩��" << std::endl;
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

    /*���磬�ڵ���·��ͼ�У����Ҫ��Aվ��Bվ��
    ��ʱ����Ҫ����������·���ܵ���Ŀ�ĵء�
    �������ѡ����һ����Aվ��Bվ��·����
    ������·��������Cվ��Dվ�ȶ����תվ��������·���Ļ��˴���������תվ�ĸ�����*/


    // �����ٻ��˴���Ϊ��׼�������㵽�յ�����·��
    void shortestPathByTransfers(std::string source, std::string destination) {
        // ��ʼ�����롢���˴�����ǰ���ڵ�
        std::map<std::string, int> distances;
        std::map<std::string, int> transfers;
        std::map<std::string, std::string> previous;

        // ��¼�ѷ��ʹ��Ľڵ�
        std::set<std::string> visited;

        // ��ʼ������ͻ��˴����������ľ���ͻ��˴���������Ϊ0
        for (auto it : graph) {
            distances[it.first] = INT_MAX;
            transfers[it.first] = INT_MAX;
        }
        distances[source] = 0;
        transfers[source] = 0;

        // ��ѭ����ֱ���ҵ��յ�������нڵ㶼������Ϊֹ
        while (!visited.count(destination)) {
            std::string current;
            int minTransfers = INT_MAX;
            int minDistance = INT_MAX;

            // ѡȡ��ǰ�ڵ㣬��δ���ʹ��ľ���+���˴�����С�Ľڵ�
          /*  distances[source] = 0;
            transfers[source] = 0;*/
            //Ѱ�������ǰ�Ľ�㣬���������
            for (auto it : graph) {
                if (!visited.count(it.first) &&
                    ((transfers[it.first] < minTransfers) ||
                        (transfers[it.first] == minTransfers && distances[it.first] < minDistance))) {
                    current = it.first;
                    minTransfers = transfers[it.first];
                    minDistance = distances[it.first];
                }
            }

            // ��ǵ�ǰ�ڵ�Ϊ�ѷ���
            visited.insert(current);

            // ������ǰ�ڵ���ھӽڵ㣬�������ǵľ��롢���˴�����ǰ���ڵ�
            for (auto neighbor : graph[current]) {
                int altDistance = distances[current] + neighbor.time;//ʱ����̵�·��ѡȡ
                //���ٻ��˴����У������Ѿ�����վ��Ϊ���·����
                //����ʱ�䣬ʱ����̼����·��(����Ĭ�ϵģ�ֻ����ǰ�����ĿҪ����Ҫ��վ��Ϊ���·������)
                //����ѡȡ����ѵ����ٻ��˴���·����Ҳ�����������·�����˴�����ͬ��������ѡ��ʱ����̵�������

                int altTransfers = transfers[current] + (current != source && current != destination);
                //���˴�����̵�·��ѡȡ
                //�ؼ����룺
                // �������ֵ��ʾ�Ƿ���Ҫ���л��ˣ��������ǰ�ڵ㲻�������յ㣬
                // ����Ҫ���л��ˣ�����ֵΪ1����������Ҫ���л��ˣ�����ֵΪ0����

                if (altDistance < distances[neighbor.destination] ||
                    (altDistance == distances[neighbor.destination] &&
                        altTransfers < transfers[neighbor.destination])) {
                    distances[neighbor.destination] = altDistance;
                    transfers[neighbor.destination] = altTransfers;
                    previous[neighbor.destination] = current;
                }//ѡ��ͬʱ����ʱ��ͻ������ٵ�·����Ϊ������
            }
        }

        // ����·�����������㵽�յ�����·��
        std::cout << "�� " << source << " �� " << destination << " �����·���������˴������㣩��" << std::endl;
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

        std::cout << "�� " << source << " �� " << destination << " �����·������ʱ����㣩��" << std::endl;
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

    // ��ӳ�վ
    rs.addStation("����");
    rs.addStation("�Ϻ�");
    rs.addStation("����");
    rs.addStation("�ɶ�");
    rs.addStation("����");
    rs.addStation("�人");
    rs.addStation("�Ͼ�");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("֣��");
    rs.addStation("��ɳ");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("�ൺ");
    rs.addStation("���");
    rs.addStation("����");
    rs.addStation("������");
    rs.addStation("ʯ��ׯ");
    rs.addStation("̫ԭ");
    rs.addStation("�Ϸ�");
    rs.addStation("�ϲ�");
    rs.addStation("����");
    rs.addStation("���ͺ���");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("��³ľ��");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("��ͨ");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("������");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("����");
    rs.addStation("�żҽ�");
    rs.addStation("����");
    rs.addStation("�γ�");
    rs.addStation("����");

    // ������ӹ�ϵ
    rs.addConnection("����", "�Ϻ�", 5);
    rs.addConnection("����", "����", 10);
    rs.addConnection("�Ϻ�", "����", 8);
    rs.addConnection("����", "�ɶ�", 12);
    rs.addConnection("�ɶ�", "����", 2);
    rs.addConnection("����", "�人", 6);
    rs.addConnection("�人", "�Ͼ�", 3);
    rs.addConnection("�Ͼ�", "�Ϻ�", 2);
    rs.addConnection("�Ϻ�", "����", 1);
    rs.addConnection("����", "����", 3);
    rs.addConnection("����", "����", 4);
    rs.addConnection("����", "��ɳ", 2);
    rs.addConnection("��ɳ", "�人", 2);
    rs.addConnection("�人", "֣��", 3);
    rs.addConnection("֣��", "����", 5);
    rs.addConnection("����", "����", 6);
    rs.addConnection("����", "�ɶ�", 4);
    rs.addConnection("����", "���", 1);
    rs.addConnection("���", "�ൺ", 3);
    rs.addConnection("�ൺ", "����", 2);
    rs.addConnection("����", "�Ϸ�", 5);
    rs.addConnection("�Ϸ�", "�ϲ�", 3);
    rs.addConnection("�ϲ�", "����", 3);
    rs.addConnection("����", "ʯ��ׯ", 3);
    rs.addConnection("ʯ��ׯ", "̫ԭ", 2);
    rs.addConnection("̫ԭ", "���ͺ���", 5);
    rs.addConnection("���ͺ���", "����", 6);
    rs.addConnection("����", "����", 3);
    rs.addConnection("����", "����", 2);
    rs.addConnection("����", "��³ľ��", 5);
    rs.addConnection("��³ľ��", "����", 12);
    rs.addConnection("����", "����", 4);
    rs.addConnection("����", "����", 9);
    rs.addConnection("����", "����", 6);
    rs.addConnection("����", "������", 3);
    rs.addConnection("������", "����", 5);
    rs.addConnection("��ͨ", "����", 1);
    rs.addConnection("����", "����", 2);
    rs.addConnection("����", "����", 3);
    rs.addConnection("����", "����", 1);
    rs.addConnection("����", "����", 2);
    rs.addConnection("����", "����", 7);
    rs.addConnection("����", "������", 1);
    rs.addConnection("�Ϸ�", "����", 2);
    rs.addConnection("����", "����", 3);
    rs.addConnection("����", "����", 2);
    rs.addConnection("��ɳ", "����", 2);
    rs.addConnection("����", "����", 4);
    rs.addConnection("����", "�żҽ�", 3);
    rs.addConnection("�żҽ�", "����", 5);
    rs.addConnection("����", "�人", 4);
    rs.addConnection("�γ�", "��ͨ", 2);
    rs.addConnection("����", "�γ�", 3);

    rs.shortestPathByStations("�人", "����");
    rs.shortestPathByTransfers("�人", "����");
    rs.shortestPathByTime("�人", "����");

    return 0;
}
