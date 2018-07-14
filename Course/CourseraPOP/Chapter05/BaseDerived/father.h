#pragma once

class Father
{
public:
    Father();
    ~Father();
    int nPublic;
private:
    int nPrivate;
protected:
    int nProtected;
};

Father::Father()
{}

Father::~Father()
{}