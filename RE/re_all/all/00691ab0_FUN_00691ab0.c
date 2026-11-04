
void FUN_00691ab0(int *param_1,short *param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = param_1[0x5d];
  piVar3 = (int *)param_1[0x5c];
  param_3 = *param_2 - param_3;
  if (param_3 < 0) {
    param_3 = -param_3;
  }
  iVar4 = 0;
  if (param_3 != 0) {
    do {
      iVar4 = iVar4 + 1;
      param_3 = param_3 >> 1;
    } while (param_3 != 0);
    if (0xb < iVar4) {
      *(undefined4 *)(*param_1 + 0x14) = 6;
      (**(code **)*param_1)(param_1);
    }
  }
  uVar5 = 0;
  *(int *)(param_4 + iVar4 * 4) = *(int *)(param_4 + iVar4 * 4) + 1;
  if (0 < iVar1) {
    param_3 = iVar1;
    do {
      piVar3 = piVar3 + 1;
      iVar1 = (int)param_2[*piVar3];
      if (iVar1 == 0) {
        uVar5 = uVar5 + 1;
      }
      else {
        if (0xf < (int)uVar5) {
          uVar2 = uVar5 >> 4;
          uVar5 = uVar5 + uVar2 * -0x10;
          iVar4 = param_5[0xf0];
          do {
            iVar4 = iVar4 + 1;
            uVar2 = uVar2 - 1;
          } while (uVar2 != 0);
          param_5[0xf0] = iVar4;
        }
        if (iVar1 < 0) {
          iVar1 = -iVar1;
        }
        iVar1 = iVar1 >> 1;
        iVar4 = 1;
        if (iVar1 != 0) {
          do {
            iVar4 = iVar4 + 1;
            iVar1 = iVar1 >> 1;
          } while (iVar1 != 0);
          if (10 < iVar4) {
            *(undefined4 *)(*param_1 + 0x14) = 6;
            (**(code **)*param_1)(param_1);
          }
        }
        iVar4 = uVar5 * 0x10 + iVar4;
        uVar5 = 0;
        param_5[iVar4] = param_5[iVar4] + 1;
      }
      param_3 = param_3 + -1;
    } while (param_3 != 0);
    if (0 < (int)uVar5) {
      *param_5 = *param_5 + 1;
    }
  }
  return;
}

