
void FUN_006b8f30(uint *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  uint uVar16;
  int iVar17;
  int local_40;
  int local_38;
  int local_34;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_18;
  int local_10;
  
  iVar2 = *(int *)(param_2 + 0xb78 + param_3 * 4);
  piVar1 = (int *)(param_3 * 0x20 + 0x48 + (int)param_1);
  iVar3 = *(int *)((int)param_1 + 0xa8);
  iVar4 = *piVar1;
  iVar5 = *(int *)(param_2 + 0xb84 + param_3 * 4);
  iVar14 = (param_3 + 0xb9) * 0x10 + param_2;
  iVar6 = iVar4 * iVar2 + piVar1[2];
  local_38 = 0;
  if (iVar2 < iVar5) {
    local_34 = iVar6 * 4;
    local_40 = iVar6 * 4 + 4;
    param_1 = (uint *)(iVar3 + local_34);
    local_10 = iVar2;
    do {
      puVar12 = param_1;
      if (local_10 == 0) {
        if (0 < iVar4) {
          local_34 = local_34 + iVar4 * 4;
          puVar12 = param_1 + iVar4;
          local_40 = local_40 + iVar4 * 4;
          local_24 = iVar4;
          do {
            uVar7 = *param_1;
            if ((uVar7 & 1) != 0) {
              uVar10 = uVar7 >> 6 & 3;
              uVar7 = (uVar7 & 0xffff0000) + *(int *)(iVar14 + uVar10 * 4) * 0x10000 ^
                      uVar7 & 0xffff;
              *param_1 = uVar7;
              *(int *)(iVar14 + uVar10 * 4) = (int)uVar7 >> 0x10;
              local_38 = local_38 + 1;
            }
            param_1 = param_1 + 1;
            local_24 = local_24 + -1;
          } while (local_24 != 0);
        }
      }
      else {
        iVar6 = iVar3 + iVar4 * -4;
        local_28 = 0xffffffff;
        local_18 = 0xffffffff;
        iVar11 = 0;
        local_2c = *(uint *)(local_34 + iVar6) >> 6 & 3;
        if (0 < iVar4) {
          puVar15 = (uint *)(local_40 + iVar6);
          local_34 = local_34 + iVar4 * 4;
          puVar12 = param_1 + iVar4;
          local_40 = local_40 + iVar4 * 4;
          while( true ) {
            uVar7 = local_2c;
            iVar11 = iVar11 + 1;
            if (iVar11 < iVar4) {
              local_24 = *puVar15 >> 6 & 3;
            }
            else {
              local_24 = 0xffffffff;
            }
            uVar10 = *param_1;
            if ((uVar10 & 1) == 0) {
              local_28 = 0xffffffff;
            }
            else {
              uVar16 = uVar10 >> 6 & 3;
              switch((((local_24 == uVar16) << 1 | local_2c == uVar16) << 1 | local_18 == uVar16) <<
                     1 | local_28 == uVar16) {
              case '\x01':
              case '\x03':
                iVar6 = (int)param_1[-1] >> 0x10;
                break;
              case '\x02':
                iVar6 = (int)puVar15[-2] >> 0x10;
                break;
              case '\x04':
              case '\x06':
              case '\f':
                iVar6 = (int)puVar15[-1] >> 0x10;
                break;
              case '\x05':
                iVar6 = (((int)puVar15[-1] >> 0x10) + ((int)param_1[-1] >> 0x10)) / 2;
                break;
              case '\a':
              case '\x0f':
                iVar8 = (int)param_1[-1] >> 0x10;
                iVar6 = (int)puVar15[-1] >> 0x10;
                iVar17 = (int)puVar15[-2] >> 0x10;
                iVar9 = (iVar8 + iVar6) * 0x1d + iVar17 * -0x1a;
                iVar9 = (int)(iVar9 + (iVar9 >> 0x1f & 0x1fU)) >> 5;
                uVar13 = iVar9 - iVar6 >> 0x1f;
                if ((((int)((iVar9 - iVar6 ^ uVar13) - uVar13) < 0x81) &&
                    (uVar13 = iVar9 - iVar8 >> 0x1f, iVar6 = iVar8,
                    (int)((iVar9 - iVar8 ^ uVar13) - uVar13) < 0x81)) &&
                   (uVar13 = iVar9 - iVar17 >> 0x1f, iVar6 = iVar9,
                   0x80 < (int)((iVar9 - iVar17 ^ uVar13) - uVar13))) {
                  iVar6 = iVar17;
                }
                break;
              case '\b':
                iVar6 = (int)*puVar15 >> 0x10;
                break;
              case '\t':
              case '\v':
              case '\r':
                iVar6 = ((int)param_1[-1] >> 0x10) * 0x4b + ((int)*puVar15 >> 0x10) * 0x35;
                iVar6 = (int)(iVar6 + (iVar6 >> 0x1f & 0x7fU)) >> 7;
                break;
              case '\n':
                iVar6 = (((int)puVar15[-2] >> 0x10) + ((int)*puVar15 >> 0x10)) / 2;
                break;
              case '\x0e':
                iVar6 = (((int)puVar15[-2] >> 0x10) + ((int)*puVar15 >> 0x10)) * 3 +
                        ((int)puVar15[-1] >> 0x10) * 10;
                iVar6 = (int)(iVar6 + (iVar6 >> 0x1f & 0xfU)) >> 4;
                break;
              default:
                iVar6 = *(int *)(iVar14 + uVar16 * 4);
              }
              uVar10 = (uVar10 & 0xffff0000) + iVar6 * 0x10000 ^ uVar10 & 0xffff;
              *param_1 = uVar10;
              *(int *)(iVar14 + uVar16 * 4) = (int)uVar10 >> 0x10;
              local_38 = local_38 + 1;
              local_28 = uVar16;
            }
            puVar15 = puVar15 + 1;
            param_1 = param_1 + 1;
            local_2c = local_24;
            if (iVar4 <= iVar11) break;
            local_18 = uVar7;
          }
        }
      }
      param_1 = puVar12;
      local_10 = local_10 + 1;
    } while (local_10 < iVar5);
  }
  *(int *)(param_2 + 0xb18 + param_3 * 4) = local_38;
  *(int *)(param_2 + 0xb24 + param_3 * 4) = (iVar5 - iVar2) * iVar4 - local_38;
  return;
}

