
int FUN_004f9850(int param_1,undefined4 *param_2,int *param_3,int param_4,uint param_5,int param_6,
                uint param_7,int param_8,uint param_9)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint local_98;
  undefined1 local_94 [4];
  int local_90;
  int local_8c;
  uint local_88;
  uint local_84;
  int local_80;
  uint local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  undefined4 local_64;
  undefined1 local_60 [4];
  undefined1 local_5c [4];
  undefined1 local_58 [4];
  undefined4 local_54;
  undefined1 local_50 [4];
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined1 local_24 [24];
  int local_c;
  int local_8;
  
  local_78 = 0;
  local_6c = 0;
  if (param_1 == 0) {
    local_78 = -0x66;
  }
  else {
    local_8 = param_1;
    iVar1 = FUN_00401750(param_1,*(undefined4 *)(param_1 + 0x30),
                         *(uint *)(param_1 + 0x58) + *(uint *)(param_1 + 0x48),
                         *(int *)(param_1 + 0x5c) + *(int *)(param_1 + 0x4c) +
                         (uint)CARRY4(*(uint *)(param_1 + 0x58),*(uint *)(param_1 + 0x48)),0);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    if (local_78 == 0) {
      iVar1 = FUN_004f8e60(local_8,*(undefined4 *)(local_8 + 0x30),&local_c);
      if (iVar1 == 0) {
        if (local_c != 0x2014b50) {
          local_78 = -0x67;
        }
      }
      else {
        local_78 = -1;
      }
    }
    iVar1 = FUN_004f8d80(local_8,*(undefined4 *)(local_8 + 0x30),&local_64);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    iVar1 = FUN_004f8d80(local_8,*(undefined4 *)(local_8 + 0x30),local_60);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    iVar1 = FUN_004f8d80(local_8,*(undefined4 *)(local_8 + 0x30),local_5c);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    iVar1 = FUN_004f8d80(local_8,*(undefined4 *)(local_8 + 0x30),local_58);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    iVar1 = FUN_004f8e60(local_8,*(undefined4 *)(local_8 + 0x30),&local_54);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    FUN_004f9f30(local_54,0,local_24);
    iVar1 = FUN_004f8e60(local_8,*(undefined4 *)(local_8 + 0x30),local_50);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    iVar1 = FUN_004f8e60(local_8,*(undefined4 *)(local_8 + 0x30),&local_68);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    local_4c = local_68;
    local_48 = 0;
    iVar1 = FUN_004f8e60(local_8,*(undefined4 *)(local_8 + 0x30),&local_68);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    local_44 = local_68;
    local_40 = 0;
    iVar1 = FUN_004f8d80(local_8,*(undefined4 *)(local_8 + 0x30),&local_3c);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    iVar1 = FUN_004f8d80(local_8,*(undefined4 *)(local_8 + 0x30),&local_38);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    iVar1 = FUN_004f8d80(local_8,*(undefined4 *)(local_8 + 0x30),&local_34);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    iVar1 = FUN_004f8d80(local_8,*(undefined4 *)(local_8 + 0x30),&local_30);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    iVar1 = FUN_004f8d80(local_8,*(undefined4 *)(local_8 + 0x30),local_2c);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    iVar1 = FUN_004f8e60(local_8,*(undefined4 *)(local_8 + 0x30),local_28);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    iVar1 = FUN_004f8e60(local_8,*(undefined4 *)(local_8 + 0x30),&local_68);
    if (iVar1 != 0) {
      local_78 = -1;
    }
    local_74 = local_68;
    local_70 = 0;
    local_6c = local_6c + local_3c;
    if ((local_78 == 0) && (param_4 != 0)) {
      if (local_3c < param_5) {
        *(undefined1 *)(param_4 + local_3c) = 0;
        local_7c = local_3c;
      }
      else {
        local_7c = param_5;
      }
      if (((local_3c != 0) && (param_5 != 0)) &&
         (uVar2 = (**(code **)(local_8 + 4))
                            (*(undefined4 *)(local_8 + 0x1c),*(undefined4 *)(local_8 + 0x30),param_4
                             ,local_7c), uVar2 != local_7c)) {
        local_78 = -1;
      }
      local_6c = local_6c - local_7c;
    }
    if ((local_78 == 0) && (param_6 != 0)) {
      if (local_38 < param_7) {
        local_84 = local_38;
      }
      else {
        local_84 = param_7;
      }
      local_80 = 0;
      if (local_6c != 0) {
        iVar1 = FUN_00401750(local_8,*(undefined4 *)(local_8 + 0x30),local_6c,local_6c >> 0x1f,1);
        if (iVar1 == 0) {
          local_6c = 0;
        }
        else {
          local_78 = -1;
        }
      }
      if (((local_38 != 0) && (param_7 != 0)) &&
         ((uVar2 = (**(code **)(local_8 + 4))
                             (*(undefined4 *)(local_8 + 0x1c),*(undefined4 *)(local_8 + 0x30),
                              param_6,local_84), uVar2 != local_84 || (local_80 != 0)))) {
        local_78 = -1;
      }
      local_6c = (local_38 - local_84) + local_6c;
    }
    else {
      local_6c = local_6c + local_38;
    }
    if ((local_78 == 0) && (local_38 != 0)) {
      local_88 = 0;
      local_6c = local_6c - local_38;
      if (local_6c != 0) {
        iVar1 = FUN_00401750(local_8,*(undefined4 *)(local_8 + 0x30),local_6c,local_6c >> 0x1f,1);
        if (iVar1 == 0) {
          local_6c = 0;
        }
        else {
          local_78 = -1;
        }
      }
      for (; local_88 < local_38; local_88 = local_88 + 4 + local_8c) {
        iVar1 = FUN_004f8d80(local_8,*(undefined4 *)(local_8 + 0x30),&local_90);
        if (iVar1 != 0) {
          local_78 = -1;
        }
        iVar1 = FUN_004f8d80(local_8,*(undefined4 *)(local_8 + 0x30),&local_8c);
        if (iVar1 != 0) {
          local_78 = -1;
        }
        if (local_90 == 1) {
          if (((local_44 == -1) && (local_40 == 0)) &&
             (iVar1 = FUN_004f8f30(local_8,*(undefined4 *)(local_8 + 0x30),&local_44), iVar1 != 0))
          {
            local_78 = -1;
          }
          if (((local_4c == -1) && (local_48 == 0)) &&
             (iVar1 = FUN_004f8f30(local_8,*(undefined4 *)(local_8 + 0x30),&local_4c), iVar1 != 0))
          {
            local_78 = -1;
          }
          if (((local_74 == -1) && (local_70 == 0)) &&
             (iVar1 = FUN_004f8f30(local_8,*(undefined4 *)(local_8 + 0x30),&local_74), iVar1 != 0))
          {
            local_78 = -1;
          }
          if ((local_30 == -1) &&
             (iVar1 = FUN_004f8e60(local_8,*(undefined4 *)(local_8 + 0x30),local_94), iVar1 != 0)) {
            local_78 = -1;
          }
        }
        else {
          iVar1 = FUN_00401750(local_8,*(undefined4 *)(local_8 + 0x30),local_8c,0,1);
          if (iVar1 != 0) {
            local_78 = -1;
          }
        }
      }
    }
    if ((local_78 == 0) && (param_8 != 0)) {
      if (local_34 < param_9) {
        *(undefined1 *)(param_8 + local_34) = 0;
        local_98 = local_34;
      }
      else {
        local_98 = param_9;
      }
      if (local_6c != 0) {
        iVar1 = FUN_00401750(local_8,*(undefined4 *)(local_8 + 0x30),local_6c,local_6c >> 0x1f,1);
        if (iVar1 == 0) {
          local_6c = 0;
        }
        else {
          local_78 = -1;
        }
      }
      if (((local_34 != 0) && (param_9 != 0)) &&
         (uVar2 = (**(code **)(local_8 + 4))
                            (*(undefined4 *)(local_8 + 0x1c),*(undefined4 *)(local_8 + 0x30),param_8
                             ,local_98), uVar2 != local_98)) {
        local_78 = -1;
      }
    }
    if ((local_78 == 0) && (param_2 != (undefined4 *)0x0)) {
      puVar3 = &local_64;
      for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
        *param_2 = *puVar3;
        puVar3 = puVar3 + 1;
        param_2 = param_2 + 1;
      }
    }
    if ((local_78 == 0) && (param_3 != (int *)0x0)) {
      *param_3 = local_74;
      param_3[1] = local_70;
    }
  }
  return local_78;
}

