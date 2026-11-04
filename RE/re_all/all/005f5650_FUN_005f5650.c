
undefined4 FUN_005f5650(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  uint uVar11;
  int *piVar12;
  undefined1 local_6c [8];
  char local_64;
  char local_63;
  char local_62;
  char local_61;
  char local_60;
  char local_5f;
  char local_5e;
  char local_5d;
  undefined1 local_5c [4];
  undefined1 local_58 [4];
  undefined1 local_54 [4];
  undefined1 local_50 [4];
  uint local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined1 *local_30;
  int local_2c;
  byte *local_28;
  byte *local_24;
  uint local_20;
  int local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  int local_10;
  int local_c;
  char local_5;
  
  local_34 = 0;
  local_18 = (undefined1 *)0x0;
  local_5 = '\0';
  (**(code **)(param_1 + 8))(&local_64,8,1,*(undefined4 *)(param_1 + 0x18));
  (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 0x18),0,0,0);
  if (local_64 != -0x77) {
    return 0xffffffff;
  }
  if (local_63 != 'P') {
    return 0xffffffff;
  }
  if (local_62 != 'N') {
    return 0xffffffff;
  }
  if (local_61 != 'G') {
    return 0xffffffff;
  }
  if (local_60 != '\r') {
    return 0xffffffff;
  }
  if (local_5f != '\n') {
    return 0xffffffff;
  }
  if (local_5e != '\x1a') {
    return 0xffffffff;
  }
  if (local_5d != '\n') {
    return 0xffffffff;
  }
  local_c = FUN_0066bc40(s_1_6_12_00a05944,0,0,0);
  if (local_c == 0) {
    return 0xffffffff;
  }
  local_10 = FUN_00669210(local_c);
  if (local_10 == 0) {
    piVar12 = (int *)0x0;
    goto LAB_005f5818;
  }
  uVar2 = FUN_00668c20(local_c,&LAB_006c5890,0x40);
  iVar3 = __setjmp3(uVar2,0);
  if (iVar3 != 0) {
LAB_005f5813:
    piVar12 = &local_10;
LAB_005f5818:
    FUN_0066c7e0(&local_c,piVar12,0);
    return 0xffffffff;
  }
  FUN_005f55a0(local_c,local_6c,param_1);
  FUN_00668df0(local_c,local_34);
  FUN_0066bcd0(local_c,local_10);
  FUN_0066bab0(local_c,local_10,&local_20,&local_14,&local_38,&local_2c,local_50,0,0);
  FUN_0066d1b0(local_c);
  FUN_0066cbf0(local_c);
  FUN_0066cc20(local_c);
  if ((local_2c == 0) && (local_38 < 9)) {
    FUN_0066d1d0(local_c);
    local_5 = '\x01';
  }
  FUN_0066cbe0(local_c);
  FUN_0066bfc0(local_c,local_10);
  uVar4 = FUN_0066ba70(local_c,local_10);
  local_4c = uVar4;
  if (param_3 == 0) {
    pbVar5 = (byte *)FUN_0056e030((int)local_14 * 4,s_D__DxLib_Develop_Source_Library__00a058f8,
                                  0x1f0);
    local_28 = pbVar5;
    if (pbVar5 == (byte *)0x0) goto LAB_005f5813;
    iVar3 = FUN_0066caf0(local_c,uVar4 * (int)local_14);
    local_3c = iVar3;
    if (iVar3 == 0) {
      FUN_0056e1d0(pbVar5);
      FUN_0066c7e0(&local_c,&local_10,0);
      return 0xffffffff;
    }
    puVar6 = (undefined1 *)0x0;
    if (local_14 != (undefined1 *)0x0) {
      iVar7 = iVar3;
      pbVar9 = pbVar5;
      do {
        *(int *)pbVar9 = iVar7;
        puVar6 = puVar6 + 1;
        pbVar9 = pbVar9 + 4;
        iVar7 = iVar7 + uVar4;
      } while (puVar6 < local_14);
    }
    FUN_0066c440(local_c,pbVar5);
    puVar6 = (undefined1 *)
             FUN_0056e030(uVar4 * (int)local_14,s_D__DxLib_Develop_Source_Library__00a058f8,0x20a);
    local_18 = puVar6;
    if (puVar6 == (undefined1 *)0x0) {
      FUN_0066cb60(local_c,iVar3);
      FUN_0056e1d0(pbVar5);
      FUN_0066c7e0(&local_c,&local_10,0);
      return 0xffffffff;
    }
    puVar10 = (undefined1 *)0x0;
    if (local_14 != (undefined1 *)0x0) {
      local_24 = local_28;
      do {
        FUN_0056d420(puVar6,*(undefined4 *)local_24,uVar4);
        puVar10 = puVar10 + 1;
        local_24 = local_24 + 4;
        puVar6 = puVar6 + uVar4;
      } while (puVar10 < local_14);
    }
    FUN_0066cb60(local_c,local_3c);
    FUN_0056e1d0(local_28);
    FUN_0066c4e0(local_c,local_10);
  }
  *(undefined1 **)(param_2 + 0x42c) = local_14;
  *(uint *)(param_2 + 0x428) = local_20;
  *(uint *)(param_2 + 0x430) = uVar4;
  *(undefined1 **)(param_2 + 0x434) = local_18;
  if ((local_2c == 3) && (local_5 == '\0')) {
    FUN_00544440(param_2);
    FUN_0066bb80(local_c,local_10,&local_30,&local_1c);
    if (0x100 < local_1c) {
      local_1c = 0x100;
    }
    puVar6 = (undefined1 *)(param_2 + 0x28);
    if (0 < local_1c) {
      puVar10 = local_30;
      iVar3 = local_1c;
      do {
        local_30 = puVar10 + 3;
        *puVar6 = puVar10[2];
        puVar6[1] = puVar10[1];
        puVar6[2] = *puVar10;
        puVar6[3] = 0;
        puVar6 = puVar6 + 4;
        iVar3 = iVar3 + -1;
        puVar10 = local_30;
      } while (iVar3 != 0);
    }
    iVar3 = FUN_0066ba50(local_c,local_10,0x10);
    if (iVar3 != 0) {
      FUN_0066bbc0(local_c,local_10,&local_44,&local_40,local_54);
      iVar3 = 0;
      if (0 < local_40) {
        puVar6 = (undefined1 *)(param_2 + 0x2b);
        do {
          puVar10 = (undefined1 *)(local_44 + iVar3);
          iVar3 = iVar3 + 1;
          *puVar6 = *puVar10;
          puVar6 = puVar6 + 4;
        } while (iVar3 < local_40);
      }
      if (local_40 < local_1c) {
        puVar6 = (undefined1 *)(param_2 + 0x2b + local_40 * 4);
        do {
          *puVar6 = 0xff;
          local_40 = local_40 + 1;
          puVar6 = puVar6 + 4;
        } while (local_40 < local_1c);
      }
      *(undefined1 *)(param_2 + 0xf) = 0x18;
      *(undefined4 *)(param_2 + 0x1c) = 0xff000000;
      *(undefined1 *)(param_2 + 0xb) = 8;
    }
  }
  else if (local_2c == 0) {
    if (uVar4 >> 1 < local_20) {
      FUN_005445c0(param_2);
    }
    else {
      *(undefined1 *)(param_2 + 5) = 0x10;
      *(undefined1 *)(param_2 + 4) = 2;
      *(undefined4 *)(param_2 + 0x20) = 0xff;
      *(undefined1 *)(param_2 + 0xf) = 0;
      *(undefined4 *)(param_2 + 0x1c) = 0;
      *(undefined1 *)(param_2 + 0xb) = 0;
      *(undefined1 *)(param_2 + 0xc) = 8;
      *(undefined4 *)(param_2 + 0x10) = 0xff00;
      *(undefined1 *)(param_2 + 8) = 8;
      *(undefined1 *)(param_2 + 0xd) = 8;
      *(undefined4 *)(param_2 + 0x14) = 0xff00;
      *(undefined1 *)(param_2 + 9) = 8;
      *(undefined1 *)(param_2 + 0xe) = 8;
      *(undefined4 *)(param_2 + 0x18) = 0xff00;
      *(undefined1 *)(param_2 + 10) = 8;
    }
  }
  else if (local_2c == 4) {
    iVar3 = local_20 * 4;
    *(int *)(param_2 + 0x430) = iVar3;
    FUN_00544500(param_2);
    if (param_3 == 0) {
      puVar6 = (undefined1 *)
               FUN_0056e030(iVar3 * (int)local_14,s_D__DxLib_Develop_Source_Library__00a058f8,0x28c)
      ;
      puVar10 = (undefined1 *)0x0;
      if (puVar6 == (undefined1 *)0x0) {
        FUN_0066c7e0(&local_c,&local_10,0);
        FUN_0056e1d0(local_18);
        return 0xffffffff;
      }
      *(undefined1 **)(param_2 + 0x434) = puVar6;
      if (uVar4 >> 1 < local_20) {
        puVar8 = local_18;
        if (local_14 != (undefined1 *)0x0) {
          do {
            uVar11 = 0;
            if (local_20 != 0) {
              do {
                *puVar6 = 0xff;
                puVar6[1] = 0xff;
                puVar6[2] = 0xff;
                puVar6[3] = *puVar8;
                puVar6 = puVar6 + 4;
                puVar8 = puVar8 + 1;
                uVar11 = uVar11 + 1;
              } while (uVar11 < local_20);
            }
            puVar8 = puVar8 + (uVar4 - local_20);
            puVar10 = puVar10 + 1;
          } while (puVar10 < local_14);
        }
      }
      else {
        local_30 = (undefined1 *)0x0;
        puVar10 = local_18;
        if (local_14 != (undefined1 *)0x0) {
          do {
            uVar11 = 0;
            puVar8 = puVar10;
            if (local_20 != 0) {
              do {
                puVar10 = puVar8 + 2;
                *puVar6 = *puVar8;
                puVar6[1] = *puVar8;
                puVar6[2] = *puVar8;
                puVar6[3] = puVar8[1];
                puVar6 = puVar6 + 4;
                uVar11 = uVar11 + 1;
                puVar8 = puVar10;
              } while (uVar11 < local_20);
            }
            puVar10 = puVar10 + uVar4 + local_20 * -2;
            local_30 = local_30 + 1;
          } while (local_30 < local_14);
          FUN_0056e1d0(local_18);
          goto LAB_005f5d75;
        }
      }
      FUN_0056e1d0(local_18);
    }
  }
  else {
    cVar1 = FUN_0066ba90(local_c,local_10);
    if (cVar1 == '\x04') {
      FUN_00544560(param_2);
      *(undefined1 *)(param_2 + 5) = 0x20;
      *(undefined1 *)(param_2 + 4) = 4;
      *(undefined1 *)(param_2 + 0xf) = 0x18;
      *(undefined1 *)(param_2 + 0xb) = 8;
      *(undefined4 *)(param_2 + 0x1c) = 0xff000000;
    }
    else {
      iVar3 = FUN_0066ba50(local_c,local_10,0x10);
      if (iVar3 == 0) {
        FUN_00544560(param_2);
      }
      else {
        FUN_0066bbc0(local_c,local_10,local_5c,local_58,&local_48);
        FUN_00544560(param_2);
        iVar7 = *(int *)(param_2 + 0x428) * 4;
        iVar3 = *(int *)(param_2 + 0x434);
        *(undefined1 *)(param_2 + 5) = 0x20;
        *(undefined1 *)(param_2 + 4) = 4;
        *(undefined1 *)(param_2 + 0xf) = 0x18;
        *(undefined1 *)(param_2 + 0xb) = 8;
        *(undefined4 *)(param_2 + 0x1c) = 0xff000000;
        *(int *)(param_2 + 0x430) = iVar7;
        local_44 = iVar3;
        pbVar5 = (byte *)FUN_0056e030(*(int *)(param_2 + 0x42c) * iVar7,
                                      s_D__DxLib_Develop_Source_Library__00a058f8,0x2e3);
        *(byte **)(param_2 + 0x434) = pbVar5;
        if (pbVar5 == (byte *)0x0) {
          FUN_0066c7e0(&local_c,&local_10,0);
          FUN_0056e1d0(iVar3);
          return 0xffffffff;
        }
        local_30 = (undefined1 *)0x0;
        local_28 = pbVar5;
        if (0 < *(int *)(param_2 + 0x42c)) {
          local_24 = (byte *)(iVar3 + 2);
          do {
            iVar3 = 0;
            if (0 < *(int *)(param_2 + 0x428)) {
              pbVar5 = local_28 + 3;
              pbVar9 = local_24;
              do {
                pbVar5[-3] = pbVar9[-2];
                pbVar5[-2] = pbVar9[-1];
                pbVar5[-1] = *pbVar9;
                if ((((ushort)pbVar9[-2] == *(ushort *)(local_48 + 6)) &&
                    ((ushort)pbVar9[-1] == *(ushort *)(local_48 + 4))) &&
                   ((ushort)*pbVar9 == *(ushort *)(local_48 + 2))) {
                  *pbVar5 = 0;
                }
                else {
                  *pbVar5 = 0xff;
                }
                iVar3 = iVar3 + 1;
                pbVar9 = pbVar9 + 3;
                pbVar5 = pbVar5 + 4;
              } while (iVar3 < *(int *)(param_2 + 0x428));
              uVar4 = local_4c;
            }
            local_24 = local_24 + uVar4;
            local_30 = local_30 + 1;
            local_28 = local_28 + *(int *)(param_2 + 0x430);
          } while ((int)local_30 < *(int *)(param_2 + 0x42c));
          iVar3 = local_44;
        }
        FUN_0056e1d0(iVar3);
      }
    }
  }
LAB_005f5d75:
  FUN_0066c7e0(&local_c,&local_10,0);
  return 0;
}

