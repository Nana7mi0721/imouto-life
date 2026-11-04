
undefined4 __thiscall FUN_00479720(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined *local_10;
  int local_c;
  
  local_c = 0;
  do {
    if (3 < local_c) {
      return 1;
    }
    if ((*(byte *)(param_1 + local_c + 1) & 1) == 0) {
      return 1;
    }
    local_10 = *(undefined **)(param_1 + 8 + local_c * 4);
    if ((999999 < (int)local_10) && ((int)local_10 < 1200000)) {
      local_10 = (undefined *)(param_2 * 10 + 1000000 + (int)local_10 % 10);
    }
    if ((0x8c3a6f < (int)local_10) && ((int)local_10 < 9200000)) {
      local_10 = &DAT_008adae0 + (int)local_10 % 10 + param_2 * 10;
    }
    uVar1 = FUN_0043b320(local_10,0,0);
    local_10 = *(undefined **)(param_1 + 0x18 + local_c * 4);
    if ((1099999 < (int)local_10) && ((int)local_10 < 1200000)) {
      local_10 = (undefined *)(param_2 * 10 + 1000000 + (int)local_10 % 10);
    }
    if ((0x8c3a6f < (int)local_10) && ((int)local_10 < 9200000)) {
      local_10 = &DAT_008adae0 + (int)local_10 % 10 + param_2 * 10;
    }
    uVar2 = FUN_0043b320(local_10,0,0);
    if ((*(byte *)(param_1 + local_c + 1) & 0xf0) == 0) {
      if ((int)uVar1 <= (int)uVar2) {
        return 0;
      }
    }
    else if ((int)(*(byte *)(param_1 + local_c + 1) & 0xf0) >> 4 == 1) {
      if ((int)uVar1 < (int)uVar2) {
        return 0;
      }
    }
    else if ((int)(*(byte *)(param_1 + local_c + 1) & 0xf0) >> 4 == 2) {
      if (uVar1 != uVar2) {
        return 0;
      }
    }
    else if ((int)(*(byte *)(param_1 + local_c + 1) & 0xf0) >> 4 == 3) {
      if ((int)uVar2 < (int)uVar1) {
        return 0;
      }
    }
    else if ((int)(*(byte *)(param_1 + local_c + 1) & 0xf0) >> 4 == 4) {
      if ((int)uVar2 <= (int)uVar1) {
        return 0;
      }
    }
    else if ((int)(*(byte *)(param_1 + local_c + 1) & 0xf0) >> 4 == 5) {
      if (uVar1 == uVar2) {
        return 0;
      }
    }
    else {
      if ((int)(*(byte *)(param_1 + local_c + 1) & 0xf0) >> 4 != 6) {
        return 0;
      }
      if ((uVar1 & uVar2) != *(uint *)(param_1 + 0x18 + local_c * 4)) {
        return 0;
      }
    }
    local_c = local_c + 1;
  } while( true );
}

