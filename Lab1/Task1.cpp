#include <bits/stdc++.h>
using namespace std;
vector<string>vs;
int vrad[1000];
string vst[1000];
int radix_num,hash_size=20;
int radix(string s)
{
    long long rad_sum=0;
    for(int i=0; i< s.length(); i++)
    {
        double rads=s[i]*pow(radix_num,i);
        rad_sum+=rads;
    }
    return rad_sum%hash_size;
}
void removeDupWord(char str[])
{
    char *token = strtok(str, " ");
    while (token != NULL)
    {
        vs.push_back(token);
        token = strtok(NULL, " ");
    }
    for(int i=0; i<vs.size(); i++)
    {
        hash_size=vs.size();
        int r=radix(vs[i]);
        cout<<r<<endl;
        vrad[r]++;
        cout<<"v[r] "<<vrad[r];
        vst[r]=vs[i];
        cout<<" vs "<<vst[r]<<endl;
    }
    for(int i=0; i<hash_size; i++)
    {
        if(vrad[i]!=0)
        {
            cout<<vst[i]<<" "<<vrad[i]<<endl;
        }

    }
}
int main()
{
    char str[] = "aba aba abc abc abd asjk asjk asfgkl";
    cout<<"Radix num ??\nrad: ";
    cin>>radix_num;
    removeDupWord(str);
    return 0;
}
