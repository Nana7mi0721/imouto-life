
undefined4
FUN_005cf6a0(int param_1,int param_2,undefined4 param_3,uint param_4,uint param_5,int param_6,
            int param_7,int param_8,int param_9,int param_10,int param_11)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (param_6 == 1) {
    uVar8 = -(uint)(param_7 != 0) & 0x880 | param_5 | 0x1000;
  }
  else {
    uVar8 = -(uint)(param_7 != 0) & 0x880 | param_5 | 0x5000;
  }
  if (param_11 == 0) {
    if (param_4 == 0) {
      if (DAT_00ef7314 != 0) {
        uVar10 = 0;
        uVar9 = 0;
        goto LAB_005cf7fa;
      }
    }
    else {
      uVar4 = uVar8 | 0x8000;
      if (*(char *)(*(int *)(param_4 + 0x4c) + 10) != '\0') {
        uVar4 = uVar8 | 0x18000;
      }
      uVar8 = uVar4;
      if (*(char *)(*(int *)(param_4 + 0x4c) + 0x12) != '\0') {
        uVar8 = uVar8 | 0x20000;
      }
      if (DAT_00ef7314 != *(int *)(**(int **)(param_4 + 0x100 + param_10 * 0x78) + 4)) {
        iVar6 = **(int **)(param_4 + 0x100 + param_10 * 0x78);
        uVar10 = *(undefined4 *)(iVar6 + 8);
        uVar9 = *(undefined4 *)(iVar6 + 4);
        goto LAB_005cf7fa;
      }
    }
  }
  else {
    if (((((DAT_00cc79c0 == 0) || ((int)param_4 < 0)) || ((param_4 & 0x7c000000) != DAT_00cc79e8))
        || ((DAT_00cc79f0 <= (int)(param_4 & 0xffff) ||
            (piVar3 = *(int **)(DAT_00cc79c4 + (param_4 & 0xffff) * 4), piVar3 == (int *)0x0)))) ||
       ((*piVar3 * 0x10000 != (param_4 & 0x3ff0000) || (piVar3[4] != 0)))) goto LAB_005cf823;
    uVar10 = ((undefined4 *)piVar3[0x114])[1];
    uVar9 = *(undefined4 *)piVar3[0x114];
    uVar8 = uVar8 | 0x8000;
LAB_005cf7fa:
    FUN_005bc5b0(uVar9,uVar10);
  }
  if (((DAT_00a3d360 != 0) || (DAT_00ef72cc != 0)) || (DAT_00ef72c8 != uVar8)) {
    FUN_005bcf50();
  }
LAB_005cf823:
  if (param_6 == 1) {
    uVar10 = *(undefined4 *)(param_4 + 0xc4);
    iVar6 = param_2 / 6;
    uVar9 = *(undefined4 *)(param_4 + 200);
    uVar1 = *(undefined4 *)(param_4 + 0xf4);
    uVar2 = *(undefined4 *)(param_4 + 0xf8);
    if (0 < iVar6) {
      puVar5 = (undefined4 *)(param_1 + 0x68);
      while( true ) {
        if (param_8 == 0) {
          puVar5[-0x15] = uVar10;
          puVar5[-7] = uVar10;
          puVar5[-0xe] = uVar1;
          *puVar5 = uVar1;
        }
        else {
          puVar5[-0x15] = uVar1;
          puVar5[-7] = uVar1;
          puVar5[-0xe] = uVar10;
          *puVar5 = uVar10;
        }
        if (param_9 == 0) {
          puVar5[-0x14] = uVar9;
          puVar5[-0xd] = uVar9;
          puVar5[-6] = uVar2;
          puVar5[1] = uVar2;
        }
        else {
          puVar5[-0x14] = uVar2;
          puVar5[-0xd] = uVar2;
          puVar5[-6] = uVar9;
          puVar5[1] = uVar9;
        }
        iVar6 = iVar6 + -1;
        puVar5[7] = puVar5[-7];
        puVar5[8] = puVar5[-6];
        puVar5[0xe] = puVar5[-0xe];
        puVar5[0xf] = puVar5[-0xd];
        if (iVar6 == 0) break;
        puVar5 = puVar5 + 0x2a;
      }
    }
  }
  if ((DAT_00a37dcc == 0) && (0 < param_2)) {
    puVar7 = (uint *)(param_1 + 0x10);
    iVar6 = param_2;
    do {
      *puVar7 = (*puVar7 & 0xff) << 0x10 | (uint)*(byte *)((int)puVar7 + 2) | *puVar7 & 0xff00ff00;
      puVar7 = puVar7 + 7;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  FUN_005cba60(1,param_3,param_1,param_2,1);
  if ((DAT_00a37dcc == 0) && (0 < param_2)) {
    puVar7 = (uint *)(param_1 + 0x10);
    do {
      *puVar7 = (*puVar7 & 0xff) << 0x10 | (uint)*(byte *)((int)puVar7 + 2) | *puVar7 & 0xff00ff00;
      puVar7 = puVar7 + 7;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return 0;
}

