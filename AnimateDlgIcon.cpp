// AnimateIcon.cpp : implementation of the CAnimateDlgIcon class
// written by Rajesh Parikh 
// email : rparikh@usa.net
// Not protected by any copyright, use it freely
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AnimateDlgIcon.h"

// default constructor
CAnimateDlgIcon::CAnimateDlgIcon()
{
	m_iImageCounter = -1;
	m_iMaxNoOfImages = -99;
	m_imgList.m_hImageList = NULL;
}

// default do nothing destructor
CAnimateDlgIcon::~CAnimateDlgIcon()
{
	DestroyIcon(hPrevIcon);
}

// This is the first function which needs to be called in order
// to fill the image list
// Parameters :
// ------------
// int IDOfImgListResource - pass the Resource ID of a toolbar resource
//                           containing the image list
// int numberOfImages      - Number of images (16x16) in the toolbar resource
// transparentColor        - RGB value of color you want to be transparent
BOOL CAnimateDlgIcon::SetImageList(int IDOfImgListResource,int numberOfImages,COLORREF transparentColor)
{
	if(numberOfImages <= 0)
		return FALSE;
	m_iMaxNoOfImages = numberOfImages;
	VERIFY(m_imgList.Create(IDOfImgListResource,16,1,transparentColor));
	return TRUE;
}

// This function needs to be called repetatively to show next image
// Parameters :
// ------------
// NONE

BOOL CAnimateDlgIcon::ShowNextImage()
{
	if(m_imgList.m_hImageList == NULL)
		return FALSE;
	m_iImageCounter++;
	if(m_iImageCounter >= m_iMaxNoOfImages)
		m_iImageCounter =0;
	// extract the icon from imagelist
	hIcon = m_imgList.ExtractIcon(m_iImageCounter);
	// send the message to frame to update icon
	HICON hPrevIcon = (HICON) AfxGetMainWnd()->SetIcon(hIcon,FALSE);	
	// Free the previous icon resource
	DestroyIcon(hPrevIcon);
	return TRUE;
}