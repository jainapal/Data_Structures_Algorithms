int totalFruits(vector<int>& fruits){
        int n = fruits.size();
        int maxcnt = 0;

        for(int i = 0; i < n; i++){
          int basket1 = 0, basket2 = 0;
          int type1 = fruits[i], type2 = -1;
          for(int j = i; j < n; j++){
            if(fruits[j] == type1){
              basket1++;
            }
            else if(type2 == -1 || fruits[j] == type2){
              basket2++;
              if(type2 == -1)type2 = fruits[j];
            }
            else{
              break;
            }
          }
          maxcnt = max(maxcnt, basket1 + basket2);
        }
        return maxcnt;
    }
    TC = O(N^2), SC =O(1)
----------------------------------------------------------------------------------
int totalFruits(vector<int>& fruits){
        int n = fruits.size();
        int maxcnt = 0;
        int l = 0, r = 0;
        unordered_map<int, int> mp;

        while(r < n && l <= r){
          mp[fruits[r]]++ ;
          while(mp.size() > 2){
            mp[fruits[l]]-- ;
            if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
            l++;
          }

          maxcnt = max(maxcnt , r - l + 1);
          r++;
        }
        return maxcnt;
    }
    TC = O (2N), SC = O(3)
---------------------------------------------------------------------------------------
int totalFruits(vector<int>& fruits){
        int n = fruits.size();
        int maxcnt = 0;
        int l = 0, r = 0;
        unordered_map<int, int> mp;

        while(r < n && l <= r){
          mp[fruits[r]]++ ;
          if(mp.size() > 2){
            mp[fruits[l]]-- ;
            if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
            l++;
          }

          maxcnt = max(maxcnt , r - l + 1);
          r++;
        }
        return maxcnt;
    }
    TC = O(N), SC = O(3)