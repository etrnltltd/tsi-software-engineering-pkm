#ifndef PRODUCTMGR_H
#define PRODUCTMGR_H

class Product;

class ProductMgr
{
public:
    ProductMgr();
    virtual ~ProductMgr();

    Product* GetProduct(long ItemNo);
};

#endif
