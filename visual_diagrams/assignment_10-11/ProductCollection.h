#ifndef PRODUCTCOLLECTION_H
#define PRODUCTCOLLECTION_H

class Product;

class ProductCollection
{
public:
    ProductCollection();
    virtual ~ProductCollection();

    Product* FindProduct(long ItemNo);
};

#endif
