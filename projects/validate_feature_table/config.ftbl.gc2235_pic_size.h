#if 1
    //  Picture Size (Both width & height must be 16-aligned)
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_PICTURE_SIZE), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_("2560x1920"), 
            ITEM_AS_VALUES_(
                "320x240",      "640x480",      "1024x768",     "1280x720",     "1280x768",     "1280x960", 
                "1600x1200",    "2048x1536",    "2560x1440",    "2560x1920",    "3264x2448",    "3328x1872", 
                "2880x1728",    "3600x2160", 
            )
        ), 
    )
#endif