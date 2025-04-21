#ifndef oval_H
#define oval_H

class Oval {
    int width, height;

public:
    Oval();
    Oval(int w, int h);
    ~Oval();
    int getWidth();
    int getHeight();
    void set(int w, int h);
    void show();
};

#endif
