/*******************************************************************************
*                                 Apollo
*                       ---------------------------
*                       innovating embedded systems
*
* Copyright (c) 2001-2014 Guangzhou ZHIYUAN Electronics Stock Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
* e-mail:      apollo.support@zlg.cn
*******************************************************************************/

/**
 * \file
 * \brief �ӳ���ҵ����
 *
 *  - �ӳ���ҵ�Ĺ����ǰ�ĳ����ӳ�һ��ʱ���ڴ������Ͷ�ʱ����ʹ������
 *  - �Ͷ�ʱ����ͬ�����ӳ���ҵ��ִ�л���Ϊ��������ж�
 *  - ͨ����Ҫ�Ǿ�ȷ�ӳ٣������ڣ�ִ�е������ʹ���ӳ���ҵ����
 *
 * ʹ�ñ�������Ҫ����ͷ�ļ� aw_delayed_work.h
 *
 * \par ʹ��ʾ��
 * \code
 * struct aw_delayed_work work;
 *
 * static void my_work (void *p_arg)
 * {
 *     ; // ʵ�ʹ���
 *
 *     // ��������ٴ�����work����work�����������
 *     // aw_delayed_work_start((struct aw_delayed_work *)p_arg, 500);
 * }
 *
 * aw_delayed_work_init(&work, my_work, &work); // ��ʼ��work
 * aw_delayed_work_start(&work, 500);           // 500���������my_work
 * ......
 * aw_delayed_work_stop(&work);                 // ֹͣwork
 * \endcode
 *
 * // �������ݴ����ӡ�����
 *
 * \internal
 * \par modification history
 * - 1.00 13-03-06  orz, first implementation.
 * \endinternal
 */

#ifndef __AW_DELAYED_WORK_H
#define __AW_DELAYED_WORK_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup grp_aw_if_delayed_work
 * \copydoc aw_delayed_work.h
 * @{
 */

#include "aw_types.h"
#include "aw_isr_defer.h"
#include "aw_timer.h"

/** \brief �ӳ���ҵ���ݽṹ */
struct aw_delayed_work {
    struct aw_isr_defer_job  job; /**< \brief the job queue */
    aw_timer_t               tmr; /**< \brief the delay timer */
};

/******************************************************************************/

/**
 * \brief �ӳ���ҵ��ʼ��
 * \param p_work        �ӳ���ҵ���ݽṹָ��
 * \param pfunc_work    �����������ú������ӳٵ���
 * \param p_arg         ���������Ĳ���
 */
void aw_delayed_work_init (struct aw_delayed_work *p_work,
                           void                  (*pfunc_work)(void *p_arg),
                           void                   *p_arg);

/**
 * \brief �����ӳ���ҵ
 * \param p_work        �ӳ���ҵ���ݽṹָ��
 * \param delay_ms      �ӳٺ�����
 */
void aw_delayed_work_start(struct aw_delayed_work *p_work, uint_t delay_ms);

/**
 * \brief ֹͣ�ӳ���ҵ
 * \note  ����ӿ�ֻ��ֹͣ�����ӳ�״̬����ҵ������ֹͣ�Ѿ���ʼ��������ҵ
 * \param p_work        �ӳ���ҵ���ݽṹָ��
 */
void aw_delayed_work_stop (struct aw_delayed_work *p_work);

/** @} grp_aw_if_delayed_work */

#ifdef __cplusplus
}
#endif

#endif /* __AW_DELAYED_WORK_H */

/* end of file */