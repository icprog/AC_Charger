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
 * \brief ͨ��DAC�ӿ�
 *
 * ʹ�ñ�������Ҫ����ͷ�ļ� 
 * \code 
 * #include aw_dac.h
 * \endcode
 *
 * \par ��ʾ��
 * \code
 *  #include aw_dac.h
 *
 *  int dac_bits = aw_dac_get_bits(0);        // ��ȡDACͨ��0��ת��λ��
 *  int dac_vref = aw_dac_vref_get(0);        // ��ȡDACͨ��0�Ĳο���ѹ(��λ��mV)
 *
 *  aw_dac_val_t dac_val��
 *
 *  dac_val = 1200 * (1 << dac_bits) / dac_vref;
 *
 *  aw_dac_val_set(0, dac_val);               // ����DACͨ��0�������ѹΪ 1.2V (δʹ�ܣ���δʵ�����)
 *  aw_dac_enable(0);                         // ʹ������������ѹΪ1.2V
 *
 *  dac_val = 1400 * (1 << dac_bits) / dac_vref; 
 *  aw_dac_val_set(0, dac_val);               // ����DACͨ��0�������ѹΪ 1.4V (ǰ����ʹ�ܣ�ʵ�������ѹ1.4V)
 *
 * \endcode
 *
 * \internal
 * \par modification history:
 * - 1.00 15-04-02 tee, first implementation
 * \endinternal
 */

#ifndef __AW_DAC_H
#define __AW_DAC_H

#ifdef __cplusplus
extern "C" {
#endif
    
/**
 * \addtogroup grp_aw_if_dac
 * \copydoc aw_dac.h
 * @{
 */

#include "apollo.h"
#include "aw_psp_dac.h"
#include "aw_list.h"

typedef aw_psp_dac_channel_t    aw_dac_channel_t;
typedef aw_psp_dac_val_t        aw_dac_val_t;


/**
 * \brief ��ȡһ��DACͨ����λ��
 *
 * \param[in] ch  DACͨ����
 *
 * \retval >0          ��DACͨ������Чλ��
 * \retval -AW_ENXIO   DACͨ��ͨ���Ų�����
 * \retval -AW_EFAULT  ��������
 */
int aw_dac_bits_get(aw_dac_channel_t ch);

/**
 * \brief ��ȡһ��DACͨ���Ĳο���ѹ(��λ��mV)
 *
 * \param[in] ch  DACͨ����
 *
 * \retval >0          ��DACͨ����Ӧ�Ĳο���ѹ
 * \retval -AW_ENXIO   DACͨ��ͨ���Ų�����
 * \retval -AW_EFAULT  ��������
 */
int aw_dac_vref_get(aw_dac_channel_t ch);

/**
 * \brief ����һ��DACͨ����������ֵ
 *
 * \param[in] ch  DACͨ����
 * \param[in] val �����õ�������ֵ
 *
 * \retval   AW_OK      �����ɹ�
 * \retval  -AW_ENXIO   DACͨ���Ų�����
 * \retval  -AW_EFAULT  ��������
 * \retval  -AW_EINVAL  ��Ч�����������õ�������ֵ����
 */
aw_err_t aw_dac_val_set(aw_dac_channel_t ch, aw_dac_val_t val);
                         
/**
 * \brief ʹ��һ��DACͨ�����ģ����
 *
 * \param[in] ch  DACͨ����
 * \param[in] val �����õ�������ֵ
 *
 * \retval   AW_OK      �����ɹ�
 * \retval  -AW_EFAULT  ��������
 * \retval  -AW_ENXIO   DACͨ���Ų�����
 *
 * \note ���ڸ�ʹ�ܺ�����aw_adc_val_set()�����ĵ����Ⱥ��ϵ��˵�����£�
 *       ����ȵ��ø�ʹ�ܺ�������DACʹ�ܺ������ѹΪ0������ͨ����������aw_dac_val_set()����Ϊ��Ҫ��ֵ��
 *       ����ȵ�������aw_dac_val_set()���������˵�ѹֵ����ʹ�ܺ�Ϊ��Ӧ�ĵ�ѹ���ֵ��
 */
aw_err_t aw_dac_enable(aw_dac_channel_t ch);

/**
 * \brief ����һ��DACͨ�����ģ����
 *
 * \param[in] ch  DACͨ����
 * \param[in] val �����õ�������ֵ
 *
 * \retval   AW_OK      �����ɹ�
 * \retval  -AW_EFAULT  ��������
 * \retval  -AW_ENXIO   DACͨ���Ų�����
 */
aw_err_t aw_dac_disable(aw_dac_channel_t ch);
                        
                        
/**
 * \brief ����һ��DACͨ����������ֵ
 *
 * \param[in] ch  DACͨ����
 * \param[in] val �����õ�������ֵ
 *
 * \retval   AW_OK      �����ɹ�
 * \retval  -AW_ENXIO   DACͨ���Ų�����
 * \retval  -AW_EFAULT  ��������
 * \retval  -AW_EINVAL  ��Ч�����������õ�������ֵ����
 */
aw_err_t aw_dac_mv_set(aw_dac_channel_t ch, int mv);
                       
/** @} grp_aw_if_dac */

#ifdef __cplusplus
}
#endif

#endif  /* __AW_dac_H */

/* end of file */