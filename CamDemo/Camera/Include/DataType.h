
// datatype.h

#ifndef DATATYPE_H
#define DATATYPE_H

#include <windows.h>
/*===========================================================*\
	AE/AWB�ص�����	dw1			����AE/AWB֮��Ĳ���, 
					dw2			����AE/AWB֮��Ĳ���, 
					lpContext	������֡�ص�����ʱ���ݵ�������

2011-04-12 �ûص�������ʽ�������豸�Ƴ��������Ϣ�Ļص�
dw1 ��ʾ�豸������Ƴ�  0���Ƴ�;1������
dw2 ��ʾ�豸�ľ��,ǿ��ת��
\*=========================================================//*/
typedef VOID (WINAPI *DL_AUTOCALLBACK )( DWORD dw1, DWORD dw2, LPVOID lpContext );

/*===========================================================*\
	֡�ص�����	lpParamָ��֡���ݵ�ָ��, 
				lpPoint ����, 
				lpContext������֡�ص�����ʱ���ݵ�������
\*=========================================================//*/
typedef VOID (WINAPI *DL_FRAMECALLBACK)( LPVOID lpParam1, LPVOID lpPoint, LPVOID lpContext );

/*-------------------------------------------------------------
	����ֵ����
  *===========================================================*/
#define		ResSuccess					0x0000		// ���سɹ�
#define		ResNullHandleErr			0x0001		// ��Ч���
#define		ResNullPointerErr			0x0002		// ָ��Ϊ��
#define		ResFileOpenErr				0x0003		// �ļ�����/��ʧ��
#define		ResNoDeviceErr				0x0004		// û�п����豸
#define		ResInvalidParameterErr		0x0005		// �ڴ���䲻��
#define		ResOutOfMemoryErr			0x0006		// û�п���Ԥ��
#define		ResNoPreviewRunningErr		0x0007		// Ԥ��û�п���
#define		ResOSVersionErr				0x0008
#define		ResUsbNotAvailableErr		0x0009
#define		ResNotSupportedErr			0x000a
#define		ResNoSerialString			0x000b
#define		ResVerificationErr			0x000c
#define		ResTimeoutErr	            0x000d
#define		ResScaleModeErr				0x000f
#define		ResUnknownErr				0x00ff

#define		ResDisplayWndExist			0x0011		// Ӧ�ùر�Ԥ������
#define		ResAllocated				0x0012		// �ڴ��Ѿ�����
#define		ResAllocateFail				0x0013		// �ڴ����ʧ��
#define		ResReadError				0x0014      // USB��ȡʧ��
#define		ResWriteError				0x0015		// USB�����ʧ��
#define		ResUsbOpen					0x0016      // USB�˿��Ѿ���
#define     ResCreateStreamErr			0x0017		// ����avi��ʧ��
#define     ResSetStreamFormatErr		0x0018		// ����AVI����ʽʧ��
#define		ResGetDCErr					0x0019		// ���ھ������ȷ
#define		ResGetFrameErr				0x0020		// ��ȡͼƬ����ȷ


typedef struct _tagDLVIDEORECT
{
    int     Left;		// ����ڸ����ڵ�ˮƽƫ��
    int     Top;		// ����ڸ����ڵĴ�ֱƫ��
    int     Width;		// ��Ƶ���ڿ��
    int     Height;		// ��Ƶ���ڸ߶�
}DLVIDEORECT, *PDLVIDEORECT;

/*-------------------------------------------------------------
    ����ͷ��ز����ṹ
  *===========================================================*/
struct CapInfoStruct
{
    UCHAR	*Buffer;		// �û����䣬���ڷ���8bitԭʼ����
    ULONG	Height;			// �ɼ��߶�
    ULONG	Width;			// �ɼ����
    ULONG	OffsetX;		// ˮƽƫ��,	CCD�������
    ULONG	OffsetY;		// ��ֱƫ��,	CCD�������
    ULONG	Exposure;		// �ع�ֵ 1-500MS
    UCHAR	Gain[3];		// Gain[0]�������� 1-63. Gain[1],Gain[2]����
    UCHAR	Control;		// ����λ
    UCHAR	InternalUse;	// �û���Ҫ�Դ��ֽڽ��в���
    UCHAR	ColorOff[3];	// �û������治Ҫ�ı�������ֵ
    USHORT  nMaxAeExp;
    USHORT  nSharpen;
    UCHAR	Reserved[1];	// ����λ
};

/*-------------------------------------------------------------
    AF������ز����ṹ
byAfState:   �������״̬˵��
  0��   ��Ч״̬  ����ǰ�����Զ��Խ�״̬ʱ�����͸�ֵǿ�ƽ����Զ��Խ�������
     1��   ɨ��״̬  ������״̬���û���Ҫָ��ɨ����ʼλ�ã�ɨ�����λ�ü�ɨ��Ĳ���ֵ
           ɨ��״̬�������£�
           ��1�� ���Ƶ����ת���û�ָ������ʼλ�ô�
           ��2�� ����ʼλ�ô��������û�ָ���Ĳ���ֵ�����Ƶ��������ֱ��ɨ�����λ�ô��� ��״̬�£�֡�ʽ���СΪʵ��֡�ʵ�����֮һ
           ��3�� ������λ�ú󣬿��Ƶ�����˵�ɨ���������������λ�ô���
     2��   ����״̬ ��״̬���Ƶ�������û�ָ���ķ���Ͳ���ת�����һ��
     4��   ��λ�ƶ�״̬  �ƶ������ָ����λ�ô� ��Ч��Χ0~750��ÿһ����Ӧ����0.02mm
     8��   ����һ���Զ��Խ�������
     16:   �����Զ��Խ�����
     ����������

 byAfDirection:		���ڲ���״̬����Ч�����Ƶ���ڲ���״̬�µ�ת������
 usAfScanStartLoc:  ����ɨ�����״̬����Ч������ɨ���������ʼλ��
 usAfScanEndLoc:    ɨ������£�����ɨ������Ľ���λ��
                    ��λ�ƶ�״̬�£����ö�λ����Ŀ��λ��
 byAfScanStep:      ɨ��״̬�򲽽�״̬�£�����ɨ������Ĳ�������  ��Ч��Χ[1��31]
                    ����״̬�£��ò�����Ч����ϵͳ��������ٶ��������ת����
  *===========================================================*/
typedef struct AutoFocusParam_St
{
    UCHAR    byAfState;			//
    UCHAR    byAfDirection;
    USHORT   usAfScanStartLoc;
    USHORT   usAfScanEndLoc;
    UCHAR    byAfScanStep;
    UCHAR 	 Reserved[4];
}*P_AUTOFOCUS_ST;//*/



/*-------------------------------------------------------------
    AF���ܶԽ���������
  *===========================================================*/
typedef struct AutoFocusRange_St
{
    USHORT   usAfRangeHS;	//�Խ�����ˮƽ��ʼ��
    USHORT   usAfRangeHL;	//�Խ�����ˮƽ�����ϵķ�Χ��С
    USHORT   usAfRangeVS;	//�Խ�����ֱ��ʼ��
    USHORT   usAfRangeVL;	//�Խ�����ֱ�����ϵķ�Χ��С
    UCHAR 	 Reserved[4];
}*P_AUTOFOCUS_RANGE_ST;//*/

//CapInfoStruct m_tCamerParam;
/*-----------------------------------------------------------
    Control ����λ˵��
    BIT7       BIT6      BIT5     BIT4     BIT3     BIT2     BIT1     BIT0
    �û�IO	����Դʹ��								HDR    	 ����	  �ü�/����
    0�͵�ƽ   0										 0		 0			0�ü�
    1�ߵ�ƽ	  1										 1����	 1 �����ɼ�	1����
  ===========================================================*/


/*-------------------------------------------------------------
    ��ɫģʽ
  *===========================================================*/
enum	COLOR_MODE {
                    COLOR_RGB24,
                    COLOR_RGB24_CLEAR,
                    COLOR_BW24,
                    COLOR_GRAY,
                    COLOR_RAWDATA,
                    COLOR_Microscope	//��ɫУ��ģʽ(��΢��ģʽ)
                };


/*-------------------------------------------------------------
    ��תģʽ Ŀǰ����RGB24,BW24��Ч
  *===========================================================*/
enum	FLIP_MODE {
                    FLIP_NATURAL,		// ������ʾ
                    FLIP_LEFTRIGHT,	    // ���ҷ�ת
                    FLIP_UPDOWN,			// ���·�ת
                    FLIP_ROTATE180,		// ��ת180
                    FLIP_ROTATE90,
                    FLIP_ROTATE270
                };

enum	RZIMAGETYPR {
                        BMP,		// ����ͼ���ʽ����
                        JPEG,	    //
                    };

enum	RZCAMERA{	RZUNKOWN,		//�������
                    RZ130,
                    RZ300,
                    RZ130CF,
                    RZ200CF,
                    RZ300CF,
                    RZ500CF,
                    RZ900CF,
                    RZ500P,			//
                    RZ130C_1_3,
                    RZ36M,
                    RZ300C_FPGA,
                    RZ130C_FPGA,
                    RZ130M_FPGA,
                    RZ80C_SP16,
                    RZ130SC_YUV,
                    RZ120C_FPGA,
                    RZ300_LED,
                    RZTEST,
                    RZF1400CF,
                    RZF1000CF,
                    RZ50C,
                    RZCCD140C,
                    RZUL200MFG,
                    MicroUH1200C,
                    RZTRIGGER,
                    MicroUH600C,
                    SuperUH500,
                    MicroUH300C,
                    SuperUH130,
                    SuperUH200,
                    SuperUH50,
                    SuperUH30,
                    RZF120CF_NEW,//�°汾���������
                    RZU31400CII,
                    RZF1400CFII,
                    RZU3120C,
                    RZU3500C,
                    RZU31000C,
                    RZU31400C,
                    RZF300CF_NEW,
                    RZF130MF_NEW,
                    RZF500CF_NEW,
                    RZ500CFSMALL,
                    RZ50016,
                    RZ500_FPGA,
                    RZ500P_FPGA//��gonganbu����(����ͺ��ǲ���¶�Ķ�����ʾ��RZ500P�����ټ����ͺż����������)
                };

enum	RZ_COLOR_TYPE{
                    RZ_COLOR,
                    RZ_GRAY
                };


enum COLOR_ADJUST_TYPE {
                    COLOR_ADJUST_NO,	//
                    COLOR_ADJUST_COLD,	//��ɫ����
                    COLOR_ADJUST_WARM	//ůɫ����
                };

//�Զ��ع�����Ч������
enum	RZ_AE_LEVEL
{
        RZ_AE_LEVEL_HIGH,	//����
        RZ_AE_LEVEL_NORMAL,	//����
        RZ_AE_LEVEL_LOW		//����
};

typedef struct _tagResolution
{
    TCHAR * lpszDesc;
    int	width;
    int	height;
}TagResolution;

enum	RZ_SPEED_MODE
{
        RZ_SPEED_MODE_LOW,	//����
        RZ_SPEED_MODE_NORMAL,	//����
        RZ_SPEED_MODE_HIGH		//����
};
//����ģʽ����
enum RZ_ZOOM_MODE
{
    RZ_ZOOM_1_1 = 0, //�����ţ��ü�Ч��
    RZ_ZOOM_1_2 = 1, //���и���Сһ������2048*1536ͼ����С�󣬽����1024*768��ͼ��
    RZ_ZOOM_1_4 = 2,  //���и���С��������2048*1536ͼ����С�󣬽����512*384��ͼ��
    RZ_ZOOM_0_2 = 3,	//��bin 2x
    RZ_ZOOM_0_3 = 4		//��bin 3x
};

/*--------------------------------------------------------------
�Զ���ƽ����������
    Ҫ����С��������Ϊ64*64
===============================================================*/
typedef struct AWB_Range_ST
{
    USHORT	usAwbRange_XS;	//�Զ���ƽ������ˮƽ�����ϵ���ʼλ��
    USHORT	usAwbRange_XL;	//�Զ���ƽ������ˮƽ�����ϵĿ��  ȡֵ��Χ���ڵ���64
    USHORT	usAwbRange_YS;	//�Զ���ƽ������ֱ�����ϵ���ʼλ��
    USHORT	usAwbRange_YL;	//�Զ���ƽ������ֱ�����ϵĸ߶�  ȡֵ��Χ���ڵ���64
    USHORT  rsvd[4];
}*P_AWB_RANGE_ST;

typedef enum		//
{
    idResolution,	//
    idContrast,		//
    idExposure,		//
    idGain_All,		//
    idGain_R,		//
    idGain_G,		//
    idGain_B,		//
    idOffsetX,		//
    idOffsetY,		//
    idControl,
    idImageType,	//
    idFlipMode,
    idColorMode,
    idSharp,
    idSta
}ENUM_Param;

typedef enum
{
    IMG_TYPE_BMP,
    IMG_TYPE_JPG,
    IMG_TYPE_PNG,
    IMG_TYPE_TIF
}ENUM_IMAGE_TYPE;

#endif
