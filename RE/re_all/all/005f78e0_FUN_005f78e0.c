
undefined4 FUN_005f78e0(int param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  
  iVar1 = param_1;
  *(undefined4 *)(param_1 + 0x4a) = 0;
  if (*(int *)(param_1 + 0x468) == 0) {
    iVar3 = FUN_006a9020(param_1 + 0xc,param_1 + 0x52,0,0,&LAB_005f7b00,&LAB_005fa380,FUN_0060b400,
                         &LAB_005f7b30);
  }
  else {
    iVar3 = FUN_005f7b50(param_1 + 0xc,param_1 + 0x52,0,0,&LAB_005f7b00,&LAB_005fa380,FUN_0060b400,
                         &LAB_005f7b30);
  }
  iVar8 = param_1 + 0x52;
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x4a) = 1;
  if (*(int *)(param_1 + 0x468) == 0) {
    iVar3 = FUN_006ab580(iVar8,0xffffffff);
  }
  else {
    iVar3 = FUN_006ab580(iVar8,0xffffffff);
  }
  piVar4 = (int *)(param_1 + 0x468);
  iVar9 = -1;
  param_1 = -1;
  if (*piVar4 == 0) {
    piVar4 = (int *)FUN_006ab5c0(iVar8,0xffffffff);
  }
  else {
    piVar4 = (int *)FUN_006ab5c0(iVar8,0xffffffff);
  }
  iVar8 = 0;
  if (0 < piVar4[2]) {
    do {
      iVar5 = FUN_00577640(0x7ffd,*(undefined4 *)(*piVar4 + iVar8 * 4),s_LOOPSTART__00a05de4,10);
      if (iVar5 == 0) {
        iVar9 = FUN_0057a7b0(0x7ffd,*(int *)(*piVar4 + iVar8 * 4) + 10);
      }
      else {
        iVar5 = FUN_00577640(0x7ffd,*(undefined4 *)(*piVar4 + iVar8 * 4),s_LOOPLENGTH__00a05dd8,0xb)
        ;
        if (iVar5 == 0) {
          param_1 = FUN_0057a7b0(0x7ffd,*(int *)(*piVar4 + iVar8 * 4) + 0xb);
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < piVar4[2]);
    if (-1 < iVar9) {
      *(int *)(iVar1 + 0x326) = iVar9;
      if (param_1 < 1) {
        if (*(int *)(iVar1 + 0x468) == 0) {
          param_1 = FUN_006aa140(iVar1 + 0x52,0xffffffff);
        }
        else {
          param_1 = FUN_005f7870();
        }
      }
      else {
        param_1 = param_1 + iVar9;
      }
      goto LAB_005f7a84;
    }
    if (0 < param_1) {
      *(undefined4 *)(iVar1 + 0x326) = 0;
      goto LAB_005f7a84;
    }
  }
  param_1 = -1;
  *(undefined4 *)(iVar1 + 0x326) = 0xffffffff;
LAB_005f7a84:
  *(int *)(iVar1 + 0x32a) = param_1;
  *(undefined2 *)(iVar1 + 0x48) = 0;
  *(undefined2 *)(iVar1 + 0x38) = 1;
  *(undefined2 *)(iVar1 + 0x3a) = *(undefined2 *)(iVar3 + 4);
  *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(iVar3 + 8);
  sVar7 = (short)*(undefined4 *)(iVar1 + 0x464);
  uVar2 = *(short *)(iVar1 + 0x3a) * sVar7;
  *(ushort *)(iVar1 + 0x44) = uVar2;
  *(uint *)(iVar1 + 0x40) = (uint)uVar2 * *(int *)(iVar1 + 0x3c);
  *(short *)(iVar1 + 0x46) = sVar7 * 8;
  *(undefined4 *)(iVar1 + 0x322) = *(undefined4 *)(iVar1 + 0x464);
  *(undefined4 *)(iVar1 + 0x450) = 0x1000;
  uVar6 = FUN_005fa1c0(iVar1);
  *(undefined4 *)(iVar1 + 8) = 1;
  *(undefined4 *)(iVar1 + 0x34) = uVar6;
  return 0;
}

