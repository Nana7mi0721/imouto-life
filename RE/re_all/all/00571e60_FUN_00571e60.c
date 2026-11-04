
uint FUN_00571e60(undefined4 param_1,uint param_2,int param_3,uint param_4)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = (int *)(&DAT_00b02d08)[param_4 & 0xfffffff];
  if (piVar1 == (int *)0x0) {
    return 0xffffffff;
  }
  if (*piVar1 == 0) {
    uVar2 = FUN_0052dcb0();
    return uVar2;
  }
  uVar2 = FUN_005716c0(piVar1 + 4,param_1,param_2 * param_3);
  return uVar2 / param_2;
}

