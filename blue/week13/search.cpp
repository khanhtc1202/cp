#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;
#define ll long long 

class trie{
    public:
    trie *node[26] ;
    
    ll weight ;
    bool endofword;
};


class trie* newnode()
{
    trie *root=new trie;
    for(int i=0;i<26;i++)
    {
        root->node[i]= NULL;
    }
    root->weight=-1;
    root->endofword=false;
    return root;
    
}

void insert( trie *root,string s,ll p)
{
    trie*temp=root;
    
    for(ll i=0;i<s.length();i++)
    {
        if(!temp->node[s[i]-'a'])
        {
            temp->node[s[i]-'a']=newnode();
        }
        temp=temp->node[s[i]-'a'];
        if(temp->weight<p)
        {
            temp->weight = p;
        }
    }
    temp->endofword=true;
}

ll funcans(trie *root,string s)
{
    trie *temp=root;
    
    for(ll i=0;i<s.length();i++)
    {
        if(!temp->node[s[i]-'a'])
        {
            return -1;
        }
        temp=temp->node[s[i]-'a'];
    }
    return temp->weight;
}

int main()
{
    ll n,q;
    cin>>n>>q;
    trie *root=newnode();
   //inserting the pair
    for(ll i=0;i<n;i++)
    {
        ll p;
        string s;
        cin>>s>>p;
        insert(root,s,p);
    }
    //searching for ans;
    for(ll i=0;i<q;i++)
    {
        string s;
        cin>>s;
        cout<<funcans(root,s)<<endl;
    }
    return 0;
}
