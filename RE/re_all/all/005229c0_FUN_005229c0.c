
undefined4
FUN_005229c0(int *param_1,undefined4 *param_2,uint param_3,int param_4,int param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_8;
  int local_4;
  
  if (param_3 == 0xffffffff) {
    param_3 = DAT_00a38120;
    param_4 = DAT_00a38140;
    param_5 = DAT_00a38160;
  }
  else {
    if (param_4 == -1) {
      param_4 = 0;
    }
    if (param_5 == -1) {
      param_5 = 0;
    }
  }
  if ((((DAT_00cc47d0 == 0) || ((int)param_3 < 0)) || ((param_3 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(param_3 & 0xffff) ||
       (piVar6 = *(int **)(DAT_00cc47d4 + (param_3 & 0xffff) * 4), piVar6 == (int *)0x0)) ||
      ((*piVar6 * 0x10000 != (param_3 & 0x3ff0000) || (piVar6[4] != 0)))))) {
    piVar6 = (int *)0x0;
    local_8 = DAT_00a381b8;
    local_4 = DAT_00a381b4;
  }
  else {
    FUN_005185c0(piVar6[0x18],piVar6[0x19],param_5,&local_4,&local_8);
  }
  iVar4 = *param_1;
  if (((iVar4 < 0) || (iVar1 = param_1[2], iVar1 <= iVar4)) ||
     ((iVar2 = param_1[1], iVar2 < 0 ||
      (((iVar3 = param_1[3], iVar3 <= iVar2 || (local_4 < iVar1)) || (local_8 < iVar3)))))) {
    return 0xffffffff;
  }
  if (DAT_00a37d78 == 0) {
    iVar5 = 0x10a;
    if (piVar6 == (int *)0x0) {
      puVar7 = *(undefined4 **)(DAT_00a37e0c + 0x14);
      puVar8 = param_2;
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      iVar5 = *(int *)(DAT_00a37e0c + 0xc);
      param_2[0x10c] = iVar5;
      param_2[0x10d] = param_1[1] * iVar5 + (uint)*(byte *)(param_2 + 1) * *param_1 + DAT_00a37e04;
    }
    else {
      puVar7 = *(undefined4 **)(piVar6[0x27] + 0x14);
      puVar8 = param_2;
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      iVar5 = *(int *)(piVar6[0x27] + 0xc);
      param_2[0x10c] = iVar5;
      param_2[0x10d] = (uint)*(byte *)(param_2 + 1) * *param_1 + param_1[1] * iVar5 + piVar6[0x25];
    }
    param_2[0x10b] = iVar3 - iVar2;
    param_2[0x10a] = iVar1 - iVar4;
    param_2[0x10e] = 0;
    param_2[0x10f] = 0;
  }
  else {
    iVar4 = FUN_00567e40(param_1,param_2,param_3,piVar6,param_4,param_5,param_6,param_7);
    if (iVar4 < 0) {
      return 0xffffffff;
    }
  }
  DAT_00a37efc = 1;
  return 0;
}

