#include<bits/stdc++.h>
using namespace std;

int d,inter,s,v,bonus;

struct Intersect{
	vector<string> inroad;
	map<string,int> loadcnt;
	int totalcnt;
}intersect[100009];

struct Street{
	int b,e,l;
	string name;
}street[100009];

struct Carpath{
	int p;
	vector<string> names;
}carpath [1009];

map<string,int> name2streetidx;

int main() {
	ifstream fin;
	ofstream fout;

	fin.open("e.txt");
	fout.open("esol.txt");

	fin>>d>>inter>>s>>v>>bonus;
	for(int i=0;i<s;i++){
		int b,e,l;
		string name;
		fin>>b>>e>>name>>l;
		street[i].b=b;
		street[i].e=e;
		street[i].name=name;
		street[i].l=l;
		name2streetidx[name]=i;
		intersect[e].inroad.push_back(name);
	}
	for(int i=0;i<v;i++){
		fin>>carpath[i].p;
		long long pathtime=0;
		for(int j=0;j<carpath[i].p;j++){
			string s;
			fin>>s;
			carpath[i].names.push_back(s);
			int streetno=name2streetidx[s];
			if(j>0){
				pathtime+=street[streetno].l;
			}
		}
		//printf("%d \n",pathtime);
		if(pathtime>d){
			continue;
		}
		for(int j=0;j<carpath[i].p;j++){
			string s=carpath[i].names[j];
			if(j!=carpath[i].p){
				int streetno=name2streetidx[s];
				int intersectno=street[streetno].e;
				intersect[intersectno].loadcnt[s]++;
				intersect[intersectno].totalcnt++;
			}
		}
	}
	fin.close();

	//output
	int outputInter = 0;
	for(int i=0;i<inter;i++){
		if(!intersect[i].loadcnt.empty()) outputInter++;
	}
	fout<<outputInter<<endl;
	for(int i=0;i<inter;i++){
		auto loadcnt = intersect[i].loadcnt;
		if(!loadcnt.empty()){
			double avgcnt = intersect[i].totalcnt *1.0 / loadcnt.size();
			fout<<i<<endl;
			int inroadsi=loadcnt.size();
			fout<<inroadsi<<endl;
			//rand output
			vector<pair<string,int> > light;
			int basecnt = avgcnt;
			int totalcnt2 = 0;
			double avgcnt2 = 0;

			for(auto it=loadcnt.begin(); it!=loadcnt.end();++it){
				totalcnt2+=min(basecnt,it->second);
			}
			avgcnt2 = totalcnt2*1.0/loadcnt.size();

			for(auto it=loadcnt.begin(); it!=loadcnt.end();++it){
				double r = it->second / avgcnt2;
				if(r<1) r=1;
				int period = (int) min(r,10.0);
				light.push_back({it->first,r});
			}
			srand(time(0));
			random_shuffle(light.begin(),light.end());
			for(auto l:light){
				fout<<l.first<<" "<<l.second<<endl;
			}
		}
	}
	fout.close();
	return 0;
}
