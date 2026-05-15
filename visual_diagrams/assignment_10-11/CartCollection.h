#ifndef CARTCOLLECTION_H
#define CARTCOLLECTION_H

class Product;

class CartCollection
{
public:
    CartCollection();
    virtual ~CartCollection();

    bool AddItem(Product* NewItem);
};

#endif
