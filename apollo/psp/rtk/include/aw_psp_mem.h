/*******************************************************************************
*                                 Apollo
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2012 Guangzhou ZHIYUAN Electronics Stock Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
* e-mail:      apollo.support@zlg.cn
*******************************************************************************/

/**
 * \file
 * \brief sys/bios6 memp managment
 *
 * \internal
 * \par modification history:
 * - 1.00 14-03-29  zen, first implementation
 * \endinternal
 */

#ifndef __AW_PSP_MEM_H
#define __AW_PSP_MEM_H

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus	*/

#include "aw_memheap.h"

typedef aw_memheap_t *aw_psp_heap_id_t;
    
/******************************************************************************/
#if defined(AW_IMG_PRJ_BUILD) || defined(AW_BSP_LIB_BUILD)
#include "aw_bsp_mem.h"
#endif

#ifdef __cplusplus
}
#endif	/* __cplusplus 	*/

#endif	/* __AW_PSP_MEM_H */

/* end of file */
