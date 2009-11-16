#ifndef _IMAGERECORD_H_
#define _IMAGERECORD_H_

#include "../WDL/wdlstring.h"

class ImageRecord : public WDL_VWnd
{
public:
  ImageRecord(const char *srcfn);
  ~ImageRecord();

  ////// WDL_VWnd impl

  virtual void OnPaint(LICE_IBitmap *drawbm, int origin_x, int origin_y, RECT *cliprect);
  virtual void SetPosition(const RECT *r);
  virtual INT_PTR SendCommand(int command, INT_PTR parm1, INT_PTR parm2, WDL_VWnd *src);

  //////

  WDL_String m_fn;
  WDL_String m_outname;

#define IR_STATE_NEEDLOAD 0
#define IR_STATE_DECODING 1
#define IR_STATE_LOADED 2
#define IR_STATE_ERROR 3

  int m_state;
  LICE_IBitmap *m_preview_image;
};


#endif