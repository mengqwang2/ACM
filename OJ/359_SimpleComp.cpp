/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 11488
 * Submitted at:  2015-01-28 15:06:05
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    359
 * Problem Name:  Simple Computers (CO assignment?)
 */

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int bin2dec(int a)
{
    return a/10000000%10*128+a/1000000%10*64+a/100000%10*32+a/10000%10*16+a/1000%10*8+a/100%10*4+a/10%10*2+a/1%10;
}

int arr[8]={0};

int dec2bin(int a)
{
    
    for(int i=0;i<8;i++)
    {
        arr[i]=0;
    }
    int i=0;
    while (a!=0)
    {
        arr[i]=a%2;
        a=a/2;
        i++; 
    }
    
    return arr[7]*10000000+arr[6]*1000000+arr[5]*100000+arr[4]*10000+arr[3]*1000+arr[2]*100+arr[1]*10+arr[0];
    
}
int main()
{
    int data[32]={0};
    vector<int> v;
	while (cin >> data[0])
	{
        for(int i=1;i<32;i++)
        {
            cin >> data[i];
        }
        int cur_data=data[0];
        int pc=0;
        int accu=0;
        int ins=cur_data/100000;
        int mry=cur_data%100000;
        while (ins!=111)
        {
            pc++;
            pc%=32;
            switch(ins)
            {
                case 0:data[bin2dec(mry)]=dec2bin(accu);break;
                case 1:accu=bin2dec(data[bin2dec(mry)]);break;
                case 10:if(accu==0) pc=bin2dec(mry);break;
                case 11:break;
                case 100:accu--;if(accu<0)accu=255;break;
                case 101:accu++;if(accu==256)accu=0;break;
                case 110:pc=bin2dec(mry);break;
                case 111:break;
            }
            cur_data=data[pc];
            ins=cur_data/100000;
            mry=cur_data%100000;
        }
        
        v.push_back(accu);
        
	}
    vector<int>::iterator iter;
    for(iter=v.begin();iter!=v.end();iter++)
    {
        int opt=*iter;
        int result=dec2bin(opt);
        for (int k=7;k>=0;k--)
        {
            cout << arr[k];
        }
        cout << endl;
    }
    
	return 0;
}