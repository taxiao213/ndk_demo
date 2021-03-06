// © 2016 and later: Unicode, Inc. and others.
// License & terms of use: http://www.unicode.org/copyright.html
/*
*******************************************************************************
*
*   Copyright (C) 1999-2011, International Business Machines
*   Corporation and others.  All Rights Reserved.
*
*******************************************************************************
*   file name:  utf.h
*   encoding:   UTF-8
*   tab size:   8 (not used)
*   indentation:4
*
*   created on: 1999sep09
*   created by: Markus W. Scherer
*/

#ifndef __UTF_H__
#define __UTF_H__

#include "umachine.h"
/* include the utfXX.h after the following definitions */

/* single-code point definitions -------------------------------------------- */

#define U_IS_UNICODE_NONCHAR(c) \
     ((c)>=0xfdd0 && \
      ((c)<=0xfdef || ((c)&0xfffe)==0xfffe) && (c)<=0x10ffff)

#define U_IS_UNICODE_CHAR(c) \
     ((uint32_t)(c)<0xd800 || \
         (0xdfff<(c) && (c)<=0x10ffff && !U_IS_UNICODE_NONCHAR(c)))

#define U_IS_BMP(c) ((uint32_t)(c)<=0xffff)

#define U_IS_SUPPLEMENTARY(c) ((uint32_t)((c)-0x10000)<=0xfffff)

#define U_IS_LEAD(c) (((c)&0xfffffc00)==0xd800)

#define U_IS_TRAIL(c) (((c)&0xfffffc00)==0xdc00)

#define U_IS_SURROGATE(c) (((c)&0xfffff800)==0xd800)

#define U_IS_SURROGATE_LEAD(c) (((c)&0x400)==0)

#define U_IS_SURROGATE_TRAIL(c) (((c)&0x400)!=0)

/* include the utfXX.h ------------------------------------------------------ */

#if !U_NO_DEFAULT_INCLUDE_UTF_HEADERS

#include "utf8.h"
#include "utf16.h"

/* utf_old.h contains deprecated, pre-ICU 2.4 definitions */
#include "utf_old.h"

#endif  /* !U_NO_DEFAULT_INCLUDE_UTF_HEADERS */

#endif  /* __UTF_H__ */