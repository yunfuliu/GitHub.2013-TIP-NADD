#include "lib/NADD.h"

#ifdef _DEBUG
#pragma comment(lib,"lib/vc10/nadd_vc10x64v2.11d.lib")
#else
#pragma comment(lib,"lib/vc10/nadd_vc10x64v2.11.lib")
#endif

using namespace	cv;

void main(){

/*	//////////////////////////////////////////////////////////////////////////
	//                    case01: ct generation and save
	//////////////////////////////////////////////////////////////////////////
	CCT	cct;
	cct.generation(512,512);	// assign the size of ct
	cct.save("ct512.map");
*/
	
	//////////////////////////////////////////////////////////////////////////
	//              case02: load ct and perform nadd halftoning
	//////////////////////////////////////////////////////////////////////////
	// load .map file
	Mat	src,dst;
	CCT	cct;
	cct.load("resource/ct512.map");

	// load image 
	src	=	imread("lake.bmp",CV_LOAD_IMAGE_GRAYSCALE);

	// process
	nadd(src,dst,cct);

	// show results
	namedWindow("src");
	namedWindow("dst");
	moveWindow("src",0,0);
	moveWindow("dst",src.cols,0);
	imshow("src",src);
	imshow("dst",dst);
	waitKey(0);
}