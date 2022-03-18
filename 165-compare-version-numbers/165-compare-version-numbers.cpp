class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        
	vector<string>v1, v2;
        int last=0;
        string temp="";
        for(int i=0;i<ver1.length();i++){
            if(ver1[i]=='.'){
                v1.push_back(temp);
                temp="";
            }else{
                temp+=ver1[i];
            }
        }
        if(temp!=""){
            v1.push_back(temp);
        }
        temp="";
        for(int i=0;i<ver2.length();i++){
            if(ver2[i]=='.'){
                v2.push_back(temp);
                temp="";
            }else{
                temp+=ver2[i];
            }
        }
        if(temp!=""){
            v2.push_back(temp);
        }
        int maxlen=max(v1.size(), v2.size());
        for(int i=0;i<maxlen;i++){
        	int a=i<v1.size()?stoi(v1[i]):0;
        	int b=i<v2.size()?stoi(v2[i]):0;
            
        	if(a>b){
        		return 1;
        	}else if(b>a)
        		return -1;
        }
        return 0;
    }
};