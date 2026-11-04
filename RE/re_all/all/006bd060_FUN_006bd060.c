
void FUN_006bd060(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint *local_10;
  
  puVar5 = *(uint **)(param_1 + 0xa8);
  *(undefined4 *)(param_1 + 0x24c) = 0;
  local_14 = 0;
  local_20 = (int *)(param_1 + 0x48);
  puVar4 = puVar5;
  local_10 = puVar5;
  do {
    local_24 = *(int *)(param_1 + 0x14);
    local_28 = *(int *)(param_1 + 0x18);
    local_34 = local_24 + *(int *)(param_1 + 0xc);
    local_30 = *(int *)(param_1 + 0x10) + local_28;
    if (0 < local_14) {
      if ((*(uint *)(param_1 + 0x30) & 1) == 0) {
        local_24 = local_24 >> 1;
        local_34 = local_34 + 1 >> 1;
      }
      if ((*(uint *)(param_1 + 0x30) & 2) == 0) {
        local_28 = local_28 >> 1;
        local_30 = local_30 + 1 >> 1;
      }
    }
    local_2c = 0;
    puVar5 = puVar5 + local_20[3];
    while (puVar4 < puVar5) {
      local_18 = 0;
      puVar2 = puVar4 + *local_20;
      while (puVar4 < puVar2) {
        iVar1 = local_18 + 8;
        if ((((local_24 < iVar1) && (local_18 < local_34)) &&
            (iVar8 = local_2c + 8, local_28 < iVar8)) &&
           (((local_2c < local_30 && (local_24 < local_34)) && (local_28 < local_30)))) {
          if ((((local_24 <= local_18) || (iVar1 <= local_24)) &&
              (((local_34 <= local_18 || (iVar1 <= local_34)) &&
               ((local_28 <= local_2c || (iVar8 <= local_28)))))) &&
             ((local_30 <= local_2c || (iVar8 <= local_30)))) {
            uVar6 = *puVar4 | 0xf800;
            goto LAB_006bd28f;
          }
          iVar9 = 0;
          uVar6 = 0;
          uVar7 = 0;
          local_1c = 0;
          iVar8 = 0;
          while( true ) {
            do {
              if ((((local_24 <= iVar8 + local_18) && (iVar8 + local_18 < local_34)) &&
                  (local_28 <= local_2c + iVar9)) && (local_2c + iVar9 < local_30)) {
                uVar10 = __allshl();
                uVar6 = uVar6 | (uint)uVar10;
                uVar7 = uVar7 | (uint)((ulonglong)uVar10 >> 0x20);
                local_1c = local_1c + 1;
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < 8);
            iVar9 = iVar9 + 1;
            if (7 < iVar9) break;
            iVar8 = 0;
          }
          uVar3 = 0;
          iVar8 = *(int *)(param_1 + 0x24c);
          if (0 < iVar8) {
            puVar4 = (uint *)(param_1 + 0x250);
            do {
              if ((*puVar4 == uVar6) && (puVar4[1] == uVar7)) goto LAB_006bd25f;
              uVar3 = uVar3 + 1;
              puVar4 = puVar4 + 4;
            } while ((int)uVar3 < iVar8);
          }
          *(int *)(param_1 + 0x24c) = iVar8 + 1;
          iVar8 = (uVar3 + 0x25) * 0x10;
          *(uint *)(iVar8 + param_1) = uVar6;
          *(uint *)(iVar8 + 4 + param_1) = uVar7;
          *(int *)(uVar3 * 0x10 + 600 + param_1) = local_1c;
LAB_006bd25f:
          *local_10 = (uVar3 & 0x1f) << 0xb | *local_10 & 0xffff07ff;
          puVar4 = local_10;
        }
        else {
          uVar6 = *puVar4 | 2;
LAB_006bd28f:
          *puVar4 = uVar6;
        }
        puVar4 = puVar4 + 1;
        local_18 = iVar1;
        local_10 = puVar4;
      }
      local_2c = local_2c + 8;
    }
    local_14 = local_14 + 1;
    local_20 = local_20 + 8;
    if (2 < local_14) {
      return;
    }
  } while( true );
}

