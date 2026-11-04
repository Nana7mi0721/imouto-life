
int FUN_00675660(int param_1,int param_2,uint param_3,uint *param_4,int param_5)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  puVar2 = param_4;
  uVar1 = param_3;
  uVar7 = *(uint *)(param_1 + 0x29c);
  uVar3 = 0xffffffff;
  if ((uVar7 != 0) && (uVar7 != 0xffffffff)) {
    uVar3 = uVar7;
  }
  uVar7 = (uint)(param_5 != 0);
  if (uVar3 < uVar7 + param_3) {
    FUN_00669790(param_1,0xfffffffc);
    return -4;
  }
  uVar3 = uVar3 - (uVar7 + param_3);
  if (uVar3 < *param_4) {
    *param_4 = uVar3;
  }
  iVar4 = FUN_006740d0(param_1,*(undefined4 *)(param_1 + 0x11c));
  if (iVar4 != 0) {
    if (iVar4 == 1) {
      iVar4 = -7;
    }
    return iVar4;
  }
  param_3 = param_2 - uVar1;
  iVar4 = FUN_006758a0(param_1,*(undefined4 *)(param_1 + 0x11c),1,*(int *)(param_1 + 0x2b8) + uVar1,
                       &param_3,0,puVar2);
  if (iVar4 != 1) {
    if (iVar4 == 0) {
      iVar4 = -7;
    }
    goto LAB_00675861;
  }
  iVar4 = FUN_0067aa30(param_1 + 0x84);
  if (iVar4 != 0) {
    FUN_00669790(param_1,1);
    *(undefined4 *)(param_1 + 0x80) = 0;
    return -7;
  }
  uVar3 = *puVar2;
  iVar5 = uVar7 + uVar3 + uVar1;
  puVar6 = (undefined4 *)FUN_0066c990(param_1,iVar5);
  if (puVar6 == (undefined4 *)0x0) {
    FUN_00669790(param_1,0xfffffffc);
    *(undefined4 *)(param_1 + 0x80) = 0;
    return -4;
  }
  iVar4 = FUN_006758a0(param_1,*(undefined4 *)(param_1 + 0x11c),1,*(int *)(param_1 + 0x2b8) + uVar1,
                       &param_3,(undefined1 *)((int)puVar6 + uVar1),param_4);
  if (iVar4 == 1) {
    if (uVar3 == *param_4) {
      if (param_5 != 0) {
        *(undefined1 *)((int)puVar6 + uVar1 + *param_4) = 0;
      }
      if (uVar1 != 0) {
        puVar8 = *(undefined4 **)(param_1 + 0x2b8);
        puVar9 = puVar6;
        for (uVar7 = uVar1 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        for (uVar7 = uVar1 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
      }
      puVar8 = *(undefined4 **)(param_1 + 0x2b8);
      *(undefined4 **)(param_1 + 0x2b8) = puVar6;
      *(int *)(param_1 + 700) = iVar5;
      puVar6 = puVar8;
    }
    else {
LAB_006757cf:
      iVar4 = -7;
    }
  }
  else if (iVar4 == 0) goto LAB_006757cf;
  FUN_0066cb60(param_1,puVar6);
  if ((iVar4 == 1) && (param_2 - uVar1 != param_3)) {
    FUN_00668b90(param_1,s_extra_compressed_data_00a0ceac);
    *(undefined4 *)(param_1 + 0x80) = 0;
    return 1;
  }
LAB_00675861:
  *(undefined4 *)(param_1 + 0x80) = 0;
  return iVar4;
}

