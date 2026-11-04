
undefined4 FUN_006c0c50(int *param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if ((param_3 < 1) && (param_3 < 0)) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  if ((param_5 < 1) && (param_5 < 0)) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 == iVar4) {
    *param_1 = param_2 - param_4;
    param_1[1] = (param_3 - param_5) - (uint)(param_2 < param_4);
    return 0;
  }
  if (iVar4 != 0) {
    uVar3 = -param_2 - 1;
    uVar1 = -param_4 - 1;
    param_5 = 0x7fffffff - param_5;
    iVar4 = -param_3 + -2 + (uint)(uVar3 != 0);
    if ((param_5 < iVar4) || ((param_5 <= iVar4 && (uVar1 <= -param_2 - 2)))) {
      *param_1 = uVar1 - uVar3;
      param_1[1] = (param_5 - (-param_3 + 0x7fffffff)) - (uint)(uVar1 < uVar3);
      return 0;
    }
    return 0xffffff7d;
  }
  param_3 = param_3 + -0x80000000;
  uVar1 = -param_4;
  iVar4 = (-0x80000000 - param_5) - (uint)(param_4 != 0);
  iVar2 = (-0x80000000 - iVar4) - (uint)(uVar1 != 0);
  if ((iVar2 < param_3) || ((iVar2 <= param_3 && (param_4 <= param_2)))) {
    *param_1 = uVar1 + param_2;
    param_1[1] = iVar4 + param_3 + (uint)CARRY4(uVar1,param_2);
    return 0;
  }
  return 0xffffff7d;
}

