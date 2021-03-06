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
 * \brief aworks1.0 异常标准接口头文件
 *
 * \internal
 * \par modification history:
 * - 1.00 12-09-04  zen, first implementation
 * \endinternal
 */

#ifndef __AW_PSP_EXC_H
#define __AW_PSP_EXC_H

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus	*/

#ifdef AW_CORTEX_M0
#include "arch/arm/armv6m/armv6m_exc.h"
#endif

#ifdef AW_CORTEX_M4
#include "arch/arm/cortex_m4/cortex_m4_exc.h"
#endif

#ifdef AW_CORTEX_M3
#include "arch/arm/cortex_m3/cortex_m3_exc.h"
#endif

#ifdef __cplusplus
}
#endif	/* __cplusplus 	*/

#endif	/* __AW_PSP_EXC_H */

/* end of file */
