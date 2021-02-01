#include <iostream>
using namespace std;

int setJ();
int setI();

class Grid {
    private:
        char grid[9];
        int grid2[9];
        int winning;
    public:
        Grid();
        void showGrid() const;
        void setCross(int i,int j) {grid[i*3+j]='X'; grid2[i*3+j]=1;};
        void setCircle(int i,int j) {grid[i*3+j]='O';grid2[i*3+j]=1;};
        int updateWin();
        int getWinning() const {return(winning);}
        int isTicked(int i,int j) const;
        int draw() const;
};

Grid :: Grid() {
    winning=0;
    for(int i=0;i<9;i++){
        grid[i]=' ';
        grid2[i]=0;
    }
}

int Grid :: isTicked(int i, int j) const {
    if(i<0 && i>2) {
        return 1;
    }
    if(j<0 && j>2) {
        return 1;
    }
    return grid2[i*3+j];
}

int Grid :: draw()const {
    for(int i=0;i<9;i++){
        if(grid2[i]==0){
            return 0;
        }
    }
    return 1;

}




void Grid :: showGrid() const {
    cout << "\n";
    cout << " " << grid[0] << " | " << grid[1] << " | " << grid[2] <<" \n";
    cout << "-----------\n";
    cout << " " << grid[3] << " | " << grid[4] << " | " << grid[5] <<" \n";
    cout << "-----------\n";
    cout << " " << grid[6] << " | " << grid[7] << " | " << grid[8] <<" \n";
    cout << "\n";
}



int Grid :: updateWin() {
    for(int i=0; i<3;i++) {
        if(grid[i]!=' ' && grid[i]==grid[i+1] && grid[i+1]==grid[i+2]) {
            winning=1;
            cout << grid[i+1];
            return(0);
        }
    }
    
    for(int i=0;i<3;i++) {
        if(grid[i]!=' ' && grid[i]==grid[i+3] && grid[i+3]==grid[i+6]) {
            winning=1;
            return(0);
        }
    }
    if(grid[0] !=' ' && grid[0]==grid[4] && grid[4]==grid[8]) {
        winning=1;
        return(0);
    }
    if(grid[2] !=' ' && grid[2]==grid[4] && grid[4]==grid[6]) {
        winning=1;
        return(0);
    }
    winning=0;
    return(0);
}


int main() {
    int player = 0; //0 cross to play / 1 circle to play
    Grid g = Grid();
    g.showGrid();
    while(g.getWinning()==0){
        int i = -1;
        int j=-1;
        if(player) {
            cout << "Circle to play \n";
            i = setI();
            j = setJ();
            while(g.isTicked(i-1,j-1)){
                g.showGrid();
                cout << "Please choose another box!\n";
                cout << "Circle to play \n";
                i = setI();
                j = setJ();
            }
            g.setCircle(i-1,j-1);
        } else {
            cout << "Cross to play\n";
            i = setI();
            j = setJ();
            while(g.isTicked(i-1,j-1)){
                g.showGrid();
                cout << "Please choose another box!\n";
                cout << "Circle to play \n";
                i = setI();
                j = setJ();
            }
            g.setCross(i-1,j-1);
        }
        g.showGrid();
        g.updateWin();
        if(g.getWinning()) {
            if(player){
                cout << "Circle wins\n";
            } else {
                cout << "Cross wins\n";
            }
        }
        if(g.draw()){
            cout << "Draw\n";
            break;
        }
        player = !player;
    }
    return 0;
}



int setI() {
    int i;
    cout << "Choose the line :";
    cin >> i;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Line must be 1, 2 or 3. \n";
        i= setI();
    } else {
        return i;
    }
};

int setJ() {
    int j;
    cout << "Choose the column :";
    cin >> j;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Column must be 1, 2 or 3. \n";
        j= setJ();
    } else {
        return j;
    }
};