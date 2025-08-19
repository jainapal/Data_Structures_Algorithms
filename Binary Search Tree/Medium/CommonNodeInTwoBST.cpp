vector<int> findCommon(Node *r1, Node *r2) {
        vector<int> ans;
        stack<Node*> s1, s2;
        
        //push all left nodes of r1 in s1
        while(r1){
            s1.push(r1);
            r1 = r1->left;
        }
        //push all left nodes of r2 in s2
        while(r2){
            s2.push(r2);
            r2 = r2->left;
        }
        
        while(!s1.empty() && !s2.empty()){
            //same elements
            if(s1.top()->data == s2.top()->data){
                ans.push_back(s1.top()->data);
                r1 = s1.top()->right;
                s1.pop();
                r2 = s2.top()->right;
                s2.pop();
                
                while(r1){
                    s1.push(r1);
                    r1 = r1->left;
                }
                while(r2){
                    s2.push(r2);
                    r2 = r2->left;
                }
            }
            //element in s1 > element in s2
            else if(s1.top()->data > s2.top()->data){
                r2 = s2.top()->right;
                s2.pop();
                while(r2){
                    s2.push(r2);
                    r2 = r2->left;
                }
            }
            else{
                r1 = s1.top()->right;
                s1.pop();
                while(r1){
                    s1.push(r1);
                    r1 = r1->left;
                }
            }
            
        }
        
        
        return ans;
    }
    TC = O(N), SC = O(H)