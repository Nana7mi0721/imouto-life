
void FUN_006ba390(int param_1)

{
  int iVar1;
  char cVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  int iVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined2 *puVar19;
  int iVar20;
  undefined *local_48;
  int *local_44;
  int local_40;
  int local_34;
  uint local_24;
  int *local_20;
  undefined2 local_10 [4];
  undefined2 local_8 [4];
  
  pcVar3 = (code *)(&PTR_LAB_00832290)[*(int *)(param_1 + 0x30)];
  iVar1 = param_1 + 0xc9b4;
  iVar13 = FUN_006bf110(iVar1);
  local_48 = &DAT_008321fc;
  if (iVar13 == 0) {
    local_48 = &DAT_00832130;
  }
  iVar13 = *(int *)(param_1 + 0x30);
  iVar4 = *(int *)(param_1 + 0xa8);
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar17 = (uint)(byte)(&DAT_00831e64)[iVar13];
  piVar6 = *(int **)(param_1 + 0xc4);
  iVar7 = *(int *)(param_1 + 200);
  uVar8 = *(uint *)(param_1 + 0xd4);
  uVar11 = 0;
  uVar10 = 0;
  local_24 = 0;
  if (uVar8 != 0) {
    local_40 = 0;
    local_20 = piVar6;
    uVar14 = 0;
    do {
      cVar2 = *(char *)(local_24 + iVar7);
      uVar18 = (uint)cVar2;
      uVar15 = uVar14;
      if (uVar18 != 0xffffffff) {
        if (uVar18 == 7) {
          puVar19 = local_10;
          local_34 = 4;
          local_44 = local_20;
          do {
            iVar20 = *local_44;
            uVar18 = *(uint *)(iVar4 + iVar20 * 4);
            if ((uVar18 & 1) == 0) {
              *puVar19 = 0;
            }
            else {
              *(uint *)(iVar4 + iVar20 * 4) = uVar18 & 0xffffff7f | 0x740;
              uVar11 = FUN_006ba650(iVar1,local_48);
              *puVar19 = uVar11;
              *(undefined2 *)(iVar5 + iVar20 * 2) = uVar11;
            }
            local_44 = local_44 + 1;
            puVar19 = puVar19 + 1;
            local_34 = local_34 + -1;
          } while (local_34 != 0);
          (*pcVar3)(local_8,local_10);
          iVar20 = 4;
          uVar15 = uVar11;
          uVar10 = uVar14;
          if (4 < uVar17) {
            do {
              uVar18 = (uint)(byte)(&DAT_00831e34)[iVar20 + iVar13 * 0xc];
              uVar16 = uVar18 & 3;
              iVar9 = piVar6[uVar16 + (((int)uVar18 >> 2) + local_40) * 4];
              uVar18 = *(uint *)(iVar4 + iVar9 * 4);
              if ((uVar18 & 1) != 0) {
                *(uint *)(iVar4 + iVar9 * 4) = uVar18 & 0xffffff7f | 0x740;
                *(undefined2 *)(iVar5 + iVar9 * 2) = local_8[uVar16];
              }
              iVar20 = iVar20 + 1;
            } while (iVar20 < (int)uVar17);
          }
        }
        else {
          switch(uVar18) {
          case 2:
            uVar12 = FUN_006ba650(iVar1,local_48);
            uVar11 = uVar12;
            break;
          case 3:
            uVar12 = uVar14;
            uVar14 = uVar10;
            break;
          case 4:
            uVar12 = uVar10;
            uVar11 = uVar10;
            break;
          default:
            uVar12 = 0;
            uVar14 = uVar10;
            break;
          case 6:
            uVar12 = FUN_006ba650(iVar1,local_48);
            uVar14 = uVar10;
          }
          local_44 = (int *)0x0;
          do {
            uVar16 = (uint)(byte)(&DAT_00831e34)[(int)local_44 + iVar13 * 0xc];
            iVar20 = piVar6[(uVar16 & 3) + (((int)uVar16 >> 2) + local_40) * 4];
            uVar16 = *(uint *)(iVar4 + iVar20 * 4);
            if ((uVar16 & 1) != 0) {
              *(uint *)(iVar4 + iVar20 * 4) =
                   ((uVar18 & 7) << 2 | 0x10011121 >> (cVar2 * '\x04' & 0x1fU) & 3U) << 6 |
                   uVar16 & 0xfffff83f;
              *(undefined2 *)(iVar5 + iVar20 * 2) = uVar12;
            }
            local_44 = (int *)((int)local_44 + 1);
            uVar15 = uVar11;
            uVar10 = uVar14;
          } while ((int)local_44 < (int)uVar17);
        }
      }
      local_24 = local_24 + 1;
      local_20 = local_20 + 0xc;
      local_40 = local_40 + 3;
      uVar14 = uVar15;
    } while (local_24 < uVar8);
  }
  return;
}

