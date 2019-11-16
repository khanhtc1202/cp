#include<iostream>
int main(){
  std::string S;
  std::cin>>S;
  int r=S.length();
  while(r!=0){
    if(S[r-1]=='r'){
      if(r>=7 && S.substr(r-7,7)=="dreamer") r-=7;
      else if(r>=6 && S.substr(r-6,6)=="eraser") r-=6;
      else{std::cout<<"NO";return 0;}
    }else{
      if(r>=5 && S.substr(r-5,5)=="dream") r-=5;
      else if(r>=5 && S.substr(r-5,5)=="erase") r-=5;
      else{std::cout<<"NO";return 0;}
    }
  }
  std::cout<<"YES";
}

