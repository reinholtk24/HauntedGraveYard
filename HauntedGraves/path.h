#ifndef PATH_H
#define PATH_H


class path
{
    public:
        path(int x, int y, int weight);
        int getFromX();
        int getFromY();
        int getTotalWeight();
        void setTotalWeight(int weight);
        virtual ~path();

    private:
        int fromX;
        int fromY;
        int totalWeight;
};

#endif // PATH_H
