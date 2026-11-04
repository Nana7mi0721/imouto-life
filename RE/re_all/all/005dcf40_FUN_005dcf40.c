
undefined4 FUN_005dcf40(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_38;
  int *local_34;
  uint local_30;
  undefined4 local_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  int local_18;
  undefined4 uStack_14;
  undefined1 auStack_10 [16];
  
  iVar3 = (int)param_1;
  piVar1 = (int *)((int)param_1 + 0x6e);
  piVar2 = (int *)((int)param_1 + 0x6a);
  local_30 = 0;
  param_1 = (int *)0x0;
  local_34 = (int *)0x0;
  local_38 = 0;
  local_2c = 0;
  if (*piVar1 != *piVar2) {
LAB_005dd0f3:
    uVar5 = *(int *)(iVar3 + 0x6e) - *(int *)(iVar3 + 0x6a);
    if (*(uint *)(iVar3 + 0x450) < uVar5) {
      uVar5 = *(uint *)(iVar3 + 0x450);
    }
    uVar6 = (uint)*(ushort *)(iVar3 + 0x44);
    iVar4 = (((uVar6 - 1) + uVar5) / uVar6) * uVar6;
    FUN_0056d420(*(undefined4 *)(iVar3 + 0x44c),*(int *)(iVar3 + 0x66) + *(int *)(iVar3 + 0x6a),
                 iVar4);
    *(int *)(iVar3 + 0x6a) = *(int *)(iVar3 + 0x6a) + iVar4;
    *(int *)(iVar3 + 0x454) = iVar4;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
      param_1 = (int *)0x0;
    }
    if (local_34 != (int *)0x0) {
      (**(code **)(*local_34 + 8))(local_34);
    }
    return 0;
  }
  do {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
      param_1 = (int *)0x0;
    }
    iVar4 = (**(code **)(**(int **)(iVar3 + 0x4a) + 0x24))
                      (*(int **)(iVar3 + 0x4a),0xfffffffd,0,0,&local_30,&local_18,&param_1);
    if ((iVar4 != 0) || ((local_30 & 0x22) != 0)) goto LAB_005dd0c4;
    if (param_1 == (int *)0x0) goto LAB_005dd0d8;
    puStack_28 = *(undefined **)(iVar3 + 0x40);
    iStack_20 = local_18;
    uStack_1c = uStack_14;
    uStack_24 = 0;
    FUN_0056d6c0(&iStack_20,&puStack_28,auStack_10);
    puStack_28 = &DAT_00989680;
    uStack_24 = 0;
    FUN_0056d730(auStack_10,&puStack_28,&iStack_20);
  } while (iStack_20 < *(int *)(iVar3 + 0x45c));
  iVar4 = (**(code **)(*param_1 + 0xa4))(param_1,&local_34);
  if (((iVar4 == 0) &&
      (iVar4 = (**(code **)(*local_34 + 0xc))(local_34,&local_2c,0,&local_38), iVar4 == 0)) &&
     (local_38 != 0)) {
    if (*(uint *)(iVar3 + 0x62) < local_38) {
      FUN_0056e1d0(*(undefined4 *)(iVar3 + 0x66));
      *(undefined4 *)(iVar3 + 0x66) = 0;
      *(uint *)(iVar3 + 0x62) = local_38 + 0x1000;
      iVar4 = FUN_0056e030(local_38 + 0x1000,
                           "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxSoundConvertWin.cpp",
                           0x633);
      *(int *)(iVar3 + 0x66) = iVar4;
      if (iVar4 == 0) goto LAB_005dd0c4;
    }
    FUN_0056d420(*(undefined4 *)(iVar3 + 0x66),local_2c,local_38);
    *(undefined4 *)(iVar3 + 0x6a) = 0;
    *(uint *)(iVar3 + 0x6e) = local_38;
    iVar4 = (**(code **)(*local_34 + 0x10))(local_34);
    if (iVar4 == 0) goto LAB_005dd0f3;
  }
LAB_005dd0c4:
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
    param_1 = (int *)0x0;
  }
LAB_005dd0d8:
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))(local_34);
  }
  return 0xffffffff;
}

