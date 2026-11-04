
void FUN_00577020(undefined4 param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = FUN_00572ac0(param_1);
  if (iVar1 == 1) {
    iVar1 = 0;
    if (0 < param_4) {
      iVar3 = param_2 - (int)param_3;
      while ((char)*param_3 != '\0') {
        *(char *)((int)param_3 + iVar3) = (char)*param_3;
        iVar1 = iVar1 + 1;
        param_3 = (int *)((int)param_3 + 1);
        if (param_4 <= iVar1) {
          return;
        }
      }
      if (iVar1 < param_4) {
        _memset((void *)(iVar1 + param_2),0,param_4 - iVar1);
      }
    }
  }
  else if (iVar1 == 2) {
    iVar1 = 0;
    if (0 < param_4) {
      iVar3 = param_2 - (int)param_3;
      while ((short)*param_3 != 0) {
        *(short *)((int)param_3 + iVar3) = (short)*param_3;
        iVar1 = iVar1 + 1;
        param_3 = (int *)((int)param_3 + 2);
        if (param_4 <= iVar1) {
          return;
        }
      }
      if (iVar1 < param_4) {
        puVar4 = (undefined4 *)(param_2 + iVar1 * 2);
        for (uVar2 = (uint)(param_4 - iVar1) >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        for (uVar2 = (uint)((param_4 - iVar1 & 1U) != 0); uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined2 *)puVar4 = 0;
          puVar4 = (undefined4 *)((int)puVar4 + 2);
        }
        return;
      }
    }
  }
  else if (iVar1 == 4) {
    iVar1 = 0;
    if (0 < param_4) {
      iVar3 = param_2 - (int)param_3;
      while (*param_3 != 0) {
        *(int *)(iVar3 + (int)param_3) = *param_3;
        iVar1 = iVar1 + 1;
        param_3 = param_3 + 1;
        if (param_4 <= iVar1) {
          return;
        }
      }
      if (iVar1 < param_4) {
        puVar4 = (undefined4 *)(param_2 + iVar1 * 4);
        for (param_4 = param_4 - iVar1; param_4 != 0; param_4 = param_4 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        return;
      }
    }
  }
  return;
}

