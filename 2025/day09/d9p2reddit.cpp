#include <bits/stdc++.h>

using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define fl(i, n) for (int i = 0; i < n; i++)
#define int long long
#define ll long long
#define in(n)    \
    long long n; \
    cin >> n;
#define pb push_back
#define eb emplace_back
#define pp pop
unsigned long long M = 1000000007;
class edge{
    public:
    pair<int,int> u;
    pair<int,int> v;
    edge(pair<int,int> u,pair<int,int> v){
        this->u=u;
        this->v=v;
    }
    bool isvertical(){
        return u.first==v.first;
    }
};
void solve()
{
    // your code goes here
    ifstream file("input");
    if(!file){
        cerr << "Could not open file!\n";
        return ;
    }

    int ans = 0;
    vector<vector<int>> pts; 
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue; 
        stringstream ss(line);
        int x,y;
        char comma;
        
        // Reads: int -> char(,) -> int
        if (ss >> x >> comma >> y) {
            pts.push_back({x, y});
        }
    }
    vector<edge>edges;
    int n=pts.size();
    for(int i=0;i<n;i++){
        int nex=(i+1)%n;
        edges.push_back(edge({pts[i][0],pts[i][1]},{pts[nex][0],pts[nex][1]}));
    }
    int maxi=INT_MIN;

    /*for(auto &e:edges){
        cout<<e.u.first<<" "<<e.u.second<<" "<<e.v.first<<" "<<e.v.second<<" "<<endl;
    }
    cout<<endl<<endl;*/

    for(int i=0;i<pts.size();i++){
        for(int j=i+1;j<pts.size();j++){
            int x1=min(pts[i][0],pts[j][0]);
            int x2=max(pts[i][0],pts[j][0]);
            int y1=min(pts[i][1],pts[j][1]);
            int y2=max(pts[i][1],pts[j][1]);
            //cout<<"gledamo "<<pts[i][0]<<" "<<pts[i][1]<<" "<<pts[j][0]<<" "<<pts[j][1]<<" "<<endl;

            int area=(x2 - x1 + 1) * (y2 - y1 + 1);
            if(area<=maxi) continue;
            bool valid=true;

            


            for(auto &e:edges){
                //cout<<"edge "<<e.u.first<<" "<<e.u.second<<"   "<<e.v.first<<" "<<e.v.second<<endl;
                if(e.isvertical()){
                    int ex=e.u.first;
                    //cout<<"vertical"<<endl;
                    //cout<<ex<<" > "<<x1<<" && "<< ex<<" < "<<x2<<endl;
                    if(ex>x1 && ex<x2){
                        int Ymin = min(e.u.second, e.v.second);
                        int Ymax = max(e.u.second, e.v.second);
                        //cout<<max(y1, Ymin)<<" < "<<min(y2, Ymax)<<endl;
                        if (max(y1, Ymin) < min(y2, Ymax)) {
                            valid = false; 
                            break;
                        }
                    }
                }else{
                    int ey=e.u.second;
                    //cout<<"horizontal"<<endl;
                    //cout<<ey<<" > "<<y1<<" && "<< ey<<" < "<<y2<<endl;
                    if(ey>y1 && ey<y2){
                        int Xmin = min(e.u.first, e.v.first);
                        int Xmax = max(e.u.first, e.v.first);
                        //cout<<max(x1, Xmin)<<" < "<<min(x2, Xmax)<<endl;
                        if (max(x1, Xmin) < min(x2, Xmax)) {
                            valid = false; 
                            break;
                        }
                    }
                }
            }
            if(!valid) continue;
            maxi=max(maxi,area);
            //cout<<"new max"<<maxi<<endl;
        }
    }
    cout<<maxi<<endl;
    
    
    
}

signed main()
{
    fastio int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}