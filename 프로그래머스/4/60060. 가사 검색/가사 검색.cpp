    #include <string>
    #include <vector>
    #include <iostream>
    #include <algorithm>
    using namespace std;

    vector<string> for_word;
    vector<string> rev_word;
    vector<int> answer;

    bool cmp(const string &p1, const string &p2){
        if(p1.length() < p2.length())
            return true;
        else if(p1.length()==p2.length()){
            if(p1<p2)
                return true;
        }
        return false;
    }

    // int lower_bound(string text, vector<string> target_word){
    //     int start = 0, mid, end = target_word.size()-1;
    //     while(start<end){
    //         mid = (start + end)/2;
    //         if(target_word[mid]<text)
    //             start = mid+1;
    //         else
    //             end = mid;
    //     }
    //     if(target_word[end]==text)
    //         return end;
    //     return end+1;
    // }
    // int upper_bound(string text, vector<string> target_word){
    //     int start = 0, mid, end = target_word.size()-1;
    //      while(start<end){
    //         mid = (start + end)/2;
    //         if(target_word[mid]<=text)
    //             start = mid+1;
    //         else
    //             end = mid;
    //     }
    //     return end;
    // }

    int sepa_quer(string text){
        
        int start,end,index;
        if(text.at(0)=='?'){
            reverse(text.begin(),text.end());
            index = text.find('?');
            for(int i=index;i<text.length();i++) text[i] ='a';
            
            start = lower_bound(rev_word.begin(),rev_word.end(),text,cmp)-rev_word.begin();
            for(int i=index;i<text.length();i++) text[i] ='z';
            end = upper_bound(rev_word.begin(),rev_word.end(),text,cmp)-rev_word.begin();
        }else{
            index = text.find('?');
            for(int i=index;i<text.length();i++) text[i] ='a';
            start = lower_bound(for_word.begin(),for_word.end(),text,cmp)-for_word.begin();
            for(int i=index;i<text.length();i++) text[i] ='z';
            end = upper_bound(for_word.begin(),for_word.end(),text,cmp)-for_word.begin();
        }
        return end - start;
    }
    vector<int> solution(vector<string> words, vector<string> queries) {
        for_word = words;
        rev_word = words;
        sort(for_word.begin(),for_word.end(),cmp);
        for(int i=0;i<rev_word.size();i++)
            reverse(rev_word[i].begin(),rev_word[i].end());
        sort(rev_word.begin(),rev_word.end(),cmp);
        for(auto it : queries){
            answer.push_back(sepa_quer(it));
        }
        return answer;
    }