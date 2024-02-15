/*
 *  rtmodel.h:
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

#ifndef RTW_HEADER_rtmodel_h_
#define RTW_HEADER_rtmodel_h_

/*
 *  Includes the appropriate headers when we are using rtModel
 */
#include "gm_rampa_ref.h"
#define GRTINTERFACE                   0

/*
 * ROOT_IO_FORMAT: 0 (Individual arguments)
 * ROOT_IO_FORMAT: 1 (Structure reference)
 * ROOT_IO_FORMAT: 2 (Part of model data structure)
 */
# define ROOT_IO_FORMAT                2

/* Macros generated for backwards compatibility  */
#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif
#endif                                 /* RTW_HEADER_rtmodel_h_ */
