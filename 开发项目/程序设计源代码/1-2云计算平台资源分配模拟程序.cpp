#include <iostream>
#include <vector>
#include <algorithm>//sort函数调用
using namespace std;

//题目解析:
//题目不关心究竟是什么类型的虚拟机被放在哪个服务器了，
//就是随机生成各种虚拟机后用最少的服务器将他们部署即可。
//即就是考虑合理插入储存数据的问题。
//将每一个服务器的CPU和内存都尽可能的利用满，
//能放入就放入，这就是最少服务器的结果。
//题意就是想让我们实现给所有数据一个最佳的存放方式，
//把服务器的空间利用率达到最高。

struct Server {
    int cpu;
    int mem;
    vector<int> vm; // 存储该服务器上部署的虚拟机编号
};

struct VM {
    int cpu;
    int mem;
};

// 随机生成虚拟机请求
vector<VM> generateRequests() {
    vector<VM> requests = { {2, 4}, {8, 32}, {24, 64} };
    int n1 = rand() % 71 + 30; // 生成30-100之间的随机数
    int n2 = rand() % 71 + 30;
    int n3 = rand() % 71 + 30;
    while (n1 + n2 + n3 > 200) {
        n1 /= 2;
        n2 /= 2;
        n3 /= 2;
    }
    //因此，在随机生成完这3个数之后，
    //    使用一个 while 循环不断将它们除以2，
    //    直到它们的和小于等于200，
    //    这样就可以确保生成的虚拟机请求总数不超过200，以保证服务器不会被过载。
    //以下是三种虚拟机的CPU和内存属性

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

// 按照服务器利用率从大到小排序
bool cmp(const Server& a, const Server& b) {
    return (a.cpu + a.mem) > (b.cpu + b.mem);
}

// 将虚拟机请求部署在服务器上
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
            servers.push_back({ 128, 512, {i} }); /*服务器的CPU和内存属性*/
        }
    }
}

// 输出部署方案
void printDeployment(vector<Server>& servers) {
    cout << "使用了" << servers.size() << "台服务器" << endl;
    for (int i = 0; i < servers.size(); i++) {
        cout << "服务器" << i << ":" << endl;
        cout << "CPU剩余核数：" << servers[i].cpu << endl;
        cout << "内存剩余大小：" << servers[i].mem << endl;
        cout << "部署的虚拟机编号：";
        for (int j = 0; j < servers[i].vm.size(); j++) {
            cout << servers[i].vm[j] << " ";
        }
        cout << endl;
    }
}
//这段代码中的输出结果中的 
//"CPU核数：32" 和 "内存大小：256" 是指部署在服务器上的虚拟机的资源占用情况。
//具体来说，其中的 "CPU核数：32" 是指服务器上剩余的 CPU 核数为 32，
//而 "内存大小：256" 则表示服务器上剩余的内存大小为 256.


int main() {
    srand(time(NULL));//随机生成的种子

    vector<Server> servers;
    vector<VM> requests = generateRequests();
    deployServers(servers, requests);
    sort(servers.begin(), servers.end(), cmp);
    printDeployment(servers);
    return 0;
}


