// AnimateDlgIcon.h : interface of the CAnimateDlgIcon class
// written by Rajesh Parikh
// email : rparikh@usa.net
// Not protected by any copyright, use it freely
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANIMATEDLGICON_H__47E058AD_6F69_11D2_B59C_86DD54033006__INCLUDED_)
#define      AFX_ANIMATEDLGICON_H__47E058AD_6F69_11D2_B59C_86DD54033006__INCLUDED_

class CAnimateDlgIcon
{
protected :
	// variable to hold the image list containing a series
	// of icons
	CImageList  m_imgList;
	// keep track of which image is current
	int m_iImageCounter;
	// store the max nos of images
	int m_iMaxNoOfImages;
	HICON hIcon;
	HICON hPrevIcon ;
		
public:
	CAnimateDlgIcon();
	~CAnimateDlgIcon();
	BOOL SetImageList(int IDOfImgListResource,int numberOfImages,COLORREF transparentColor);
	BOOL ShowNextImage();
};

#endif //#define AFX_ANIMATEDLGICON_H__47E058AD_6F69_11D2_B59C_86DD54033006__INCLUDED_