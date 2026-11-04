
void FUN_00577120(undefined4 param_1,int param_2,uint param_3,int *param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = FUN_00572ac0(param_1);
  if (iVar1 == 1) {
    if (param_3 != 0) {
      if ((int)param_3 < (int)param_5) {
        param_5 = param_3;
      }
      iVar1 = 0;
      if (0 < (int)param_5) {
        iVar3 = param_2 - (int)param_4;
        while ((char)*param_4 != '\0') {
          *(char *)((int)param_4 + iVar3) = (char)*param_4;
          iVar1 = iVar1 + 1;
          param_4 = (int *)((int)param_4 + 1);
          if ((int)param_5 <= iVar1) {
            return;
          }
        }
        if (iVar1 < (int)param_5) {
          _memset((void *)(iVar1 + param_2),0,param_5 - iVar1);
        }
      }
    }
  }
  else if (iVar1 == 2) {
    if (1 < param_3) {
      if ((int)(param_3 >> 1) < (int)param_5) {
        param_5 = param_3 >> 1;
      }
      iVar1 = 0;
      if (0 < (int)param_5) {
        iVar3 = param_2 - (int)param_4;
        while ((short)*param_4 != 0) {
          *(short *)((int)param_4 + iVar3) = (short)*param_4;
          iVar1 = iVar1 + 1;
          param_4 = (int *)((int)param_4 + 2);
          if ((int)param_5 <= iVar1) {
            return;
          }
        }
        if (iVar1 < (int)param_5) {
          puVar4 = (undefined4 *)(param_2 + iVar1 * 2);
          for (uVar2 = param_5 - iVar1 >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
          }
          for (uVar2 = (uint)((param_5 - iVar1 & 1) != 0); uVar2 != 0; uVar2 = uVar2 - 1) {
            *(undefined2 *)puVar4 = 0;
            puVar4 = (undefined4 *)((int)puVar4 + 2);
          }
          return;
        }
      }
    }
  }
  else if ((iVar1 == 4) && (3 < param_3)) {
    if ((int)(param_3 >> 2) < (int)param_5) {
      param_5 = param_3 >> 2;
    }
    iVar1 = 0;
    if (0 < (int)param_5) {
      iVar3 = param_2 - (int)param_4;
      while (*param_4 != 0) {
        *(int *)(iVar3 + (int)param_4) = *param_4;
        iVar1 = iVar1 + 1;
        param_4 = param_4 + 1;
        if ((int)param_5 <= iVar1) {
          return;
        }
      }
      if (iVar1 < (int)param_5) {
        puVar4 = (undefined4 *)(param_2 + iVar1 * 4);
        for (iVar3 = param_5 - iVar1; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        return;
      }
    }
  }
  return;
}

