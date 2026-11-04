
undefined4 FUN_005409e0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int local_94;
  int local_8c;
  undefined1 local_88;
  undefined4 local_87;
  undefined2 local_83;
  undefined1 local_81;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  int local_6c;
  int local_64;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  uint local_10;
  
  FUN_0056d380(&local_80,0,0x80);
  local_80 = 0x44;
  local_7f = 0x44;
  local_7e = 0x53;
  local_7d = 0x20;
  local_7c = 0x7c;
  local_78 = 0x100f;
  local_14 = 0x1000;
  if (1 < param_4) {
    local_14 = 0x401008;
    local_78 = 0x2100f;
    local_64 = param_4;
  }
  if (param_3 != 0) {
    local_10 = local_10 | 0xfe00;
  }
  local_74 = *(undefined4 *)(param_2 + 0x42c);
  local_70 = *(int *)(param_2 + 0x428);
  pbVar7 = (byte *)(param_2 + 4);
  local_6c = (uint)*pbVar7 * local_70;
  local_34 = 0x20;
  if (*(char *)(param_2 + 3) == '\0') {
    if (*(char *)(param_2 + 2) == '\x10') {
      cVar1 = *(char *)(param_2 + 1);
      local_30 = 4;
      if (cVar1 == '\x01') {
        local_2c = 0x51;
      }
      else if (cVar1 == '\x02') {
        local_2c = 0x22;
      }
      else {
        if (cVar1 != '\x04') {
          FUN_0056bb10(&DAT_007d5d30);
          return 0xffffffff;
        }
        local_2c = 0x24;
      }
    }
    else {
      local_30 = 0x40;
      if (*(char *)(param_2 + 0xb) != '\0') {
        local_14 = local_14 | 2;
        local_30 = 0x41;
      }
      local_28 = (uint)*(byte *)(param_2 + 5);
      local_24 = *(undefined4 *)(param_2 + 0x10);
      local_20 = *(undefined4 *)(param_2 + 0x14);
      local_1c = *(undefined4 *)(param_2 + 0x18);
      local_18 = *(undefined4 *)(param_2 + 0x1c);
    }
  }
  else {
    local_30 = 4;
    if (*(char *)(param_2 + 2) == '\x10') {
      cVar1 = *(char *)(param_2 + 1);
      if (cVar1 == '\x01') {
        local_2c = 0x6f;
      }
      else if (cVar1 == '\x02') {
        local_2c = 0x70;
      }
      else {
        if (cVar1 != '\x04') goto LAB_00540ae7;
        local_2c = 0x71;
      }
    }
    else {
      if (*(char *)(param_2 + 2) != ' ') {
        FUN_0056bb10(&DAT_007d5dbc);
        return 0xffffffff;
      }
      cVar1 = *(char *)(param_2 + 1);
      if (cVar1 == '\x01') {
        local_2c = 0x72;
      }
      else if (cVar1 == '\x02') {
        local_2c = 0x73;
      }
      else {
        if (cVar1 != '\x04') {
LAB_00540ae7:
          FUN_0056bb10(&DAT_007d5d80);
          return 0xffffffff;
        }
        local_2c = 0x74;
      }
    }
  }
  thunk_FUN_00595680(param_1);
  iVar3 = thunk_FUN_00595690(param_1);
  if (iVar3 == 0) {
    FUN_0056bb10(&DAT_007d5cfc);
    return 0xffffffff;
  }
  thunk_FUN_00595750(iVar3,&local_80,0x80,0);
  local_94 = (-(uint)(param_3 != 0) & 5) + 1;
  if (param_4 < 2) {
    if (local_94 != 0) {
      do {
        bVar2 = *pbVar7;
        iVar8 = *(int *)(pbVar7 + 0x424);
        iVar5 = *(int *)(pbVar7 + 0x430);
        if (0 < *(int *)(pbVar7 + 0x428)) {
          iVar6 = 0;
          do {
            thunk_FUN_00595750(iVar3,iVar5,(uint)bVar2 * iVar8,0);
            iVar5 = iVar5 + *(int *)(pbVar7 + 0x42c);
            iVar6 = iVar6 + 1;
          } while (iVar6 < *(int *)(pbVar7 + 0x428));
        }
        pbVar7 = pbVar7 + 0x440;
        local_94 = local_94 + -1;
      } while (local_94 != 0);
    }
  }
  else {
    local_88 = 0;
    local_87 = 0;
    local_83 = 0;
    local_81 = 0;
    if (local_94 != 0) {
      do {
        if (0 < param_4) {
          local_8c = param_4;
          do {
            iVar6 = (uint)*(byte *)(param_2 + 4) * *(int *)(param_2 + 0x428);
            iVar8 = *(int *)(param_2 + 0x434);
            iVar5 = 0;
            if (0 < *(int *)(param_2 + 0x42c)) {
              do {
                thunk_FUN_00595750(iVar3,iVar8,iVar6,0);
                iVar8 = iVar8 + *(int *)(param_2 + 0x430);
                iVar5 = iVar5 + 1;
              } while (iVar5 < *(int *)(param_2 + 0x42c));
            }
            uVar4 = *(int *)(param_2 + 0x42c) * iVar6;
            if (uVar4 < 8) {
              thunk_FUN_00595750(iVar3,&local_88,8 - uVar4,0);
            }
            param_2 = param_2 + 0x440;
            local_8c = local_8c + -1;
          } while (local_8c != 0);
        }
        local_94 = local_94 + -1;
      } while (local_94 != 0);
    }
  }
  thunk_FUN_005956d0(iVar3);
  return 0;
}

