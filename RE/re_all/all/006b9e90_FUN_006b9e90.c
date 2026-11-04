
void FUN_006b9e90(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  byte bVar8;
  bool bVar9;
  byte bVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int *piVar16;
  bool bVar17;
  uint local_44;
  byte *local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int *local_2c;
  int local_24;
  uint local_20;
  int local_1c;
  
  uVar11 = FUN_006ba120(param_1);
  if (uVar11 < *(uint *)(param_1 + 0xc0)) {
    FUN_006ba220(param_1);
  }
  if (uVar11 == 0) {
    bVar17 = false;
  }
  else {
    iVar12 = FUN_006bf110(param_1 + 0xc9b4);
    bVar17 = iVar12 == 0;
  }
  iVar12 = *(int *)(param_1 + 200);
  iVar1 = *(int *)(param_1 + 0xb8);
  iVar2 = *(int *)(param_1 + 0xb4);
  iVar3 = *(int *)(param_1 + 0xbc);
  iVar4 = *(int *)(param_1 + 0xd8);
  iVar5 = *(int *)(param_1 + 0xa8);
  uVar14 = 0;
  uVar11 = 0;
  local_34 = 0;
  local_44 = 0;
  local_38 = 0;
  local_3c = 0;
  local_1c = 0;
  local_30 = 0;
  do {
    uVar14 = uVar14 + *(int *)(local_30 * 0x20 + 100 + param_1);
    iVar13 = local_1c;
    if (uVar11 < uVar14) {
      local_40 = (byte *)(uVar11 + iVar3);
      do {
        local_20 = 0;
        do {
          if ((byte)((byte)(1 << ((byte)local_20 & 0x1f)) & (byte)((*local_40 & 0x3c) >> 2)) != 0) {
            bVar10 = 0;
            local_2c = (int *)(iVar4 + local_3c * 4);
            local_24 = 4;
            iVar15 = iVar4 + iVar2 * 4 + local_38 * -4;
            piVar16 = (int *)((local_20 + local_44 * 4) * 0x10 + iVar1);
            iVar13 = local_34;
            do {
              iVar6 = *piVar16;
              if (-1 < iVar6) {
                if ((*local_40 & 1) == 0) {
                  if ((*local_40 & 2) == 0) {
                    bVar9 = false;
                  }
                  else {
                    if (iVar13 < 1) {
                      iVar13 = FUN_006ba100(param_1 + 0xc9b4);
                      bVar17 = !bVar17;
                    }
                    local_34 = iVar13 + -1;
                    bVar9 = bVar17;
                    if (bVar17) goto LAB_006ba0da;
                  }
                  *(int *)(iVar15 + -4) = iVar6;
                  local_38 = local_38 + 1;
                  iVar15 = iVar15 + -4;
                }
                else {
                  bVar9 = true;
LAB_006ba0da:
                  local_3c = local_3c + 1;
                  *local_2c = iVar6;
                  local_2c = local_2c + 1;
                }
                bVar10 = bVar10 | bVar9;
                uVar7 = *(undefined4 *)(iVar5 + iVar6 * 4);
                bVar8 = (byte)uVar7;
                *(uint *)(iVar5 + iVar6 * 4) =
                     CONCAT31((int3)((uint)uVar7 >> 8),(bVar8 ^ bVar9) & 1 ^ bVar8) | 0xc0;
                iVar13 = local_34;
              }
              piVar16 = piVar16 + 1;
              local_24 = local_24 + -1;
            } while (local_24 != 0);
            if (local_30 == 0) {
              *(byte *)((local_44 * 4 | local_20) + iVar12) = bVar10;
            }
          }
          local_20 = local_20 + 1;
        } while ((int)local_20 < 4);
        uVar11 = local_44 + 1;
        local_40 = local_40 + 1;
        local_44 = uVar11;
      } while (uVar11 < uVar14);
      iVar13 = local_3c;
    }
    *(int *)(param_1 + 0xdc + local_30 * 4) = iVar13 - local_1c;
    local_30 = local_30 + 1;
    local_1c = iVar13;
    if (2 < local_30) {
      *(int *)(param_1 + 0xe8) = iVar13;
      return;
    }
  } while( true );
}

