
undefined4
FUN_00521280(undefined4 *param_1,int param_2,undefined4 param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint local_20;
  int local_1c;
  undefined4 *local_18;
  int *local_14;
  
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  local_14 = (int *)0x0;
  if (param_4 == 0xfffffffb) {
    local_20 = DAT_00a37d78;
  }
  else {
    if (DAT_00cc47d0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_4 < 0) {
      return 0xffffffff;
    }
    if ((param_4 & 0x7c000000) != DAT_00cc47f8) {
      return 0xffffffff;
    }
    if (DAT_00cc4800 <= (int)(param_4 & 0xffff)) {
      return 0xffffffff;
    }
    local_14 = *(int **)(DAT_00cc47d4 + (param_4 & 0xffff) * 4);
    if (local_14 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*local_14 * 0x10000 != (param_4 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (local_14[4] != 0) {
      return 0xffffffff;
    }
    local_20 = (uint)*(byte *)(local_14[0x13] + 8);
    FUN_0057b670(local_14[0xd],0);
  }
  cVar5 = DAT_00a38116;
  cVar4 = DAT_00a38115;
  cVar3 = DAT_00a38114;
  if ((((DAT_00a38116 != -1) || (DAT_00a38115 != -1)) || (DAT_00a38114 != -1)) ||
     ((DAT_00a380cc != 0 && (DAT_00a380d0 != 0xff)))) {
    local_18 = &DAT_00d0a2e0 + DAT_00a380d0 * 0x100;
    if (DAT_00a380cc == 0) {
      local_18 = (undefined4 *)&DAT_00d49ee0;
    }
    iVar1 = param_2 * 0x1c;
    if (DAT_00a37f6c < iVar1) {
      if (DAT_00a37f70 != (undefined4 *)0x0) {
        FUN_0056e1d0(DAT_00a37f70);
        DAT_00a37f6c = 0;
      }
      DAT_00a37f70 = (undefined4 *)
                     FUN_0056e030(iVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",
                                  0x362d);
      if (DAT_00a37f70 == (undefined4 *)0x0) {
        return 0xffffffff;
      }
      DAT_00a37f6c = iVar1;
    }
    local_1c = 0;
    puVar13 = DAT_00a37f70;
    if (3 < param_2) {
      param_4 = (param_2 - 4U >> 2) + 1;
      local_1c = param_4 * 4;
      puVar9 = param_1;
      puVar12 = DAT_00a37f70;
      do {
        *puVar12 = *puVar9;
        puVar12[1] = puVar9[1];
        puVar12[2] = puVar9[2];
        puVar12[3] = puVar9[3];
        *(undefined1 *)(puVar12 + 4) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar3,*(undefined1 *)(puVar9 + 4)));
        *(undefined1 *)((int)puVar12 + 0x11) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar4,*(undefined1 *)((int)puVar9 + 0x11)));
        *(undefined1 *)((int)puVar12 + 0x12) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar5,*(undefined1 *)((int)puVar9 + 0x12)));
        *(undefined1 *)((int)puVar12 + 0x13) =
             *(undefined1 *)(local_18 + *(byte *)((int)puVar9 + 0x13));
        puVar12[5] = puVar9[5];
        puVar12[6] = puVar9[6];
        puVar12[7] = puVar9[7];
        puVar12[8] = puVar9[8];
        puVar12[9] = puVar9[9];
        puVar12[10] = puVar9[10];
        *(undefined1 *)(puVar12 + 0xb) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar3,*(undefined1 *)(puVar9 + 0xb)));
        *(undefined1 *)((int)puVar12 + 0x2d) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar4,*(undefined1 *)((int)puVar9 + 0x2d)));
        *(undefined1 *)((int)puVar12 + 0x2e) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar5,*(undefined1 *)((int)puVar9 + 0x2e)));
        *(undefined1 *)((int)puVar12 + 0x2f) =
             *(undefined1 *)(local_18 + *(byte *)((int)puVar9 + 0x2f));
        puVar12[0xc] = puVar9[0xc];
        puVar12[0xd] = puVar9[0xd];
        puVar12[0xe] = puVar9[0xe];
        puVar12[0xf] = puVar9[0xf];
        puVar12[0x10] = puVar9[0x10];
        puVar12[0x11] = puVar9[0x11];
        *(undefined1 *)(puVar12 + 0x12) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar3,*(undefined1 *)(puVar9 + 0x12)));
        *(undefined1 *)((int)puVar12 + 0x49) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar4,*(undefined1 *)((int)puVar9 + 0x49)));
        *(undefined1 *)((int)puVar12 + 0x4a) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar5,*(undefined1 *)((int)puVar9 + 0x4a)));
        *(undefined1 *)((int)puVar12 + 0x4b) =
             *(undefined1 *)(local_18 + *(byte *)((int)puVar9 + 0x4b));
        puVar12[0x13] = puVar9[0x13];
        puVar12[0x14] = puVar9[0x14];
        puVar12[0x15] = puVar9[0x15];
        puVar12[0x16] = puVar9[0x16];
        puVar12[0x17] = puVar9[0x17];
        puVar12[0x18] = puVar9[0x18];
        *(undefined1 *)(puVar12 + 0x19) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar3,*(undefined1 *)(puVar9 + 0x19)));
        *(undefined1 *)((int)puVar12 + 0x65) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar4,*(undefined1 *)((int)puVar9 + 0x65)));
        *(undefined1 *)((int)puVar12 + 0x66) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar5,*(undefined1 *)((int)puVar9 + 0x66)));
        *(undefined1 *)((int)puVar12 + 0x67) =
             *(undefined1 *)(local_18 + *(byte *)((int)puVar9 + 0x67));
        param_1 = puVar9 + 0x1c;
        puVar13 = puVar12 + 0x1c;
        param_4 = param_4 + -1;
        puVar12[0x1a] = puVar9[0x1a];
        puVar12[0x1b] = puVar9[0x1b];
        puVar9 = param_1;
        puVar12 = puVar13;
      } while (param_4 != 0);
    }
    if (local_1c < param_2) {
      param_4 = param_2 - local_1c;
      do {
        *puVar13 = *param_1;
        puVar13[1] = param_1[1];
        puVar13[2] = param_1[2];
        puVar13[3] = param_1[3];
        *(undefined1 *)(puVar13 + 4) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar3,*(undefined1 *)(param_1 + 4)));
        *(undefined1 *)((int)puVar13 + 0x11) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar4,*(undefined1 *)((int)param_1 + 0x11)));
        *(undefined1 *)((int)puVar13 + 0x12) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar5,*(undefined1 *)((int)param_1 + 0x12)));
        *(undefined1 *)((int)puVar13 + 0x13) =
             *(undefined1 *)(local_18 + *(byte *)((int)param_1 + 0x13));
        param_4 = param_4 + -1;
        puVar13[5] = param_1[5];
        puVar13[6] = param_1[6];
        param_1 = param_1 + 7;
        puVar13 = puVar13 + 7;
      } while (param_4 != 0);
    }
    param_1 = DAT_00a37f70;
  }
  if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
    FUN_005198b0();
  }
  uVar8 = DAT_00a381a0;
  uVar7 = DAT_00a3819c;
  uVar6 = DAT_00a38198;
  uVar11 = DAT_00a38194;
  if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (local_20 != 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
    if (DAT_00ca39f4 == 0) {
      if (local_20 == 0) {
        return 0;
      }
      uVar11 = FUN_00569110(param_1,param_2,param_3,local_14,param_5,0,0,0,0);
      return uVar11;
    }
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057b170(DAT_00a38194,DAT_00a38198,DAT_00a3819c,DAT_00a381a0);
  }
  if (bVar2) {
    FUN_00519580();
    uVar10 = FUN_00569110(param_1,param_2,param_3,local_14,param_5,0,0,0,0);
    FUN_00519650();
  }
  else if (local_20 == 0) {
    uVar10 = 0;
  }
  else {
    uVar10 = FUN_00569110(param_1,param_2,param_3,local_14,param_5,0,0,0,0);
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057ae10(uVar11,uVar6,uVar7,uVar8);
  }
  return uVar10;
}

