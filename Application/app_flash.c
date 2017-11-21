/*
 * app_flash.c
 *
 *  Created on: Nov 21, 2017
 *      Author: Jacob
 */

#include <osal_snv.h>
#include <bcomdef.h>

#include "app_flash.h"

#define FLASH_BUF_LEN 40

static uint8_t flash_buf[FLASH_BUF_LEN] = {0,};

static void init_id(app_flash_id_t id) {
    uint8_t status = SUCCESS;
    status = osal_snv_read(id, FLASH_BUF_LEN, (uint8_t *)flash_buf);
    if (status != SUCCESS) {
        osal_snv_write(id, FLASH_BUF_LEN, (uint8_t *)flash_buf);
    }
}

void app_flash_init() {
    init_id(APP_FLASH_DEV_EUI);
}

void app_flash_write(app_flash_id_t id, uint8 n, const uint8 *buf) {
    osal_snv_write(id, n, buf);
}

void app_flash_read(app_flash_id_t id, uint8 n, uint8 *buf) {
    osal_snv_read(id, n, buf);
}
