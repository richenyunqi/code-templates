void getNext(string pattern,LL*next){
    LL j=-1;
    next[0]=-1;
    for(LL i=1;i<pattern.size();++i){
        while(j!=-1&&pattern[i]!=pattern[j+1])
            j=next[j];
        if(pattern[i]==pattern[j+1])
            ++j;
        next[i]=j;
    }
}
bool KMP(string text,string pattern){
    LL next[pattern.size()];
    getNextval(pattern,next);
    for(LL i:next)
        prLLf("%d ",i);
    LL j=-1;
    for(LL i=0;i<text.size();++i){
        while(j!=-1&&text[i]!=pattern[j+1])
            j=next[j];
        if(text[i]==pattern[j+1])
            ++j;
        if(j==pattern.size()-1)
            return true;
    }
    return false;
}
void getNextval(string pattern,LL*next){
    LL j=-1;
    next[0]=-1;
    for(LL i=1;i<pattern.size();++i){
        if(j!=-1&&pattern[i]!=pattern[j+1])
            j=next[j];
        if(pattern[i]==pattern[j+1])
            ++j;
        if(j==-1||pattern[i+1]!=pattern[j+1])
            next[i]=j;
        else
            next[i]=next[j];
    }
}
LL KMPcount(string text,string pattern){
    LL next[pattern.size()];
    getNextval(pattern,next);
    for(LL i:next)
        prLLf("%d ",i);
    LL j=-1,result=0;
    for(LL i=0;i<text.size();++i){
        while(j!=-1&&text[i]!=pattern[j+1])
            j=next[j];
        if(text[i]==pattern[j+1])
            ++j;
        if(j==pattern.size()-1){
            ++result;
            j=next[j];
        }
    }
    return result;
}
