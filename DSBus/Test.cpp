#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <string>
#define MaxSize 20
#define BUS_NUM 10
#define ROUTE_NUM 48
#define STATION_NUM 17
using namespace std;

bool visited[STATION_NUM];
typedef struct Bus
{
    char *name; //公交名
    int start;  //起点
    int end;    //终点
} Bus;

typedef struct Route
{
    int station;        //指向的站点索引号
    int bus;            //公交索引号
    int distance;       //两站之间公路的距离
    struct Route *next; //起始站点相同的，下一条下行路线
} Route;

typedef struct Station
{
    char *station;
    struct Route *routes;
} Station;

typedef struct BusMap
{
    Bus *buses;
    Station *stations;
    int station_num;
    int bus_num;
} BusMap;

BusMap g_BusMap;

int FindBus(char *bus)
{
    for (int i = 0; i < g_BusMap.bus_num; i++)
    {
        if (strcmp(g_BusMap.buses[i].name, bus) == 0)
        {
            return i;
        }
    }
    return -1;
}

int GetBus(char *bus)
{
    int nBus = FindBus(bus);
    if (nBus == -1)
    {
        g_BusMap.buses = (Bus *)realloc(g_BusMap.buses, sizeof(Bus) * (g_BusMap.bus_num + 1));
        Bus *pBus = g_BusMap.buses + g_BusMap.bus_num;
        pBus->name = bus;
        pBus->start = -1;
        pBus->end = -1;
        nBus = g_BusMap.bus_num;
        g_BusMap.bus_num++;
    }
    return nBus;
}

int FindStation(char *station)
{
    for (int i = 0; i < g_BusMap.station_num; i++)
    {
        if (strcmp(g_BusMap.stations[i].station, station) == 0)
            return i;
    }
    return -1;
}

int GetStation(char *station)
{
    int nStation = FindStation(station);
    if (nStation == -1)
    {
        g_BusMap.stations = (Station *)realloc(g_BusMap.stations, sizeof(Station) * (g_BusMap.station_num + 1));
        Station *pStation = g_BusMap.stations + g_BusMap.station_num;
        pStation->station = station;
        pStation->routes = NULL;
        nStation = g_BusMap.station_num;
        g_BusMap.station_num++;
    }
    return nStation;
}

void AddRoute(int nBus, int nStart, int nEnd, int distance)
{
    Station *pStStation = &g_BusMap.stations[nStart];
    Route *pStRoute = pStStation->routes;
    while (pStRoute != NULL && pStRoute->next != NULL)
    {
        if (pStRoute->bus == nBus && pStRoute->station == nEnd)
            return;
        pStRoute = pStRoute->next;
    }
    Route *pNewRoute = (Route *)malloc(sizeof(Route));
    pNewRoute->bus = nBus;
    pNewRoute->station = nEnd;
    pNewRoute->distance = distance;
    pNewRoute->next = NULL;
    if (pStRoute == NULL)
        pStStation->routes = pNewRoute;
    else
        pStRoute->next = pNewRoute;
}

void AddBus(char *bus, char *pStart, char *pEnd)
{
    int nBus = GetBus(bus);
    int nStart = GetStation(pStart);
    int nEnd = GetStation(pEnd);
    Bus *pBus = g_BusMap.buses + nBus;
    pBus->start = nStart;
    pBus->end = nEnd;
}
#pragma region 修改部分

//输入字符串 根据分隔符
void SplitString(const string &s, vector<string> &v, const string &c)
{
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
}

int FigureNum(string path)
{
    int num = 0;
    ifstream infile;
    infile.open(path); //将文件流对象与文件连接起来
    string str;
    while (getline(infile, str))
    {
        num++;
    }
    infile.close();
    return num;
}

//默认同目录下文件 否则用绝对路径
void CreateMap(string buspath, string stationpath, string routepath)
{
    ifstream infile;
    int bus_num = FigureNum(buspath);
    g_BusMap.bus_num = bus_num;
    infile.open(buspath);
    string str;
    g_BusMap.buses = (Bus *)malloc(sizeof(Bus) * bus_num);
    //获取公交路线
    for (int i = 0; i < bus_num; i++)
    {
        vector<string> v;
        getline(infile, str);
        SplitString(str, v, " ");
        //获取公交名称
        g_BusMap.buses[i].name = new char(v[0].length() + 1);
        v[0].copy(g_BusMap.buses[i].name, v[0].length(), 0);
        g_BusMap.buses[i].name[v[0].length()] = '\0';
        g_BusMap.buses[i].start = -1;
        g_BusMap.buses[i].end = -1;
    }
    infile.close();

    //获取公交站
    int station_num = FigureNum(stationpath);
    g_BusMap.station_num = station_num;
    g_BusMap.stations = (Station *)malloc(sizeof(Station) * station_num);
    infile.open(stationpath);
    for (int i = 0; i < station_num; i++)
    {
        getline(infile, str);
        g_BusMap.stations[i].station = new char(str.length() + 1);
        str.copy(g_BusMap.stations[i].station, str.length(), 0);
        g_BusMap.stations[i].station[str.length()] = '\0';
        g_BusMap.stations[i].routes = NULL;
    }
    infile.close();

    infile.open(buspath);
    //添加Bus 根据你那一起的
    for (int i = 0; i < bus_num; i++)
    {
        vector<string> v;
        getline(infile, str);
        SplitString(str, v, " ");
        //获取start
        char *pStar = new char(v[1].length() + 1);
        v[1].copy(pStar, v[1].length(), 0);
        pStar[v[1].length()] = '\0';
        //获取end
        char *pEnd = new char(v[2].length() + 1);
        v[2].copy(pEnd, v[2].length(), 0);
        pEnd[v[2].length()] = '\0';
        AddBus(g_BusMap.buses[i].name, pStar, pEnd);
    }
    infile.close();

    int route_num = FigureNum(routepath);
    infile.open(routepath);
    while (getline(infile, str))
    {
        vector<string> v;
        SplitString(str, v, " ");
        int nBus = atoi(v[0].c_str());
        int nStart = atoi(v[1].c_str());
        int nEnd = atoi(v[2].c_str());
        int distance = atoi(v[3].c_str());
        AddRoute(nBus, nStart, nEnd, distance);
    }
}

string CharToStr(char *contentChar)
{
    string tempStr;
    for (int i = 0; contentChar[i] != '\0'; i++)
    {
        tempStr += contentChar[i];
    }
    return tempStr;
}

//判断是否是字串
bool Contains(const char *s1, const char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int index1 = 0, index2 = 0;

    while (index1 < (len1 - len2))
    {
        if (s1[index1] == s2[index2])
        {
            index2++;
            index1++;
        }
        else
        {
            index1 -= index2;
            index1++;
            index2 = 0;
        }
        if (index2 == len2)
            return true;
    }
    return false;
}

//等于isDelete==true就删除
void ModifyBusStation(char *bus, char *from, char *to, string buspath, bool isDelete = false)
{
    //读文件
    ifstream infile;
    infile.open(buspath);
    string str;
    string strFileData = "";
    bool tag = false;
    while (getline(infile, str))
    {
        vector<string> v;
        SplitString(str, v, " ");

        if (Contains(v[0].data(), bus))
        { //肯定是俩行一组于是旋转下
            tag = true;
            if (!isDelete)
            {
                strFileData = strFileData + CharToStr(bus) + "上行" + " " + CharToStr(from) + " " + CharToStr(to) + "\n";
                strFileData = strFileData + CharToStr(bus) + "下行" + " " + CharToStr(to) + " " + CharToStr(from) + "\n";
            }
            getline(infile, str);
        }
        else
        {
            strFileData = strFileData + v[0] + " " + v[1] + " " + v[2] + "\n";
        }
    }
    infile.close();
    if (!tag && !isDelete)
    {
        strFileData = strFileData + CharToStr(bus) + "上行" + " " + CharToStr(from) + " " + CharToStr(to) + "\n";
        strFileData = strFileData + CharToStr(bus) + "下行" + " " + CharToStr(to) + " " + CharToStr(from) + "\n";
    }

    //写入文件
    ofstream out;
    out.open(buspath);
    out.flush();
    out << strFileData;
    out.close();
}

//修改路线
void ModifyBusRoute(int nBus, int nStart, int nEnd, int distance, string routepath, bool isDelete = false)
{
    //读文件
    ifstream infile;
    infile.open(routepath);
    string str;
    string strFileData = "";
    bool tag = false;
    while (getline(infile, str))
    {
        vector<string> v;
        SplitString(str, v, " ");
        int tempNbus = atoi(v[0].c_str());
        int tempNstart = atoi(v[1].c_str());
        int tempNend = atoi(v[2].c_str());
        int tempNdis = atoi(v[3].c_str());

        //暂时站点 起始一样 改距离 需要的自己改判断函数
        if (nBus == tempNbus && nStart == tempNstart && tempNend == nEnd)
        {
            tag = true;
            if (!isDelete)
            {
                strFileData = strFileData + to_string(nBus) + " " + to_string(nStart) + " " + to_string(nEnd) + " " + to_string(distance) + "\n";
            }
        }
        else
        {
            strFileData = strFileData + v[0] + " " + v[1] + " " + v[2] + " " + v[3] + "\n";
        }
    }
    infile.close();
    if (!tag && !isDelete)
    {
        strFileData = strFileData + to_string(nBus) + " " + to_string(nStart) + " " + to_string(nEnd) + " " + to_string(distance) + "\n";
    }

    //写入文件
    ofstream out;
    out.open(routepath);
    out.flush();
    out << strFileData;
    out.close();
}

#pragma endregion
int Is(int *buses, int name, int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (buses[i] == name)
            break;
    if (i == n)
        return 0;
    else
        return 1;
}

int QueryStation(char *station, int *buses)
{
    int nSta = FindStation(station);
    int nBus;
    Station *pstation = &g_BusMap.stations[nSta];
    Route *pRoute = pstation->routes;
    int num = 0;
    while (pRoute != NULL)
    {
        nBus = pRoute->bus;
        pRoute = pRoute->next;
        *(buses + num) = nBus;
        num++;
    }
    for (int i = 0; i < g_BusMap.station_num; i++)
    {
        Station *qstation = &g_BusMap.stations[i];
        Route *qRoute = qstation->routes;
        while (qRoute)
        {
            if (qRoute->station == nSta)
            {
                nBus = qRoute->bus;
                if (Is(buses, nBus, num) == 0)
                {
                    *(buses + num) = nBus;
                    num++;
                }
            }
            qRoute = qRoute->next;
        }
    }
    cout << "@" << station << "@ "
         << " 共" << num << "辆车经过:" << endl;
    for (int j = 0; j < num; j++)
    {
        cout << g_BusMap.buses[buses[j]].name << endl;
    }
    cout << endl;
    return num;
}

void QueryBus(char *pBus, int *route)
{
    int nBus = FindBus(pBus);
    int nStart = g_BusMap.buses[nBus].start;
    int nEnd = g_BusMap.buses[nBus].end;
    route[0] = nStart;
    Station *pStation = &g_BusMap.stations[nStart];
    Route *pRoute = pStation->routes;
    int nStation = nStart;
    int num = 1;
    while (nStation != nEnd)
    {
        while (pRoute->bus != nBus)
        {
            pRoute = pRoute->next;
        }
        nStation = pRoute->station;
        route[num] = nStation;
        num++;
        pStation = &g_BusMap.stations[nStation];
        pRoute = pStation->routes;
    }
    cout << "#" << pBus << "# "
         << "从 " << g_BusMap.stations[nStart].station << " 开往 " << g_BusMap.stations[nEnd].station << " 共经" << num << "个站点:" << endl;
    cout << endl;
    cout << g_BusMap.stations[route[0]].station;
    for (int j = 1; j < num; j++)
    {
        cout << "->" << g_BusMap.stations[route[j]].station;
    }
    cout << endl
         << endl;
}

typedef struct Path
{
    Route r[MaxSize];
    int transfer;
    int distance;
    int top;
} Path;

void Clear()
{
    for (int i = 0; i < STATION_NUM; i++)
        visited[i] = false;
}

void Init(Path *&p, char *s)
{
    p = (Path *)malloc(sizeof(Path));
    p->r[0].bus = -1;
    p->r[0].distance = 0;
    p->r[0].next = NULL;
    p->r[0].station = FindStation(s);
    p->transfer = -1;
    visited[FindStation(s)] = true;
    p->top = 0;
}

void Push(Path *&p, Route *s)
{
    if (p->r[p->top].bus != s->bus)
        p->transfer++;
    p->top++;
    p->r[p->top].bus = s->bus;
    p->r[p->top].distance = s->distance;
    p->r[p->top].next = s->next;
    p->r[p->top].station = s->station;
    p->distance += s->distance;
}
void Pop(Path *&p, Route *&s)
{
    s = (Route *)malloc(sizeof(Route));
    s->bus = p->r[p->top].bus;
    s->distance = p->r[p->top].distance;
    s->next = p->r[p->top].next;
    s->station = p->r[p->top].station;
    p->distance -= s->distance;
    p->top--;
    if (p->r[p->top].bus != s->bus)
        p->transfer--;
}

void Show(Path *p)
{
    if (p->transfer <= 1)
    {
        cout << g_BusMap.stations[p->r[0].station].station;
        for (int i = 1; i <= p->top; i++)
        {
            cout << "--"
                 << "[" << g_BusMap.buses[p->r[i].bus].name << "]"
                 << "-->" << g_BusMap.stations[p->r[i].station].station;
        }
        cout << endl;
        cout << "该路线总距离：" << p->distance << " 换乘次数：" << p->transfer << endl
             << endl;
    }
}

void QueryRoutes(char *pStart, char *pEnd, Path *path)
{
    int nStart = GetStation(pStart);
    int nEnd = GetStation(pEnd);
    int n = nStart;
    Station *pStation = &g_BusMap.stations[nStart];
    Route *pRoute = pStation->routes;
    if (n == nEnd)
    {
        Show(path);
    }
    else
    {
        for (; pRoute != NULL; pRoute = pRoute->next)
        {
            if (!visited[pRoute->station])
            {
                visited[pRoute->station] = true;
                Push(path, pRoute);
                QueryRoutes(g_BusMap.stations[pRoute->station].station, pEnd, path);
            }
        }
    }
    Pop(path, pRoute);
    visited[pRoute->station] = false;
}

int main()
{
    string buspath = "C:\\NoobOJCollection\\DSBus\\buses.txt";
    string stationpath = "C:\\NoobOJCollection\\DSBus\\stations.txt";
    string routepath = "C:\\NoobOJCollection\\DSBus\\routes.txt";
    CreateMap(buspath, stationpath, routepath);

    int pp;
    int route[10];
    char b[10];
    int bbb[10];
    char sta[10];
    do
    {
        cout << "========公交管理系统========" << endl;
        cout << "1.查询公交线路" << endl;
        cout << "2.查询站点信息" << endl;
        cout << "3.查询两个站点公交线路" << endl;
        cout << "4.公交车路线修改" << endl;
        cout << "5.公交车起终点修改" << endl;

        cout << "0.退出" << endl;
        cout << "请输入操作编号(0~5):" << endl;
        cin >> pp;
        int q;

        switch (pp)
        {
        case 1:
        {
            cout << "========查询公交线路========" << endl;
            cout << "请输入要查询的公交名:";
            cin >> b;
            cout << "----------------------------" << endl;
            QueryBus(b, route);
            break;
        }
        case 2:
        {
            cout << "========查询站点信息========" << endl;
            cout << "请输入要查询的站点名:";
            cin >> sta;
            cout << "----------------------------" << endl;
            QueryStation(sta, bbb);
            break;
        }
        case 3:
        {
            cout << "========查询两个站点公交线路========" << endl;
            char start[10];
            char end[10];
            cout << "请输入要查询的起点：";
            scanf("%s", start);
            cout << "请输入要查询的终点：";
            scanf("%s", end);
            Path *path;
            Clear();
            Init(path, start);
            cout << "从 " << start << " 开往 " << end << " 找到以下线路：" << endl
                 << endl;
            QueryRoutes(start, end, path);
            free(path);
            break;
        }
        case 4:
        {
            system("cls");
            cout << "========公交车路线修改========" << endl;
            cout << "1.修改公交车路线" << endl;
            cout << "2.删除公交车路线" << endl;
            cout << "3.添加公交车路线" << endl;
            cout << "0.返回上一层" << endl;
            cin >> q;
            int nBus, nStart, nEnd, distance = -1;
            switch (q)
            {
            case 1:
            {
                cout << "========修改公交车起终点========" << endl;
                cout << "请输入公交车号：";
                cin >> nBus;
                cout << "请输入起点：";
                cin >> nStart;
                cout << "请输入终点：";
                cin >> nEnd;
                cout << "请输入距离：";
                cin >> distance;
                ModifyBusRoute(nBus, nStart, nEnd, distance, routepath);
                break;
            }
            case 2:
            {
                cout << "========删除公交号========" << endl;
                cout << "请输入公交车号：";
                cin >> nBus;
                cout << "请输入起点：";
                cin >> nStart;
                cout << "请输入终点：";
                cin >> nEnd;
                ModifyBusRoute(nBus, nStart, nEnd, distance, routepath, true);
                break;
            }
            case 3:
            {
                cout << "========修改公交车起终点========" << endl;
                cout << "请输入公交车号：";
                cin >> nBus;
                cout << "请输入起点：";
                cin >> nStart;
                cout << "请输入终点：";
                cin >> nEnd;
                cout << "请输入距离：";
                cin >> distance;
                ModifyBusRoute(nBus, nStart, nEnd, distance, routepath);
                break;
            }
            default:;
            }
            break;
        }
        case 5:
        {
            system("cls");
            cout << "========公交车起终点修改========" << endl;
            cout << "1.修改公交车起终点" << endl;
            cout << "2.删除公交号" << endl;
            cout << "3.添加公交车起终点" << endl;
            cout << "0.返回上一层" << endl;
            cin >> q;
            char bus[10];
            char from[10];
            char to[10];
            switch (q)
            {
            case 1:
                cout << "========修改公交车起终点========" << endl;
                cout << "请输入公交车号：";
                cin >> bus;
                cout << "请输入公交车的起点：";
                cin >> from;
                cout << "请输入公交车的终点：";
                cin >> to;
                ModifyBusStation(bus, from, to, buspath);
                break;
            case 2:
                cout << "========删除公交号========" << endl;
                cout << "请输入公交车号：";
                cin >> bus; //"C:\\NoobOJCollection\\DSBus\\buses.txt"
                ModifyBusStation(bus, from, to, buspath, true);
                break;
            case 3:
                cout << "========添加公交车起终点========" << endl;
                cout << "请输入公交车号：";
                cin >> bus;
                cout << "请输入公交车的起点：";
                cin >> from;
                cout << "请输入公交车的终点：";
                cin >> to;
                ModifyBusStation(bus, from, to, buspath);
                break;
            default:
                break;
            }
            break;
        }
        default:;
        }
    } while (pp != 0);
    return 0;
}