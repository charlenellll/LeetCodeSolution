class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> change;
        for(int i = 0; i < bills.size(); i++ ){
            if( bills[i] == 5 ){
                change[5]++;
                continue;
            }
            else{
                change[bills[i]]++;
                int needToReturn = bills[i]-5;
                int findChange = needToReturn;
                while( findChange > 0 ){
                    if( change.find(findChange) != change.end()){
                        while( needToReturn >= findChange && change[findChange] != 0 ) {
                            change[findChange]--;
                            needToReturn -= findChange;
                        }
                        if( change[findChange] == 0 )
                            change.erase(findChange);
                    }
                    findChange -= 5;
                }
                if( needToReturn != 0 ) return false;
            }
        }

        return true;
    }
};