/**
 * @copyright (C) 2017 Melexis N.V.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef _MLX640_API_H_
#define _MLX640_API_H_
#include <stddef.h>
#include <stdint.h>

/*************************** C++ guard macro *****************************/
#ifdef __cplusplus
extern "C"
{
#endif

#define MLX90640_I2C_ADDR UINT8_C(0x33)

typedef int8_t (*mlx90640_com_fptr_t_read)(uint8_t dev_addr, uint16_t reg_addr,
              uint16_t *data, uint16_t len);
typedef int8_t (*mlx90640_com_fptr_t_write)(uint8_t dev_addr, uint16_t reg_addr,
              uint16_t data);
typedef int8_t (*mlx90640_com_fptr_t_read8)(uint8_t dev_addr, uint16_t reg_addr,
              uint8_t *data, uint16_t len);
typedef void (*mlx90640_delay_fptr_t)(uint32_t period);

// complete params struct for temperature calculation 
typedef struct
  {
      int16_t kVdd;
      int16_t vdd25;
      float KvPTAT;
      float KtPTAT;
      uint16_t vPTAT25;
      float alphaPTAT;
      int16_t gainEE;
      float tgc;
      float cpKv;
      float cpKta;
      uint8_t resolutionEE;
      uint8_t calibrationModeEE;
      float KsTa;
      float ksTo[4];
      int16_t ct[4];
      float alpha[768];    
      int16_t offset[768];    
      float kta[768];    
      float kv[768];
      float cpAlpha[2];
      int16_t cpOffset[2];
      float ilChessC[3]; 
      uint16_t brokenPixels[5];
      uint16_t outlierPixels[5];  
  } paramsMLX90640;


struct mlx90640_dev {
	/*! Chip Id */
	uint8_t chip_id;
	/*! Device Id */
	uint8_t id;
        /*! Parameters */
	//paramsMLX90640 params;
	/*! Read function pointer */
	mlx90640_com_fptr_t_read read;
        /*! Read function pointer with 16bit addressing and 8bit data */
	mlx90640_com_fptr_t_read8 read8;
	/*! Write function pointer */
	mlx90640_com_fptr_t_write write;
	/*!  Delay function pointer */
	mlx90640_delay_fptr_t delay_ms;
};

    int MLX90640_I2CRead(const struct mlx90640_dev *dev, uint16_t reg_addr, uint16_t len, uint16_t *data);
    int MLX90640_I2CRead8(const struct mlx90640_dev *dev, uint16_t reg_addr, uint16_t len, uint8_t *data);
    int MLX90640_I2CWrite(const struct mlx90640_dev *dev, uint16_t reg_addr, uint16_t data);
    //int mlx90640_get_regs(uint8_t reg_addr, uint8_t *data, uint16_t len, const struct mlx90640_dev *dev);
    int MLX90640_DumpEE(struct mlx90640_dev *dev, uint16_t *eeData);
    int MLX90640_DumpEE8(struct mlx90640_dev *dev, uint8_t *eeData);
    int MLX90640_GetFrameData(struct mlx90640_dev *dev, uint16_t *frameData);
    int MLX90640_GetFrameData8(struct mlx90640_dev *dev, uint8_t *frameData);
    int MLX90640_ExtractParameters(uint16_t *eeData,  const paramsMLX90640 *params);
    float MLX90640_GetVdd(uint16_t *frameData, const paramsMLX90640 *params);
    float MLX90640_GetTa(uint16_t *frameData, const paramsMLX90640 *params);
    void MLX90640_GetImage(uint16_t *frameData, const paramsMLX90640 *params, float *result);
    void MLX90640_CalculateTo(uint16_t *frameData, const paramsMLX90640 *params, float emissivity, float tr, float *result);
    int MLX90640_SetResolution(struct mlx90640_dev *dev, uint8_t resolution);
    int MLX90640_GetCurResolution(struct mlx90640_dev *dev);
    int MLX90640_SetRefreshRate(struct mlx90640_dev *dev, uint8_t refreshRate);   
    int MLX90640_GetRefreshRate(struct mlx90640_dev *dev);  
    int MLX90640_GetSubPageNumber(uint16_t *frameData);
    int MLX90640_GetCurMode(struct mlx90640_dev *dev); 
    int MLX90640_SetInterleavedMode(struct mlx90640_dev *dev);
    int MLX90640_SetChessMode(struct mlx90640_dev *dev);
    void MLX90640_BadPixelsCorrection(uint16_t *pixels, float *to, int mode, paramsMLX90640 *params);
    /*************************** C++ guard macro *****************************/
#ifdef __cplusplus
}
#endif

#endif