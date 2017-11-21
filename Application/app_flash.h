/*
 * app_flash.h
 *
 *  Created on: Nov 21, 2017
 *      Author: Jacob
 */

#ifndef APPLICATION_APP_FLASH_H_
#define APPLICATION_APP_FLASH_H_

#include <bcomdef.h>

typedef enum {
    APP_FLASH_DEV_EUI = BLE_NVID_CUST_START,
} app_flash_id_t;

void app_flash_init();

void app_flash_write(app_flash_id_t id, uint8 n, const uint8 *buf);

void app_flash_read(app_flash_id_t id, uint8 n, uint8 *buf);

#endif /* APPLICATION_APP_FLASH_H_ */
