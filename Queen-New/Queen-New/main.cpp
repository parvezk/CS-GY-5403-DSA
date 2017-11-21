#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void queen();
void clearmatrix(vector<vector<int> >& printmatrix, int N);
bool isrotate(vector<vector<int> > printmatrix,
              vector<vector<vector<int> > > res, int N);
void printsolution(int Count, vector<vector<int> > printmaxtrix, int N);
void createNode(int value);
void insert(int value);
void deleteLast();

struct node {
    int data;
    node *next;
};

class list {
private:
    node *head, *tail;
public:
    list() {
        head=NULL;
        tail=NULL;
    }
    createNode(value) {
        return createNode(value);
    }
};

int main(int argc, const char* argv[])
{
    queen();
    system("pause");
    return 0;
}

node* head = NULL;
node* tail = NULL;

void createNode(int value) {
    
    node *temp=new node;
    
    temp->data=value;
    temp->next=NULL;
    if (head==NULL) {
        head=temp;
        tail=temp;
        temp=NULL;
    } else {
        tail->next=temp;
        tail=temp;
    }
}

void insert(int value) {
    node *temp=new node;
    temp->data = value;
    temp->next=head;
    head=temp;
}

void insert_position(int pos, int value) {
    node *pre=new node;
    node *cur=new node;
    node *temp=new node;
    cur=head;
    for(int i=1;i<pos;i++)
    {
        pre=cur;
        cur=cur->next;
    }
    temp->data=value;
    pre->next=temp;
    temp->next=cur;
}

void delete_position(int pos) {
    node *current=new node;
    node *previous=new node;
    current=head;
    for(int i=1;i<pos;i++)
    {
        previous=current;
        current=current->next;
    }
    previous->next=current->next;
}

void deleteLast() {
    node *current=new node;
    node *previous=new node;
    current=head;
    while(current->next!=NULL) {
        previous=current;
        current=current->next;
    }
    
    tail=previous;
    previous->next=NULL;
    delete current;
}

void replace(int pos, int value) {
    delete_position(pos);
    insert_position(pos, value);
}

int data_at_position(int pos) {
    node *temp=new node;
    temp=head;
    for (int i = 0; i < pos; i++)
    {
        temp=temp->next;
    }
    return temp->data;
}

void queen()
{
    
    int N;
    cout << "please input the number of queens: ";
    cin >> N;
    cout << endl;
    int Count = 0; //count the number of solution
    list column; //column[m]=n represent the mth column，nth row placed queen;
    
    list row; //row[m]=1 represent the mth row doesn't have queen
    
    list b; //b[m]=1 represent the mth minor diagonal doesn't have queen(right*up to left*down)
    
    list c; //c[m]=1 represent the mth main diagonal doesn't have queen(left*up to right*down)
    
    int numQueen = 1; //count the number of queens placed， numQueen=N represent complete
    
    int good
    = 1; //good=1 represent no conflict
    
    vector<vector<vector<int> > > res; //store all results
    vector<vector<int> > printmatrix; //store the current result
    list m;
    
    for (int i = 0; i < N + 1; i++)
        column.createNode(0);
    for (int i = 0; i < N + 1; i++)
        m.createNode(0);
    for (int i = 0; i < N + 1; i++)
        printmatrix.push_back(m);
    for (int j = 0; j < N + 1; ++j)
        row.createNode(1);
    for (int j = 0; j < 2 * N + 1; ++j) {
        b.createNode(1);
        c.createNode(1);
    }
    
    column->head = 1; //initially, place queen at 1st row, 1st col.
    
    do {
        if (good) {
            if (numQueen == N) //judge this solution is complete?
            {
                for (int j = 1; j < N + 1; j++) {
                    printmatrix[column[j]][j] = 1;
                }
                
                if (!isrotate(printmatrix, res, N))
                    //judge is this solution is rotate from previous solution
                {
                    res.push_back(printmatrix);
                    Count++;
                    printsolution(Count, printmatrix, N);
                }
                
                clearmatrix(printmatrix, N);
                
                while (column[numQueen] == N) {
                    numQueen--; //backtracking
                    row.replace(N, 1); //change state
                    b.replace(numQueen + N, 1);
                    c.replace(numQueen, 1);
                }
                
                N++; //go to next row.
            }
            else {
                //change this place's state
                row.insert_position(column[numQueen]) = 0;
                b[numQueen + column[numQueen]] = 0;
                c[N + numQueen - column[numQueen]] = 0;
                
                //if this time there is no conflict and not complete. we place the next queen at the first row of next col.
                column[++numQueen] = 1;
            }
            
            //if there is a conflict
        }
        else {
            
            while (column[numQueen] == N) //if the queen placed in the last row of this col, backtracking to previous col.!
            {
                numQueen--;
                row[column[numQueen]] = 1;
                b[numQueen + column[numQueen]] = 1;
                c[N + numQueen - column[numQueen]] = 1;
            }
            column[numQueen]++;
            //if the queen is not
            // placed the last row of this col,just move to next row;
        }
        
        good = row[column[numQueen]] & b[numQueen + column[numQueen]] & c[N + numQueen - column[numQueen]];
        
    } while (numQueen);
    cout << N << " "
    << "queen problem find totally: ";
    cout << Count << " "
    << "unique solutions" << endl;
}

bool isrotate(vector<vector<int> > printmatrix,
              vector<vector<vector<int> > > res, int N)
{
    if (res.size() == 0)
        return false;
    
    //checking for left and right symmetry!
    for (int i = 0; i < res.size(); i++) {
        for (int rowt = 1; rowt < N + 1; rowt++) {
            for (int colt = 1; colt < N + 1; colt++) {
                if (printmatrix[rowt][colt] != res[i][N - rowt + 1][colt])
                    goto test1;
            }
        }
        return true;
    test1:;
    }
    
    //checking for up and down symmetry!
    for (int i = 0; i < res.size(); i++) {
        for (int rowt = 1; rowt < N + 1; rowt++) {
            for (int colt = 1; colt < N + 1; colt++) {
                if (printmatrix[rowt][colt] != res[i][rowt][N - colt + 1])
                    goto test2;
            }
        }
        return true;
    test2:;
    }
    
    //checking for main diagonal symmetry!
    for (int i = 0; i < res.size(); i++) {
        for (int rowt = 1; rowt < N + 1; rowt++) {
            for (int colt = 1; colt < N + 1; colt++) {
                if (printmatrix[rowt][colt] != res[i][colt][rowt])
                    goto test3;
            }
        }
        return true;
    test3:;
    }
    
    //checking for minor diagonal symmetry!
    for (int i = 0; i < res.size(); i++) {
        for (int rowt = 1; rowt < N + 1; rowt++) {
            for (int colt = 1; colt < N + 1; colt++) {
                if (printmatrix[rowt][colt] != res[i][N - colt + 1][N - rowt + 1])
                    goto test4;
            }
        }
        return true;
    test4:;
    }
    
    //checking for the solution is equal to the Rotated 90 degrees counterclockwise from the previous solution
    for (int i = 0; i < res.size(); i++) {
        for (int rowt = 1; rowt < N + 1; rowt++) {
            for (int colt = 1; colt < N + 1; colt++) {
                if (printmatrix[rowt][colt] != res[i][colt][N - rowt + 1])
                    goto test5;
            }
        }
        return true;
    test5:;
    }
    
    //checking for the solution is equal to the Rotated 90 degrees clockwise from the previous solution!
    for (int i = 0; i < res.size(); i++) {
        for (int rowt = 1; rowt < N + 1; rowt++) {
            for (int colt = 1; colt < N + 1; colt++) {
                if (printmatrix[rowt][colt] != res[i][N - colt + 1][rowt])
                    goto test6;
            }
        }
        return true;
    test6:;
    }
    
    //checking for the solution is equal to the Rotated 180 degrees clockwise from the previous solution!
    for (int i = 0; i < res.size(); i++) {
        for (int rowt = 1; rowt < N + 1; rowt++) {
            for (int colt = 1; colt < N + 1; colt++) {
                if (printmatrix[rowt][colt] != res[i][N - rowt + 1][N - colt + 1])
                    goto test7;
            }
        }
        return true;
    test7:;
    }
    return false;
}

void clearmatrix(vector<vector<int> >& printmatrix, int N)
{
    for (int i = 1; i < N + 1; i++)
        //clear the printmatrix for next solution!
    {
        for (int j = 1; j < N + 1; j++) {
            printmatrix[i][j] = 0;
        }
    }
}

void printsolution(int Count, vector<vector<int> > printmatrix, int N)
{
    cout << "find solution!!!"
    << " " << Count << endl;
    
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (printmatrix[i][j] == 1)
                cout << "Q"
                << " ";
            else
                cout << "#"
                << " ";
        }
        cout << endl;
    }
    cout << endl;
}
