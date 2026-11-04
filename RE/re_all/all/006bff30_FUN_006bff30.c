
undefined4 FUN_006bff30(int *param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  
  if ((int)param_4 < 1) {
    if ((int)param_4 < 0) {
      if (-1 < param_3) {
        iVar1 = (int)-param_4 >> 0x1f;
        if ((param_3 <= iVar1) && ((param_3 < iVar1 || (param_2 < -param_4)))) {
          return 0xffffff7d;
        }
      }
      iVar1 = (-0x80000000 - ((int)param_4 >> 0x1f)) - (uint)(param_4 != 0);
      if ((param_3 <= iVar1) && ((param_3 < iVar1 || (param_2 < -param_4)))) {
        param_4 = param_4 + 1 + param_2;
        param_2 = 0xffffffff;
        param_3 = 0x7fffffff;
      }
    }
  }
  else {
    if ((param_3 < 1) && (param_3 < 0)) {
      iVar1 = (int)(-param_4 - 1) >> 0x1f;
      if ((iVar1 <= param_3) && ((iVar1 < param_3 || (-param_4 - 1 <= param_2)))) {
        return 0xffffff7d;
      }
    }
    iVar1 = 0x7fffffff - ((int)param_4 >> 0x1f);
    if ((iVar1 <= param_3) && ((iVar1 < param_3 || (-param_4 - 1 < param_2)))) {
      param_4 = param_4 + param_2;
      param_2 = 0;
      param_3 = -0x80000000;
    }
  }
  *param_1 = param_4 + param_2;
  param_1[1] = ((int)param_4 >> 0x1f) + param_3 + (uint)CARRY4(param_4,param_2);
  return 0;
}

