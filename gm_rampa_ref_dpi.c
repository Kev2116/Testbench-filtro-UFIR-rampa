/*

 File: C:\Users\Windows\Documents\Practicas MATLAB\gm_rampa_ref_build\gm_rampa_ref_dpi.c
 Created: 2022-05-08 12:33:22
 Generated by MATLAB 9.2 and HDL Verifier 5.2

*/

#include "gm_rampa_ref.h"
#include "gm_rampa_ref_dpi.h"

#ifndef RT_MEMORY_ALLOCATION_ERROR_DEF
#define RT_MEMORY_ALLOCATION_ERROR_DEF
const char *RT_MEMORY_ALLOCATION_ERROR = "memory allocation error";
#endif
static RT_MODEL_gm_rampa_ref_T* RT_MODEL_gm_rampa_ref = NULL;

DPI_DLL_EXPORT void* DPI_gm_rampa_ref_initialize(void* existhandle)
{
    RT_MODEL_gm_rampa_ref_T* objhandle;
    if(existhandle == NULL)
    {
        objhandle = gm_rampa_ref();
    }
    else
    {
        objhandle = (RT_MODEL_gm_rampa_ref_T*) existhandle;
    }
    gm_rampa_ref_initialize(((RT_MODEL_gm_rampa_ref_T*)objhandle));
    return (void*) objhandle;
}

DPI_DLL_EXPORT void DPI_gm_rampa_ref_output(void* objhandle, int16_T* gm_rampa_ref_Y_dpi_1, int16_T* gm_rampa_ref_Y_dpi_2)
{
    
    
    
    
    int16_T* gm_rampa_ref_Y_dpi_1_Ptr = gm_rampa_ref_Y_dpi_1;
    int16_T* gm_rampa_ref_Y_dpi_2_Ptr = gm_rampa_ref_Y_dpi_2;
    
    int16_T* RT_MODEL_gm_rampa_ref_outputs_dpi_1_Ptr = &(((RT_MODEL_gm_rampa_ref_T*) objhandle )->outputs->dpi_1);
    int16_T* RT_MODEL_gm_rampa_ref_outputs_dpi_2_Ptr = &(((RT_MODEL_gm_rampa_ref_T*) objhandle )->outputs->dpi_2);
    
    
    
    
    gm_rampa_ref_output(((RT_MODEL_gm_rampa_ref_T*) objhandle ));
    
    
    memcpy(gm_rampa_ref_Y_dpi_1_Ptr, RT_MODEL_gm_rampa_ref_outputs_dpi_1_Ptr, sizeof(int16_T[1]));
    memcpy(gm_rampa_ref_Y_dpi_2_Ptr, RT_MODEL_gm_rampa_ref_outputs_dpi_2_Ptr, sizeof(int16_T[1]));
    
}

DPI_DLL_EXPORT void DPI_gm_rampa_ref_update(void* objhandle)
{
    
    
    
    
    
    
    
    gm_rampa_ref_update(((RT_MODEL_gm_rampa_ref_T*) objhandle ));
}

DPI_DLL_EXPORT void DPI_gm_rampa_ref_terminate(void* objhandle)
{
    gm_rampa_ref_terminate(((RT_MODEL_gm_rampa_ref_T*)objhandle));
}

