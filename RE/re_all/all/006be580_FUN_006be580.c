
void FUN_006be580(int param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  uint *puVar12;
  int *piVar13;
  uint *puVar14;
  int *piVar15;
  bool bVar16;
  int *local_7c;
  int local_78;
  int local_74;
  int local_70;
  ushort *local_6c;
  int local_68;
  uint *local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int *local_4c;
  uint local_40 [16];
  
  local_74 = 0;
  local_70 = 0x1b;
  local_4c = (int *)(param_3 + 0x148);
  do {
    local_78 = 0;
    do {
      local_54 = 0;
      if (-1 < local_4c[-2]) {
        local_50 = 0;
        iVar10 = 0;
LAB_006be5c9:
        puVar12 = (uint *)(local_50 + *local_4c);
        puVar14 = local_40;
        for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar14 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar14 = puVar14 + 1;
        }
        if (local_54 == local_4c[-2]) {
          iVar2 = iVar10 + 1;
        }
        else {
          iVar2 = *(int *)(*(int *)(param_3 + (local_70 + local_78) * 0xc) + local_54 * 4) + iVar10;
        }
        local_60 = iVar10 * 6;
        local_58 = iVar2 - iVar10;
        local_5c = iVar10 * 3;
        local_64 = (uint *)(param_2 + iVar10 * 4);
        local_6c = (ushort *)(param_3 + iVar10 * 2);
        local_7c = (int *)(param_1 + (local_74 + (local_5c + local_78) * 2) * 4);
        iVar11 = iVar10;
        do {
          uVar3 = (uint)*local_6c * (local_40[0] & 0xff);
          if (param_2 != 0) {
            *local_64 = uVar3 / 0xa0;
          }
          uVar3 = uVar3 / 100;
          uVar8 = uVar3 * 4;
          sVar1 = (short)*(uint *)(&DAT_00832430 + local_74 * 4);
          iVar4 = 1;
          *(ushort *)*local_7c =
               sVar1 - ((sVar1 - (-(ushort)(0x1000 < uVar8) & (short)uVar3 * -4 + 0x1000U)) +
                        (short)uVar3 * -4 &
                       -(ushort)(*(uint *)(&DAT_00832430 + local_74 * 4) <
                                (-(uint)(0x1000 < uVar8) & uVar3 * -4 + 0x1000) + uVar8));
          do {
            uVar3 = ((uint)*(byte *)((int)local_40 + (uint)(byte)(&DAT_00831d70)[iVar4]) *
                    (uint)local_6c[0x40]) / 100;
            uVar8 = uVar3 * 4;
            sVar1 = (short)*(uint *)(&DAT_00832438 + local_74 * 4);
            iVar4 = iVar4 + 1;
            *(ushort *)(*local_7c + -2 + iVar4 * 2) =
                 sVar1 - ((sVar1 - (-(ushort)(0x1000 < uVar8) & (short)uVar3 * -4 + 0x1000U)) +
                          (short)uVar3 * -4 &
                         -(ushort)(*(uint *)(&DAT_00832438 + local_74 * 4) <
                                  (-(uint)(0x1000 < uVar8) & uVar3 * -4 + 0x1000) + uVar8));
          } while (iVar4 < 0x40);
          local_68 = 0;
          if (0x1a < local_70) {
            do {
              iVar4 = 0;
              puVar9 = (undefined4 *)(param_1 + (local_60 + local_68) * 4);
              while( true ) {
                iVar5 = 3;
                if (local_74 <= local_68) {
                  iVar5 = local_78;
                }
                if (iVar5 <= iVar4) break;
                iVar5 = 0x20;
                bVar16 = true;
                piVar13 = (int *)*local_7c;
                piVar15 = (int *)*puVar9;
                do {
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  bVar16 = *piVar13 == *piVar15;
                  piVar13 = piVar13 + 1;
                  piVar15 = piVar15 + 1;
                } while (bVar16);
                if (bVar16) {
                  *local_7c = *(int *)(param_1 + (local_68 + (local_5c + iVar4) * 2) * 4);
                  goto LAB_006be7ed;
                }
                iVar4 = iVar4 + 1;
                puVar9 = puVar9 + 2;
              }
              local_68 = local_68 + 1;
            } while (local_68 <= local_74);
          }
LAB_006be7ed:
          local_6c = local_6c + 1;
          iVar11 = iVar11 + 1;
          local_64 = local_64 + 1;
          local_60 = local_60 + 6;
          local_5c = local_5c + 3;
          local_7c = local_7c + 6;
          local_58 = local_58 + -1;
          if (iVar2 <= iVar11) goto LAB_006be8a0;
          iVar4 = *(int *)(*(int *)(param_3 + (local_78 + local_70) * 0xc) + local_54 * 4);
          iVar5 = *local_4c;
          iVar6 = 0;
          do {
            iVar7 = iVar6 + 1;
            *(char *)((int)local_40 + iVar6) =
                 (char)((int)(iVar4 + ((uint)*(byte *)(local_50 + iVar5 + 0x40 + iVar6) *
                                       (iVar11 - iVar10) +
                                      (uint)*(byte *)(local_50 + iVar5 + iVar6) * local_58) * 2) /
                       (iVar4 * 2));
            iVar6 = iVar7;
          } while (iVar7 < 0x40);
        } while( true );
      }
LAB_006be8ca:
      local_4c = local_4c + 3;
      local_78 = local_78 + 1;
    } while (local_78 < 3);
    local_70 = local_70 + 3;
    local_74 = local_74 + 1;
    if (0x20 < local_70) {
      return;
    }
  } while( true );
LAB_006be8a0:
  local_54 = local_54 + 1;
  local_50 = local_50 + 0x40;
  iVar10 = iVar11;
  if (local_4c[-2] < local_54) goto LAB_006be8ca;
  goto LAB_006be5c9;
}

