
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_0062f020(int *param_1,float param_2,int param_3,float param_4)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  float10 extraout_ST0;
  
  iVar6 = 0;
  if (param_3 == 0) {
    bVar2 = _DAT_00804520 <= ABS(param_2);
    param_4 = param_2;
    param_1[0x3a] = (int)param_2;
    if (bVar2) {
      iVar6 = 1;
      param_3 = 1;
    }
    else {
      iVar6 = 0;
      param_3 = 0;
    }
  }
  else {
    fVar1 = (float)param_1[0x3a];
    param_1[0x3a] = (int)(param_2 + fVar1);
    if (param_4 <= param_2 + fVar1) {
      iVar6 = __ftol();
      param_1[0x3a] = (int)(float)(extraout_ST0 - (float10)iVar6 * (float10)param_4);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0xc))();
  if (iVar3 != 0) {
    piVar4 = (int *)(**(code **)(*param_1 + 0xc))();
    uVar5 = (**(code **)(*piVar4 + 0x2c))();
    DAT_00f3f818 = (byte)(uVar5 >> 4) & 1;
  }
  if (iVar6 == 0) {
    (**(code **)(*param_1 + 0x3c))();
  }
  else {
    (**(code **)(*param_1 + 0x88))(param_4);
    (**(code **)(*param_1 + 0x90))();
    if (iVar6 <= param_3) {
      param_3 = iVar6;
    }
    if (0 < param_3) {
      do {
        (**(code **)(*param_1 + 0x84))(param_4);
        (**(code **)(*param_1 + 0x3c))();
        param_3 = param_3 + -1;
      } while (param_3 != 0);
      (**(code **)(*param_1 + 0x60))();
      return iVar6;
    }
  }
  (**(code **)(*param_1 + 0x60))();
  return iVar6;
}

