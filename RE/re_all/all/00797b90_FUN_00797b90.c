
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

int FUN_00797b90(int *param_1,int param_2,int param_3,undefined4 param_4,code *param_5,int param_6,
                undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  int aiStack_44 [2];
  int *piStack_3c;
  undefined4 uStack_38;
  int *piStack_34;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  piStack_34 = &local_10;
  uStack_38 = 0xfbd;
  piStack_3c = param_1;
  local_14 = 0;
  aiStack_44[1] = 0x797bb2;
  FUN_00797f60();
  iVar8 = (local_10 / 0x19) * 3;
  if (iVar8 <= param_6) {
    param_6 = iVar8;
  }
  iVar3 = param_6;
  piStack_34 = (int *)0x797be9;
  iVar8 = param_6 * -2;
  iVar16 = param_6 * -2;
  iVar2 = param_6 * -2;
  (&piStack_34)[param_6 * -2] = (int *)0x2;
  local_8 = param_1 + 0x43;
  aiStack_44[param_6 * -2 + 3] = 0x797bfc;
  iVar5 = FUN_00798960();
  aiStack_44[param_6 * -2 + 3] = 1;
  aiStack_44[param_6 * -2 + 2] = 0x797c06;
  iVar6 = FUN_00798960();
  piVar14 = aiStack_44 + param_6 * -2 + 5;
  if (param_3 == 0) {
    local_14 = 1;
  }
  else {
    if (param_3 < 0) {
      return -1;
    }
    iVar7 = param_1[1];
    if (param_3 < iVar7 * 2 + -1) {
      return -4;
    }
    (&piStack_34)[param_6 * -2] = (int *)local_10;
    aiStack_44[param_6 * -2 + 3] = iVar7;
    aiStack_44[param_6 * -2 + 2] = param_3;
    aiStack_44[param_6 * -2 + 1] = param_2;
    aiStack_44[param_6 * -2] = 0x797c61;
    iVar7 = FUN_00797e20();
    piVar14 = aiStack_44 + param_6 * -2 + 5;
    if (iVar7 < 0) {
      return iVar7;
    }
    if (param_6 < iVar7) {
      return -2;
    }
  }
  iVar7 = param_1[1];
  iVar15 = 0;
  if (0 < iVar7) {
    do {
      piVar4 = local_8;
      if (iVar15 < param_1[2]) {
        iVar1 = iVar5;
      }
      else {
        iVar1 = iVar6;
      }
      local_8 = (int *)((int)local_8 + (iVar1 + 3U & 0xfffffffc));
      if ((local_14 == 0) && (param_3 < 1)) {
        return -3;
      }
      *(undefined4 *)((int)piVar14 + -4) = param_8;
      local_18 = 0;
      *(int **)((int)piVar14 + -8) = &local_18;
      *(uint *)((int)piVar14 + -0xc) = (uint)(iVar15 != iVar7 + -1);
      *(undefined4 *)((int)piVar14 + -0x10) = param_7;
      *(int *)((int)piVar14 + -0x14) = param_6;
      *(int **)((int)piVar14 + -0x18) = aiStack_44 + iVar8 + 5;
      *(int *)((int)piVar14 + -0x1c) = param_3;
      *(int *)((int)piVar14 + -0x20) = param_2;
      *(int **)((int)piVar14 + -0x24) = piVar4;
      *(undefined4 *)((int)piVar14 + -0x28) = 0x797cec;
      param_6 = FUN_00798ad0();
      param_2 = param_2 + local_18;
      param_3 = param_3 - local_18;
      if (param_6 < 1) {
        return param_6;
      }
      iVar7 = param_1[2];
      local_c = param_6;
      *(undefined4 *)((int)piVar14 + -4) = 0xffffffff;
      *(int *)((int)piVar14 + -8) = iVar15;
      *(int **)((int)piVar14 + -0xc) = param_1;
      if (iVar15 < iVar7) {
        *(undefined4 *)((int)piVar14 + -0x10) = 0x797d1d;
        iVar7 = FUN_00799b60();
        puVar10 = (undefined1 *)piVar14;
        while (iVar7 != -1) {
          iVar1 = *param_1;
          *(int *)(puVar10 + -4) = local_c;
          *(undefined4 *)(puVar10 + -8) = 2;
          *(int **)(puVar10 + -0xc) = aiStack_44 + iVar16 + 5;
          *(int *)(puVar10 + -0x10) = iVar7;
          *(int *)(puVar10 + -0x14) = iVar1;
          *(undefined4 *)(puVar10 + -0x18) = param_4;
          puVar9 = puVar10 + -0x1c;
          *(undefined4 *)(puVar10 + -0x1c) = 0x797d3c;
          (*param_5)();
          *(int *)(puVar9 + -4) = iVar7;
          *(int *)(puVar9 + -8) = iVar15;
          *(int **)(puVar9 + -0xc) = param_1;
          *(undefined4 *)(puVar9 + -0x10) = 0x797d44;
          iVar7 = FUN_00799b60();
          puVar10 = puVar9 + 0x18;
        }
        *(undefined4 *)(puVar10 + -4) = 0xffffffff;
        *(int *)(puVar10 + -8) = iVar15;
        *(int **)(puVar10 + -0xc) = param_1;
        *(undefined4 *)(puVar10 + -0x10) = 0x797d57;
        iVar7 = FUN_00799ba0();
        piVar14 = (int *)puVar10;
        if (iVar7 != -1) {
          do {
            iVar1 = *param_1;
            *(int *)(puVar10 + -4) = local_c;
            *(undefined4 *)(puVar10 + -8) = 2;
            *(int **)(puVar10 + -0xc) = aiStack_44 + iVar3 * -2 + 6;
            *(int *)(puVar10 + -0x10) = iVar7;
            *(int *)(puVar10 + -0x14) = iVar1;
            *(undefined4 *)(puVar10 + -0x18) = param_4;
            puVar11 = puVar10 + -0x1c;
            *(undefined4 *)(puVar10 + -0x1c) = 0x797d7f;
            (*param_5)();
            *(int *)(puVar11 + -4) = iVar7;
            *(int *)(puVar11 + -8) = iVar15;
            *(int **)(puVar11 + -0xc) = param_1;
            *(undefined4 *)(puVar11 + -0x10) = 0x797d87;
            iVar7 = FUN_00799ba0();
            puVar10 = puVar11 + 0x18;
            piVar14 = (int *)(puVar11 + 0x18);
          } while (iVar7 != -1);
        }
      }
      else {
        *(undefined4 *)((int)piVar14 + -0x10) = 0x797d98;
        iVar7 = FUN_00799be0();
        while (iVar7 != -1) {
          iVar1 = *param_1;
          *(int *)((int)piVar14 + -4) = local_c;
          *(undefined4 *)((int)piVar14 + -8) = 1;
          *(int **)((int)piVar14 + -0xc) = aiStack_44 + iVar2 + 5;
          *(int *)((int)piVar14 + -0x10) = iVar7;
          *(int *)((int)piVar14 + -0x14) = iVar1;
          *(undefined4 *)((int)piVar14 + -0x18) = param_4;
          puVar12 = (undefined1 *)((int)piVar14 + -0x1c);
          *(undefined4 *)((int)piVar14 + -0x1c) = 0x797db7;
          (*param_5)();
          *(int *)(puVar12 + -4) = iVar7;
          *(int *)(puVar12 + -8) = iVar15;
          *(int **)(puVar12 + -0xc) = param_1;
          *(undefined4 *)(puVar12 + -0x10) = 0x797dbf;
          iVar7 = FUN_00799be0();
          piVar14 = (int *)(puVar12 + 0x18);
        }
      }
      iVar7 = param_1[1];
      iVar15 = iVar15 + 1;
    } while (iVar15 < iVar7);
  }
  iVar8 = *param_1;
  iVar16 = 0;
  if (0 < iVar8) {
    do {
      if (*(char *)((int)param_1 + iVar16 + 0xc) == -1) {
        *(int *)((int)piVar14 + -4) = param_6;
        *(undefined4 *)((int)piVar14 + -8) = 0;
        *(undefined4 *)((int)piVar14 + -0xc) = 0;
        *(int *)((int)piVar14 + -0x10) = iVar16;
        *(int *)((int)piVar14 + -0x14) = iVar8;
        *(undefined4 *)((int)piVar14 + -0x18) = param_4;
        puVar13 = (undefined1 *)((int)piVar14 + -0x1c);
        *(undefined4 *)((int)piVar14 + -0x1c) = 0x797df6;
        (*param_5)();
        piVar14 = (int *)(puVar13 + 0x18);
      }
      iVar8 = *param_1;
      iVar16 = iVar16 + 1;
    } while (iVar16 < iVar8);
  }
  return param_6;
}

