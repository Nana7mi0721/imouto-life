
undefined4 FUN_0051ba30(int *param_1)

{
  uint uVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  if (DAT_00a49730 != 0) {
    if (DAT_00a37fd0 != 0) {
      return 0;
    }
    if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
      FUN_0050e770();
    }
    if ((((DAT_00cc47d0 != 0) && (uVar1 = param_1[2], -1 < (int)uVar1)) &&
        ((uVar1 & 0x7c000000) == DAT_00cc47f8)) &&
       ((((int)(uVar1 & 0xffff) < DAT_00cc4800 &&
         (piVar2 = *(int **)(DAT_00cc47d4 + (uVar1 & 0xffff) * 4), piVar2 != (int *)0x0)) &&
        ((*piVar2 * 0x10000 == (uVar1 & 0x3ff0000) && (piVar2[4] == 0)))))) {
      local_24 = 0;
      if (0 < (int)DAT_00a380d4) {
        if (((-1 < (int)DAT_00a380d4) && ((DAT_00a380d4 & 0x7c000000) == DAT_00cc47f8)) &&
           ((int)(DAT_00a380d4 & 0xffff) < DAT_00cc4800)) {
          local_24 = *(undefined4 *)(DAT_00cc47d4 + (DAT_00a380d4 & 0xffff) * 4);
        }
        iVar4 = FUN_00514e90();
        if (iVar4 != 0) {
          return 0xffffffff;
        }
      }
      if (piVar2[0xd] != -1) {
        FUN_0057b670(piVar2[0xd],0);
      }
      if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
        FUN_005198b0();
      }
      if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (*(char *)(piVar2[0x13] + 8) != '\0')) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
        if (DAT_00ca39f4 == 0) {
          if (*(char *)(piVar2[0x13] + 8) == '\0') {
            return 0;
          }
          uVar7 = FUN_00568fd0(param_1,piVar2,local_24);
          return uVar7;
        }
      }
      local_18 = *param_1 * 4;
      iVar8 = 0;
      iVar4 = 0xfffffff;
      local_1c = 0;
      local_20 = 0xfffffff;
      if (0 < local_18) {
        iVar9 = 0;
        do {
          iVar5 = FUN_0050e270(*(undefined4 *)(param_1[1] + iVar9));
          iVar6 = FUN_0050e270(*(undefined4 *)(param_1[1] + 4 + iVar9));
          if (iVar8 < iVar5) {
            iVar8 = iVar5;
          }
          if (local_1c < iVar6) {
            local_1c = iVar6;
          }
          if (iVar5 < local_20) {
            local_20 = iVar5;
          }
          if (iVar6 < iVar4) {
            iVar4 = iVar6;
          }
          iVar9 = iVar9 + 0x10;
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
      if (DAT_00ca39f4 != 0) {
        FUN_0057b170(local_20,iVar4,iVar8,local_1c);
      }
      if (bVar3) {
        FUN_00519580();
        uVar7 = FUN_00568fd0(param_1,piVar2,local_24);
        FUN_00519650();
      }
      else if (*(char *)(piVar2[0x13] + 8) == '\0') {
        uVar7 = 0;
      }
      else {
        uVar7 = FUN_00568fd0(param_1,piVar2,local_24);
      }
      if (DAT_00ca39f4 != 0) {
        FUN_0057ae10(local_20,iVar4,iVar8,local_1c);
      }
      return uVar7;
    }
  }
  return 0xffffffff;
}

