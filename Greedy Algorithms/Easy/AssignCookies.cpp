int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());
        int i = 0, j = 0;
        int cnt = 0;
        while(i < Student.size() && j < Cookie.size()){
            if(Student[i] <= Cookie[j]){
                cnt++;
                j++;
                i++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
    TC = O(NLOGN + MLOGM + M), SC = O(1)
    N = size of student array, M = size of cookie array

    Q What if some students can share a cookie?
    
    int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());
        int i = 0, j = 0;
        int cnt = 0;
        while(j < Cookie.size()){
            int remaining = Cookie[j];
            while(i < Student.size() && Student[i] <= remaining){
                remaining -= Student[i];
                i++;
                cnt++;
            }
            if(i == Student.size()) break;
            j++;
        }
        return cnt;
    }
    TC = O(NLOGN + MLOGM + M + N), SC = O(1)