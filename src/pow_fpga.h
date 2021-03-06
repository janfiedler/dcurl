/*
 * Copyright (C) 2018-2019 BiiLabs Co., Ltd. and Contributors
 * All Rights Reserved.
 * This is free software; you can redistribute it and/or modify it under the
 * terms of the MIT license. A copy of the license can be found in the file
 * "LICENSE" at the root of this distribution.
 */

#ifndef POW_FPGA_H_
#define POW_FPGA_H_

#include <stdint.h>
#include "common.h"
#include "constants.h"

typedef struct _pow_fpga_context PoW_FPGA_Context;

struct _pow_fpga_context {
    /* Management of Multi-thread */
    int indexOfContext;
    /* Arguments of PoW */
    int8_t input_trytes[TRANSACTION_TRYTES_LENGTH];  /* 2673 */
    int8_t output_trytes[TRANSACTION_TRYTES_LENGTH]; /* 2673 */
    int mwm;
    /* PoW-related information */
    PoW_Info pow_info;
    /* Device files for the FPGA accelerator*/
    int ctrl_fd;
    int in_fd;
    int out_fd;
    int devmem_fd;
    /* Memory map of fpga */
    void *fpga_regs_map;
    uint32_t *cpow_map;
};

#endif
