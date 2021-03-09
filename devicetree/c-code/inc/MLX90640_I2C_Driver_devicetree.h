#ifndef __MLX90640_I2C_DRIVER_DEVICETREE_H__
#define __MLX90640_I2C_DRIVER_DEVICETREE_H__

#include <stdint.h>

#include "mlx90640_driver_register.h"

#ifdef __cplusplus
extern "C" {
#endif

struct MLX90640DriverRegister_t *MLX90640_get_register_devicetree(void);

void *MLX90640_get_i2c_handle_devicetree(void);
void MLX90640_set_i2c_handle_devicetree(void *handle);

void MLX90640_I2CInit_devicetree(const char *port);
void MLX90640_I2CClose_devicetree(void);
int MLX90640_I2CRead_devicetree(uint8_t slaveAddr, uint16_t startAddr, uint16_t nMemAddressRead, uint16_t *data);
void MLX90640_I2CFreqSet_devicetree(int freq);
int MLX90640_I2CGeneralReset_devicetree(void);
int MLX90640_I2CWrite_devicetree(uint8_t slaveAddr, uint16_t writeAddress, uint16_t data);

#ifdef __cplusplus
}
#endif

#endif // __MLX90640_I2C_DRIVER_DEVICETREE_H__
