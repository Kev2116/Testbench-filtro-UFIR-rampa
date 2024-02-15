/*
 * gm_rampa_ref_capi.c
 *
 * Code generation for model "gm_rampa_ref".
 *
 * Model version              : 1.20
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Sun May 08 12:32:57 2022
 *
 * Target selection: systemverilog_dpi_grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "gm_rampa_ref_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "gm_rampa_ref.h"
#include "gm_rampa_ref_capi.h"
#include "gm_rampa_ref_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  {
    "", "", 0, 0, 0, 0, 0, 0
  }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  {
    rtwCAPI_SCALAR, 0, 0, 0
  }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = { 0 };

/* Fixed Point Map */
static rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  {
    (NULL), (NULL), 0, 0
  }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 0,
    (NULL), 0,
    (NULL), 0 },

  { (NULL), 0,
    (NULL), 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3704970553U,
    2627373413U,
    3600958378U,
    2138459350U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  gm_rampa_ref_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void gm_rampa_ref_InitializeDataMapInfo(RT_MODEL_gm_rampa_ref_T *const
  gm_rampa_ref_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(gm_rampa_ref_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(gm_rampa_ref_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(gm_rampa_ref_M->DataMapInfo.mmi, (NULL));

  /* Set Instance specific path */
  rtwCAPI_SetPath(gm_rampa_ref_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetFullPath(gm_rampa_ref_M->DataMapInfo.mmi, (NULL));

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(gm_rampa_ref_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(gm_rampa_ref_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(gm_rampa_ref_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void gm_rampa_ref_host_InitializeDataMapInfo(gm_rampa_ref_host_DataMapInfo_T
    *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: gm_rampa_ref_capi.c */
