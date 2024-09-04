#include <iostream>
#include <vector>
#include <algorithm>//sort��������
using namespace std;

//��Ŀ����:
//��Ŀ�����ľ�����ʲô���͵�������������ĸ��������ˣ�
//����������ɸ���������������ٵķ����������ǲ��𼴿ɡ�
//�����ǿ��Ǻ�����봢�����ݵ����⡣
//��ÿһ����������CPU���ڴ涼�����ܵ���������
//�ܷ���ͷ��룬��������ٷ������Ľ����
//���������������ʵ�ָ���������һ����ѵĴ�ŷ�ʽ��
//�ѷ������Ŀռ������ʴﵽ��ߡ�

struct Server {
    int cpu;
    int mem;
    vector<int> vm; // �洢�÷������ϲ������������
};

struct VM {
    int cpu;
    int mem;
};

// ����������������
vector<VM> generateRequests() {
    vector<VM> requests = { {2, 4}, {8, 32}, {24, 64} };
    int n1 = rand() % 71 + 30; // ����30-100֮��������
    int n2 = rand() % 71 + 30;
    int n3 = rand() % 71 + 30;
    while (n1 + n2 + n3 > 200) {
        n1 /= 2;
        n2 /= 2;
        n3 /= 2;
    }
    //��ˣ��������������3����֮��
    //    ʹ��һ�� while ѭ�����Ͻ����ǳ���2��
    //    ֱ�����ǵĺ�С�ڵ���200��
    //    �����Ϳ���ȷ�����ɵ��������������������200���Ա�֤���������ᱻ���ء�
    //�����������������CPU���ڴ�����

    for (int i = 0; i < n1; i++) {
        requests.push_back({ 2, 4 });
    }
    for (int i = 0; i < n2; i++) {
        requests.push_back({ 8, 32 });
    }
    for (int i = 0; i < n3; i++) {
        requests.push_back({ 24, 64 });
    }
    return requests;
}

// ���շ����������ʴӴ�С����
bool cmp(const Server& a, const Server& b) {
    return (a.cpu + a.mem) > (b.cpu + b.mem);
}

// ��������������ڷ�������
void deployServers(vector<Server>& servers, vector<VM>& requests) {
    for (int i = 0; i < requests.size(); i++) {
        bool deployed = false;
        int j;
        for (j = 0; j < servers.size(); j++) {
            if (servers[j].cpu >= requests[i].cpu && servers[j].mem >= requests[i].mem) {
                servers[j].cpu -= requests[i].cpu;
                servers[j].mem -= requests[i].mem;
                servers[j].vm.push_back(i);
                deployed = true;
                break;
            }
        }
        if (!deployed) {
            servers.push_back({ 128, 512, {i} }); /*��������CPU���ڴ�����*/
        }
    }
}

// ������𷽰�
void printDeployment(vector<Server>& servers) {
    cout << "ʹ����" << servers.size() << "̨������" << endl;
    for (int i = 0; i < servers.size(); i++) {
        cout << "������" << i << ":" << endl;
        cout << "CPUʣ�������" << servers[i].cpu << endl;
        cout << "�ڴ�ʣ���С��" << servers[i].mem << endl;
        cout << "������������ţ�";
        for (int j = 0; j < servers[i].vm.size(); j++) {
            cout << servers[i].vm[j] << " ";
        }
        cout << endl;
    }
}
//��δ����е��������е� 
//"CPU������32" �� "�ڴ��С��256" ��ָ�����ڷ������ϵ����������Դռ�������
//������˵�����е� "CPU������32" ��ָ��������ʣ��� CPU ����Ϊ 32��
//�� "�ڴ��С��256" ���ʾ��������ʣ����ڴ��СΪ 256.


int main() {
    srand(time(NULL));//������ɵ�����

    vector<Server> servers;
    vector<VM> requests = generateRequests();
    deployServers(servers, requests);
    sort(servers.begin(), servers.end(), cmp);
    printDeployment(servers);
    return 0;
}


