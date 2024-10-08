#pragma once
#include <iostream>
#include "clsUser.h";

clsUser CurrentUser = clsUser::Find("",""); //will return empty object if user not found (empty mode)
