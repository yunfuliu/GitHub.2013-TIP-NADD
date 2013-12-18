//////////////////////////////////////////////////////////////////////////
//
// SOURCE CODE: 
//	https://sites.google.com/site/yunfuliu/2010/2012nctdfddh
//
// CURRENT VERSION: 
//	v2.11
//
// CORRESPONDING ARTICLE:
//	Yun-Fu Liu and Jing-Ming Guo, "New class tiling design for dot-diffused halftoning," IEEE Trans. Image Processing, vol. 22, no. 3, pp. 1199-1208, March 2013.
//
// CONTACT INFO:
//	Yun-Fu Liu (yunfuliu@gmail.com)
//
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <ctime>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class	CLOAD{
public:
	double	**	m_Image;
	int			m_Height;
	int			m_Width;
	CLOAD(int Height=0,int Width=0);	
	virtual		~CLOAD(void);
private:	
	double	*	m_Data;
	bool		m_ImageNewSpaceFlag;
	int			m_ImageHeadLength;
	bool		NewSpace(void);
	bool		ReleaseSpace(void);
};
class CCT{
public:
	int				m_CT_Height;	// ct
	int				m_CT_Width;
	unsigned char	**m_ct;
					CCT();
					~CCT();
	bool			generation(int height,int width);	// ct generation
	bool			save(char name[]);
	bool			load(char name[]);
private:
	int				m_CTmap_Height;	// ct map
	int				m_CTmap_Width;
	int				m_CM_Size;		// class matrix
	int				m_numberofcm;	// number of cm in a ct
	int				m_cm[8][8];
	unsigned char	*m_ctmap;
	unsigned char	*m_ctData;
	bool			trans_ctmap_to_ct();	// for load ()
	bool			char3tovalue8(unsigned char *csrc,int clength,int *idst,int ilength);	// for load ()
	bool			value8tochar3(int *isrc,int ilength,unsigned char *cdst,int clength);	// for save ()

	void			iTrans_CM(int *src,int *dst,int &CM_Size);
	void			Trans_CM(int *src,int *dst,int &CM_Size);
	void			Copy_CM(int *src,int *dst,int &CM_Size);
	void			LfRt_CM(int *src,int *dst,int &CM_Size);
	void			UpDn_CM(int *src,int *dst,int &CM_Size);
	bool			change_cm_type(int type_num,int *src,int *dst,int &CM_Size);
	bool			same_cm_point(int *src,int src_corner_num,int order_type,int order_corner_num,CLOAD &order,int x,int y,int &CM_Size,bool check_diagonal=false);
	bool			check_cm_type(int *src,CLOAD &order,int x,int y,int &CM_Size);
};
void nadd(cv::Mat &src,cv::Mat &dst,CCT &cct);