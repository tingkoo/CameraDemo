#ifndef DEMODATA_H
#define DEMODATA_H

typedef char TCHAR;

typedef struct _tagResolution
{
    TCHAR * lpszDesc;
    int	width;
    int	height;
}TagResolution;


typedef enum
{
    idResolution,
    idContrast,
    idExposure,
    idGain_All,
    idGain_R,
    idGain_G,
    idGain_B,
    idOffsetX,
    idOffsetY,
    idControl,
    idImageType,
    idFlipMode,
    idColorMode,
    idSharp
}ENUM_Param;

typedef enum
{
    IMG_TYPE_BMP,
    IMG_TYPE_JPG,
    IMG_TYPE_PNG,
    IMG_TYPE_TIF
}ENUM_IMAGE_TYPE;

#endif // DEMODATA_H
