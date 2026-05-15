#ifndef CARTMGR_H
#define CARTMGR_H

class CartMgr
{
public:
    CartMgr();
    virtual ~CartMgr();

    bool AddItem(long ItemNo);
};

#endif
