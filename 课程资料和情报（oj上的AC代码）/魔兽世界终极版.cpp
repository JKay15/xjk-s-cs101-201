#include <iostream>
#include <unordered_set>
#include <vector>
#include <cstring>
#include <string>
#include <string.h>
#include <algorithm>
#include <unordered_map>
using namespace std;
// use to check if the game has stopped
int stop;
// basic variable
int M, N, R, K, T;
// use to store, print and compare the game time
class mtime
{
    int hour;
    int minute;
    int pointer = 0;

public:
    mtime(int h = 0, int m = 0) : hour(h), minute(m) {}
    const int minute_tank[10] = {0, 5, 10, 20, 30, 35, 38, 40, 50, 55};
    mtime &operator++()
    {
        if (pointer == 9)
        {
            pointer = 0;
            minute = minute_tank[pointer];
            hour++;
        }
        else
        {
            pointer++;
            minute = minute_tank[pointer];
        }
        return *this;
    }
    int get_minute() { return minute; }
    void reset()
    {
        hour = 0;
        minute = 0;
        pointer = 0;
    }
    bool operator<=(int T)
    {
        if (hour * 60 + minute <= T)
            return 1;
        return 0;
    }
    void print()
    {
        printf("%03d:%02d", hour, minute);
    }
} timer;
// use to store weapon names
const char *warrior_name[5]{"dragon", "ninja", "iceman", "lion", "wolf"}, *weapon_name[3]{"sword", "bomb", "arrow"};
// warrior base class
class warrior
{
public:
    int element;
    int strength;
    int type;
    char *color;
    int num;
    double morale = 0;
    int loyalty;
    unordered_map<string, int> w_set{{"sword", 0}, {"bomb", 0}, {"arrow", 0}};

    warrior(int e, int a, int t, char *c, int n, vector<int> x) : element(e), strength(a), type(t), color(c), num(n)
    {
        for (int i = 0; i < x.size(); i++)
        {
            w_set[weapon_name[i]] = x[i];
        }
    }

    virtual bool check_loyalty() { return 1; }

    virtual void wolf_get(warrior *x) {}

    virtual void attack(warrior *x)
    {
        x->element -= strength + w_set["sword"];
        w_set["sword"] = int(w_set["sword"] * 0.8);
    }
    virtual void shoot(warrior *x)
    {
        x->element -= R;
        w_set["arrow"]--;
    }

    virtual void move() {}

    virtual void report()
    {
        timer.print();
        printf(" %s %s %d has ", color, warrior_name[type], num);
        int first = 1;
        if (w_set["arrow"] > 0)
        {
            printf("arrow(%d)", w_set["arrow"]);
            first = 0;
        }
        if (w_set["bomb"] > 0)
        {
            if (first == 0)
                printf(",");
            printf("bomb");
            first = 0;
        }
        if (w_set["sword"] > 0)
        {
            if (first == 0)
                printf(",");
            printf("sword(%d)", w_set["sword"]);
            first = 0;
        }
        if (first)
            printf("no weapon");
        printf("\n");
    }
    virtual void fight_back(warrior *x)
    {
        if (type != 1)
            x->element -= int(strength / 2) + w_set["sword"];
        w_set["sword"] = int(w_set["sword"] * 0.8);
    }
    virtual void boom(warrior *x, bool pos)
    {
        // pos表示是否为主动进攻
        if (pos)
        {
            if (x->type != 1 && strength + w_set["sword"] < x->element && x->strength / 2 + x->w_set["sword"] >= element)
            {
                timer.print();
                printf(" %s %s %d used a bomb and killed %s %s %d\n", color, warrior_name[type], num, x->color, warrior_name[x->type], x->num);
                w_set["bomb"] = 0;
                element = 0;
                x->element = 0;
            }
        }
        else
        {
            if (x->strength + x->w_set["sword"] >= element)
            {
                timer.print();
                printf(" %s %s %d used a bomb and killed %s %s %d\n", color, warrior_name[type], num, x->color, warrior_name[x->type], x->num);
                w_set["bomb"] = 0;
                element = 0;
                x->element = 0;
            }
        }
    }
    virtual void out_shoot(warrior *x)
    {
        if (x->element <= R)
        {
            x->element = 0;
            w_set["arrow"]--;
            timer.print();
            printf(" %s %s %d shot and killed %s %s %d\n", color, warrior_name[type], num, x->color, warrior_name[x->type], x->num);
        }
        else
        {
            x->element -= R;
            w_set["arrow"]--;
            timer.print();
            printf(" %s %s %d shot\n", color, warrior_name[type], num);
        }
    }
    virtual void set_loyalty(){}; // lion
    virtual ~warrior() {}
};
// specific warriors
class dragon : public warrior
{
public:
    dragon(int e, int a, int t, char *c, int n, vector<int> x, double m) : warrior(e, a, t, c, n, x)
    {
        morale = m;
    };
    virtual ~dragon() {}
};
class ninja : public warrior
{
public:
    ninja(int e, int a, int t, char *c, int n, vector<int> x) : warrior(e, a, t, c, n, x){};
    virtual ~ninja() {}
};
class iceman : public warrior
{
public:
    int step = 0;
    iceman(int e, int a, int t, char *c, int n, vector<int> x) : warrior(e, a, t, c, n, x){};
    void move()
    {
        if (step == 0)
        {
            step++;
        }
        else
        {
            if (element <= 9)
            {
                element = 1;
            }
            else
            {
                element -= 9;
            }
            strength += 20;
            step = 0;
        }
    }
    virtual ~iceman() {}
};
class lion : public warrior
{
public:
    lion(int e, int a, int t, char *c, int n, vector<int> x, int l) : warrior(e, a, t, c, n, x)
    {
        loyalty = l;
    };
    void set_loyalty()
    {
        loyalty -= K;
    }
    bool check_loyalty()
    {
        if (loyalty > 0)
            return 1;
        return 0;
    }
    virtual ~lion() {}
};
class wolf : public warrior
{
public:
    wolf(int e, int a, int t, char *c, int n, vector<int> x) : warrior(e, a, t, c, n, x){};
    virtual void wolf_get(warrior *x)
    {
        // x's weapon is sorted
        for (int i = 0; i < 3; i++)
        {
            if (w_set[weapon_name[i]] == 0 && x->w_set[weapon_name[i]] > 0)
            {
                w_set[weapon_name[i]] = x->w_set[weapon_name[i]];
            }
        }
    }
    virtual ~wolf() {}
};

// basement and city's base class
class building
{
    warrior *blue_w = nullptr;
    warrior *red_w = nullptr;
    warrior *red_tmp = nullptr;

public:
    int winner = 0;
    int city_element = 0;
    int flag = 0;
    int accum_vic = 0;
    // const int for city to produce elements
    static const int city_produce = 10;
    warrior *pop_red()
    {
        warrior *tmp = red_w;
        red_w = red_tmp;
        red_tmp = nullptr;
        return tmp;
    }
    warrior *pop_blue()
    {
        warrior *tmp = blue_w;
        blue_w = nullptr;
        return tmp;
    }
    void set_blue(warrior *x)
    {
        if (x != nullptr && blue_w == nullptr)
        {
            blue_w = x;
        }
    }
    void set_red(warrior *x)
    {
        if (x != nullptr)
        {
            if (red_w != nullptr && red_tmp == nullptr)
            {
                red_tmp = x;
            }
            else
            {
                red_w = x;
            }
        }
    }
    virtual void reward(warrior *x) {}
    virtual void earn(int x) {}
    virtual bool check_stop()
    {
        return 0;
    }
    virtual void w_produce() {}
    virtual void print_element() {}
    virtual void change_element(int x) {}
    warrior *get_red()
    {
        return red_w;
    }
    warrior *get_blue()
    {
        return blue_w;
    }
    virtual ~building() {}
};
// red and blue order
int red_order[5] = {2, 3, 4, 1, 0};
int blue_order[5] = {3, 0, 1, 2, 4};
int element_com[5];
int strength_com[5];
// headquarter
class basement : public building
{
    int element;
    char *color;
    int *produce;
    int pointer = 0;
    int total = 0;
    int opposite = 0;

public:
    basement(int e, char *c, int *x) : element(e), color(c), produce(x) {}
    void change_element(int x)
    {
        element += x;
    }
    void print_element()
    {
        timer.print();
        printf(" %d elements in %s headquarter\n", element, color);
    }
    void reward(warrior *x)
    {
        if (element >= 8)
        {
            element -= 8;
            x->element += 8;
        }
    }
    void earn(int x)
    {
        element += x;
    }
    void w_produce()
    {
        if (element >= element_com[produce[pointer]])
        {
            // prepare variable to store info needed by warrior
            warrior *tmp0;
            int tmp = produce[pointer];
            int tmp1 = element_com[tmp];
            element -= tmp1;
            int tmp2 = strength_com[tmp];
            int tmp4 = element;
            int tmp5 = ++total;
            double morale = 1.0 * element / tmp1;
            vector<int> tmp3{0, 0, 0};
            if (tmp5 % 3 == 0)
                tmp3[0] = int(tmp2 * 0.2);
            else if (tmp5 % 3 == 1)
                tmp3[1] = 1;
            else
                tmp3[2] = 3;
            // initialize warrior due to the pointer place
            switch (tmp)
            {
            case 0:
                tmp0 = new dragon(tmp1, tmp2, tmp, color, tmp5, tmp3, morale);
                break;
            case 1:
                if ((tmp5 + 1) % 3 == 0)
                    tmp3[0] = int(tmp2 * 0.2);
                else if ((tmp5 + 1) % 3 == 1)
                    tmp3[1] = 1;
                else
                    tmp3[2] = 3;
                tmp0 = new ninja(tmp1, tmp2, tmp, color, tmp5, tmp3);
                break;
            case 2:
                tmp0 = new iceman(tmp1, tmp2, tmp, color, tmp5, tmp3);
                break;
            case 3:
                tmp0 = new lion(tmp1, tmp2, tmp, color, tmp5, vector<int>{0, 0, 0}, tmp4);
                break;
            case 4:
                tmp0 = new wolf(tmp1, tmp2, tmp, color, tmp5, vector<int>{0, 0, 0});
                break;
            }
            // change pointer
            pointer = (pointer + 1) % 5;
            // put warrior in place
            if (color == "red")
            {
                set_red(tmp0);
            }
            else
                set_blue(tmp0);
            // print info
            timer.print();
            printf(" %s %s %d born\n", color, warrior_name[tmp], tmp5);
            // extra info for lion
            if (tmp == 3)
            {
                printf("Its loyalty is %d\n", tmp4);
            }
            // extra info for dragon
            if (tmp == 0)
            {
                printf("Its morale is %.2f\n", morale);
            }
        }
    }

    bool check_stop()
    {
        if (opposite == 2)
        {
            stop = 1;
            return 1;
        }
        if (color == "red")
        {
            if (get_blue() != nullptr)
            {
                opposite++;
                set_blue(nullptr);
                if (opposite == 2)
                {
                    stop = 1;
                    return 1;
                }
            }
        }
        else
        {
            if (get_red() != nullptr)
            {
                opposite++;
                set_red(nullptr);
                if (opposite == 2)
                {
                    stop = 1;
                    return 1;
                }
            }
        }
        return 0;
    }
    virtual ~basement() {}
};
void game_play()
{
    // initialization
    timer.reset();
    stop = 0;
    vector<building *> world;
    world.push_back(new basement(M, "red", red_order));
    for (int i = 1; i <= N; ++i)
        world.push_back(new building());
    world.push_back(new basement(M, "blue", blue_order));
    // game loop
    for (; timer <= T && stop == 0; ++timer)
    {
        if (stop == 1)
            break;
        switch (timer.get_minute())
        {
        case 0:
            world[0]->w_produce();
            world[N + 1]->w_produce();
            break;
        case 5:
            // escape the lion
            for (int i = 0; i <= N + 1; ++i)
            {
                building *tmp = world[i];
                if (tmp->get_red() != nullptr && tmp->get_red()->type == 3 && i != N + 1)
                {
                    if (tmp->get_red()->check_loyalty() == 0)
                    {
                        // print info
                        timer.print();
                        printf(" red lion %d ran away\n", tmp->get_red()->num);
                        // escape the lion
                        tmp->pop_red();
                    }
                }
                if (tmp->get_blue() != nullptr && tmp->get_blue()->type == 3 && i != 0)
                {
                    if (tmp->get_blue()->check_loyalty() == 0)
                    {
                        timer.print();
                        printf(" blue lion %d ran away\n", tmp->get_blue()->num);
                        tmp->pop_blue();
                    }
                }
            }
            break;
        case 10:
            if (stop == 0)
            {
                // move forward
                unordered_set<warrior *> moved;
                for (int i = 0; i <= N + 1; ++i)
                {
                    building *tmp = world[i];
                    if (i != N + 1 && i > 0 && world[i - 1]->get_red() != nullptr && moved.find(world[i - 1]->get_red()) == moved.end())
                    {
                        // move effect
                        world[i - 1]->get_red()->move();
                        moved.insert(world[i - 1]->get_red());
                        // print info
                        timer.print();
                        printf(" red %s %d marched to city %d with %d elements and force %d\n", warrior_name[world[i - 1]->get_red()->type], world[i - 1]->get_red()->num, i, world[i - 1]->get_red()->element, world[i - 1]->get_red()->strength);
                        // real move
                        tmp->set_red(world[i - 1]->pop_red());
                    }
                    if (i != 0 && i <= N && world[i + 1]->get_blue() != nullptr && moved.find(world[i + 1]->get_blue()) == moved.end())
                    {
                        world[i + 1]->get_blue()->move();
                        moved.insert(world[i + 1]->get_blue());
                        timer.print();
                        printf(" blue %s %d marched to city %d with %d elements and force %d\n", warrior_name[world[i + 1]->get_blue()->type], world[i + 1]->get_blue()->num, i, world[i + 1]->get_blue()->element, world[i + 1]->get_blue()->strength);
                        tmp->set_blue(world[i + 1]->pop_blue());
                    }
                    if (i == 0 && world[i + 1]->get_blue() != nullptr && moved.find(world[i + 1]->get_blue()) == moved.end())
                    {
                        world[i + 1]->get_blue()->move();
                        moved.insert(world[i + 1]->get_blue());
                        timer.print();
                        printf(" blue %s %d reached red headquarter with %d elements and force %d\n", warrior_name[world[i + 1]->get_blue()->type], world[i + 1]->get_blue()->num, world[i + 1]->get_blue()->element, world[i + 1]->get_blue()->strength);
                        tmp->set_blue(world[i + 1]->pop_blue());
                        if (tmp->check_stop())
                        {
                            timer.print();
                            printf(" red headquarter was taken\n");
                        }
                    }
                    if (i == N + 1 && world[i - 1]->get_red() != nullptr && moved.find(world[i - 1]->get_red()) == moved.end())
                    {
                        world[i - 1]->get_red()->move();
                        moved.insert(world[i - 1]->get_red());
                        timer.print();
                        printf(" red %s %d reached blue headquarter with %d elements and force %d\n", warrior_name[world[i - 1]->get_red()->type], world[i - 1]->get_red()->num, world[i - 1]->get_red()->element, world[i - 1]->get_red()->strength);
                        tmp->set_red(world[i - 1]->pop_red());
                        if (tmp->check_stop())
                        {
                            timer.print();
                            printf(" blue headquarter was taken\n");
                        }
                    }
                }
            }
            break;
        case 20:
            if (stop == 0)
            {
                for (int i = 1; i <= N; ++i)
                {
                    building *tmp = world[i];
                    tmp->city_element += building::city_produce;
                }
            }
            break;
        case 30:
            if (stop == 0)
            {
                for (int i = 1; i <= N; ++i)
                {
                    building *tmp = world[i];
                    if (tmp->get_red() != nullptr && tmp->get_blue() == nullptr && tmp->city_element > 0)
                    {
                        building *tmp1 = world[0];
                        tmp1->change_element(tmp->city_element);
                        timer.print();
                        printf(" red %s %d earned %d elements for his headquarter\n", warrior_name[tmp->get_red()->type], tmp->get_red()->num, tmp->city_element);
                        tmp->city_element = 0;
                    }
                    else if (tmp->get_blue() != nullptr && tmp->get_red() == nullptr && tmp->city_element > 0)
                    {
                        building *tmp1 = world[N + 1];
                        tmp1->change_element(tmp->city_element);
                        timer.print();
                        printf(" blue %s %d earned %d elements for his headquarter\n", warrior_name[tmp->get_blue()->type], tmp->get_blue()->num, tmp->city_element);
                        tmp->city_element = 0;
                    }
                }
            }
            break;
        case 35:
            if (stop == 0)
            {
                // arrow shooting
                for (int i = 1; i <= N; ++i)
                {
                    building *tmp = world[i];
                    if (tmp->get_red() != nullptr && tmp->get_red()->w_set["arrow"] > 0)
                    {
                        if (i != N)
                        {
                            building *tmp1 = world[i + 1];
                            if (tmp1->get_blue() != nullptr)
                            {
                                tmp->get_red()->out_shoot(tmp1->get_blue());
                            }
                        }
                    }
                    if (tmp->get_blue() != nullptr && tmp->get_blue()->w_set["arrow"] > 0)
                    {
                        if (i != 1)
                        {
                            building *tmp1 = world[i - 1];
                            if (tmp1->get_red() != nullptr)
                            {
                                tmp->get_blue()->out_shoot(tmp1->get_red());
                            }
                        }
                    }
                }
            }
            break;
        case 38:
            if (stop == 0)
            {
                for (int i = 1; i <= N; ++i)
                {
                    building *tmp = world[i];
                    if (tmp->get_red() == nullptr || tmp->get_blue() == nullptr || tmp->get_red()->element <= 0 || tmp->get_blue()->element <= 0)
                        continue;
                    if (tmp->get_red()->w_set["bomb"] <= 0 && tmp->get_blue()->w_set["bomb"] <= 0)
                        continue;
                    int color = (tmp->flag != 0) ? tmp->flag : ((i % 2 == 0) ? -1 : 1);
                    if (tmp->get_red()->w_set["bomb"] > 0)
                    {
                        if (color > 0)
                        {
                            tmp->get_red()->boom(tmp->get_blue(), 1);
                        }
                        else
                        {
                            tmp->get_red()->boom(tmp->get_blue(), 0);
                        }
                    }
                    if (tmp->get_blue()->w_set["bomb"] > 0)
                    {
                        if (color > 0)
                        {
                            tmp->get_blue()->boom(tmp->get_red(), 0);
                        }
                        else
                        {
                            tmp->get_blue()->boom(tmp->get_red(), 1);
                        }
                    }
                }
            }
            break;
        case 40:
            if (stop == 0)
            {
                // fight
                for (int i = 1; i <= N; ++i)
                {
                    building *tmp = world[i];
                    if (tmp->get_red() != nullptr && tmp->get_blue() != nullptr)
                    {
                        int color = (tmp->flag != 0) ? tmp->flag : ((i % 2 == 0) ? -1 : 1);
                        if (tmp->get_red()->element > 0 && tmp->get_blue()->element > 0)
                        {
                            int red_ori = tmp->get_red()->element;
                            int blue_ori = tmp->get_blue()->element;
                            if (color > 0)
                            {
                                tmp->get_red()->attack(tmp->get_blue());
                                timer.print();
                                printf(" red %s %d attacked blue %s %d in city %d with %d elements and force %d\n", warrior_name[tmp->get_red()->type], tmp->get_red()->num, warrior_name[tmp->get_blue()->type], tmp->get_blue()->num, i, tmp->get_red()->element, tmp->get_red()->strength);
                                if (tmp->get_blue()->element > 0 && tmp->get_blue()->type != 1)
                                {
                                    tmp->get_blue()->fight_back(tmp->get_red());
                                    timer.print();
                                    printf(" blue %s %d fought back against red %s %d in city %d\n", warrior_name[tmp->get_blue()->type], tmp->get_blue()->num, warrior_name[tmp->get_red()->type], tmp->get_red()->num, i);
                                }
                                if (tmp->get_red()->element > 0 && tmp->get_blue()->element <= 0)
                                {
                                    tmp->winner = 1;
                                    timer.print();
                                    printf(" blue %s %d was killed in city %d\n", warrior_name[tmp->get_blue()->type], tmp->get_blue()->num, i);
                                }
                                else if (tmp->get_red()->element <= 0 && tmp->get_blue()->element > 0)
                                {
                                    tmp->winner = -1;
                                    timer.print();
                                    printf(" red %s %d was killed in city %d\n", warrior_name[tmp->get_red()->type], tmp->get_red()->num, i);
                                }
                                else
                                {
                                    tmp->winner = 0;
                                    tmp->accum_vic = 0;
                                    // dragon morale
                                    if (tmp->get_red()->type == 0)
                                    {
                                        tmp->get_red()->morale -= 0.2;
                                    }
                                    else if (tmp->get_blue()->type == 0)
                                    {
                                        tmp->get_blue()->morale -= 0.2;
                                    }
                                }
                                // dragon morale
                                if (tmp->winner == 1 && tmp->get_red()->type == 0)
                                {
                                    tmp->get_red()->morale += 0.2;
                                }
                                else if (tmp->winner == -1 && tmp->get_blue()->type == 0)
                                {
                                    tmp->get_blue()->morale += 0.2;
                                }
                                // dragon yell
                                if (tmp->get_red()->type == 0 && tmp->get_red()->element > 0 && tmp->get_red()->morale > 0.8)
                                {
                                    timer.print();
                                    printf(" red dragon %d yelled in city %d\n", tmp->get_red()->num, i);
                                }
                                if (tmp->city_element > 0 && tmp->winner == 1)
                                {
                                    building *tmp1 = world[0];
                                    timer.print();
                                    printf(" red %s %d earned %d elements for his headquarter\n", warrior_name[tmp->get_red()->type], tmp->get_red()->num, tmp->city_element);
                                    tmp1->earn(tmp->city_element);
                                    tmp->city_element = 0;
                                }
                                else if (tmp->city_element > 0 && tmp->winner == -1)
                                {
                                    building *tmp1 = world[N + 1];
                                    timer.print();
                                    printf(" blue %s %d earned %d elements for his headquarter\n", warrior_name[tmp->get_blue()->type], tmp->get_blue()->num, tmp->city_element);
                                    tmp1->earn(tmp->city_element);
                                    tmp->city_element = 0;
                                }
                                if (tmp->winner == 1)
                                {
                                    if (tmp->accum_vic < 0)
                                    {
                                        tmp->accum_vic = 1;
                                    }
                                    else
                                    {
                                        tmp->accum_vic = min(2, tmp->accum_vic + 1);
                                        if (tmp->accum_vic == 2 && tmp->flag != 1)
                                        {
                                            tmp->flag = 1;
                                            timer.print();
                                            printf(" red flag raised in city %d\n", i);
                                        }
                                    }
                                }
                                else if (tmp->winner == -1)
                                {
                                    if (tmp->accum_vic > 0)
                                    {
                                        tmp->accum_vic = -1;
                                    }
                                    else
                                    {
                                        tmp->accum_vic = max(-2, tmp->accum_vic - 1);
                                        if (tmp->accum_vic == -2 && tmp->flag != -1)
                                        {
                                            tmp->flag = -1;
                                            timer.print();
                                            printf(" blue flag raised in city %d\n", i);
                                        }
                                    }
                                }
                            }
                            else
                            {
                                tmp->get_blue()->attack(tmp->get_red());
                                timer.print();
                                printf(" blue %s %d attacked red %s %d in city %d with %d elements and force %d\n", warrior_name[tmp->get_blue()->type], tmp->get_blue()->num, warrior_name[tmp->get_red()->type], tmp->get_red()->num, i, tmp->get_blue()->element, tmp->get_blue()->strength);
                                if (tmp->get_red()->element > 0 && tmp->get_red()->type != 1)
                                {
                                    tmp->get_red()->fight_back(tmp->get_blue());
                                    timer.print();
                                    printf(" red %s %d fought back against blue %s %d in city %d\n", warrior_name[tmp->get_red()->type], tmp->get_red()->num, warrior_name[tmp->get_blue()->type], tmp->get_blue()->num, i);
                                }
                                if (tmp->get_red()->element > 0 && tmp->get_blue()->element <= 0)
                                {
                                    tmp->winner = 1;
                                    timer.print();
                                    printf(" blue %s %d was killed in city %d\n", warrior_name[tmp->get_blue()->type], tmp->get_blue()->num, i);
                                }
                                else if (tmp->get_red()->element <= 0 && tmp->get_blue()->element > 0)
                                {
                                    tmp->winner = -1;
                                    timer.print();
                                    printf(" red %s %d was killed in city %d\n", warrior_name[tmp->get_red()->type], tmp->get_red()->num, i);
                                }
                                else
                                {
                                    tmp->winner = 0;
                                    // update accum_vic
                                    tmp->accum_vic = 0;
                                    // dragon morale
                                    if (tmp->get_red()->type == 0)
                                    {
                                        tmp->get_red()->morale -= 0.2;
                                    }
                                    else if (tmp->get_blue()->type == 0)
                                    {
                                        tmp->get_blue()->morale -= 0.2;
                                    }
                                }
                                // dragon morale
                                if (tmp->winner == 1 && tmp->get_red()->type == 0)
                                {
                                    tmp->get_red()->morale += 0.2;
                                }
                                else if (tmp->winner == -1 && tmp->get_blue()->type == 0)
                                {
                                    tmp->get_blue()->morale += 0.2;
                                }
                                // dragon yell
                                if (tmp->get_blue()->type == 0 && tmp->get_blue()->element > 0 && tmp->get_blue()->morale > 0.8)
                                {
                                    timer.print();
                                    printf(" blue dragon %d yelled in city %d\n", tmp->get_blue()->num, i);
                                }
                                if (tmp->city_element > 0 && tmp->winner == 1)
                                {
                                    building *tmp1 = world[0];
                                    timer.print();
                                    printf(" red %s %d earned %d elements for his headquarter\n", warrior_name[tmp->get_red()->type], tmp->get_red()->num, tmp->city_element);
                                    tmp1->earn(tmp->city_element);
                                    tmp->city_element = 0;
                                }
                                else if (tmp->city_element > 0 && tmp->winner == -1)
                                {
                                    building *tmp1 = world[N + 1];
                                    timer.print();
                                    printf(" blue %s %d earned %d elements for his headquarter\n", warrior_name[tmp->get_blue()->type], tmp->get_blue()->num, tmp->city_element);
                                    tmp1->earn(tmp->city_element);
                                    tmp->city_element = 0;
                                }
                                if (tmp->winner == 1)
                                {
                                    if (tmp->accum_vic < 0)
                                    {
                                        tmp->accum_vic = 1;
                                    }
                                    else
                                    {
                                        tmp->accum_vic = min(2, tmp->accum_vic + 1);
                                        if (tmp->accum_vic == 2 && tmp->flag != 1)
                                        {
                                            tmp->flag = 1;
                                            timer.print();
                                            printf(" red flag raised in city %d\n", i);
                                        }
                                    }
                                }
                                else if (tmp->winner == -1)
                                {
                                    if (tmp->accum_vic > 0)
                                    {
                                        tmp->accum_vic = -1;
                                    }
                                    else
                                    {
                                        tmp->accum_vic = max(-2, tmp->accum_vic - 1);
                                        if (tmp->accum_vic == -2 && tmp->flag != -1)
                                        {
                                            tmp->flag = -1;
                                            timer.print();
                                            printf(" blue flag raised in city %d\n", i);
                                        }
                                    }
                                }
                            }
                            if (tmp->get_blue()->type == 3 && tmp->get_red()->type == 3)
                            {
                                if (tmp->get_blue()->element > 0 && tmp->get_red()->element > 0)
                                {
                                    tmp->get_blue()->set_loyalty();
                                    tmp->get_red()->set_loyalty();
                                }
                                else if (tmp->get_blue()->element > 0 && tmp->get_red()->element <= 0)
                                {
                                    tmp->get_blue()->element += red_ori;
                                }
                                else if (tmp->get_blue()->element <= 0 && tmp->get_red()->element > 0)
                                {
                                    tmp->get_red()->element += blue_ori;
                                }
                            }
                            else if (tmp->get_blue()->type == 3)
                            {
                                if (tmp->get_blue()->element > 0 && tmp->get_red()->element > 0)
                                {
                                    tmp->get_blue()->set_loyalty();
                                }
                                else if (tmp->get_blue()->element <= 0 && tmp->get_red()->element > 0)
                                {
                                    tmp->get_red()->element += blue_ori;
                                }
                            }
                            else if (tmp->get_red()->type == 3)
                            {
                                if (tmp->get_blue()->element > 0 && tmp->get_red()->element > 0)
                                {
                                    tmp->get_red()->set_loyalty();
                                }
                                else if (tmp->get_blue()->element > 0 && tmp->get_red()->element <= 0)
                                {
                                    tmp->get_blue()->element += red_ori;
                                }
                            }
                        }
                        else
                        {
                            int color = (tmp->flag != 0) ? tmp->flag : ((i % 2 == 0) ? -1 : 1);
                            if (tmp->get_red()->element > 0 && tmp->get_blue()->element <= 0)
                            {
                                tmp->winner = 1;
                                if (tmp->get_red()->type == 0)
                                {
                                    tmp->get_red()->morale += 0.2;
                                    if (tmp->get_red()->morale > 0.8 && color > 0)
                                    {
                                        timer.print();
                                        printf(" red dragon %d yelled in city %d\n", tmp->get_red()->num, i);
                                    }
                                }
                                building *tmp1 = world[0];
                                timer.print();
                                printf(" red %s %d earned %d elements for his headquarter\n", warrior_name[tmp->get_red()->type], tmp->get_red()->num, tmp->city_element);
                                tmp1->earn(tmp->city_element);
                                tmp->city_element = 0;
                                if (tmp->accum_vic < 0)
                                {
                                    tmp->accum_vic = 1;
                                }
                                else
                                {
                                    tmp->accum_vic = min(2, tmp->accum_vic + 1);
                                    if (tmp->accum_vic == 2 && tmp->flag != 1)
                                    {
                                        tmp->flag = 1;
                                        timer.print();
                                        printf(" red flag raised in city %d\n", i);
                                    }
                                }
                            }
                            else if (tmp->get_red()->element <= 0 && tmp->get_blue()->element > 0)
                            {
                                tmp->winner = -1;
                                if (tmp->get_blue()->type == 0)
                                {
                                    tmp->get_blue()->morale += 0.2;
                                    if (tmp->get_blue()->morale > 0.8 && color < 0)
                                    {
                                        timer.print();
                                        printf(" blue dragon %d yelled in city %d\n", tmp->get_blue()->num, i);
                                    }
                                }
                                building *tmp1 = world[N + 1];
                                timer.print();
                                printf(" blue %s %d earned %d elements for his headquarter\n", warrior_name[tmp->get_blue()->type], tmp->get_blue()->num, tmp->city_element);
                                tmp1->earn(tmp->city_element);
                                tmp->city_element = 0;
                                if (tmp->accum_vic > 0)
                                {
                                    tmp->accum_vic = -1;
                                }
                                else
                                {
                                    tmp->accum_vic = max(-2, tmp->accum_vic - 1);
                                    if (tmp->accum_vic == -2 && tmp->flag != -1)
                                    {
                                        tmp->flag = -1;
                                        timer.print();
                                        printf(" blue flag raised in city %d\n", i);
                                    }
                                }
                            }
                            else
                            {
                                tmp->winner = 0;
                            }
                        }
                    }
                }
                // wolf steal
                for (int i = 1; i <= N; ++i)
                {
                    building *tmp = world[i];
                    if (tmp->winner == 1 && tmp->get_red()->type == 4)
                    {
                        tmp->get_red()->wolf_get(tmp->get_blue());
                    }
                    else if (tmp->winner == -1 && tmp->get_blue()->type == 4)
                    {
                        tmp->get_blue()->wolf_get(tmp->get_red());
                    }
                }
                // clean the dead
                for (int i = 1; i <= N; ++i)
                {
                    building *tmp = world[i];
                    if (tmp->get_blue() != nullptr && tmp->get_blue()->element <= 0)
                    {
                        tmp->pop_blue();
                    }
                    if (tmp->get_red() != nullptr && tmp->get_red()->element <= 0)
                    {
                        tmp->pop_red();
                    }
                }
                // red reward
                for (int i = 1; i <= N; ++i)
                {
                    building *tmp = world[i];
                    if (tmp->winner == 1)
                    {
                        building *tmp1 = world[0];
                        tmp1->reward(tmp->get_red());
                    }
                }
                // blue reward
                for (int i = N; i >= 1; --i)
                {
                    building *tmp = world[i];
                    if (tmp->winner == -1)
                    {
                        building *tmp1 = world[N + 1];
                        tmp1->reward(tmp->get_blue());
                    }
                }
                // clear winner
                for (int i = 1; i <= N; ++i)
                {
                    building *tmp = world[i];
                    tmp->winner = 0;
                }
            }
            break;
        case 50:
            if (stop == 0)
            {
                world[0]->print_element();
                world[N + 1]->print_element();
            }
            break;
        case 55:
            if (stop == 0)
            {
                for (int i = 0; i <= N + 1; ++i)
                {
                    if (world[i]->get_red() != nullptr)
                    {
                        world[i]->get_red()->report();
                    }
                }
                for (int i = 0; i <= N + 1; ++i)
                {
                    if (world[i]->get_blue() != nullptr)
                    {
                        world[i]->get_blue()->report();
                    }
                }
            }
            break;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
    {
        scanf("%d %d %d %d %d", &M, &N, &R, &K, &T);
        for (int i = 0; i < 5; ++i)
            scanf("%d", &element_com[i]);
        for (int i = 0; i < 5; ++i)
            scanf("%d", &strength_com[i]);
        printf("Case %d:\n", i);
        game_play();
    }
}