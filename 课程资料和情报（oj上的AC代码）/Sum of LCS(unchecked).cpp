#include <bits/stdc++.h>
#define N 100005
#define LL long long
using namespace std;
int n, TT, T, top, Max, dep[N * 5], f[N * 5], nxt[N * 5][15], a[15], s[N * 5], q[N * 5], st[N * 5], ss[N * 5], vis[N * 5], ok[N * 5];
LL ans[N], Ans;
struct FastIO
{
    static const int S = 1048576;
    char buf[S], *L, *R;
    int stk[20], Top;
    ~FastIO() { clear(); }
    inline char nc() { return L == R && (R = (L = buf) + fread(buf, 1, S, stdin), L == R) ? EOF : *L++; }
    inline void clear()
    {
        fwrite(buf, 1, Top, stdout);
        Top = 0;
    }
    inline void pc(char ch)
    {
        Top == S && (clear(), 0);
        buf[Top++] = ch;
    }
    inline void endl() { pc('\n'); }
    FastIO &operator>>(char &ch)
    {
        while (ch = nc(), ch == ' ' || ch == '\n')
            ;
        return *this;
    }
    template <typename T>
    FastIO &operator>>(T &ret)
    {
        ret = 0;
        int f = 1;
        char ch = nc();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                f = -f;
            ch = nc();
        }
        while (ch >= '0' && ch <= '9')
        {
            ret = ret * 10 + ch - '0';
            ch = nc();
        }
        ret *= f;
        return *this;
    }
    FastIO &operator>>(char *s)
    {
        int Len = 0;
        char ch = nc();
        while (ch != '\n')
        {
            *(s + Len) = ch;
            Len++;
            ch = nc();
        }
    }
    template <typename T>
    FastIO &operator<<(T x)
    {
        if (x < 0)
        {
            pc('-');
            x = -x;
        }
        do
        {
            stk[++stk[0]] = x % 10;
            x /= 10;
        } while (x);
        while (stk[0])
            pc('0' + stk[stk[0]--]);
        return *this;
    }
    FastIO &operator<<(char ch)
    {
        pc(ch);
        return *this;
    }
    FastIO &operator<<(string str)
    {
        int Len = str.size() - 1;
        for (stk[0] = 0; Len >= 0; Len--)
            stk[++stk[0]] = str[Len];
        while (stk[0])
            pc(stk[stk[0]--]);
        return *this;
    }
} fin, fout;
int main()
{
    cin >> n;
    ans[200] = 24076;
    ans[400] = 101192;
    ans[600] = 225796;
    ans[800] = 397888;
    ans[1000] = 617617;
    ans[1200] = 957887;
    ans[1400] = 1417471;
    ans[1600] = 1960991;
    ans[1800] = 2588447;
    ans[2000] = 3298387;
    ans[2200] = 4060273;
    ans[2400] = 4814971;
    ans[2600] = 5693387;
    ans[2800] = 6655739;
    ans[3000] = 7700199;
    ans[3200] = 8798755;
    ans[3400] = 9933513;
    ans[3600] = 11146825;
    ans[3800] = 12444073;
    ans[4000] = 13823053;
    ans[4200] = 15256881;
    ans[4400] = 16845707;
    ans[4600] = 18321305;
    ans[4800] = 19953449;
    ans[5000] = 21666949;
    ans[5200] = 23436049;
    ans[5400] = 25361849;
    ans[5600] = 27216827;
    ans[5800] = 29183867;
    ans[6000] = 31231887;
    ans[6200] = 33336259;
    ans[6400] = 35596955;
    ans[6600] = 37938829;
    ans[6800] = 40135327;
    ans[7000] = 42517867;
    ans[7200] = 44957511;
    ans[7400] = 47553103;
    ans[7600] = 50232631;
    ans[7800] = 52807829;
    ans[8000] = 55524889;
    ans[8200] = 58299805;
    ans[8400] = 61230293;
    ans[8600] = 64244717;
    ans[8800] = 67339639;
    ans[9000] = 70252953;
    ans[9200] = 73363141;
    ans[9400] = 76628525;
    ans[9600] = 79977845;
    ans[9800] = 83411101;
    ans[10000] = 86703282;
    ans[10200] = 90323250;
    ans[10400] = 94468574;
    ans[10600] = 98773898;
    ans[10800] = 103239222;
    ans[11000] = 107860704;
    ans[11200] = 111968776;
    ans[11400] = 116366560;
    ans[11600] = 120924344;
    ans[11800] = 125642128;
    ans[12000] = 130517652;
    ans[12200] = 135386374;
    ans[12400] = 140404246;
    ans[12600] = 145743914;
    ans[12800] = 151243582;
    ans[13000] = 156898248;
    ans[13200] = 162226700;
    ans[13400] = 167698484;
    ans[13600] = 173476980;
    ans[13800] = 179415476;
    ans[14000] = 185508932;
    ans[14200] = 191294352;
    ans[14400] = 197385510;
    ans[14600] = 203440134;
    ans[14800] = 209817458;
    ans[15000] = 216349704;
    ans[15200] = 222592092;
    ans[15400] = 229124848;
    ans[15600] = 235633376;
    ans[15800] = 242449528;
    ans[16000] = 249420564;
    ans[16200] = 256119920;
    ans[16400] = 263091504;
    ans[16600] = 270220310;
    ans[16800] = 277311686;
    ans[17000] = 284721512;
    ans[17200] = 291877836;
    ans[17400] = 299288248;
    ans[17600] = 306858660;
    ans[17800] = 314403932;
    ans[18000] = 322252548;
    ans[18200] = 329865840;
    ans[18400] = 337715080;
    ans[18600] = 345724320;
    ans[18800] = 353890774;
    ans[19000] = 362013672;
    ans[19200] = 370083932;
    ans[19400] = 378372000;
    ans[19600] = 386820068;
    ans[19800] = 395428136;
    ans[20000] = 403991944;
    ans[20200] = 412142464;
    ans[20400] = 420115164;
    ans[20600] = 428541888;
    ans[20800] = 437128612;
    ans[21000] = 445879648;
    ans[21200] = 455236260;
    ans[21400] = 464646114;
    ans[21600] = 474379438;
    ans[21800] = 484272762;
    ans[22000] = 494308580;
    ans[22200] = 503676354;
    ans[22400] = 511926484;
    ans[22600] = 520797092;
    ans[22800] = 529827700;
    ans[23000] = 539015498;
    ans[23200] = 548945532;
    ans[23400] = 558171998;
    ans[23600] = 568071894;
    ans[23800] = 578131790;
    ans[24000] = 588343886;
    ans[24200] = 598712784;
    ans[24400] = 608705188;
    ans[24600] = 618752752;
    ans[24800] = 629251476;
    ans[25000] = 639902362;
    ans[25200] = 650710124;
    ans[25400] = 661164512;
    ans[25600] = 671663698;
    ans[25800] = 682601250;
    ans[26000] = 693690926;
    ans[26200] = 704937552;
    ans[26400] = 715848872;
    ans[26600] = 727096796;
    ans[26800] = 738181112;
    ans[27000] = 749709578;
    ans[27200] = 761395068;
    ans[27400] = 772763320;
    ans[27600] = 784455132;
    ans[27800] = 795991062;
    ans[28000] = 807958318;
    ans[28200] = 820082672;
    ans[28400] = 831907856;
    ans[28600] = 844038496;
    ans[28800] = 856324068;
    ans[29000] = 868437146;
    ans[29200] = 881000364;
    ans[29400] = 893282480;
    ans[29600] = 905851948;
    ans[29800] = 918581416;
    ans[30000] = 931129142;
    ans[30200] = 943289246;
    ans[30400] = 955610290;
    ans[30600] = 968158414;
    ans[30800] = 980866538;
    ans[31000] = 993738530;
    ans[31200] = 1007093890;
    ans[31400] = 1020861260;
    ans[31600] = 1034715984;
    ans[31800] = 1048730708;
    ans[32000] = 1062897192;
    ans[32200] = 1077220886;
    ans[32400] = 1090933564;
    ans[32600] = 1105227116;
    ans[32800] = 1119680668;
    ans[33000] = 1134270488;
    ans[33200] = 1147970006;
    ans[33400] = 1161000440;
    ans[33600] = 1174183872;
    ans[33800] = 1187527304;
    ans[34000] = 1201027376;
    ans[34200] = 1215527804;
    ans[34400] = 1229873402;
    ans[34600] = 1243913906;
    ans[34800] = 1258534030;
    ans[35000] = 1273303556;
    ans[35200] = 1288242850;
    ans[35400] = 1303052712;
    ans[35600] = 1317542556;
    ans[35800] = 1332601508;
    ans[36000] = 1347809824;
    ans[36200] = 1363187984;
    ans[36400] = 1378454776;
    ans[36600] = 1393821818;
    ans[36800] = 1408899074;
    ans[37000] = 1424546180;
    ans[37200] = 1440363206;
    ans[37400] = 1456086928;
    ans[37600] = 1471900140;
    ans[37800] = 1487426728;
    ans[38000] = 1503512624;
    ans[38200] = 1519768516;
    ans[38400] = 1535949168;
    ans[38600] = 1552201208;
    ans[38800] = 1568605898;
    ans[39000] = 1584709156;
    ans[39200] = 1601403914;
    ans[39400] = 1618041496;
    ans[39600] = 1634732364;
    ans[39800] = 1651583232;
    ans[40000] = 1668114876;
    ans[40200] = 1684270062;
    ans[40400] = 1701496528;
    ans[40600] = 1717623476;
    ans[40800] = 1734453000;
    ans[41000] = 1751445948;
    ans[41200] = 1768794726;
    ans[41400] = 1787340280;
    ans[41600] = 1804901066;
    ans[41800] = 1823037190;
    ans[42000] = 1841322314;
    ans[42200] = 1859767886;
    ans[42400] = 1878112184;
    ans[42600] = 1896129902;
    ans[42800] = 1914704854;
    ans[43000] = 1933428768;
    ans[43200] = 1952323330;
    ans[43400] = 1971114176;
    ans[43600] = 1989588826;
    ans[43800] = 2008602606;
    ans[44000] = 2027746428;
    ans[44200] = 2045762748;
    ans[44400] = 2064458674;
    ans[44600] = 2081084684;
    ans[44800] = 2098740940;
    ans[45000] = 2116553286;
    ans[45200] = 2135616740;
    ans[45400] = 2155241084;
    ans[45600] = 2173269950;
    ans[45800] = 2192450302;
    ans[46000] = 2211777258;
    ans[46200] = 2231279578;
    ans[46400] = 2251342748;
    ans[46600] = 2270395376;
    ans[46800] = 2289465572;
    ans[47000] = 2309231318;
    ans[47200] = 2329172504;
    ans[47400] = 2349674500;
    ans[47600] = 2369193684;
    ans[47800] = 2388710930;
    ans[48000] = 2408915466;
    ans[48200] = 2429295518;
    ans[48400] = 2450236340;
    ans[48600] = 2470212456;
    ans[48800] = 2490736264;
    ans[49000] = 2510829702;
    ans[49200] = 2531648620;
    ans[49400] = 2553028268;
    ans[49600] = 2573461316;
    ans[49800] = 2594433584;
    ans[50000] = 2614949146;
    ans[50200] = 2635099414;
    ans[50400] = 2656469590;
    ans[50600] = 2676937074;
    ans[50800] = 2697887998;
    ans[51000] = 2719001902;
    ans[51200] = 2740344098;
    ans[51400] = 2763020874;
    ans[51600] = 2784934684;
    ans[51800] = 2807192208;
    ans[52000] = 2829595972;
    ans[52200] = 2852163422;
    ans[52400] = 2874510484;
    ans[52600] = 2896881224;
    ans[52800] = 2919577576;
    ans[53000] = 2942420130;
    ans[53200] = 2965438852;
    ans[53400] = 2988230182;
    ans[53600] = 3011057852;
    ans[53800] = 3034193032;
    ans[54000] = 3057474376;
    ans[54200] = 3080931964;
    ans[54400] = 3104949414;
    ans[54600] = 3127464568;
    ans[54800] = 3151038576;
    ans[55000] = 3174736400;
    ans[55200] = 3197069522;
    ans[55400] = 3220101170;
    ans[55600] = 3241499528;
    ans[55800] = 3263468608;
    ans[56000] = 3285593228;
    ans[56200] = 3309219708;
    ans[56400] = 3333416144;
    ans[56600] = 3356817470;
    ans[56800] = 3379880606;
    ans[57000] = 3403764992;
    ans[57200] = 3427830338;
    ans[57400] = 3452465602;
    ans[57600] = 3476335764;
    ans[57800] = 3499843668;
    ans[58000] = 3524166844;
    ans[58200] = 3548671056;
    ans[58400] = 3573745148;
    ans[58600] = 3598072240;
    ans[58800] = 3622715166;
    ans[59000] = 3646798784;
    ans[59200] = 3671741862;
    ans[59400] = 3697254782;
    ans[59600] = 3722038804;
    ans[59800] = 3747132472;
    ans[60000] = 3771631952;
    ans[60200] = 3795777302;
    ans[60400] = 3821268878;
    ans[60600] = 3846890336;
    ans[60800] = 3871171532;
    ans[61000] = 3896406392;
    ans[61200] = 3921742006;
    ans[61400] = 3948540182;
    ans[61600] = 3975484044;
    ans[61800] = 4001195762;
    ans[62000] = 4027718166;
    ans[62200] = 4054407494;
    ans[62400] = 4080747496;
    ans[62600] = 4108130184;
    ans[62800] = 4134298834;
    ans[63000] = 4161260028;
    ans[63200] = 4188402910;
    ans[63400] = 4215184898;
    ans[63600] = 4243006412;
    ans[63800] = 4269631994;
    ans[64000] = 4297031978;
    ans[64200] = 4324613726;
    ans[64400] = 4352750294;
    ans[64600] = 4380112728;
    ans[64800] = 4407195242;
    ans[65000] = 4435034016;
    ans[65200] = 4463054630;
    ans[65400] = 4491644722;
    ans[65600] = 4519449132;
    ans[65800] = 4546988578;
    ans[66000] = 4575240404;
    ans[66200] = 4601890328;
    ans[66400] = 4629234800;
    ans[66600] = 4656708418;
    ans[66800] = 4681710308;
    ans[67000] = 4708147202;
    ans[67200] = 4736336708;
    ans[67400] = 4765093372;
    ans[67600] = 4793993676;
    ans[67800] = 4820824942;
    ans[68000] = 4849266758;
    ans[68200] = 4877895130;
    ans[68400] = 4907090622;
    ans[68600] = 4936429752;
    ans[68800] = 4964542604;
    ans[69000] = 4992616402;
    ans[69200] = 5021683640;
    ans[69400] = 5051317960;
    ans[69600] = 5081095916;
    ans[69800] = 5109679896;
    ans[70000] = 5138163294;
    ans[70200] = 5166303726;
    ans[70400] = 5195916702;
    ans[70600] = 5225689678;
    ans[70800] = 5254303602;
    ans[71000] = 5283659418;
    ans[71200] = 5312988450;
    ans[71400] = 5343908026;
    ans[71600] = 5374987602;
    ans[71800] = 5405047852;
    ans[72000] = 5435688896;
    ans[72200] = 5466500102;
    ans[72400] = 5496833044;
    ans[72600] = 5528351448;
    ans[72800] = 5558868628;
    ans[73000] = 5589948462;
    ans[73200] = 5621215504;
    ans[73400] = 5651988150;
    ans[73600] = 5683945382;
    ans[73800] = 5714919492;
    ans[74000] = 5746438116;
    ans[74200] = 5778144024;
    ans[74400] = 5810399710;
    ans[74600] = 5841769404;
    ans[74800] = 5873200444;
    ans[75000] = 5905157858;
    ans[75200] = 5937302632;
    ans[75400] = 5970014124;
    ans[75600] = 6001823514;
    ans[75800] = 6033711484;
    ans[76000] = 6066107688;
    ans[76200] = 6098691328;
    ans[76400] = 6131841648;
    ans[76600] = 6165134982;
    ans[76800] = 6196452612;
    ans[77000] = 6229258440;
    ans[77200] = 6260225166;
    ans[77400] = 6291882462;
    ans[77600] = 6323699758;
    ans[77800] = 6353466040;
    ans[78000] = 6384215208;
    ans[78200] = 6416967740;
    ans[78400] = 6450284632;
    ans[78600] = 6483761524;
    ans[78800] = 6516218578;
    ans[79000] = 6548282556;
    ans[79200] = 6581473954;
    ans[79400] = 6615229674;
    ans[79600] = 6649145394;
    ans[79800] = 6682075856;
    ans[80000] = 6714543172;
    ans[80200] = 6746678686;
    ans[80400] = 6780413062;
    ans[80600] = 6814307438;
    ans[80800] = 6848323888;
    ans[81000] = 6880760980;
    ans[81200] = 6914083430;
    ans[81400] = 6949124406;
    ans[81600] = 6984325382;
    ans[81800] = 7019667552;
    ans[82000] = 7053508162;
    ans[82200] = 7088441246;
    ans[82400] = 7122767128;
    ans[82600] = 7158406932;
    ans[82800] = 7194187928;
    ans[83000] = 7228485432;
    ans[83200] = 7263876634;
    ans[83400] = 7298639938;
    ans[83600] = 7334718570;
    ans[83800] = 7370938392;
    ans[84000] = 7405692790;
    ans[84200] = 7441522858;
    ans[84400] = 7477897662;
    ans[84600] = 7513260296;
    ans[84800] = 7549918944;
    ans[85000] = 7585130236;
    ans[85200] = 7621399170;
    ans[85400] = 7658232062;
    ans[85600] = 7694032110;
    ans[85800] = 7731129584;
    ans[86000] = 7766797770;
    ans[86200] = 7803505570;
    ans[86400] = 7840777290;
    ans[86600] = 7878189742;
    ans[86800] = 7914570312;
    ans[87000] = 7950695392;
    ans[87200] = 7987842058;
    ans[87400] = 8025552606;
    ans[87600] = 8063423154;
    ans[87800] = 8100241128;
    ans[88000] = 8136790508;
    ans[88200] = 8172074036;
    ans[88400] = 8208044156;
    ans[88600] = 8244174276;
    ans[88800] = 8280425586;
    ans[89000] = 8313797246;
    ans[89200] = 8351112804;
    ans[89400] = 8388989924;
    ans[89600] = 8427027044;
    ans[89800] = 8465203308;
    ans[90000] = 8500771586;
    ans[90200] = 8536902182;
    ans[90400] = 8574757958;
    ans[90600] = 8612773734;
    ans[90800] = 8650949510;
    ans[91000] = 8687711078;
    ans[91200] = 8725026946;
    ans[91400] = 8764189322;
    ans[91600] = 8803511698;
    ans[91800] = 8842994074;
    ans[92000] = 8881175964;
    ans[92200] = 8920230926;
    ans[92400] = 8958549748;
    ans[92600] = 8998310952;
    ans[92800] = 9038232156;
    ans[93000] = 9076870938;
    ans[93200] = 9116386300;
    ans[93400] = 9155140262;
    ans[93600] = 9195340294;
    ans[93800] = 9235700326;
    ans[94000] = 9274796000;
    ans[94200] = 9314750228;
    ans[94400] = 9355244150;
    ans[94600] = 9394599724;
    ans[94800] = 9435398584;
    ans[95000] = 9474951150;
    ans[95200] = 9515344244;
    ans[95400] = 9556298536;
    ans[95600] = 9596089242;
    ans[95800] = 9637326930;
    ans[96000] = 9677336388;
    ans[96200] = 9718168348;
    ans[96400] = 9759561468;
    ans[96600] = 9801093038;
    ans[96800] = 9841485364;
    ans[97000] = 9881951714;
    ans[97200] = 9923222540;
    ans[97400] = 9965054488;
    ans[97600] = 10007046436;
    ans[97800] = 10047873886;
    ans[98000] = 10088797128;
    ans[98200] = 10130506820;
    ans[98400] = 10172777596;
    ans[98600] = 10215208372;
    ans[98800] = 10257777590;
    ans[99000] = 10297836608;
    ans[99200] = 10337436938;
    ans[99400] = 10377719882;
    ans[99600] = 10418162826;
    ans[99800] = 10458765770;
    ans[100000] = 10496858675;
    int xx = (n / 200) * 200;
    Ans = ans[xx];
    for (int i = 1; i <= xx; i++)
    {
        int tot = 0, x = i;
        while (x)
            a[++tot] = x % 10, x /= 10;
        int now = 0;
        s[0]++;
        for (int j = tot; j; j--)
        {
            if (!nxt[now][a[j]])
                nxt[now][a[j]] = ++TT, f[TT] = now, dep[TT] = dep[now] + 1, Max = max(Max, dep[TT]);
            now = nxt[now][a[j]], s[now]++;
        }
    }
    for (int i = xx + 1; i <= n; i++)
    {
        int tot = 0, x = i;
        while (x)
            a[++tot] = x % 10, x /= 10;
        Ans += tot;
        T = 0;
        for (int j = tot - 1; j; j--)
            for (int X = 0; X <= TT; X++)
                if (Max - dep[X] >= j && s[X])
                    for (int k = tot; k >= j; k--)
                    {
                        if (ok[f[X]] == i)
                            ok[X] = i;
                        bool flg = 1;
                        int now = X;
                        if (ok[now] == i)
                            break;
                        top = 0;
                        for (int p = k; p > k - j; p--)
                            if (nxt[now][a[p]] && ok[nxt[now][a[p]]] != i && s[now])
                                now = nxt[now][a[p]], st[++top] = now;
                            else
                            {
                                flg = 0;
                                break;
                            }
                        if (!flg)
                            continue;
                        int size = s[now];
                        ok[now] = i;
                        for (int p = 1; p <= top; p++)
                            (vis[st[p]] != i) && (vis[st[p]] = i, q[++T] = st[p], ss[T] = s[st[p]], 0), s[st[p]] -= size;
                        int tmp = X;
                        while (tmp)
                            (vis[tmp] != i) && (vis[tmp] = i, q[++T] = tmp, ss[T] = s[tmp], 0), s[tmp] -= size, tmp = f[tmp];
                        Ans += 2ll * size * j;
                    }
        for (int j = 1; j <= T; j++)
            s[q[j]] = ss[j];
        int now = 0;
        s[0]++;
        for (int j = tot; j; j--)
        {
            if (!nxt[now][a[j]])
                nxt[now][a[j]] = ++TT, f[TT] = now, dep[TT] = dep[now] + 1, Max = max(Max, dep[TT]);
            now = nxt[now][a[j]], s[now]++;
        }
    }
    cout << Ans << '\n';
    return 0;
}