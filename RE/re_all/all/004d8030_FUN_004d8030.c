
undefined4 __thiscall FUN_004d8030(void *param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  *(undefined4 *)((int)param_1 + 4) = 0;
  *(undefined4 *)((int)param_1 + 8) = 0;
  *(undefined4 *)((int)param_1 + 0xc) = 0;
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = FUN_004e26e0();
    if (uVar1 < param_2) {
      FID_conflict__Xran(param_1);
    }
    else {
      uVar2 = FUN_004e38c0(param_2);
      *(undefined4 *)((int)param_1 + 4) = uVar2;
      *(undefined4 *)((int)param_1 + 8) = *(undefined4 *)((int)param_1 + 4);
      *(uint *)((int)param_1 + 0xc) = param_2 * 0x10 + *(int *)((int)param_1 + 4);
    }
    uVar2 = 1;
  }
  return uVar2;
}

