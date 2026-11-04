
void FUN_005b45e0(uint param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 local_1b4;
  undefined4 local_1b0;
  int local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  int local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  int local_184;
  int local_17c [95];
  
  if ((DAT_00e39a4c != 0) && (DAT_00f3a04c != 0)) {
    if ((DAT_00e39a54 == 0) && (FUN_00568ca0(0), DAT_00dda46c != 0)) {
      FUN_00584d70();
    }
    DAT_00e39a1c = 1;
    if (DAT_00e39a4c != 0) {
      DAT_00e39a18 = 1;
    }
    DAT_00e39a4c = 0;
    DAT_00e39a00 = 1;
  }
  if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != (param_1 | 0x7500))) {
    FUN_005a7f60();
  }
  if (param_4 == 0) {
    uVar4 = 9;
  }
  else {
    uVar4 = 3;
  }
  FUN_0059c240(&DAT_00ddb600,uVar4);
  if (DAT_00f3a04c != 0) {
    if ((DAT_00e80628 != 0) || (DAT_00e39a54 != 0)) {
      FUN_005d3bd0(0);
      DAT_00e80628 = 0;
    }
    DAT_00e80614 = 0;
    DAT_00e39a00 = 1;
  }
  local_1a4 = 0;
  local_190 = 0xffffffff;
  local_18c = 0xffffffff;
  local_188 = 0xffffffff;
  local_1b4 = 1;
  if (DAT_00a380ec == -1) {
    local_1b0 = 0;
    local_1ac = 5;
  }
  else {
    local_1ac = DAT_00a380ec;
    local_1b0 = DAT_00a380f0;
  }
  if ((DAT_00a380cc == 0) || (local_1a8 = 1, DAT_00a380cc == 6)) {
    local_1a8 = 0;
  }
  iVar2 = DAT_00a380cc * 0x1c;
  local_198 = *(undefined4 *)(&DAT_007da400 + iVar2);
  local_19c = *(undefined4 *)(&DAT_007da404 + iVar2);
  local_194 = *(int *)(&DAT_007da40c + iVar2);
  if ((DAT_00a380cc == 3) && (DAT_00ddb4bc != 0)) {
    local_198 = 2;
    local_19c = 5;
    local_194 = DAT_00a380cc;
  }
  local_1a0 = 0xffffffff;
  local_184 = 0;
  iVar2 = 0;
  piVar3 = local_17c;
  do {
    iVar1 = (&DAT_00a38d78)[iVar2];
    piVar3[-1] = iVar1;
    *piVar3 = iVar2;
    if (iVar1 != 0) {
      local_184 = iVar2 + 1;
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 6;
  } while (iVar2 < 0x10);
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  FUN_005a0d80(&local_1b4,1,1,1);
  DAT_00e39a18 = 1;
  DAT_00e39a1c = 1;
  DAT_00e39a00 = 1;
  FUN_0059b980();
  if (-1 < param_2) {
    iVar2 = (&DAT_00e3991c)[param_2];
    if (DAT_00f3a04c != 0) {
      if ((DAT_00e80628 != iVar2) || (DAT_00e39a54 != 0)) {
        FUN_005d3bd0(iVar2);
        DAT_00e80628 = iVar2;
      }
      DAT_00e80614 = 0;
      DAT_00e39a00 = 1;
    }
    FUN_005a0ca0(DAT_00a38dd8);
    goto LAB_005b48b6;
  }
  iVar2 = DAT_00e39a54;
  if (DAT_00e8061c == 0) {
    if ((DAT_00e39a54 == 0) && (DAT_00e8062c == 0)) {
      iVar2 = DAT_00e80628;
      goto LAB_005b484c;
    }
LAB_005b484e:
    if (DAT_00f3a04c != 0) {
      if ((DAT_00e39a54 == 0) && (DAT_00e8062c == 0)) {
LAB_005b4875:
        if (DAT_00e80628 != 0) goto LAB_005b487d;
      }
      else {
        FUN_005d3c30(0);
        DAT_00e8062c = 0;
        if (DAT_00e39a54 == 0) goto LAB_005b4875;
LAB_005b487d:
        FUN_005d3bd0(0);
        DAT_00e80628 = 0;
      }
      DAT_00e8061c = 0;
      DAT_00e80614 = 0;
      DAT_00e39a00 = 1;
    }
  }
  else {
LAB_005b484c:
    if (iVar2 != 0) goto LAB_005b484e;
  }
  FUN_005a7ce0();
LAB_005b48b6:
  FUN_005a0d10(DAT_00a38ddc);
  return;
}

