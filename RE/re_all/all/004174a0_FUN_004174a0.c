
uint FUN_004174a0(int param_1,uint param_2)

{
  undefined8 uVar1;
  
  if ((DAT_00a192c4 & 1) == 0) {
    DAT_00a192c4 = DAT_00a192c4 | 1;
    DAT_00a192c0 = GetTickCount();
  }
  if (param_1 == 0) {
    uVar1 = __allmul(DAT_00a192c0,0,0x41a7,0);
    DAT_00a192c0 = __allrem(uVar1,0x7fffffff,0);
    while (2000000000 < DAT_00a192c0) {
      uVar1 = __allmul(DAT_00a192c0,0,0x41a7,0);
      DAT_00a192c0 = __allrem(uVar1,0x7fffffff,0);
    }
  }
  else if (param_1 == 2) {
    DAT_00a192c0 = param_2;
  }
  if (DAT_00a192c0 == 0) {
    DAT_00a192c0 = GetTickCount();
  }
  return DAT_00a192c0;
}

