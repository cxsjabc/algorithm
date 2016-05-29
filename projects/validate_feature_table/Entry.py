#!/usr/bin/python

import ConfigParser

config = ConfigParser.ConfigParser()

config.read("ProjectConfig.mk");
print config.get("main", "MTK_MAIN_SENSOR");



