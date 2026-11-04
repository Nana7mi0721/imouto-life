
void FUN_00577300(undefined4 param_1,int *param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = FUN_00572ac0(param_1);
  if (iVar3 == 1) {
    uVar4 = 0;
    cVar1 = (char)*param_2;
    while (cVar1 != '\0') {
      uVar4 = uVar4 + 1;
      cVar1 = *(char *)(uVar4 + (int)param_2);
    }
    if (uVar4 < param_3 - 1U) {
      FUN_00576f40(param_1,(char *)(uVar4 + (int)param_2),param_3 - uVar4,param_4);
    }
  }
  else {
    if (iVar3 == 2) {
      iVar3 = 0;
      sVar2 = (short)*param_2;
      while (sVar2 != 0) {
        iVar3 = iVar3 + 1;
        sVar2 = *(short *)((int)param_2 + iVar3 * 2);
      }
      uVar5 = iVar3 * 2;
      uVar4 = param_3 - 2;
    }
    else {
      if (iVar3 != 4) {
        return;
      }
      iVar3 = 0;
      if (*param_2 != 0) {
        iVar3 = 0;
        do {
          iVar3 = iVar3 + 1;
        } while (param_2[iVar3] != 0);
      }
      uVar5 = iVar3 * 4;
      uVar4 = param_3 - 4;
    }
    if (uVar5 < uVar4) {
      FUN_00576f40(param_1,(char *)(uVar5 + (int)param_2),param_3 - uVar5,param_4);
      return;
    }
  }
  return;
}

