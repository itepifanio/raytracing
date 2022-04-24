#include "../include/api.h"

Api &Api::Instance()
{
    static Api s;
    return s;
}

Api::Api()
{
}

Api::~Api()
{
}
