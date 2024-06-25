#pragma once
#ifndef CONFIGLOADER_H_INCLUDED
#define CONFIGLOADER_H_INCLUDED

#include <string>
#include "../Config.h"

Config loadConfig(std::string filename);

#endif