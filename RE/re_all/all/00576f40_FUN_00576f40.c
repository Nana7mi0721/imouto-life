
void FUN_00576f40(undefined4 param_1,int param_2,uint param_3,char *param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00572ac0(param_1);
  if (iVar1 == 1) {
    if (param_3 != 0) {
      uVar2 = 0;
      if (param_3 != 1) {
        iVar1 = param_2 - (int)param_4;
        do {
          if (*param_4 == '\0') break;
          param_4[iVar1] = *param_4;
          uVar2 = uVar2 + 1;
          param_4 = param_4 + 1;
        } while (uVar2 < param_3 - 1);
      }
      *(undefined1 *)(uVar2 + param_2) = 0;
    }
  }
  else if (iVar1 == 2) {
    if (1 < param_3) {
      iVar1 = 0;
      if (param_3 != 2) {
        uVar2 = 0;
        do {
          if (*(short *)(param_4 + uVar2) == 0) break;
          iVar1 = iVar1 + 1;
          *(short *)(uVar2 + param_2) = *(short *)(param_4 + uVar2);
          uVar2 = iVar1 * 2;
        } while (uVar2 < param_3 - 2);
      }
      *(undefined2 *)(param_2 + iVar1 * 2) = 0;
      return;
    }
  }
  else if ((iVar1 == 4) && (3 < param_3)) {
    iVar1 = 0;
    if (param_3 != 4) {
      uVar2 = 0;
      do {
        if (*(int *)(param_4 + uVar2) == 0) break;
        iVar1 = iVar1 + 1;
        *(int *)(uVar2 + param_2) = *(int *)(param_4 + uVar2);
        uVar2 = iVar1 * 4;
      } while (uVar2 < param_3 - 4);
    }
    *(undefined4 *)(param_2 + iVar1 * 4) = 0;
    return;
  }
  return;
}

