#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
struct process_info{
bool checked = false;
int allocated[4];
int wanted[4];
};
int main(int argc, char** argv)
{
int available[4]={7,7,7,7};
vector<process_info>vect;
process_info p1,p2,p3,p4,p5;
vect.push_back(p1);
vect.push_back(p2);
vect.push_back(p3);
vect.push_back(p4);
vect.push_back(p5);
int y=1;
for(process_info x:vect)
{
for(int i=0; i<4; i++)
{
    cout<<"Enter Allocated info for process "<<y<<" and Resource No "<< i+1 <<endl;
    cin>>x.allocated[i];
}
for(int i=0; i<4; i++)
{
cout<<"Enter Need info for process "<<y<<" and Resource No "<< i+1 <<endl;
cin>>x.wanted[i];
}
y++;
}
for(process_info x:vect)
{
    for(int i=0; i<4; i++)
    {
        cout<<x.allocated[i]<<"\t";
    }
    cout<<endl;
    for(int i=0; i<4; i++)
    {
        cout<<x.wanted[i]<<"\t";
    }
    cout<<endl;
}
int process=4;
int processexecuted=0;
for(int j=0; j<process; j++)
{
for(process_info x:vect)
{
    int z=0;
    for(int i=0; i<4; i++)
    {
        if(x.wanted[i]<=available[i]&&x.checked==false)
        {
            z++;
        }
    }
    cout<<z<<endl;
    if(z==4)
    {
        x.checked=true;
        for(int i=0; i<4; i++)
        {
            available[i]+=x.allocated[i];
        }
        processexecuted++;
        break;
    }
}
}
cout<<"process executed are "<< processexecuted<<endl;
process==processexecuted?cout<<"system is in safe state\n":cout<<"System is not in safe state\n";
}