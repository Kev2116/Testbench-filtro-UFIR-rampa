/*
 * gm_rampa_ref.h
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

#ifndef RTW_HEADER_gm_rampa_ref_h_
#define RTW_HEADER_gm_rampa_ref_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef gm_rampa_ref_COMMON_INCLUDES_
# define gm_rampa_ref_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* gm_rampa_ref_COMMON_INCLUDES_ */

#include "gm_rampa_ref_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#define gm_rampa_ref_M_TYPE            RT_MODEL_gm_rampa_ref_T

/* Block signals (auto storage) */
typedef struct {
  real_T Output;                       /* '<S1>/Output' */
  int32_T Gain5;                       /* '<S2>/Gain5' */
  int32_T Gain2;                       /* '<S2>/Gain2' */
  int32_T Gain3;                       /* '<S2>/Gain3' */
  int16_T DataTypeConversion;          /* '<Root>/Data Type Conversion' */
  int16_T Delay;                       /* '<S2>/Delay' */
  int16_T Sum1;                        /* '<S2>/Sum1' */
  int16_T Sum;                         /* '<S2>/Sum' */
  int16_T Delay2;                      /* '<S2>/Delay2' */
  int16_T Sum2;                        /* '<S2>/Sum2' */
} B_gm_rampa_ref_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T NextOutput;                   /* '<S1>/White Noise' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T DiscreteFIRFilter_circBuf;   /* '<S2>/Discrete FIR Filter' */
  int32_T DiscreteFIRFilter_states[34];/* '<S2>/Discrete FIR Filter' */
  uint32_T RandSeed;                   /* '<S1>/White Noise' */
  int16_T Delay_DSTATE;                /* '<S2>/Delay' */
  int16_T Delay1_DSTATE;               /* '<S2>/Delay1' */
  int16_T Delay2_DSTATE[35];           /* '<S2>/Delay2' */
} DW_gm_rampa_ref_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: DiscreteFIRFilter_Coefficients
   * Referenced by: '<S2>/Discrete FIR Filter'
   */
  int16_T DiscreteFIRFilter_Coefficients[35];
} ConstP_gm_rampa_ref_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  int16_T dpi_1;                       /* '<Root>/dpi_1' */
  int16_T dpi_2;                       /* '<Root>/dpi_2' */
} ExtY_gm_rampa_ref_T;

/* Real-time Model Data Structure */
struct tag_RTM_gm_rampa_ref_T {
  const char_T *errorStatus;
  RTWSolverInfo *solverInfo;
  B_gm_rampa_ref_T *blockIO;
  ExtY_gm_rampa_ref_T *outputs;
  DW_gm_rampa_ref_T *dwork;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

/* Constant parameters (auto storage) */
extern const ConstP_gm_rampa_ref_T gm_rampa_ref_ConstP;

/* Model entry point functions */
extern RT_MODEL_gm_rampa_ref_T *gm_rampa_ref(void);
extern void gm_rampa_ref_initialize(RT_MODEL_gm_rampa_ref_T *const
  gm_rampa_ref_M);
extern void gm_rampa_ref_output(RT_MODEL_gm_rampa_ref_T *const gm_rampa_ref_M);
extern void gm_rampa_ref_update(RT_MODEL_gm_rampa_ref_T *const gm_rampa_ref_M);
extern void gm_rampa_ref_terminate(RT_MODEL_gm_rampa_ref_T * gm_rampa_ref_M);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  gm_rampa_ref_GetCAPIStaticMap(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'gm_rampa_ref'
 * '<S1>'   : 'gm_rampa_ref/Band-Limited White Noise'
 * '<S2>'   : 'gm_rampa_ref/rampa'
 */
#endif                                 /* RTW_HEADER_gm_rampa_ref_h_ */
