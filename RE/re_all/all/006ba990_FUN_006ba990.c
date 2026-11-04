
int FUN_006ba990(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int local_130;
  int *local_128;
  int *local_124;
  int *local_120;
  int local_11c;
  int local_110;
  int local_100 [61];
  int aiStack_c [3];
  
  iVar13 = 0;
  iVar2 = *(int *)(param_1 + 0xa8);
  iVar3 = *(int *)(param_1 + 0xd108);
  iVar4 = *(int *)(param_1 + 0xd8);
  iVar6 = 0;
  iVar10 = 0;
  local_120 = (int *)(param_3 + 0xfc);
  local_124 = (int *)(param_1 + 0xcb08);
  local_128 = (int *)(param_1 + 0xdc);
  local_130 = 0;
  local_110 = 0;
  do {
    iVar6 = iVar6 + *local_128;
    piVar7 = local_100;
    for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
      *piVar7 = 0;
      piVar7 = piVar7 + 1;
    }
    local_124[0xc0] = iVar10;
    *local_124 = local_130;
    local_11c = iVar10;
    if (iVar6 - iVar13 < iVar10) {
      local_11c = iVar6 - iVar13;
    }
    iVar10 = iVar10 - local_11c;
    if (0 < local_11c) {
      piVar7 = (int *)(iVar4 + iVar13 * 4);
      iVar13 = iVar13 + local_11c;
      iVar9 = local_11c;
      do {
        iVar5 = *piVar7;
        piVar7 = piVar7 + 1;
        puVar1 = (uint *)(iVar2 + iVar5 * 4);
        iVar9 = iVar9 + -1;
        *puVar1 = *puVar1 & 0xffff;
      } while (iVar9 != 0);
    }
    if (iVar13 < iVar6) {
      do {
        iVar10 = FUN_006bef60(param_1 + 0xc9b4,
                              *(undefined4 *)
                               (param_1 + 0xc9c8 + *(int *)(param_2 + (local_110 + 1 >> 1) * 4) * 4)
                             );
        *(char *)(local_130 + iVar3) = (char)iVar10;
        if (iVar10 < 0xf) {
          iVar9 = FUN_006bf0c0(param_1 + 0xc9b4,(&DAT_00831ec0)[iVar10]);
          *(char *)(local_130 + 1 + iVar3) = (char)iVar9;
          iVar5 = local_130 + 2;
          if (iVar10 == 0) {
            *(char *)(local_130 + 2 + iVar3) = (char)((uint)iVar9 >> 8);
            iVar5 = local_130 + 3;
          }
          local_130 = iVar5;
          iVar9 = iVar9 << ((-(iVar10 < 0xc) & 0x15U) + (-(iVar10 < 2) & 0xf3U) & 0x1f);
        }
        else {
          iVar9 = 0;
          local_130 = local_130 + 1;
        }
        uVar12 = *(int *)(&DAT_00831ed0 + iVar10 * 4) + iVar9;
        uVar11 = (int)uVar12 >> 8 & 0xfff;
        if (uVar12 == 0) {
          uVar11 = 0x7fffffff;
LAB_006bab2e:
          iVar9 = (-(uint)(iVar6 - iVar13 < (int)uVar11) & (iVar6 - uVar11) - iVar13) + uVar11;
          local_11c = local_11c + iVar9;
          iVar10 = uVar11 - iVar9;
          if (0 < iVar9) {
            piVar7 = (int *)(iVar4 + iVar13 * 4);
            iVar13 = iVar13 + iVar9;
            do {
              puVar1 = (uint *)(iVar2 + *piVar7 * 4);
              *puVar1 = *puVar1 & 0xffff;
              piVar7 = piVar7 + 1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
        }
        else {
          if (uVar11 != 0) goto LAB_006bab2e;
          uVar11 = uVar12 & 0xff;
          iVar10 = (int)(-(uVar12 & 0x100000) ^ uVar12) >> 0x15;
          if (uVar11 != 0) {
            iVar10 = 0;
          }
          local_100[uVar11] = local_100[uVar11] + 1;
          puVar1 = (uint *)(iVar2 + *(int *)(iVar4 + iVar13 * 4) * 4);
          iVar13 = iVar13 + 1;
          *puVar1 = iVar10 << 0x10 | *puVar1 & 0xffff;
          iVar10 = 0;
        }
      } while (iVar13 < iVar6);
    }
    piVar7 = aiStack_c + 1;
    aiStack_c[2] = aiStack_c[2] + local_11c;
    iVar9 = 0x3f;
    do {
      iVar9 = iVar9 + -1;
      *piVar7 = *piVar7 + piVar7[1];
      piVar7 = piVar7 + -1;
    } while (iVar9 != 0);
    iVar9 = 0x40;
    piVar8 = local_120;
    piVar7 = (int *)register0x00000010;
    do {
      piVar7 = piVar7 + -1;
      *piVar8 = *piVar8 - *piVar7;
      iVar9 = iVar9 + -1;
      piVar8 = piVar8 + -1;
    } while (iVar9 != 0);
    local_128 = local_128 + 1;
    local_110 = local_110 + 1;
    local_124 = local_124 + 0x40;
    local_120 = local_120 + 0x40;
    if (2 < local_110) {
      *(int *)(param_1 + 0xd110) = local_130;
      return iVar10;
    }
  } while( true );
}

