
undefined4
FUN_005a57f0(int *param_1,undefined4 *param_2,undefined4 param_3,int param_4,int param_5,
            undefined4 param_6,int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_28;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  int local_4;
  
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  iVar2 = FUN_005d35f0();
  if ((iVar2 != 0) && (DAT_00e79688 != 0)) {
    FUN_005d3950();
    DAT_00e79688 = 0;
  }
  iVar7 = param_1[3] - param_1[1];
  iVar2 = param_1[2] - *param_1;
  if (param_4 == 0) {
    if (DAT_00ddb5c4 == 0) {
      local_28 = DAT_00ddb5b4;
    }
    else {
      local_28 = DAT_00ddb5c4;
    }
    uVar6 = DAT_00ddb4d0;
    iVar4 = DAT_00ddb4c0;
  }
  else {
    iVar1 = *(int *)(param_4 + 0x4c);
    iVar5 = *(int *)(iVar1 + 0x3c + param_8 * 0x1c);
    local_28 = *(int *)(iVar5 + 0x1c);
    iVar4 = 0;
    if (local_28 == 0) {
      local_28 = *(int *)(iVar5 + 4 + param_5 * 4);
      uVar6 = *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(iVar1 + 4) * 4);
    }
    else {
      uVar6 = *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(iVar1 + 4) * 4);
    }
  }
  puVar3 = (undefined4 *)FUN_00598180(uVar6);
  if ((iVar4 == 0) ||
     (iVar4 = FUN_005d4b80(local_28,&local_18,param_1,-(param_7 != 0) & 0x10), iVar4 != 0)) {
    param_4 = 0;
    iVar4 = FUN_005d3790(iVar2,iVar7,uVar6,0,0,0,&param_4,0);
    if (iVar4 != 0) {
      FUN_0056bb10(&DAT_007fc5a0);
      return 0xffffffff;
    }
    iVar4 = FUN_005a4db0(iVar2,iVar7,uVar6,0);
    while (iVar4 == -1) {
      iVar4 = FUN_005501a0();
      if (iVar4 != 0) {
        FUN_0056bb10(&DAT_007fc558);
        FUN_005d3370(param_4);
        return 0xffffffff;
      }
      FUN_0056da20(1);
      iVar4 = FUN_005a4db0(iVar2,iVar7,uVar6,0);
    }
    uVar6 = (&DAT_00ecfb30)[iVar4 * 6];
    local_10 = 0;
    local_c = 0;
    iVar1 = iVar4 * 0x18;
    local_8 = iVar2;
    local_4 = iVar7;
    iVar5 = FUN_005d3850(local_28,param_1,param_4,&local_10,0);
    if (iVar5 != 0) {
      FUN_005d3370(param_4);
      if (((&DAT_00ecfb1c)[iVar1] != '\0') && ((&DAT_00ecfb1d)[iVar1] != '\0')) {
        (&DAT_00ecfb1d)[iVar1] = 0;
        uVar6 = FUN_00550060(0);
        (&DAT_00ecfb2c)[iVar4 * 6] = uVar6;
      }
      return 0xffffffff;
    }
    FUN_005d3830(param_4,uVar6);
    FUN_005d4b80(uVar6,&local_18,0,-(param_7 != 0) & 0x10);
    DAT_00ddb5d8 = uVar6;
    DAT_00ddb5dc = iVar4;
    FUN_005d3370(param_4);
  }
  else {
    DAT_00ddb5e0 = local_28;
    DAT_00ddb5d8 = 0;
  }
  puVar8 = param_2;
  for (iVar4 = 0x10a; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar8 = puVar8 + 1;
  }
  param_2[0x10b] = iVar7;
  param_2[0x10c] = local_18;
  param_2[0x10a] = iVar2;
  param_2[0x10d] = local_14;
  param_2[0x10e] = 0;
  param_2[0x10f] = 0;
  return 0;
}

