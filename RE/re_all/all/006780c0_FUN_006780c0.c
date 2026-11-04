
int FUN_006780c0(int param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = FUN_00677c50(param_1,param_2,param_3[1]);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = param_3[1];
  uVar1 = *param_3;
  param_2 = (undefined4 *)(param_1 + 0xbc);
  *(undefined4 **)(param_1 + 0x90) = param_3 + 3;
  iVar5 = 0x400;
  *(undefined4 *)(param_1 + 0x84) = uVar1;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0x400;
  do {
    iVar4 = -1;
    if (iVar2 != -1) {
      iVar4 = iVar2;
    }
    iVar2 = iVar2 - iVar4;
    *(int *)(param_1 + 0x88) = iVar4;
    if (*(int *)(param_1 + 0x94) == 0) {
      if (0x7fffffff < (uint)(param_4 + iVar5)) {
LAB_006781c1:
        iVar4 = -4;
        break;
      }
      puVar3 = (undefined4 *)*param_2;
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)FUN_0066c990(param_1,*(int *)(param_1 + 0xc0) + 4);
        if (puVar3 == (undefined4 *)0x0) goto LAB_006781c1;
        *puVar3 = 0;
        *param_2 = puVar3;
      }
      *(undefined4 **)(param_1 + 0x90) = puVar3 + 1;
      *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0xc0);
      iVar5 = iVar5 + *(int *)(param_1 + 0xc0);
      param_2 = puVar3;
    }
    iVar4 = FUN_0067cde0(param_1 + 0x84,(-(uint)(iVar2 != 0) & 0xfffffffc) + 4);
    iVar2 = iVar2 + *(int *)(param_1 + 0x88);
    *(undefined4 *)(param_1 + 0x88) = 0;
  } while (iVar4 == 0);
  iVar5 = iVar5 - *(int *)(param_1 + 0x94);
  *(undefined4 *)(param_1 + 0x94) = 0;
  param_3[2] = iVar5;
  if ((uint)(iVar5 + param_4) < 0x7fffffff) {
    FUN_00669790(param_1,iVar4);
  }
  else {
    *(char **)(param_1 + 0x9c) = s_compressed_data_too_long_00a0d590;
    iVar4 = -4;
  }
  *(undefined4 *)(param_1 + 0x80) = 0;
  if ((iVar4 == 1) && (iVar2 == 0)) {
    FUN_00677be0(param_3 + 3,param_3[1]);
    return 0;
  }
  return iVar4;
}

