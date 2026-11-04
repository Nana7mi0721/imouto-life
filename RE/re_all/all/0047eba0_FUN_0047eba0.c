
uint __thiscall FUN_0047eba0(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  byte *pbVar2;
  uint local_28;
  uint local_20;
  undefined1 local_1c;
  uint local_18 [4];
  int local_8;
  
  if (*(int *)(param_1 + 0x1658) != -1) {
    for (local_8 = 2; -1 < local_8; local_8 = local_8 + -1) {
      uVar1 = FUN_0047a4d0(param_2,param_3 + 1,local_8);
      pbVar2 = (byte *)FUN_004cd7c0(uVar1);
      local_18[0] = (uint)*pbVar2;
      uVar1 = FUN_0047a4d0(param_2 + 1,param_3 + 1,local_8);
      pbVar2 = (byte *)FUN_004cd7c0(uVar1);
      param_1 = (uint)*pbVar2;
      local_18[1] = param_1;
      for (local_20 = 0; (int)local_20 < 2; local_20 = local_20 + 1) {
        if (local_18[local_20] == 0) {
          local_18[local_20] = 0xffffd8f0;
          param_1 = local_20;
        }
      }
      if ((int)local_18[1] < (int)local_18[0]) {
        local_28 = local_18[0];
      }
      else {
        local_28 = local_18[1];
        param_1 = local_18[1];
      }
      if (local_28 != 0xffffd8f0) {
        local_1c = (undefined1)local_28;
        return CONCAT31((int3)(param_1 >> 8),local_1c);
      }
    }
  }
  return param_1 & 0xffffff00;
}

