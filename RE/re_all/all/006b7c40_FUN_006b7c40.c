
void FUN_006b7c40(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  uVar2 = param_5 - param_4;
  iVar7 = param_3 - param_2;
  iVar1 = (int)uVar2 / iVar7;
  if ((int)uVar2 < 0) {
    param_5 = iVar1 + -1;
  }
  else {
    param_5 = iVar1 + 1;
  }
  uVar3 = iVar1 * iVar7 >> 0x1f;
  if (param_3 < param_1) {
    param_1 = param_3;
  }
  if (param_2 < param_1) {
    *(int *)(param_6 + param_2 * 4) = param_4;
  }
  iVar5 = 0;
  param_2 = param_2 + 1;
  if (param_2 < param_1) {
    piVar6 = (int *)(param_6 + param_2 * 4);
    param_1 = param_1 - param_2;
    do {
      iVar5 = iVar5 + (((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f)) -
                      ((iVar1 * iVar7 ^ uVar3) - uVar3));
      if (iVar5 < iVar7) {
        iVar4 = iVar1;
      }
      else {
        iVar5 = iVar5 - iVar7;
        iVar4 = param_5;
      }
      param_4 = param_4 + iVar4;
      *piVar6 = param_4;
      piVar6 = piVar6 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}

