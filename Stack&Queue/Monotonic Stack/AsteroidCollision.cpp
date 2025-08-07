vector<int> asteroidCollision(vector<int> &asteroids){
      int n = asteroids.size();
      vector<int> st; //list implementation of stack
      for(int i = 0; i < n; i++){
        //push right moving asteroids in stack
        if(asteroids[i] > 0) st.push_back(asteroids[i]);
        else{
            while(!st.empty() && st.back() > 0 && 
            st.back() < abs(asteroids[i])){
                st.pop_back();
            }
            if(!st.empty() && st.back() == abs(asteroids[i])){
                st.pop_back();
            }
            else if(st.empty() || st.back() < 0){
                st.push_back(asteroids[i]);
            }
        }
      }
      return st;
    }
    TC = O(2N), SC = O(N)