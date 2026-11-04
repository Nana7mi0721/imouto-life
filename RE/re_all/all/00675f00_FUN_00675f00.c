
void FUN_00675f00(int param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  byte *local_18;
  byte local_c;
  byte *local_4;
  
  bVar1 = *(byte *)(param_1 + 0x15f);
  uVar7 = (uint)bVar1;
  uVar11 = *(uint *)(param_1 + 0x100);
  local_18 = (byte *)(*(int *)(param_1 + 0x124) + 1);
  bVar2 = *(byte *)(param_1 + 0x155);
  uVar12 = (uint)bVar2;
  local_4 = (byte *)0x0;
  bVar3 = 0;
  if (uVar7 == 0) {
    FUN_00668620(param_1,s_internal_row_logic_error_00a0d21c);
  }
  if (*(uint *)(param_1 + 0x138) != 0) {
    if (uVar7 < 8) {
      uVar6 = uVar11 * uVar7 + 7 >> 3;
    }
    else {
      uVar6 = (bVar1 >> 3) * uVar11;
    }
    if (*(uint *)(param_1 + 0x138) != uVar6) {
      FUN_00668620(param_1,s_internal_row_size_calculation_er_00a0d1f8);
    }
  }
  if (uVar11 == 0) {
    FUN_00668620(param_1,s_internal_row_width_error_00a0d1dc);
  }
  uVar6 = uVar11 * uVar7;
  local_c = (byte)(uVar6 & 7);
  if ((uVar6 & 7) != 0) {
    if (uVar7 < 8) {
      uVar9 = uVar6 + 7 >> 3;
    }
    else {
      uVar9 = (bVar1 >> 3) * uVar11;
    }
    local_4 = param_2 + (uVar9 - 1);
    bVar3 = *local_4;
    if ((*(uint *)(param_1 + 0x7c) & 0x10000) == 0) {
      local_c = (byte)(0xff >> local_c);
    }
    else {
      local_c = (byte)(0xff << local_c);
    }
  }
  if ((((*(char *)(param_1 + 0x154) == '\0') || ((*(uint *)(param_1 + 0x7c) & 2) == 0)) ||
      (5 < uVar12)) || ((param_3 != 0 && ((param_3 != 1 || ((bVar2 & 1) == 0)))))) {
    if (uVar7 < 8) {
      uVar11 = uVar6 + 7 >> 3;
    }
    else {
      uVar11 = (bVar1 >> 3) * uVar11;
    }
    for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
      *(undefined4 *)param_2 = *(undefined4 *)local_18;
      local_18 = local_18 + 4;
      param_2 = param_2 + 4;
    }
    for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
      *param_2 = *local_18;
      local_18 = local_18 + 1;
      param_2 = param_2 + 1;
    }
  }
  else {
    uVar6 = (uVar12 & 1) << (3U - (char)(uVar12 + 1 >> 1) & 0x1f) & 7;
    if (uVar11 <= uVar6) {
      return;
    }
    if (7 < uVar7) {
      if ((bVar1 & 7) != 0) {
        FUN_00668620(param_1,s_invalid_user_transform_pixel_dep_00a0d1b8);
      }
      uVar7 = (uint)(bVar1 >> 3);
      iVar8 = uVar6 * uVar7;
      uVar11 = uVar11 * uVar7 - iVar8;
      param_2 = param_2 + iVar8;
      local_18 = local_18 + iVar8;
      if (param_3 == 0) {
        param_3 = uVar7;
      }
      else {
        param_3 = (1 << ((byte)(6 - uVar12 >> 1) & 0x1f)) * uVar7;
        if (uVar11 < param_3) {
          param_3 = uVar11;
        }
      }
      uVar6 = param_3;
      uVar7 = (1 << ((byte)(7 - uVar12 >> 1) & 0x1f)) * uVar7;
      if (param_3 == 1) {
        *param_2 = *local_18;
        if (uVar11 <= uVar7) {
          return;
        }
        do {
          pbVar10 = local_18 + uVar7;
          local_18 = local_18 + uVar7;
          param_2 = param_2 + uVar7;
          uVar11 = uVar11 - uVar7;
          *param_2 = *pbVar10;
        } while (uVar7 < uVar11);
        return;
      }
      if (param_3 == 2) {
        *param_2 = *local_18;
        param_2[1] = local_18[1];
        if (uVar11 <= uVar7) {
          return;
        }
        do {
          uVar11 = uVar11 - uVar7;
          local_18 = local_18 + uVar7;
          param_2 = param_2 + uVar7;
          if (uVar11 < 2) {
            *param_2 = *local_18;
            return;
          }
          *param_2 = *local_18;
          param_2[1] = local_18[1];
        } while (uVar7 < uVar11);
        return;
      }
      if (param_3 == 3) {
        *param_2 = *local_18;
        param_2[1] = local_18[1];
        param_2[2] = local_18[2];
        if (uVar11 <= uVar7) {
          return;
        }
        do {
          pbVar10 = local_18 + uVar7;
          local_18 = local_18 + uVar7;
          param_2 = param_2 + uVar7;
          uVar11 = uVar11 - uVar7;
          *param_2 = *pbVar10;
          param_2[1] = local_18[1];
          param_2[2] = local_18[2];
        } while (uVar7 < uVar11);
        return;
      }
      if (((param_3 < 0x10) && (((uint)param_2 & 1) == 0)) &&
         ((((uint)local_18 & 1) == 0 && (((param_3 & 1) == 0 && ((uVar7 & 1) == 0)))))) {
        if ((((uint)param_2 & 3) == 0) &&
           (((((uint)local_18 & 3) == 0 && ((param_3 & 3) == 0)) && ((uVar7 & 3) == 0)))) {
          uVar12 = uVar7 - param_3;
          while( true ) {
            param_3 = uVar6;
            do {
              uVar5 = *(undefined4 *)local_18;
              local_18 = local_18 + 4;
              *(undefined4 *)param_2 = uVar5;
              param_2 = param_2 + 4;
              param_3 = param_3 - 4;
            } while (param_3 != 0);
            if (uVar11 <= uVar7) break;
            uVar9 = uVar12 & 0xfffffffc;
            uVar11 = uVar11 - uVar7;
            param_2 = param_2 + uVar9;
            local_18 = local_18 + uVar9;
            if (uVar11 < uVar6) {
              iVar8 = (int)local_18 - (int)param_2;
              do {
                *param_2 = param_2[iVar8];
                param_2 = param_2 + 1;
                uVar11 = uVar11 - 1;
              } while (uVar11 != 0);
              return;
            }
          }
          return;
        }
        uVar12 = uVar7 - param_3;
        while( true ) {
          param_3 = uVar6;
          do {
            uVar4 = *(undefined2 *)local_18;
            local_18 = local_18 + 2;
            *(undefined2 *)param_2 = uVar4;
            param_2 = param_2 + 2;
            param_3 = param_3 - 2;
          } while (param_3 != 0);
          if (uVar11 <= uVar7) break;
          uVar9 = uVar12 & 0xfffffffe;
          uVar11 = uVar11 - uVar7;
          param_2 = param_2 + uVar9;
          local_18 = local_18 + uVar9;
          if (uVar11 < uVar6) {
            iVar8 = (int)local_18 - (int)param_2;
            do {
              *param_2 = param_2[iVar8];
              param_2 = param_2 + 1;
              uVar11 = uVar11 - 1;
            } while (uVar11 != 0);
            return;
          }
        }
        return;
      }
      pbVar10 = local_18;
      pbVar13 = param_2;
      for (uVar12 = param_3 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined4 *)pbVar13 = *(undefined4 *)pbVar10;
        pbVar10 = pbVar10 + 4;
        pbVar13 = pbVar13 + 4;
      }
      for (uVar12 = param_3 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pbVar13 = *pbVar10;
        pbVar10 = pbVar10 + 1;
        pbVar13 = pbVar13 + 1;
      }
      if (uVar11 <= uVar7) {
        return;
      }
      do {
        uVar11 = uVar11 - uVar7;
        local_18 = local_18 + uVar7;
        param_2 = param_2 + uVar7;
        if (uVar11 < param_3) {
          param_3 = uVar11;
        }
        pbVar10 = local_18;
        pbVar13 = param_2;
        for (uVar12 = param_3 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
          *(undefined4 *)pbVar13 = *(undefined4 *)pbVar10;
          pbVar10 = pbVar10 + 4;
          pbVar13 = pbVar13 + 4;
        }
        for (uVar12 = param_3 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
          *pbVar13 = *pbVar10;
          pbVar10 = pbVar10 + 1;
          pbVar13 = pbVar13 + 1;
        }
      } while (uVar7 < uVar11);
      return;
    }
    uVar6 = (uint)(8 / (ulonglong)uVar7);
    if ((*(uint *)(param_1 + 0x7c) & 0x10000) == 0) {
      if (param_3 == 0) {
        if (uVar7 == 1) {
          iVar8 = 0;
        }
        else {
          iVar8 = (uVar7 != 2) + 1;
        }
        uVar12 = *(uint *)(&DAT_0081f018 + (uVar12 + iVar8 * 6) * 4);
      }
      else {
        if (uVar7 == 1) {
          iVar8 = 0;
        }
        else {
          iVar8 = (uVar7 != 2) + 1;
        }
        uVar12 = *(uint *)(&DAT_0081f084 + ((uint)(bVar2 >> 1) + iVar8 * 3) * 4);
      }
    }
    else if (param_3 == 0) {
      if (uVar7 == 1) {
        iVar8 = 0;
      }
      else {
        iVar8 = (uVar7 != 2) + 1;
      }
      uVar12 = *(uint *)(&DAT_0081efd0 + (uVar12 + iVar8 * 6) * 4);
    }
    else {
      if (uVar7 == 1) {
        iVar8 = 0;
      }
      else {
        iVar8 = (uVar7 != 2) + 1;
      }
      uVar12 = *(uint *)(&DAT_0081f060 + ((uint)(bVar2 >> 1) + iVar8 * 3) * 4);
    }
    while( true ) {
      if ((uVar12 & 0xff) != 0) {
        if ((uVar12 & 0xff) == 0xff) {
          *param_2 = *local_18;
        }
        else {
          *param_2 = ~(byte)uVar12 & *param_2 | *local_18 & (byte)uVar12;
        }
      }
      if (uVar11 <= uVar6) break;
      uVar11 = uVar11 - uVar6;
      param_2 = param_2 + 1;
      local_18 = local_18 + 1;
      uVar12 = uVar12 >> 8 | uVar12 << 0x18;
    }
  }
  if (local_4 != (byte *)0x0) {
    *local_4 = ~local_c & *local_4 | local_c & bVar3;
  }
  return;
}

