
undefined4 FUN_00571e10(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(&DAT_00b02d08)[param_1 & 0xfffffff];
  if (piVar1 == (int *)0x0) {
    return 0xffffffff;
  }
  if (*piVar1 == 0) {
    uVar2 = FUN_0052dc20(piVar1[1]);
    return uVar2;
  }
  uVar2 = FUN_00571970(piVar1 + 4,param_2,param_3,param_4);
  return uVar2;
}

