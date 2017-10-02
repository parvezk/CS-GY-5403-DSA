class Magic
{

private:

    int *number;
    int size;
    
public:
    //  This is the constructor which is called when

    Magic();
    ~Magic();

    int getSize();
    void setSize(int newSize);
    int getNumber(int x, int y);
    void setNumber(int x, int y, int newNumber);
    void initNumber();
    //  And here comes the end of the class...
};
