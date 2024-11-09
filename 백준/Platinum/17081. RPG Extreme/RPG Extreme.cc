#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
#include <string>
using namespace std;

struct MONSTER {
    string name;
    int Power, Dura, MaxHP, EXP;
    MONSTER() : Power(0), Dura(0), MaxHP(0), EXP(0), name("") {}
    MONSTER(string _name, int _P, int _D, int _MH, int _E) : name(_name), Power(_P), Dura(_D), MaxHP(_MH), EXP(_E) {}
};
struct ITEM {
    char Type;
    int value;
    ITEM() : Type(0), value(0) {}
    ITEM(char T, int v) : Type(T), value(v) {}
};

map<string, int> Code = {
    {"HR", 6}, {"RE", 5}, {"CO", 4}, {"EX", 3},
    {"DX", 2}, {"HU", 1}, {"CU", 0}
};

int N, M;
bool endflag = false;
bool killboss = false;
vector<string> arr;
string cmd;
map<pair<int, int>, MONSTER> Monster;
map<pair<int, int>, ITEM> Item;

struct USER {
    int MaxHp, Attack, Defence, HP, Level, EXP, Weapon, Shield, Turn;
    bitset<7> Acc; //HR(6), RE(5), CO(4), EX(3), DX(2), HU(1), CU(0)
    int starty, startx, y,x;
    USER(int _y, int _x) : MaxHp(20), Attack(2), Defence(2), HP(20), Level(1), EXP(0), Weapon(0), Shield(0), Turn(0), starty(_y), startx(_x), y(_y), x(_x), Acc({}) {}
    USER() : MaxHp(20), Attack(2), Defence(2), HP(20), Level(1), EXP(0), Acc({}),
        Weapon(0), Shield(0), Turn(0), starty(0), startx(0), y(0), x(0) {}
    void LevelUp() {
        MaxHp += 5;
        Attack += 2;
        Defence += 2;
        HP = MaxHp;
        EXP = 0;
        Level++;
    }
    void Die() {
        if (Acc.test(5)) {
            //부활
            Acc.reset(5);
            HP = MaxHp;
            y = starty;
            x = startx;
        }
        else Ending(0); //부활안됨, 게임 종료
    }
    void Win(int getExp) {
        if (Acc.test(6)) HP = min(MaxHp, HP + 3);
        EXP += Acc.test(3) ? getExp * 1.2 : getExp;
        if (EXP >= Level * 5) LevelUp();
    }
    void Ending(int win) {
        //win이 0: 사망, 1: 승리 -> 보스몹. 2-> 키 더 입력해야함.
        if (win!=0) arr[y][x] = '@'; 
        for (auto it : arr) 
            cout << it << '\n';
        cout << "Passed Turns : " << Turn << '\n';
        cout << "LV : " << Level << '\n';
        cout << "HP : " << max(0, HP) << "/" << MaxHp << '\n';
        cout << "ATT : " << Attack << "+"  << Weapon << '\n';
        cout << "DEF : " << Defence << "+" << Shield << '\n';
        cout << "EXP : " << EXP << "/" << Level*5 << '\n';
        if (win==1)  cout << "YOU WIN!";
        else if(win==0) {
            cout << "YOU HAVE BEEN KILLED BY ";
            if (arr[y][x] == '^') cout << "SPIKE TRAP..";     
            else cout << Monster[make_pair(y, x)].name << "..";    
        }
        else  cout << "Press any key to continue.";
        endflag = true;
    }
};

USER *me;

void Battle(int y, int x, char T) {
    MONSTER monster = Monster[make_pair(y, x)];
    bool protect = false;
    bool firstattack = true;
    if (T == 'M' && me->Acc.test(1)) {
        me->HP = me->MaxHp;
        protect = true;
    }
    //battle의 시작.
    int monsterHp = monster.MaxHP;
    while (1) {
        //주인공이 먼저 공격
        int Attack = me->Attack + me->Weapon;
        if (firstattack && me->Acc.test(4)) { //맨 처음 공격
            if (me->Acc.test(2)) Attack *= 3;
            else  Attack *= 2;
            firstattack = false;
        }
        monsterHp -= max(1, Attack - monster.Dura);
        if (monsterHp <= 0) {
            me->Win(monster.EXP);
            arr[y][x] = '.';
            if (T == 'M')  killboss = true;
            break;
        }
        //몬스터가 공격
        if (protect) {
            protect = false;
            continue;
        }
        me->HP -= max(1, monster.Power - (me->Defence + me->Shield));
        if (me->HP <= 0) {
            break;
        }
    }
}

void Play() {
    int y = me->y;
    int x = me->x;
    if (arr[y][x] == '^')
        me->HP -= me->Acc.test(2) ? 1 : 5;
    else if (arr[y][x] == 'B') {
        ITEM item = Item[make_pair(y, x)];
        if (item.Type == 'O' && me->Acc.count() < 4) me->Acc.set(item.value); ;
        if (item.Type == 'W') me->Weapon = item.value;
        if (item.Type == 'A') me->Shield = item.value;
        arr[y][x] = '.';
    }
    else if (arr[y][x] == '&' || arr[y][x] == 'M')  Battle(y, x, arr[y][x]);
    if (me->HP <= 0) me->Die();
    if (killboss) me->Ending(1);
}

void solution() {
    cin >> N >> M;
    arr.resize(N);
    int K = 0, L = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        for (int j = 0; j < arr[i].length(); j++)
            if (arr[i][j] == '@') {
                me = new USER(i, j);
                arr[i][j] = '.';
            }
            else if (arr[i][j] == '&' || arr[i][j] == 'M') K++;
            else if (arr[i][j] == 'B') L++;
    }
    cin >> cmd;
    for (int i = 0; i < K; i++) {
        int R, C, W, A, H, E;
        string S;
        cin >> R >> C >> S >> W >> A >> H >> E;
        Monster[make_pair(R-1, C-1)] = MONSTER(S, W, A, H, E);
    }
    for (int i = 0; i < L; i++) {
        //HR(6), RE(5), CO(4), EX(3), DX(2), HU(1), CU(0)
        int R, C, V=0;
        char T;
        string acc = "";
        cin >> R >> C >> T;
        if (T == 'O') {
            cin >> acc;
            V = Code[acc];
        }
        else cin >> V;
        Item[make_pair(R-1, C-1)] = ITEM(T, V);
    }
    for (auto it : cmd) {
        if (endflag) break;
        int ny = me->y;
        int nx = me->x;
        if (it == 'L') nx -= 1;    
        else if (it == 'R') nx += 1; 
        else if (it == 'U') ny -= 1;    
        else if (it == 'D') ny += 1;
        if (!(ny >= N || ny < 0 || nx >= M || nx < 0 || arr[ny][nx] == '#')) {
            me->y = ny;
            me->x = nx;
        }
        me->Turn++;
        Play();
    }
    if (!endflag)
        me->Ending(2);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
    return 0;
}