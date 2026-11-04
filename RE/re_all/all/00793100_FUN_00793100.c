
void FUN_00793100(ushort *param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  
  if (param_3 == 0) {
    uVar1 = __ftol();
    *param_1 = uVar1 & 0xfffe;
    uVar1 = __ftol();
    param_1[1] = uVar1 & 0xfffe;
    uVar1 = __ftol();
    param_1[2] = uVar1 & 0xfffe;
    return;
  }
  uVar1 = __ftol();
  *param_1 = uVar1 | 1;
  uVar1 = __ftol();
  param_1[1] = uVar1 | 1;
  uVar1 = __ftol();
  param_1[2] = uVar1 | 1;
  return;
}

