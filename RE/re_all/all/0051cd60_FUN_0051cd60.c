
undefined4
FUN_0051cd60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10)

{
  int *piVar1;
  bool bVar2;
  uint in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  undefined4 local_28;
  
  if (DAT_00a37fd0 != 0) {
    return 0;
  }
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if ((((DAT_00cc47d0 == 0) || ((int)in_EAX < 0)) || ((in_EAX & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(in_EAX & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc47d4 + (in_EAX & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (in_EAX & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  local_28 = 0;
  if (0 < (int)DAT_00a380d4) {
    if (((-1 < (int)DAT_00a380d4) && ((DAT_00a380d4 & 0x7c000000) == DAT_00cc47f8)) &&
       ((int)(DAT_00a380d4 & 0xffff) < DAT_00cc4800)) {
      local_28 = *(undefined4 *)(DAT_00cc47d4 + (DAT_00a380d4 & 0xffff) * 4);
    }
    iVar3 = FUN_00514e90();
    if (iVar3 != 0) {
      return 0xffffffff;
    }
  }
  if (piVar1[0xd] != -1) {
    FUN_0057b670(piVar1[0xd],0);
  }
  if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
    FUN_005198b0();
  }
  if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (*(char *)(piVar1[0x13] + 8) != '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
    if (DAT_00ca39f4 == 0) {
      if (*(char *)(piVar1[0x13] + 8) == '\0') {
        uVar12 = FUN_005154c0(param_1,param_2,param_3,param_4,param_7,param_8,param_5,param_6,piVar1
                              ,param_9);
        return uVar12;
      }
      uVar12 = FUN_00568f00(param_1,param_2,param_3,param_4,param_7,param_8,param_5,param_6,piVar1,
                            local_28,param_9,param_10);
      return uVar12;
    }
  }
  iVar4 = FUN_0050e270(param_1);
  iVar5 = FUN_0050e270(param_3);
  iVar6 = FUN_0050e270(param_5);
  iVar7 = FUN_0050e270(param_7);
  iVar8 = FUN_0050e270(param_2);
  iVar9 = FUN_0050e270(param_4);
  iVar10 = FUN_0050e270(param_6);
  iVar11 = FUN_0050e270(param_8);
  iVar3 = 0;
  if (0 < iVar4) {
    iVar3 = iVar4;
  }
  iVar14 = 0;
  if (0 < iVar8) {
    iVar14 = iVar8;
  }
  iVar13 = 0xfffffff;
  if (iVar4 < 0xfffffff) {
    iVar13 = iVar4;
  }
  iVar4 = 0xfffffff;
  if (iVar8 < 0xfffffff) {
    iVar4 = iVar8;
  }
  if (iVar3 < iVar5) {
    iVar3 = iVar5;
  }
  if (iVar14 < iVar9) {
    iVar14 = iVar9;
  }
  if (iVar5 < iVar13) {
    iVar13 = iVar5;
  }
  if (iVar9 < iVar4) {
    iVar4 = iVar9;
  }
  if (iVar3 < iVar6) {
    iVar3 = iVar6;
  }
  if (iVar14 < iVar10) {
    iVar14 = iVar10;
  }
  if (iVar6 < iVar13) {
    iVar13 = iVar6;
  }
  if (iVar10 < iVar4) {
    iVar4 = iVar10;
  }
  if (iVar3 < iVar7) {
    iVar3 = iVar7;
  }
  if (iVar14 < iVar11) {
    iVar14 = iVar11;
  }
  if (iVar7 < iVar13) {
    iVar13 = iVar7;
  }
  if (iVar11 < iVar4) {
    iVar4 = iVar11;
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057b170(iVar13,iVar4,iVar3,iVar14);
  }
  if (bVar2) {
    FUN_00519580();
    uVar12 = FUN_00568f00(param_1,param_2,param_3,param_4,param_7,param_8,param_5,param_6,piVar1,
                          local_28,param_9,param_10);
    FUN_00519650();
  }
  else if (*(char *)(piVar1[0x13] + 8) == '\0') {
    uVar12 = FUN_005154c0(param_1,param_2,param_3,param_4,param_7,param_8,param_5,param_6,piVar1,
                          param_9);
  }
  else {
    uVar12 = FUN_00568f00(param_1,param_2,param_3,param_4,param_7,param_8,param_5,param_6,piVar1,
                          local_28,param_9,param_10);
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057ae10(iVar13,iVar4,iVar3,iVar14);
  }
  return uVar12;
}

