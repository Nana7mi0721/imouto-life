
undefined4
FUN_00542590(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,uint param_10,uint param_11)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint *puVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint local_30;
  uint *local_18;
  uint *local_14;
  uint *local_10;
  int local_8;
  
  if (((param_10 != 1) && ((param_10 & 1) != 0)) || ((param_11 != 1 && ((param_11 & 1) != 0)))) {
    return 0xffffffff;
  }
  uVar10 = (int)param_10 / 2;
  uVar6 = *(uint *)(param_1 + 0x14);
  bVar1 = *(byte *)(param_1 + 0xd);
  uVar7 = *(uint *)(param_1 + 0x18);
  uVar8 = *(uint *)(param_1 + 0x1c);
  bVar2 = *(byte *)(param_1 + 0xc);
  bVar3 = *(byte *)(param_1 + 0xe);
  uVar18 = (uint)*(byte *)(param_1 + 4);
  uVar11 = (int)param_11 / 2;
  cVar4 = *(char *)(param_1 + 5);
  bVar5 = *(byte *)(param_1 + 0xf);
  uVar9 = *(uint *)(param_1 + 0x10);
  if (param_10 == 1) {
    if (param_11 == 1) {
      puVar12 = (undefined4 *)(param_5 * param_9 + uVar18 * param_8 + param_4);
      puVar14 = (undefined4 *)(param_3 * param_7 + uVar18 * param_6 + param_2);
      if (cVar4 == '\x10') {
        *(undefined2 *)puVar14 = *(undefined2 *)puVar12;
        return 0;
      }
      if (cVar4 == ' ') {
        *puVar14 = *puVar12;
      }
    }
    else {
      param_10 = 0;
      if (uVar11 != 0) {
        local_14 = (uint *)(param_3 * param_9);
        local_18 = (uint *)(param_5 * param_9 + uVar18 * param_8 + param_4);
        do {
          if (cVar4 == '\x10') {
            uVar10 = (uint)(ushort)*local_18;
            uVar15 = (uint)*(ushort *)((int)local_18 + param_5);
          }
          else {
            if (cVar4 != ' ') {
              return 0xffffffff;
            }
            uVar10 = *local_18;
            uVar15 = *(uint *)((int)local_18 + param_5);
          }
          puVar13 = (uint *)(uVar18 * param_6 + (int)local_14 + param_2);
          uVar10 = (((uVar15 & uVar8) >> (bVar5 & 0x1f)) + ((uVar10 & uVar8) >> (bVar5 & 0x1f)) >> 1
                   ) << (bVar5 & 0x1f) |
                   (((uVar15 & uVar7) >> (bVar3 & 0x1f)) + ((uVar10 & uVar7) >> (bVar3 & 0x1f)) >> 1
                   ) << (bVar3 & 0x1f) |
                   (((uVar15 & uVar6) >> (bVar1 & 0x1f)) + ((uVar10 & uVar6) >> (bVar1 & 0x1f)) >> 1
                   ) << (bVar1 & 0x1f) |
                   (((uVar15 & uVar9) >> (bVar2 & 0x1f)) + ((uVar10 & uVar9) >> (bVar2 & 0x1f)) >> 1
                   ) << (bVar2 & 0x1f);
          if (cVar4 == '\x10') {
            *(short *)puVar13 = (short)uVar10;
          }
          else if (cVar4 == ' ') {
            *puVar13 = uVar10;
          }
          local_14 = (uint *)((int)local_14 + param_3);
          param_10 = param_10 + 1;
          local_18 = (uint *)((int)local_18 + param_5 * 2);
        } while (param_10 < uVar11);
        return 0;
      }
    }
  }
  else if (param_11 == 1) {
    local_30 = 0;
    if (uVar10 != 0) {
      param_10 = uVar18 * param_6;
      local_14 = (uint *)(param_5 * param_9 + uVar18 * param_8 + param_4);
      do {
        if (cVar4 == '\x10') {
          uVar11 = (uint)(ushort)*local_14;
          uVar15 = (uint)*(ushort *)((int)local_14 + 2);
        }
        else {
          if (cVar4 != ' ') {
            return 0xffffffff;
          }
          uVar11 = *local_14;
          uVar15 = local_14[1];
        }
        puVar13 = (uint *)(param_3 * param_9 + param_10 + param_2);
        uVar11 = (((uVar15 & uVar8) >> (bVar5 & 0x1f)) + ((uVar11 & uVar8) >> (bVar5 & 0x1f)) >> 1)
                 << (bVar5 & 0x1f) |
                 (((uVar15 & uVar7) >> (bVar3 & 0x1f)) + ((uVar11 & uVar7) >> (bVar3 & 0x1f)) >> 1)
                 << (bVar3 & 0x1f) |
                 (((uVar15 & uVar6) >> (bVar1 & 0x1f)) + ((uVar11 & uVar6) >> (bVar1 & 0x1f)) >> 1)
                 << (bVar1 & 0x1f) |
                 (((uVar15 & uVar9) >> (bVar2 & 0x1f)) + ((uVar11 & uVar9) >> (bVar2 & 0x1f)) >> 1)
                 << (bVar2 & 0x1f);
        if (cVar4 == '\x10') {
          *(short *)puVar13 = (short)uVar11;
        }
        else if (cVar4 == ' ') {
          *puVar13 = uVar11;
        }
        param_10 = param_10 + uVar18;
        local_30 = local_30 + 1;
        local_14 = (uint *)((int)local_14 + uVar18 * 2);
      } while (local_30 < uVar10);
      return 0;
    }
  }
  else {
    param_10 = 0;
    if (uVar11 != 0) {
      local_14 = (uint *)(param_3 * param_9);
      local_8 = param_5 * param_9;
      do {
        local_30 = 0;
        if (uVar10 != 0) {
          local_18 = (uint *)(uVar18 * param_6);
          local_10 = (uint *)(uVar18 * param_8 + local_8 + param_4);
          do {
            if (cVar4 == '\x10') {
              uVar15 = (uint)*(ushort *)((int)local_10 + param_5);
              uVar19 = (uint)(ushort)*local_10;
              uVar17 = (uint)*(ushort *)((int)local_10 + 2);
              uVar16 = (uint)*(ushort *)((int)local_10 + param_5 + 2);
            }
            else {
              if (cVar4 != ' ') {
                return 0xffffffff;
              }
              uVar15 = *(uint *)((int)local_10 + param_5);
              uVar19 = *local_10;
              uVar17 = local_10[1];
              uVar16 = *(uint *)((int)local_10 + param_5 + 4);
            }
            uVar15 = (((uVar16 & uVar9) >> (bVar2 & 0x1f)) + ((uVar17 & uVar9) >> (bVar2 & 0x1f)) +
                      ((uVar15 & uVar9) >> (bVar2 & 0x1f)) + ((uVar19 & uVar9) >> (bVar2 & 0x1f)) >>
                     2) << (bVar2 & 0x1f) |
                     (((uVar16 & uVar8) >> (bVar5 & 0x1f)) + ((uVar17 & uVar8) >> (bVar5 & 0x1f)) +
                      ((uVar15 & uVar8) >> (bVar5 & 0x1f)) + ((uVar19 & uVar8) >> (bVar5 & 0x1f)) >>
                     2) << (bVar5 & 0x1f) |
                     (((uVar16 & uVar7) >> (bVar3 & 0x1f)) + ((uVar17 & uVar7) >> (bVar3 & 0x1f)) +
                      ((uVar15 & uVar7) >> (bVar3 & 0x1f)) + ((uVar19 & uVar7) >> (bVar3 & 0x1f)) >>
                     2) << (bVar3 & 0x1f) |
                     (((uVar16 & uVar6) >> (bVar1 & 0x1f)) + ((uVar17 & uVar6) >> (bVar1 & 0x1f)) +
                      ((uVar15 & uVar6) >> (bVar1 & 0x1f)) + ((uVar19 & uVar6) >> (bVar1 & 0x1f)) >>
                     2) << (bVar1 & 0x1f);
            puVar13 = (uint *)((int)local_14 + (int)local_18 + param_2);
            if (cVar4 == '\x10') {
              *(short *)puVar13 = (short)uVar15;
            }
            else if (cVar4 == ' ') {
              *puVar13 = uVar15;
            }
            local_18 = (uint *)((int)local_18 + uVar18);
            local_30 = local_30 + 1;
            local_10 = (uint *)((int)local_10 + uVar18 * 2);
          } while (local_30 < uVar10);
        }
        param_10 = param_10 + 1;
        local_8 = local_8 + param_5 * 2;
        local_14 = (uint *)((int)local_14 + param_3);
      } while (param_10 < uVar11);
      return 0;
    }
  }
  return 0;
}

