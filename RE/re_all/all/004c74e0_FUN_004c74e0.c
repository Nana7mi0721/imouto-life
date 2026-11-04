
/* WARNING: Removing unreachable block (ram,0x004c76b8) */
/* WARNING: Removing unreachable block (ram,0x004c7705) */
/* WARNING: Removing unreachable block (ram,0x004c770e) */
/* WARNING: Removing unreachable block (ram,0x004c773f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c74e0(int param_1,char param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  char *pcVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int local_90;
  int local_8c;
  int local_80;
  int local_7c;
  int local_78;
  int local_5c [8];
  int local_3c;
  int local_28 [8];
  int local_8;
  
  iVar2 = FUN_004ce080();
  if (param_2 == '\0') {
    *(int *)(param_1 + 0x9eb4) = *(int *)(param_1 + 0x9eb4) - _DAT_00a180f8;
    *(int *)(param_1 + 0x9eb8) = *(int *)(param_1 + 0x9eb8) - _DAT_00a180fc;
  }
  *(int *)(param_1 + 0x260) = DAT_00a180f0 / 0x14;
  FUN_005160d0(0,0xff);
  if (param_2 == '\0') {
    _memset((void *)(param_1 + 0x264),-1,40000);
  }
  local_8 = (DAT_0084b248 * 100 * DAT_00a18174) / 100;
  iVar3 = ((DAT_00a18174 + -100) * DAT_00a1816c) / DAT_0084b248;
  iVar4 = DAT_0084b264 * DAT_00a18174;
  iVar5 = ((((*DAT_00a16718 - DAT_00a1816c) * 100) / DAT_00a18174) / DAT_0084b248) / DAT_0084b264;
  local_78 = ((((DAT_00a18174 + -100) * DAT_00a18170) / DAT_0084b248) / 100) /
             ((DAT_0084b264 * DAT_00a18174) / 100) + -9;
  iVar6 = ((((*DAT_00a1671c - DAT_00a18170) * 100) / DAT_00a18174) / DAT_0084b248) / DAT_0084b264;
  do {
    if (iVar6 <= local_78) {
      return;
    }
    if (param_2 == '\x01') {
      local_78 = param_3 - *(int *)(param_1 + 0x9eb8) / DAT_0084b264;
      if (iVar6 < local_78) {
        return;
      }
LAB_004c77e9:
      for (local_7c = (iVar3 / 100) / (iVar4 / 100) + -5; local_7c < iVar5 + 1;
          local_7c = local_7c + 1) {
        local_80 = *(int *)(param_1 + (local_78 + 2) * 400 + 0x268 + local_7c * 4);
        while (local_80 = local_80 + 1, local_80 < 3) {
          iVar7 = *(int *)(param_1 + 0x9eb8) / DAT_0084b264;
          iVar8 = FUN_0047a4b0();
          iVar9 = FUN_0047a4b0();
          iVar9 = (iVar7 + local_78 + iVar8 * 100) % iVar9;
          iVar7 = *(int *)(param_1 + 0x9eb4) / DAT_0084b264;
          iVar8 = FUN_0047a490(iVar9);
          iVar10 = FUN_0047a490();
          iVar10 = (iVar7 + local_7c + iVar8 * 100) % iVar10;
          FUN_004cd3a0(local_80);
          FUN_004cde80(iVar10);
          piVar11 = (int *)FUN_004ce990(iVar9);
          local_3c = *piVar11;
          if (local_3c == 100000) {
            local_3c = 100000;
          }
          else {
            if (local_3c < 100000) {
              local_3c = local_3c + 0xf;
            }
            else {
              local_3c = local_3c / 100000;
            }
            if ((local_3c < iVar2) && (piVar11 = (int *)FUN_004ce990(local_3c), *piVar11 != 0)) {
              if (param_2 < '\x01') {
                pcVar12 = (char *)FUN_004cd7c0(local_3c + 1);
                cVar1 = *pcVar12;
              }
              else {
                pcVar12 = (char *)FUN_004cd7c0(local_3c + 1);
                cVar1 = *pcVar12;
              }
              if (param_2 < cVar1) break;
              *(int *)(param_1 + (local_78 + 2) * 400 + 0x268 + local_7c * 4) = local_80;
              if ((DAT_0084b248 == 1) && (DAT_00a18174 == 100)) {
                uVar15 = DAT_0084b240;
                puVar13 = (undefined4 *)FUN_004ce990(local_3c);
                uVar14 = *puVar13;
                iVar8 = local_78 * DAT_0084b264;
                iVar7 = *(int *)(param_1 + 0x9eb8) % DAT_0084b264;
                piVar11 = (int *)FUN_004ce990(local_3c);
                iVar8 = (iVar8 - iVar7) + *piVar11 % 10000;
                iVar9 = local_7c * DAT_0084b264;
                iVar7 = *(int *)(param_1 + 0x9eb4) % DAT_0084b264;
                piVar11 = (int *)FUN_004ce990(local_3c);
                FUN_0051e930((iVar9 - iVar7) + *piVar11 / 10000,iVar8,uVar14,uVar15);
              }
              else {
                for (local_8c = 0; local_8c < 1; local_8c = local_8c + 1) {
                  iVar7 = (local_7c * DAT_0084b264 - *(int *)(param_1 + 0x9eb4) % DAT_0084b264) *
                          DAT_0084b248;
                  piVar11 = (int *)FUN_004ce990(local_7c);
                  local_5c[local_8c * 2] = iVar7 + *piVar11 / 10000;
                  iVar7 = (local_78 * DAT_0084b264 - *(int *)(param_1 + 0x9eb8) % DAT_0084b264) *
                          DAT_0084b248;
                  piVar11 = (int *)FUN_004ce990(local_7c);
                  local_28[local_8c * 2] = iVar7 + *piVar11 % 10000;
                  iVar8 = local_7c * DAT_0084b264;
                  iVar7 = *(int *)(param_1 + 0x9eb4) % DAT_0084b264;
                  piVar11 = (int *)FUN_004ce990(local_3c);
                  iVar7 = ((iVar8 - iVar7) + *piVar11 / 10000) * DAT_0084b248;
                  piVar11 = (int *)FUN_004ce990(local_3c);
                  local_5c[local_8c * 2 + 1] = iVar7 + *piVar11 / 10000;
                  iVar8 = local_78 * DAT_0084b264;
                  iVar7 = *(int *)(param_1 + 0x9eb8) % DAT_0084b264;
                  piVar11 = (int *)FUN_004ce990(local_3c);
                  iVar7 = ((iVar8 - iVar7) + *piVar11 % 10000) * DAT_0084b248;
                  piVar11 = (int *)FUN_004ce990(local_3c);
                  local_28[local_8c * 2 + 1] = iVar7 + *piVar11 % 10000;
                  for (local_90 = 0; local_90 < 2; local_90 = local_90 + 1) {
                    local_5c[local_8c * 2 + local_90] =
                         ((local_5c[local_8c * 2 + local_90] - DAT_00a1816c * DAT_0084b248) *
                         (DAT_00a18174 + -100)) / 100 + local_5c[local_8c * 2 + local_90];
                    local_28[local_8c * 2 + local_90] =
                         ((local_28[local_8c * 2 + local_90] - DAT_00a18170 * DAT_0084b248) *
                         (DAT_00a18174 + -100)) / 100 + local_28[local_8c * 2 + local_90];
                  }
                }
                uVar14 = DAT_0084b240;
                puVar13 = (undefined4 *)FUN_004ce990(local_3c);
                FUN_0051f060(local_5c[0],local_28[0],local_5c[1],local_28[1],*puVar13,uVar14);
              }
            }
          }
        }
      }
      if (param_2 == '\x01') {
        return;
      }
    }
    else if ((DAT_00a180f5 != '\0') ||
            ((-1 < *(int *)(param_1 + 0x9eb8) / DAT_0084b264 + local_78 &&
             (iVar7 = FUN_0047a4b0(), *(int *)(param_1 + 0x9eb8) / DAT_0084b264 + local_78 < iVar7))
            )) goto LAB_004c77e9;
    local_78 = local_78 + 1;
  } while( true );
}

