
/* WARNING: Removing unreachable block (ram,0x004f8ca1) */

undefined4 * FUN_004f87b0(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  undefined1 local_128 [4];
  undefined1 local_124 [8];
  ulonglong local_11c;
  undefined4 local_114 [5];
  code *local_100;
  undefined4 local_f8;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  int local_e4;
  uint local_dc;
  int local_d8;
  undefined4 local_d4 [2];
  longlong local_cc;
  ulonglong local_ac;
  uint local_a4;
  int local_a0;
  uint local_9c;
  int local_98;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  uint local_10;
  undefined4 *local_c;
  int local_8;
  
  local_14 = 0;
  if (s_unzip_1_01_Copyright_1998_2004_G_007d22b8[0] == ' ') {
    local_ec = 0;
    local_f0 = 0;
    if (param_2 == (undefined4 *)0x0) {
      FUN_00401ad0(local_114);
    }
    else {
      puVar2 = local_114;
      for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *param_2;
        param_2 = param_2 + 1;
        puVar2 = puVar2 + 1;
      }
    }
    local_e8 = param_3;
    local_e4 = FUN_00401710(local_114,param_1,5);
    if (local_e4 == 0) {
      local_c = (undefined4 *)0x0;
    }
    else {
      local_11c = FUN_004f9340(local_114,local_e4);
      if (local_11c == 0) {
        uVar4 = FUN_004f9100(local_114,local_e4);
        if (uVar4 == 0) {
          local_14 = -1;
        }
        local_2c = 0;
        local_11c = uVar4;
        iVar1 = FUN_00401750(local_114,local_e4,uVar4,0);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        iVar1 = FUN_004f8e60(local_114,local_e4,&local_10);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        iVar1 = FUN_004f8d80(local_114,local_e4,&local_8);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        iVar1 = FUN_004f8d80(local_114,local_e4,&local_20);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        iVar1 = FUN_004f8d80(local_114,local_e4,&local_10);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        local_dc = local_10;
        local_d8 = 0;
        iVar1 = FUN_004f8d80(local_114,local_e4,&local_10);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        local_1c = local_10;
        local_18 = 0;
        if ((((local_10 != local_dc) || (local_d8 != 0)) || (local_20 != 0)) || (local_8 != 0)) {
          local_14 = -0x67;
        }
        iVar1 = FUN_004f8e60(local_114,local_e4,&local_10);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        local_a4 = local_10;
        local_a0 = 0;
        iVar1 = FUN_004f8e60(local_114,local_e4,&local_10);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        local_9c = local_10;
        local_98 = 0;
        iVar1 = FUN_004f8d80(local_114,local_e4,local_d4);
        if (iVar1 != 0) {
          local_14 = -1;
        }
      }
      else {
        local_2c = 1;
        iVar1 = FUN_00401750(local_114,local_e4,local_11c,0);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        iVar1 = FUN_004f8e60(local_114,local_e4,&local_10);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        iVar1 = FUN_004f8f30(local_114,local_e4,local_124);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        iVar1 = FUN_004f8d80(local_114,local_e4,local_128);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        iVar1 = FUN_004f8d80(local_114,local_e4,local_128);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        iVar1 = FUN_004f8e60(local_114,local_e4,&local_8);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        iVar1 = FUN_004f8e60(local_114,local_e4,&local_20);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        iVar1 = FUN_004f8f30(local_114,local_e4,&local_dc);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        iVar1 = FUN_004f8f30(local_114,local_e4,&local_1c);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        if (((local_1c != local_dc) || (local_18 != local_d8)) ||
           ((local_20 != 0 || (local_8 != 0)))) {
          local_14 = -0x67;
        }
        iVar1 = FUN_004f8f30(local_114,local_e4,&local_a4);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        iVar1 = FUN_004f8f30(local_114,local_e4,&local_9c);
        if (iVar1 != 0) {
          local_14 = -1;
        }
        local_d4[0] = 0;
      }
      if ((local_11c <
           CONCAT44(local_98 + local_a0 + (uint)CARRY4(local_9c,local_a4),local_9c + local_a4)) &&
         (local_14 == 0)) {
        local_14 = -0x67;
      }
      if (local_14 == 0) {
        local_cc = local_11c -
                   CONCAT44(local_98 + local_a0 + (uint)CARRY4(local_9c,local_a4),
                            local_9c + local_a4);
        local_34 = 0;
        local_30 = 0;
        local_ac = local_11c;
        local_c = _malloc(0xf0);
        if (local_c != (undefined4 *)0x0) {
          puVar2 = local_114;
          puVar3 = local_c;
          for (iVar1 = 0x3c; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar3 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar3 = puVar3 + 1;
          }
          FUN_004fa100(local_c);
        }
      }
      else {
        (*local_100)(local_f8,local_e4);
        local_c = (undefined4 *)0x0;
      }
    }
  }
  else {
    local_c = (undefined4 *)0x0;
  }
  return local_c;
}

