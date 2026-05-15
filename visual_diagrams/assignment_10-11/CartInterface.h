#ifndef CARTINTERFACE_H
#define CARTINTERFACE_H

class CartInterface
{
public:
    CartInterface();
    virtual ~CartInterface();

    bool AddItem(long ItemNo);
};

#endif
