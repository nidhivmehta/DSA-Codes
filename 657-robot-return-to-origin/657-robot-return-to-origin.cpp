class Solution {
public:
    bool judgeCircle(string moves) {
        int UD = 0;
        int LR = 0;
        
        for(int i=0; i<moves.size(); i++) {
            if(moves[i] == 'U')
                UD++;
            else if(moves[i] == 'D')
                UD--;
            else if(moves[i] == 'L')
                LR++;
            else
                LR--;
        }
        if(UD==0 && LR==0)
            return true;
        return false;
    }
};