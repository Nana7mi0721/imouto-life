
uint FUN_006bac80(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  uint *local_11c;
  int *local_118;
  int local_114;
  int local_110;
  int local_100 [61];
  int aiStack_c [3];
  
  iVar1 = *(int *)(param_1 + 0xd108);
  iVar10 = *(int *)(param_1 + 0xd110);
  local_110 = 0;
  local_114 = 0;
  local_11c = (uint *)(param_4 + param_2 * 4);
  local_118 = (int *)(param_1 + 0xcb08 + param_2 * 4);
  do {
    local_118[0xc0] = param_5;
    *local_118 = iVar10;
    iVar9 = 0;
    uVar2 = *local_11c;
    piVar5 = local_100;
    for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar5 = 0;
      piVar5 = piVar5 + 1;
    }
    iVar6 = 0;
    if (param_5 < uVar2) {
      iVar7 = iVar10;
      do {
        iVar6 = iVar6 + param_5;
        iVar9 = iVar9 + param_5;
        iVar3 = FUN_006bef60(param_1 + 0xc9b4,
                             *(undefined4 *)
                              (param_1 + 0xc9c8 + *(int *)(param_3 + (local_110 + 1 >> 1) * 4) * 4))
        ;
        *(char *)(iVar7 + iVar1) = (char)iVar3;
        iVar10 = iVar7 + 1;
        if (iVar3 < 0xf) {
          iVar4 = FUN_006bf0c0(param_1 + 0xc9b4,(&DAT_00831ec0)[iVar3]);
          *(char *)(iVar10 + iVar1) = (char)iVar4;
          iVar10 = iVar7 + 2;
          if (iVar3 == 0) {
            *(char *)(iVar10 + iVar1) = (char)((uint)iVar4 >> 8);
            iVar10 = iVar7 + 3;
          }
          iVar4 = iVar4 << ((-(iVar3 < 0xc) & 0x15U) + (-(iVar3 < 2) & 0xf3U) & 0x1f);
        }
        else {
          iVar4 = 0;
        }
        uVar8 = *(int *)(&DAT_00831ed0 + iVar3 * 4) + iVar4;
        param_5 = (int)uVar8 >> 8 & 0xfff;
        if (uVar8 == 0) {
          param_5 = 0x7fffffff;
        }
        else if (param_5 == 0) {
          iVar6 = iVar6 + 1;
          local_100[uVar8 & 0xff] = local_100[uVar8 & 0xff] + 1;
        }
        iVar7 = iVar10;
      } while (iVar6 + param_5 < uVar2);
    }
    param_5 = param_5 + (iVar6 - uVar2);
    iVar7 = 0x3f;
    aiStack_c[2] = aiStack_c[2] + (iVar9 - iVar6) + uVar2;
    piVar5 = aiStack_c + 1;
    do {
      iVar7 = iVar7 + -1;
      *piVar5 = *piVar5 + piVar5[1];
      piVar5 = piVar5 + -1;
    } while (iVar7 != 0);
    iVar9 = -param_2 + 0x40;
    iVar6 = -param_2 + 0x3f;
    if (0 < iVar9) {
      piVar11 = local_100 + iVar6;
      piVar5 = (int *)(param_4 + (local_114 + iVar6 + param_2) * 4);
      do {
        iVar9 = iVar9 + -1;
        *piVar5 = *piVar5 - *piVar11;
        piVar11 = piVar11 + -1;
        piVar5 = piVar5 + -1;
      } while (iVar9 != 0);
    }
    local_110 = local_110 + 1;
    local_114 = local_114 + 0x40;
    local_118 = local_118 + 0x40;
    local_11c = local_11c + 0x40;
  } while (local_114 < 0xc0);
  *(int *)(param_1 + 0xd110) = iVar10;
  return param_5;
}

