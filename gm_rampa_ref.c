/*
 * gm_rampa_ref.c
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

#include "gm_rampa_ref_capi.h"
#include "gm_rampa_ref.h"
#include "gm_rampa_ref_private.h"

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model output function */
void gm_rampa_ref_output(RT_MODEL_gm_rampa_ref_T *const gm_rampa_ref_M)
{
  B_gm_rampa_ref_T *gm_rampa_ref_B = ((B_gm_rampa_ref_T *)
    gm_rampa_ref_M->blockIO);
  DW_gm_rampa_ref_T *gm_rampa_ref_DW = ((DW_gm_rampa_ref_T *)
    gm_rampa_ref_M->dwork);
  ExtY_gm_rampa_ref_T *gm_rampa_ref_Y = (ExtY_gm_rampa_ref_T *)
    gm_rampa_ref_M->outputs;

  /* local block i/o variables */
  int16_T rtb_DiscreteFIRFilter;
  int16_T acc1;
  int32_T j;
  int32_T cff;
  real_T tmp;

  /* Gain: '<S1>/Output' incorporates:
   *  RandomNumber: '<S1>/White Noise'
   */
  gm_rampa_ref_B->Output = 1.0 * gm_rampa_ref_DW->NextOutput;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  SignalGenerator: '<Root>/Signal Generator1'
   *  Sum: '<Root>/Sum'
   */
  tmp = floor((sin(6.2831853071795862 * gm_rampa_ref_M->Timing.t[0] * 2000.0) *
               1.0 + gm_rampa_ref_B->Output) * 1024.0);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  gm_rampa_ref_B->DataTypeConversion = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* Outport: '<Root>/dpi_1' */
  gm_rampa_ref_Y->dpi_1 = gm_rampa_ref_B->DataTypeConversion;

  /* Delay: '<S2>/Delay' */
  gm_rampa_ref_B->Delay = gm_rampa_ref_DW->Delay_DSTATE;

  /* Sum: '<S2>/Sum1' incorporates:
   *  Delay: '<S2>/Delay1'
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain1'
   */
  gm_rampa_ref_B->Sum1 = (int16_T)((int16_T)(16384 * gm_rampa_ref_B->Delay >> 13)
    + (int16_T)((-32768) * gm_rampa_ref_DW->Delay1_DSTATE >> 15));

  /* Sum: '<S2>/Sum' */
  gm_rampa_ref_B->Sum = (int16_T)(gm_rampa_ref_B->DataTypeConversion +
    gm_rampa_ref_B->Sum1);

  /* Gain: '<S2>/Gain3' */
  gm_rampa_ref_B->Gain3 = (-32768) * gm_rampa_ref_B->Delay;

  /* Delay: '<S2>/Delay2' */
  gm_rampa_ref_B->Delay2 = gm_rampa_ref_DW->Delay2_DSTATE[0];

  /* Gain: '<S2>/Gain5' incorporates:
   *  Gain: '<S2>/Gain4'
   *  Sum: '<S2>/Sum3'
   *  Sum: '<S2>/Sum4'
   */
  gm_rampa_ref_B->Gain5 = (int16_T)((int16_T)((int16_T)(17920 *
    gm_rampa_ref_B->Sum >> 10) + (int16_T)(gm_rampa_ref_B->Gain3 >> 14)) +
    gm_rampa_ref_B->Delay2) * 29959;

  /* DiscreteFir: '<S2>/Discrete FIR Filter' */
  acc1 = (int16_T)((int64_T)gm_rampa_ref_B->Gain5 * 112 >> 29);
  cff = 1;
  for (j = gm_rampa_ref_DW->DiscreteFIRFilter_circBuf; j < 34; j++) {
    acc1 += (int16_T)((int64_T)gm_rampa_ref_DW->DiscreteFIRFilter_states[j] *
                      gm_rampa_ref_ConstP.DiscreteFIRFilter_Coefficients[cff] >>
                      29);
    cff++;
  }

  for (j = 0; j < gm_rampa_ref_DW->DiscreteFIRFilter_circBuf; j++) {
    acc1 += (int16_T)((int64_T)gm_rampa_ref_DW->DiscreteFIRFilter_states[j] *
                      gm_rampa_ref_ConstP.DiscreteFIRFilter_Coefficients[cff] >>
                      29);
    cff++;
  }

  rtb_DiscreteFIRFilter = acc1;

  /* End of DiscreteFir: '<S2>/Discrete FIR Filter' */

  /* Outport: '<Root>/dpi_2' */
  gm_rampa_ref_Y->dpi_2 = rtb_DiscreteFIRFilter;

  /* Gain: '<S2>/Gain2' */
  gm_rampa_ref_B->Gain2 = (-17379) * gm_rampa_ref_B->Delay;

  /* Sum: '<S2>/Sum2' */
  gm_rampa_ref_B->Sum2 = (int16_T)((int16_T)(gm_rampa_ref_B->Gain2 >> 9) +
    gm_rampa_ref_B->Sum);
}

/* Model update function */
void gm_rampa_ref_update(RT_MODEL_gm_rampa_ref_T *const gm_rampa_ref_M)
{
  B_gm_rampa_ref_T *gm_rampa_ref_B = ((B_gm_rampa_ref_T *)
    gm_rampa_ref_M->blockIO);
  DW_gm_rampa_ref_T *gm_rampa_ref_DW = ((DW_gm_rampa_ref_T *)
    gm_rampa_ref_M->dwork);
  int_T idxDelay;

  /* Update for RandomNumber: '<S1>/White Noise' */
  gm_rampa_ref_DW->NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
    (&gm_rampa_ref_DW->RandSeed) * 1.0 + 0.0;

  /* Update for Delay: '<S2>/Delay' */
  gm_rampa_ref_DW->Delay_DSTATE = gm_rampa_ref_B->Sum;

  /* Update for Delay: '<S2>/Delay1' */
  gm_rampa_ref_DW->Delay1_DSTATE = gm_rampa_ref_B->Delay;

  /* Update for Delay: '<S2>/Delay2' */
  for (idxDelay = 0; idxDelay < 34; idxDelay++) {
    gm_rampa_ref_DW->Delay2_DSTATE[idxDelay] = gm_rampa_ref_DW->
      Delay2_DSTATE[idxDelay + 1];
  }

  gm_rampa_ref_DW->Delay2_DSTATE[34] = gm_rampa_ref_B->Sum2;

  /* End of Update for Delay: '<S2>/Delay2' */

  /* Update for DiscreteFir: '<S2>/Discrete FIR Filter' */
  /* Update circular buffer index */
  gm_rampa_ref_DW->DiscreteFIRFilter_circBuf--;
  if (gm_rampa_ref_DW->DiscreteFIRFilter_circBuf < 0) {
    gm_rampa_ref_DW->DiscreteFIRFilter_circBuf = 33;
  }

  /* Update circular buffer */
  gm_rampa_ref_DW->DiscreteFIRFilter_states
    [gm_rampa_ref_DW->DiscreteFIRFilter_circBuf] = gm_rampa_ref_B->Gain5;

  /* End of Update for DiscreteFir: '<S2>/Discrete FIR Filter' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++gm_rampa_ref_M->Timing.clockTick0)) {
    ++gm_rampa_ref_M->Timing.clockTickH0;
  }

  gm_rampa_ref_M->Timing.t[0] = gm_rampa_ref_M->Timing.clockTick0 *
    gm_rampa_ref_M->Timing.stepSize0 + gm_rampa_ref_M->Timing.clockTickH0 *
    gm_rampa_ref_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    gm_rampa_ref_M->Timing.clockTick1++;
    if (!gm_rampa_ref_M->Timing.clockTick1) {
      gm_rampa_ref_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void gm_rampa_ref_initialize(RT_MODEL_gm_rampa_ref_T *const gm_rampa_ref_M)
{
  DW_gm_rampa_ref_T *gm_rampa_ref_DW = ((DW_gm_rampa_ref_T *)
    gm_rampa_ref_M->dwork);

  {
    uint32_T tseed;
    int32_T t;
    int32_T i;
    real_T tmp;

    /* InitializeConditions for RandomNumber: '<S1>/White Noise' */
    tmp = floor(23341.0);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    gm_rampa_ref_DW->RandSeed = tseed;
    gm_rampa_ref_DW->NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&gm_rampa_ref_DW->RandSeed) * 1.0 + 0.0;

    /* End of InitializeConditions for RandomNumber: '<S1>/White Noise' */

    /* InitializeConditions for Delay: '<S2>/Delay' */
    gm_rampa_ref_DW->Delay_DSTATE = 0;

    /* InitializeConditions for Delay: '<S2>/Delay1' */
    gm_rampa_ref_DW->Delay1_DSTATE = 0;

    /* InitializeConditions for Delay: '<S2>/Delay2' */
    for (i = 0; i < 35; i++) {
      gm_rampa_ref_DW->Delay2_DSTATE[i] = 0;
    }

    /* End of InitializeConditions for Delay: '<S2>/Delay2' */

    /* InitializeConditions for DiscreteFir: '<S2>/Discrete FIR Filter' */
    gm_rampa_ref_DW->DiscreteFIRFilter_circBuf = 0;
    for (i = 0; i < 34; i++) {
      gm_rampa_ref_DW->DiscreteFIRFilter_states[i] = 0;
    }

    /* End of InitializeConditions for DiscreteFir: '<S2>/Discrete FIR Filter' */
  }
}

/* Model terminate function */
void gm_rampa_ref_terminate(RT_MODEL_gm_rampa_ref_T * gm_rampa_ref_M)
{
  rt_FREE(gm_rampa_ref_M->solverInfo);

  /* model code */
  rt_FREE(gm_rampa_ref_M->blockIO);
  rt_FREE(gm_rampa_ref_M->outputs);
  rt_FREE(gm_rampa_ref_M->dwork);
  rt_FREE(gm_rampa_ref_M);
}

/* Model data allocation function */
RT_MODEL_gm_rampa_ref_T *gm_rampa_ref(void)
{
  RT_MODEL_gm_rampa_ref_T *gm_rampa_ref_M;
  gm_rampa_ref_M = (RT_MODEL_gm_rampa_ref_T *) malloc(sizeof
    (RT_MODEL_gm_rampa_ref_T));
  if (gm_rampa_ref_M == NULL) {
    return NULL;
  }

  (void) memset((char *)gm_rampa_ref_M, 0,
                sizeof(RT_MODEL_gm_rampa_ref_T));

  {
    /* Setup solver object */
    RTWSolverInfo *rt_SolverInfo = (RTWSolverInfo *) malloc(sizeof(RTWSolverInfo));
    rt_VALIDATE_MEMORY(gm_rampa_ref_M,rt_SolverInfo);
    gm_rampa_ref_M->solverInfo = (rt_SolverInfo);
    rtsiSetSimTimeStepPtr(gm_rampa_ref_M->solverInfo,
                          &gm_rampa_ref_M->Timing.simTimeStep);
    rtsiSetTPtr(gm_rampa_ref_M->solverInfo, &rtmGetTPtr(gm_rampa_ref_M));
    rtsiSetStepSizePtr(gm_rampa_ref_M->solverInfo,
                       &gm_rampa_ref_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(gm_rampa_ref_M->solverInfo, (&rtmGetErrorStatus
      (gm_rampa_ref_M)));
    rtsiSetRTModelPtr(gm_rampa_ref_M->solverInfo, gm_rampa_ref_M);
  }

  rtsiSetSolverName(gm_rampa_ref_M->solverInfo,"FixedStepDiscrete");

  /* block I/O */
  {
    B_gm_rampa_ref_T *b = (B_gm_rampa_ref_T *) malloc(sizeof(B_gm_rampa_ref_T));
    rt_VALIDATE_MEMORY(gm_rampa_ref_M,b);
    gm_rampa_ref_M->blockIO = (b);
  }

  /* states (dwork) */
  {
    DW_gm_rampa_ref_T *dwork = (DW_gm_rampa_ref_T *) malloc(sizeof
      (DW_gm_rampa_ref_T));
    rt_VALIDATE_MEMORY(gm_rampa_ref_M,dwork);
    gm_rampa_ref_M->dwork = (dwork);
  }

  /* external outputs */
  {
    ExtY_gm_rampa_ref_T *gm_rampa_ref_Y = (ExtY_gm_rampa_ref_T *) malloc(sizeof
      (ExtY_gm_rampa_ref_T));
    rt_VALIDATE_MEMORY(gm_rampa_ref_M,gm_rampa_ref_Y);
    gm_rampa_ref_M->outputs = (gm_rampa_ref_Y);
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  gm_rampa_ref_InitializeDataMapInfo(gm_rampa_ref_M);

  {
    B_gm_rampa_ref_T *gm_rampa_ref_B = ((B_gm_rampa_ref_T *)
      gm_rampa_ref_M->blockIO);
    DW_gm_rampa_ref_T *gm_rampa_ref_DW = ((DW_gm_rampa_ref_T *)
      gm_rampa_ref_M->dwork);
    ExtY_gm_rampa_ref_T *gm_rampa_ref_Y = (ExtY_gm_rampa_ref_T *)
      gm_rampa_ref_M->outputs;

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));
    rtsiSetSimTimeStep(gm_rampa_ref_M->solverInfo, MAJOR_TIME_STEP);
    rtmSetTPtr(gm_rampa_ref_M, &gm_rampa_ref_M->Timing.tArray[0]);
    gm_rampa_ref_M->Timing.stepSize0 = 0.001;

    /* block I/O */
    (void) memset(((void *) gm_rampa_ref_B), 0,
                  sizeof(B_gm_rampa_ref_T));

    /* states (dwork) */
    (void) memset((void *)gm_rampa_ref_DW, 0,
                  sizeof(DW_gm_rampa_ref_T));

    /* external outputs */
    (void) memset((void *)gm_rampa_ref_Y, 0,
                  sizeof(ExtY_gm_rampa_ref_T));
  }

  return gm_rampa_ref_M;
}
