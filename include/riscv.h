#ifndef  _RISCV_H_
#define  _RISCV_H_

#define RISCV_MSTATUS_SUM       1L<<18
#define RISCV_MSTATUS_MEI_BIT   1<<3    /* IRQs globally disabled on all privilege levels when set to 1. */
#define RISCV_MPP_TO_S_MODE     1<<11   /* Set the previous mode to S-mode so XINU can switch to S-Mode when completed. */
#define RISCV_SPP_TO_U_MODE     1<<8    /* Set the previous mode to U-mode so XINU can switch to U-Mode when completed. */
#define RISCV_SIE_ENABLE        1<<1
#define RISCV_SIE_DISABLE       0<<1
#define RISCV_MDELEG_ALL_S_MODE 0xFFFFFFFFFFFFFFFF

#define RISCV_SIE_SEIE 1<<9
#define RISCV_SIE_STIE 1<<5
#define RISCV_SIE_SSIE 1<<1

#define AGING 1
#define PREEMPT 0
#define QUANTUM 3

#define RISCV_ENABLE_ALL_SMODE_INTR (RISCV_SIE_SEIE | RISCV_SIE_STIE | RISCV_SIE_SSIE)
#define RISCV_MAX_ADDR 0x3FFFFFFFFFFFFFull
#define RISCV_ALL_PERM 0xF

#define PREGS   35

#define PREG_A0 0
#define PREG_A1 1
#define PREG_A2 2
#define PREG_A3 3
#define PREG_A4 4
#define PREG_A5 5
#define PREG_A6 6
#define PREG_A7 7
#define PREG_S0 8
#define PREG_S1 9
#define PREG_S2 10
#define PREG_S3 11
#define PREG_S4 12
#define PREG_S5 13
#define PREG_S6 14
#define PREG_S7 15
#define PREG_S8 16
#define PREG_S9 17
#define PREG_S10 18
#define PREG_S11 19
#define PREG_RA 20
#define PREG_SP 21
#define PREG_PC 22

#define PREG_GP 23
#define PREG_TP 24
#define PREG_T0 25
#define PREG_T1 26
#define PREG_T2 27
#define PREG_T3 28
#define PREG_T4 29
#define PREG_T5 30
#define PREG_T6 31
#define PREG_KERNSATP 32
#define PREG_KERNSP 33
#define PREG_DISPATCH_ADDR 34

#define MAXVIRTADDR		0x4000000000        //(1L << 38)
#define INTERRUPTADDR   0x3FFFFFF000    // truncpage((MAXVIRTADDR - PAGE_SIZE))
#define SWAPAREAADDR    0x3FFFFFE000    // truncpage((MAXVIRTADDR - PAGE_SIZE))
#define PROCSTACKADDR   0x3FFFFFD000    // truncpage((MAXVIRTADDR - PAGE_SIZE - PAGE_SIZE))

#define WATCHDOG_CONF	0x00020500B4

#endif                          /* _RISCV_H_ */
