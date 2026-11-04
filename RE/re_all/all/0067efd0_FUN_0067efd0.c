
undefined4
FUN_0067efd0(int param_1,ushort *param_2,uint param_3,int *param_4,uint *param_5,ushort *param_6)

{
  ushort uVar1;
  byte bVar2;
  ushort *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  byte bVar10;
  uint uVar11;
  char cVar12;
  uint uVar13;
  undefined4 local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  int local_6c;
  ushort *local_68;
  int local_60;
  ushort *local_5c;
  ushort *local_58;
  uint local_54;
  uint local_4c;
  ushort local_40 [15];
  ushort local_22 [17];
  
  puVar3 = local_40;
  for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
    puVar3[0] = 0;
    puVar3[1] = 0;
    puVar3 = puVar3 + 2;
  }
  if (param_3 != 0) {
    puVar3 = param_2;
    uVar11 = param_3;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      local_40[uVar1] = local_40[uVar1] + 1;
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
  }
  uVar11 = 0xf;
  puVar3 = local_22;
  do {
    if (*puVar3 != 0) break;
    uVar11 = uVar11 - 1;
    puVar3 = puVar3 + -1;
  } while (uVar11 != 0);
  local_78 = *param_5;
  if (uVar11 < *param_5) {
    local_78 = uVar11;
  }
  if (uVar11 == 0) {
    *(undefined4 *)*param_4 = 0x140;
    iVar7 = *param_4;
    *param_4 = iVar7 + 4;
    *(undefined4 *)(iVar7 + 4) = 0x140;
    *param_4 = *param_4 + 4;
    *param_5 = 1;
    return 0;
  }
  uVar13 = 1;
  if (1 < uVar11) {
    puVar3 = local_40;
    do {
      puVar3 = puVar3 + 1;
      if (*puVar3 != 0) break;
      uVar13 = uVar13 + 1;
    } while (uVar13 < uVar11);
  }
  if (local_78 < uVar13) {
    local_78 = uVar13;
  }
  iVar7 = 1;
  puVar3 = local_40;
  uVar4 = 1;
  do {
    puVar3 = puVar3 + 1;
    iVar7 = iVar7 * 2 - (uint)*puVar3;
    if (iVar7 < 0) {
      return 0xffffffff;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x10);
  if ((0 < iVar7) && ((param_1 == 0 || (uVar11 != 1)))) {
    return 0xffffffff;
  }
  local_22[2] = 0;
  uVar4 = 0;
  do {
    uVar5 = uVar4 + 2;
    *(short *)((int)local_22 + uVar4 + 6) =
         *(short *)((int)local_40 + uVar4 + 2) + *(short *)((int)local_22 + uVar4 + 4);
    uVar4 = uVar5;
  } while (uVar5 < 0x1c);
  uVar4 = 0;
  if (param_3 != 0) {
    puVar3 = param_2;
    do {
      if (*puVar3 != 0) {
        param_6[local_22[*puVar3 + 1]] = (ushort)uVar4;
        local_22[*puVar3 + 1] = local_22[*puVar3 + 1] + 1;
      }
      uVar4 = uVar4 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar4 < param_3);
  }
  if (param_1 == 0) {
    local_5c = param_6;
    local_58 = param_6;
    local_60 = 0x13;
  }
  else if (param_1 == 1) {
    local_60 = 0x100;
    local_58 = (ushort *)&DAT_0082191e;
    local_5c = (ushort *)&DAT_0082195e;
  }
  else {
    local_58 = (ushort *)&DAT_00821ba0;
    local_5c = (ushort *)&DAT_00821be0;
    local_60 = -1;
  }
  local_74 = 0;
  local_70 = 0;
  local_6c = *param_4;
  local_54 = 1 << ((byte)local_78 & 0x1f);
  uVar4 = local_54 - 1;
  if (param_1 == 1) {
    if (local_54 < 0x355) {
LAB_0067f20c:
      local_68 = param_6;
      uVar5 = 0xffffffff;
      local_4c = local_54;
      do {
        do {
          cVar12 = (char)uVar13;
          bVar10 = (byte)local_70;
          bVar2 = cVar12 - bVar10;
          uVar6 = (uint)*local_68;
          if ((int)uVar6 < local_60) {
            local_7c = (uint)CONCAT21(*local_68,bVar2) << 8;
          }
          else if (local_60 < (int)uVar6) {
            local_7c = CONCAT22(local_58[uVar6],CONCAT11(bVar2,(char)local_5c[uVar6]));
          }
          else {
            local_7c = CONCAT31((uint3)bVar2,0x60);
          }
          iVar7 = 1 << (cVar12 - bVar10 & 0x1f);
          piVar8 = (int *)(local_6c + ((local_74 >> (bVar10 & 0x1f)) + local_4c) * 4);
          uVar6 = local_4c;
          do {
            uVar6 = uVar6 - iVar7;
            piVar8 = piVar8 + -iVar7;
            *piVar8 = local_7c;
          } while (uVar6 != 0);
          for (uVar6 = 1 << (cVar12 - 1U & 0x1f); (local_74 & uVar6) != 0; uVar6 = uVar6 >> 1) {
          }
          if (uVar6 == 0) {
            local_74 = 0;
          }
          else {
            local_74 = (uVar6 - 1 & local_74) + uVar6;
          }
          local_68 = local_68 + 1;
          local_40[uVar13] = local_40[uVar13] - 1;
          if (local_40[uVar13] == 0) {
            if (uVar13 == uVar11) {
              if (local_74 != 0) {
                local_7c = (uint)CONCAT11(cVar12 - bVar10,0x40);
                *(uint *)(local_6c + local_74 * 4) = local_7c;
              }
              *param_4 = *param_4 + local_54 * 4;
              *param_5 = local_78;
              return 0;
            }
            uVar13 = (uint)param_2[*local_68];
          }
        } while ((uVar13 <= local_78) || (uVar6 = uVar4 & local_74, uVar6 == uVar5));
        if (local_70 == 0) {
          local_70 = local_78;
        }
        local_6c = local_6c + local_4c * 4;
        iVar9 = uVar13 - local_70;
        uVar5 = local_70 + iVar9;
        iVar7 = 1 << ((byte)iVar9 & 0x1f);
        if (uVar5 < uVar11) {
          puVar3 = local_40 + uVar5;
          do {
            uVar1 = *puVar3;
            if ((int)(iVar7 - (uint)uVar1) < 1) break;
            iVar9 = iVar9 + 1;
            uVar5 = uVar5 + 1;
            puVar3 = puVar3 + 1;
            iVar7 = (iVar7 - (uint)uVar1) * 2;
          } while (uVar5 < uVar11);
        }
        local_4c = 1 << ((byte)iVar9 & 0x1f);
        local_54 = local_54 + local_4c;
        if (param_1 == 1) {
          if (0x354 < local_54) {
            return 1;
          }
        }
        else if ((param_1 == 2) && (0x250 < local_54)) {
          return 1;
        }
        *(byte *)(*param_4 + uVar6 * 4) = (byte)iVar9;
        *(byte *)(*param_4 + 1 + uVar6 * 4) = (byte)local_78;
        *(short *)(*param_4 + 2 + uVar6 * 4) = (short)(local_6c - *param_4 >> 2);
        uVar5 = uVar6;
      } while( true );
    }
  }
  else if ((param_1 != 2) || (local_54 < 0x251)) goto LAB_0067f20c;
  return 1;
}

