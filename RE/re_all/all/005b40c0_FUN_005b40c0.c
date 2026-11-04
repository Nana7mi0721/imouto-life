
undefined4
FUN_005b40c0(int param_1,uint param_2,int param_3,uint param_4,uint param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  iVar7 = FUN_005d35f0();
  if ((iVar7 != 0) && (DAT_00e79688 != 1)) {
    FUN_005d3930();
    DAT_00e79688 = 1;
    DAT_00e399fc = 0;
  }
  if (DAT_00f3a04c != 0) {
    if (DAT_00e39a54 == 0) {
      if (DAT_00e39a50 == 0) goto LAB_005b4164;
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
    }
    DAT_00e39a1c = 1;
    DAT_00e39a00 = 1;
    if (DAT_00e39a50 != 0) {
      DAT_00e39a18 = 1;
    }
    DAT_00e39a50 = 0;
  }
LAB_005b4164:
  if (param_6 == 1) {
    uVar9 = -(uint)(param_7 != 0) & 0x880 | param_5 | 0x1000;
  }
  else {
    uVar9 = -(uint)(param_7 != 0) & 0x880 | param_5 | 0x5078;
  }
  if (param_11 == 0) {
    if (param_4 == 0) {
      if (DAT_00e39a4c != 0) {
        iVar7 = 0;
        goto LAB_005b4273;
      }
    }
    else {
      uVar6 = uVar9 | 0x8000;
      if (*(char *)(*(int *)(param_4 + 0x4c) + 10) != '\0') {
        uVar6 = uVar9 | 0x18000;
      }
      uVar9 = uVar6;
      if (*(char *)(*(int *)(param_4 + 0x4c) + 0x12) != '\0') {
        uVar9 = uVar9 | 0x20000;
      }
      piVar5 = (int *)**(undefined4 **)(param_4 + 0x100 + param_10 * 0x78);
      if (DAT_00e39a4c != *piVar5) {
        iVar7 = *piVar5;
        goto LAB_005b4273;
      }
    }
  }
  else {
    if (((((DAT_00cc79c0 == 0) || ((int)param_4 < 0)) || ((param_4 & 0x7c000000) != DAT_00cc79e8))
        || ((DAT_00cc79f0 <= (int)(param_4 & 0xffff) ||
            (piVar5 = *(int **)(DAT_00cc79c4 + (param_4 & 0xffff) * 4), piVar5 == (int *)0x0)))) ||
       ((*piVar5 * 0x10000 != (param_4 & 0x3ff0000) || (piVar5[4] != 0)))) goto LAB_005b429c;
    iVar7 = *(int *)piVar5[0x114];
    uVar9 = uVar9 | 0x8000;
LAB_005b4273:
    FUN_0059bcf0(iVar7);
  }
  if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != uVar9)) {
    FUN_005a7f60();
  }
LAB_005b429c:
  if (param_6 == 1) {
    uVar1 = *(undefined4 *)(param_4 + 0xc4);
    iVar7 = (int)param_2 / 6;
    uVar2 = *(undefined4 *)(param_4 + 200);
    uVar3 = *(undefined4 *)(param_4 + 0xf4);
    uVar4 = *(undefined4 *)(param_4 + 0xf8);
    if (0 < iVar7) {
      puVar8 = (undefined4 *)(param_1 + 0x68);
      while( true ) {
        if (param_8 == 0) {
          puVar8[-0x15] = uVar1;
          puVar8[-7] = uVar1;
          puVar8[-0xe] = uVar3;
          *puVar8 = uVar3;
        }
        else {
          puVar8[-0x15] = uVar3;
          puVar8[-7] = uVar3;
          puVar8[-0xe] = uVar1;
          *puVar8 = uVar1;
        }
        if (param_9 == 0) {
          puVar8[-0x14] = uVar2;
          puVar8[-0xd] = uVar2;
          puVar8[-6] = uVar4;
          puVar8[1] = uVar4;
        }
        else {
          puVar8[-0x14] = uVar4;
          puVar8[-0xd] = uVar4;
          puVar8[-6] = uVar2;
          puVar8[1] = uVar2;
        }
        iVar7 = iVar7 + -1;
        puVar8[7] = puVar8[-7];
        puVar8[8] = puVar8[-6];
        puVar8[0xe] = puVar8[-0xe];
        puVar8[0xf] = puVar8[-0xd];
        if (iVar7 == 0) break;
        puVar8 = puVar8 + 0x2a;
      }
    }
  }
  FUN_005a7ce0();
  if (param_3 == 4) {
    param_2 = (int)param_2 / 3;
  }
  else if (param_3 == 2) {
    param_2 = (int)param_2 / 2;
  }
  else if ((param_3 == 6) || (param_3 == 5)) {
    param_2 = param_2 - 2;
  }
  else if (param_3 == 3) {
    param_2 = param_2 - 1;
  }
  else {
    param_2 = ~-(uint)(param_3 != 1) & param_2;
  }
  FUN_005d3b40(param_3,param_2,param_1,0x1c);
  DAT_00a37de4 = DAT_00a37de4 + 1;
  return 0;
}

