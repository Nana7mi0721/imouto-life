
undefined4 FUN_00571330(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  
  if (param_1[8] == 0) {
    return 1;
  }
  iVar2 = param_1[9];
  if (iVar2 == 0) {
    return 1;
  }
  if (iVar2 == 1) {
    iVar2 = thunk_FUN_005954e0(param_1[4]);
    if (iVar2 == 0) {
      return 0;
    }
    piVar1 = (int *)*param_1;
    iVar2 = param_1[1];
    if (*piVar1 == 0) {
      iVar9 = *(int *)(iVar2 + 0x30);
      iVar6 = *(int *)(iVar2 + 0x34);
      uVar8 = *(undefined4 *)(iVar2 + 0x3c);
      uVar7 = *(undefined4 *)(iVar2 + 0x38);
    }
    else if (*(ushort *)((int)piVar1 + 10) < 5) {
      iVar6 = param_1[0xb];
      iVar9 = param_1[10];
      uVar7 = *(undefined4 *)(iVar2 + 0x28);
      uVar8 = 0;
    }
    else {
      iVar9 = *(int *)(iVar2 + 0x24);
      uVar7 = *(undefined4 *)(iVar2 + 0x28);
      iVar6 = 0;
      uVar8 = 0;
    }
    FUN_0056e590(uVar7,uVar8,iVar9,iVar6,piVar1 + 0x216);
    FUN_00570180(param_1[3],param_1[2]);
    FUN_0056e1d0(param_1[3]);
    param_1[3] = 0;
    param_1[9] = 0;
    return 1;
  }
  if (iVar2 != 2) {
    return 1;
  }
  iVar2 = thunk_FUN_005954e0(param_1[4]);
  if (iVar2 == 0) {
    return 0;
  }
  piVar1 = (int *)*param_1;
  if (*piVar1 == 0) {
    iVar2 = param_1[1];
    uVar5 = *(uint *)(iVar2 + 0x30) - *(uint *)(iVar2 + 0x28);
    uVar3 = uVar5 - piVar1[4];
    iVar6 = uVar3 + param_1[10];
    iVar2 = ((((*(int *)(iVar2 + 0x34) - *(int *)(iVar2 + 0x2c)) -
              (uint)(*(uint *)(iVar2 + 0x30) < *(uint *)(iVar2 + 0x28))) - piVar1[5]) -
            (uint)(uVar5 < (uint)piVar1[4])) + param_1[0xb] + (uint)CARRY4(uVar3,param_1[10]);
  }
  else {
    if (4 < *(ushort *)((int)piVar1 + 10)) {
      uVar4 = *(int *)(param_1[1] + 0x20) + piVar1[4];
      uVar5 = *(uint *)(param_1[1] + 0x24);
      uVar3 = uVar5 - uVar4;
      FUN_0056e590(param_1[0xe],param_1[0xf],uVar3 + param_1[10],
                   (param_1[0xb] - (uint)(uVar5 < uVar4)) + (uint)CARRY4(uVar3,param_1[10]),
                   piVar1 + 0x216);
      param_1[9] = 0;
      return 1;
    }
    iVar2 = param_1[0xb];
    iVar6 = param_1[10];
  }
  FUN_0056e590(param_1[0xe],param_1[0xf],iVar6,iVar2,piVar1 + 0x216);
  param_1[9] = 0;
  return 1;
}

