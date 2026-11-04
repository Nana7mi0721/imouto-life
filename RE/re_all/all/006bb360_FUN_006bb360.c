
void FUN_006bb360(int param_1,short *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  short *psVar9;
  int iVar10;
  uint uVar11;
  short sVar12;
  undefined2 *puVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int *local_30;
  int local_24;
  undefined2 local_8 [2];
  int local_4;
  
  local_30 = (int *)0x2;
  iVar2 = *(int *)(param_1 + 0x40);
  iVar3 = *(int *)(param_1 + 0xa8);
  iVar4 = *(int *)(param_2 + param_3 * 2 + 0x58c);
  iVar5 = *(int *)(param_1 + 0xd108);
  iVar15 = param_3 + 8;
  psVar9 = param_2 + param_3 * 0xc + 0x598;
  puVar13 = local_8;
  do {
    puVar6 = *(undefined2 **)psVar9;
    psVar9 = psVar9 + 2;
    *puVar13 = *puVar6;
    local_30 = (int *)((int)local_30 + -1);
    puVar13 = puVar13 + 1;
  } while (local_30 != (int *)0x0);
  if (0 < iVar4) {
    local_30 = *(int **)(param_2 + param_3 * 2 + 0x580);
    local_24 = iVar4;
    do {
      iVar7 = *local_30;
      uVar16 = *(uint *)(iVar3 + iVar7 * 4);
      uVar14 = (uint)((uVar16 & 0x700) != 0x100);
      iVar8 = *(int *)(param_2 + (uVar14 + 0x2cc + ((uVar16 >> 2 & 0xf) + param_3 * 3) * 2) * 2);
      iVar10 = 0;
      do {
        local_4 = iVar10;
        if (*(int *)(param_2 + iVar15 * 0x80 + local_4 * 2) != 0) {
          *(int *)(param_2 + iVar15 * 0x80 + local_4 * 2) =
               *(int *)(param_2 + iVar15 * 0x80 + local_4 * 2) + -1;
          break;
        }
        iVar10 = *(int *)(param_2 + (param_3 + 2) * 0x80 + local_4 * 2);
        bVar1 = *(byte *)(iVar10 + iVar5);
        iVar17 = iVar10 + 1;
        uVar16 = *(uint *)(&DAT_00831ed0 + (uint)bVar1 * 4);
        if (bVar1 < 0xf) {
          uVar16 = uVar16 + ((uint)*(byte *)(iVar17 + iVar5) <<
                            ((-(bVar1 < 0xc) & 0x15U) + (-(bVar1 < 2) & 0xf3U) & 0x1f));
          iVar17 = iVar10 + 2;
        }
        uVar11 = (int)uVar16 >> 8 & 0xfff;
        if (bVar1 == 0) {
          uVar11 = uVar11 + (uint)*(byte *)(iVar17 + iVar5) * 0x100;
          iVar17 = iVar17 + 1;
          if (uVar11 == 0) {
            uVar11 = 0x7fffffff;
          }
        }
        *(uint *)(param_2 + iVar15 * 0x80 + local_4 * 2) = uVar11;
        *(int *)(param_2 + (param_3 + 2) * 0x80 + local_4 * 2) = iVar17;
        iVar10 = local_4 + (uVar16 & 0xff);
        param_2[*(byte *)(iVar10 + iVar2)] =
             ((short)((ushort)(-(uVar16 & 0x100000) >> 0x10) ^ (ushort)(uVar16 >> 0x10)) >> 5) *
             *(short *)(iVar8 + iVar10 * 2);
        iVar10 = iVar10 + (uint)(uVar11 == 0);
      } while (iVar10 < 0x40);
      sVar12 = (short)((uint)*(undefined4 *)(iVar3 + iVar7 * 4) >> 0x10);
      *param_2 = sVar12;
      FUN_006bd9a0(param_1,iVar7,param_3,param_2,local_4,CONCAT22(sVar12 >> 0xf,local_8[uVar14]));
      local_30 = local_30 + 1;
      local_24 = local_24 + -1;
    } while (local_24 != 0);
  }
  *(int *)(param_2 + param_3 * 2 + 0x580) = *(int *)(param_2 + param_3 * 2 + 0x580) + iVar4 * 4;
  if (0 < *(int *)(param_2 + param_3 * 2 + 0x592)) {
    iVar15 = *(int *)(param_2 + param_3 * 2 + 0x586) + *(int *)(param_2 + param_3 * 2 + 0x592) * -4;
    *(int *)(param_2 + param_3 * 2 + 0x586) = iVar15;
    FUN_006bf190(*(undefined4 *)(param_1 + 0x22c),*(undefined4 *)(param_1 + 0x228),
                 *(undefined4 *)(param_1 + 0x240 + param_3 * 4),iVar15,
                 *(undefined4 *)(param_2 + param_3 * 2 + 0x592),*(undefined4 *)(param_1 + 0xac));
  }
  return;
}

