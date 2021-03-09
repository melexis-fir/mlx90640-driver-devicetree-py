#define _DEFAULT_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <stdint.h>
#include <unistd.h>

#include "MLX90640_I2C_Driver_devicetree.h"

#define MLX_I2C_ADDR 0x33

int main(void)
{
  struct MLX90640DriverRegister_t *driver = MLX90640_get_register_devicetree();
  printf ("driver name: '%s'\n", driver->name_);
  MLX90640_I2CInit_devicetree("/dev/i2c-1");

  fflush(stdout);

  uint16_t data[832];
  memset(data, 0, sizeof(data));
  MLX90640_I2CRead_devicetree(MLX_I2C_ADDR, 0x2400, 832, data);
  for (int i = 0; i < 832; i+=16)
  {
    printf ("0x%04X:", 0x2400+i);
    for (int j = 0; j < 16; j++)
    {
      printf (" %04X", data[i+j]);
    }
    printf("\n");
  }

  int refresh_rate = 6;
  uint16_t control_register1;
  int value;
  value = (refresh_rate & 0x07)<<7;
    
  MLX90640_I2CRead_devicetree(MLX_I2C_ADDR, 0x800D, 1, &control_register1);
  printf ("original refresh_rate: %d\n", (control_register1 >> 7) & 0x07);
  value = (control_register1 & 0xFC7F) | value;
  MLX90640_I2CWrite_devicetree(MLX_I2C_ADDR, 0x800D, value);

  MLX90640_I2CRead_devicetree(MLX_I2C_ADDR, 0x800D, 1, &control_register1);
  printf ("new refresh_rate: %d\n", (control_register1 >> 7) & 0x07);

  MLX90640_I2CClose_devicetree(); 

  return 0;
}
