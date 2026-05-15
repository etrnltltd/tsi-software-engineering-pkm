#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
public:
    Product();
    virtual ~Product();

    Product* GetProduct(long ItemNo);

    long ProductID;
    std::string ProductDescription;
    double ProductUnitPrice;
};

#endif
